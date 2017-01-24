#include "PeakMeter.h"
#include "Utils.h"
#include <QDebug>
#include <QResizeEvent>
#include <QDateTime>
#include <QPainter>
#include <QStyle>

const int BaseMeter::LINES_MARGIN = 3;
const int BaseMeter::MIN_SIZE = 1;
const int BaseMeter::DEFAULT_DECAY_TIME = 2000;

const QColor AudioMeter::MAX_PEAK_COLOR = QColor(0, 0, 0, 80);
const QColor AudioMeter::RMS_COLOR = QColor(255, 255, 255, 120);

const int AudioMeter::MAX_PEAK_MARKER_SIZE = 2;
const int AudioMeter::MAX_PEAK_SHOW_TIME = 1500;

bool AudioMeter::paintingMaxPeakMarker = true;
bool AudioMeter::paintingPeaks = true;
bool AudioMeter::paintingRMS = true;

const quint8 AudioMeter::segmentsSize = 6;

BaseMeter::BaseMeter(QWidget *parent) :
    QFrame(parent),
    lastUpdate(QDateTime::currentMSecsSinceEpoch()),
    decayTime(DEFAULT_DECAY_TIME),
    orientation(Qt::Vertical)
{
    //setAttribute(Qt::WA_NoBackground);
    //update();
}

BaseMeter::~BaseMeter()
{

}

QSize BaseMeter::minimumSizeHint() const
{
    bool isVerticalMeter = isVertical();
    int w = isVerticalMeter ? MIN_SIZE : width();
    int h = isVerticalMeter ? height() : MIN_SIZE;
    return QSize(w, h);
}

void BaseMeter::setOrientation(Qt::Orientation orientation)
{
    this->orientation = orientation;
    style()->unpolish(this);
    style()->polish(this);
    update();
}

void BaseMeter::setDecayTime(quint32 decayTimeInMiliseconds)
{
    this->decayTime = decayTimeInMiliseconds;
    update();
}

QRectF BaseMeter::getPaintRect(float peakValue) const
{
    bool isVerticalMeter = isVertical();
    return QRectF(isVerticalMeter ? 1.0f : 0.0f,                // x
               isVerticalMeter ? height() - peakValue : 1.0f,   // y
               isVerticalMeter ? width()-2.0f : peakValue,      // width
               height() - (isVerticalMeter ? 0.0f : 2.0f));     // height
}

float BaseMeter::limitFloatValue(float value, float minValue, float maxValue)
{
    if (value < minValue)
        return minValue;

    if( value > maxValue)
        return maxValue;

    return value;
}

//--------------------------------------------------------------------------------
AudioMeter::AudioMeter(QWidget *parent)
    :
      BaseMeter(parent),
      currentPeak(0.0f),
      currentRms(0.0f),
      maxPeak(0),
      lastMaxPeakTime(0)
{

}

void AudioMeter::setOrientation(Qt::Orientation orientation)
{
    BaseMeter::setOrientation(orientation);
    update();
}


void AudioMeter::resizeEvent(QResizeEvent * /*ev*/)
{
    update();

    // rebuild the peak colors vector
    peakColors.clear();

    const quint32 size = isVertical() ? height() : width();
    const quint32 segments = size/segmentsSize;
    int alpha = 225;
    for (quint32 i = 0; i < segments; ++i) {
        int r = std::pow(((float)i/segments), 2) * 255; // will be 255 when i == segments (max 'i' value)
        int g = (float)(segments - i)/segments * 200;
        int b = 0;
        peakColors.push_back(QColor(r, g, b, alpha));
    }
}

