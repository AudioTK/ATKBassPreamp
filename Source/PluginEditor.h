/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "PluginProcessor.h"
#include <JuceHeader.h>

#include <ATKJUCEComponents/JUCE/ImageLookAndFeel.h>
#include <ATKJUCEComponents/JUCE/Slider.h>

//==============================================================================
/**
 */
class ATKBassPreampAudioProcessorEditor: public juce::AudioProcessorEditor
{
public:
  ATKBassPreampAudioProcessorEditor(ATKBassPreampAudioProcessor&, juce::AudioProcessorValueTreeState& paramState);
  ~ATKBassPreampAudioProcessorEditor() override;

  //==============================================================================
  void paint(juce::Graphics&) override;
  void resized() override;

private:
  // This reference is provided as a quick way for your editor to
  // access the processor object that created it.
  ATKBassPreampAudioProcessor& processor;
  juce::AudioProcessorValueTreeState& paramState;

  ATK::juce::ImageLookAndFeel knob;
  juce::Image bckgndImage;

  ATK::juce::SliderComponent gain;
  ATK::juce::SliderComponent lowStack;
  ATK::juce::SliderComponent midStack;
  ATK::juce::SliderComponent highStack;
  ATK::juce::SliderComponent volume;
  ATK::juce::SliderComponent drywet;

  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ATKBassPreampAudioProcessorEditor)
};
