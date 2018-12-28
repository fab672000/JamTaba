#include "PortAudioDriver.h"
#include "pa_mac_core.h"
#include "log/Logging.h"

namespace audio {

PortAudioDriver::PortAudioDriver(controller::MainController *mainController,
                                 int deviceInputIndex, int deviceOutputIndex,
                                 int firstInIndex, int lastInIndex, int firstOutIndex,
                                 int lastOutIndex, int sampleRate, int bufferSize) :
    AudioDriver(mainController),
    useSystemDefaultDevices(false) // in mac deviceIndex is always the system default values
{

    Q_UNUSED(firstInIndex)
    Q_UNUSED(firstOutIndex)
    Q_UNUSED(lastInIndex)
    Q_UNUSED(lastOutIndex)

    // initialize portaudio using default devices, mono input and try estereo output if possible
    PaError error = Pa_Initialize();
    if (error == paNoError) {
        audioInputDeviceIndex = deviceInputIndex;
        audioOutputDeviceIndex = UseSingleAudioIODevice ? deviceInputIndex : deviceOutputIndex;

        int minInputs = getMaxInputs();
        if (minInputs<1) { // this driver is ouput only or does not exist anymore, so fallback to default device
            audioInputDeviceIndex = Pa_GetDefaultInputDevice();
        }

        int maxOutputs = getMaxOutputs();
        if (maxOutputs<1) { // this driver is input only or does not exist anymore, so fallback to default device
            audioOutputDeviceIndex = Pa_GetDefaultOutputDevice();
            maxOutputs = getMaxOutputs();
        }

        globalInputRange = ChannelRange(0, getMaxInputs());

        globalOutputRange = ChannelRange(0, 2);// 2 channels for output

        if (maxOutputs > 1)
            globalOutputRange.setToStereo();
        if(maxOutputs < 1 || !initPortAudio(sampleRate, bufferSize)) {
            qCritical() << "ERROR initializing portaudio: " << (error ? Pa_GetErrorText(error) : "no output.");
            audioInputDeviceIndex = audioOutputDeviceIndex = paNoDevice;
        }
    } else {
        qCritical() << "ERROR initializing portaudio:" << Pa_GetErrorText(error);
        audioInputDeviceIndex = audioOutputDeviceIndex = paNoDevice;
    }
}

QList<int> PortAudioDriver::getValidBufferSizes(int deviceIndex) const
{
    QList<int> buffersSize;
    long maxBufferSize;
    long minBufferSize;
    PaError result = PaMacCore_GetBufferSizeRange(deviceIndex, &minBufferSize, &maxBufferSize);
    if (result != paNoError) {
        buffersSize.append(256);
        return buffersSize;// return 256 as the only possible value
    }
    for (long size = minBufferSize; size <= maxBufferSize; size *= 2)
        buffersSize.append(size);
    return buffersSize;
}

QString PortAudioDriver::getOutputChannelName(const unsigned int index) const
{
    if (audioOutputDeviceIndex == paNoDevice)
        return "Error! No Output!";

    return QString(PaMacCore_GetChannelName(audioOutputDeviceIndex, index, false));
}

QString PortAudioDriver::getInputChannelName(const unsigned int index) const
{
    if (audioInputDeviceIndex == paNoDevice)
        return "Error! No Input!";

    return QString(PaMacCore_GetChannelName(audioInputDeviceIndex, index, true));
}

void PortAudioDriver::configureHostSpecificInputParameters(PaStreamParameters &inputParameters)
{
    Q_UNUSED(inputParameters)
    // qCDebug(portaudio) << "using MAC scpecific stream infos for inputs";
    // PaMacCoreStreamInfo streamInfo;
    // PaMacCore_SetupStreamInfo(&streamInfo, paMacCorePro);
    // inputParams.hostApiSpecificStreamInfo  = &streamInfo;
}

void PortAudioDriver::configureHostSpecificOutputParameters(PaStreamParameters &outputParameters)
{
    Q_UNUSED(outputParameters)
    // qCDebug(portaudio) << "using MAC scpecific stream infos for output";
    // PaMacCoreStreamInfo outStreamInfo;
    // PaMacCore_SetupStreamInfo(&outStreamInfo, paMacCorePro);
    // outputParams.hostApiSpecificStreamInfo = &outStreamInfo;
}

void PortAudioDriver::releaseHostSpecificParameters(const PaStreamParameters &inputParameters,
                                                    const PaStreamParameters &outputParameters)
{
    Q_UNUSED(inputParameters)
    Q_UNUSED(outputParameters)
}

bool PortAudioDriver::hasControlPanel() const
{
    return false;
}

void PortAudioDriver::openControlPanel(void *mainWindowHandle)
{
    Q_UNUSED(mainWindowHandle)
}

void PortAudioDriver::preInitializePortAudioStream(PaStream *stream)
{
    Q_UNUSED(stream)
}


}// namespace
