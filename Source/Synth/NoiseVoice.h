#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../Common/VoiceModuleBase.h"
#include "../Common/IVoiceModuleHost.h"

class CNoiseVoice : public CVoiceModuleBase {
public:
	CNoiseVoice(const std::string& name, IVoiceModuleHost& host)
		: CVoiceModuleBase(name, host) {}

	void OnNoteStart(int midiNoteNumber, float velocity,
		SynthesiserSound*, int currentPitchWheelPosition) override;

	void OnNoteStop(float velocity, bool allowTailOff) override;

	void ProcessBlock(AudioSampleBuffer& outputBuffer, int startSample, int numSamples) override;

	virtual void InitProperties(CPropertiesRegistry & registry) override;
private: 
	juce::Random mRandom;
};