void AudioMeter::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    // meter
    if (isEnabled()) {
        bool isVerticalMeter = isVertical();
        const int rectSize = isVerticalMeter ? height() : width();

        if (currentPeak && paintingPeaks) {
            float peakValue = Utils::poweredGainToLinear(currentPeak) * rectSize;
            const quint32 segmentsToPaint = (quint32)peakValue / segmentsSize;

            int x = 1;
            int y = isVerticalMeter ? (height() - 1) : 1;
            const int w = isVerticalMeter ? (width() - 2) : segmentsSize - 1;
            const int h = isVerticalMeter ? (segmentsSize - 1) : height() - 2;
            for (quint32 i = 0; i < segmentsToPaint; ++i) {
                QColor color = Qt::green;
                if (i < peakColors.size())
                    color = peakColors[i];
                painter.fillRect(x, y, w, h, color);

                if (isVerticalMeter)
                    y -= segmentsSize;
                else
                    x += segmentsSize;
            }
        }

        //draw the rms rect in the top layer
        if (currentRms && paintingRMS) {
            float rmsValue = Utils::poweredGainToLinear(currentRms) * rectSize;
            QRectF rmsRect = getPaintRect(rmsValue);
                painter.fillRect(rmsRect, RMS_COLOR); //paint the "transparent white" rect to highlight the rms meter
        }

        // draw max peak marker
        if (maxPeak > 0 && paintingMaxPeakMarker) {
            float linearPeak = Utils::poweredGainToLinear(maxPeak);
            QRect maxPeakRect(isVerticalMeter ? 0 : (linearPeak * width()),
                           isVerticalMeter ? (height() - linearPeak * height()) : 0,
                           isVerticalMeter ? width() : MAX_PEAK_MARKER_SIZE,
                           isVerticalMeter ? MAX_PEAK_MARKER_SIZE : height());
            painter.fillRect(maxPeakRect, MAX_PEAK_COLOR);
        }
    }

    quint64 now = QDateTime::currentMSecsSinceEpoch();

    // decay
    long ellapsedTimeFromLastUpdate = now - lastUpdate;
    float deltaTime = (float)ellapsedTimeFromLastUpdate/decayTime;
    currentPeak -= deltaTime;
    currentRms  -= deltaTime;

    if (currentPeak < 0)
        currentPeak = 0;

    if (currentRms < 0)
        currentRms = 0;

    lastUpdate = now;

    // max peak
    long ellapsedTimeFromLastMaxPeak = now - lastMaxPeakTime;
    if (ellapsedTimeFromLastMaxPeak >= MAX_PEAK_SHOW_TIME)
        maxPeak = 0;
}

void AudioMeter::setPeak(float peak, float rms)
{
    peak = limitFloatValue(peak);
    rms = limitFloatValue(rms);

    if (peak > currentPeak) {
        currentPeak = peak;
        if (peak > maxPeak) {
            maxPeak = peak;
            lastMaxPeakTime = QDateTime::currentMSecsSinceEpoch();
        }
    }

    if (rms > currentRms)
        currentRms = rms;

    update();
}



void AudioMeter::setPaintMaxPeakMarker(bool paintMaxPeak)
{
    AudioMeter::paintingMaxPeakMarker = paintMaxPeak;
}

void AudioMeter::paintRmsOnly()
{
    paintingRMS = true;
    paintingPeaks = false;
}

void AudioMeter::paintPeaksOnly()
{
    paintingRMS = false;
    paintingPeaks = true;
}

void AudioMeter::paintPeaksAndRms()
{
    paintingRMS = true;
    paintingPeaks = true;
}

bool AudioMeter::isPaintingPeaksOnly()
{
    return paintingPeaks && !paintingRMS;
}

bool AudioMeter::isPaintingRmsOnly()
{
    return paintingRMS && !paintingPeaks;
}

//--------------------------------------------

MidiActivityMeter::MidiActivityMeter(QWidget *parent)
    : BaseMeter(parent),
      solidColor(Qt::red)
{

}

void MidiActivityMeter::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    // meter
    if (isEnabled()) {
        float value = (isVertical() ? height() : width()) * activityValue;
        painter.fillRect(getPaintRect(value), solidColor);

        quint64 now = QDateTime::currentMSecsSinceEpoch();

        // decay
        long ellapsedTimeFromLastUpdate = now - lastUpdate;
        float deltaTime = (float)ellapsedTimeFromLastUpdate/decayTime;
        activityValue -= deltaTime;

        if (activityValue < 0)
            activityValue = 0;

        lastUpdate = now;
    }
}

void MidiActivityMeter::setSolidColor(const QColor &color)
{
    this->solidColor = color;
    update();
}

void MidiActivityMeter::setActivityValue(float value)
{
    this->activityValue = limitFloatValue(value);
}
