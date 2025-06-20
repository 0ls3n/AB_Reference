/*
  ==============================================================================

    WaveformVisualizerComponent.h
    Created: 20 Jun 2025 10:45:26pm
    Author:  rasmu

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "ApplicationColours.h"

//==============================================================================
/*
*/
class WaveformVisualizerComponent  : public juce::Component, private juce::ChangeListener
{
public:
    WaveformVisualizerComponent();
    ~WaveformVisualizerComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

	void setAudioFile(const juce::File& audioFile);
    void setWaveformColour(const juce::Colour& colour);

    void setPlayheadTime(double timeInSeconds);

    std::function<void(double timeInSeconds)> onSeek;

private:

    void WaveformVisualizerComponent::mouseDown(const juce::MouseEvent& e) override;
    void WaveformVisualizerComponent::mouseDrag(const juce::MouseEvent& e) override;

    juce::AudioFormatManager formatManager;
    juce::AudioThumbnailCache thumbnailCache{ 10 };
	juce::AudioThumbnail thumbnail{ 256, formatManager, thumbnailCache };

	juce::Colour waveformColour{ ApplicationColours().secondary };

    double currentPlayheadTime = 0.0f;

    // Inherited via ChangeListener
    void changeListenerCallback(juce::ChangeBroadcaster* source) override;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(WaveformVisualizerComponent)
    

        

};
