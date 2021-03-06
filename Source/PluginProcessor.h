/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <ATK/Core/InPointerFilter.h>
#include <ATK/Core/OutPointerFilter.h>
#include <ATK/EQ/ButterworthFilter.h>
#include <ATK/EQ/IIRFilter.h>
#include <ATK/EQ/ToneStackFilter.h>
#include <ATK/Preamplifier/DempwolfTriodeFunction.h>
#include <ATK/Preamplifier/Triode2Filter.h>
#include <ATK/Tools/DecimationFilter.h>
#include <ATK/Tools/DryWetFilter.h>
#include <ATK/Tools/OversamplingFilter.h>
#include <ATK/Tools/VolumeFilter.h>
#include <JuceHeader.h>
#include <JucePluginDefines.h>

//==============================================================================
/**
 */
static const double minVolume = -40;
static const double maxVolume = 40;
static const double minGain = -40;
static const double originGain = -24;
static const double maxGain = 40;

class ATKBassPreampAudioProcessor: public juce::AudioProcessor
{
public:
  //==============================================================================
  ATKBassPreampAudioProcessor();
  ~ATKBassPreampAudioProcessor() override;

  //==============================================================================
  void prepareToPlay(double sampleRate, int samplesPerBlock) override;
  void releaseResources() override;

#ifndef JucePlugin_PreferredChannelConfigurations
  bool isBusesLayoutSupported(const BusesLayout& layouts) const override;
#endif

  void processBlock(juce::AudioSampleBuffer&, juce::MidiBuffer&) override;

  //==============================================================================
  juce::AudioProcessorEditor* createEditor() override;
  bool hasEditor() const override;

  //==============================================================================
  const juce::String getName() const override;

  bool isMidiEffect() const override;
  bool acceptsMidi() const override;
  bool producesMidi() const override;
  double getTailLengthSeconds() const override;

  //==============================================================================
  int getNumPrograms() override;
  int getCurrentProgram() override;
  void setCurrentProgram(int index) override;
  const juce::String getProgramName(int index) override;
  void changeProgramName(int index, const juce::String& newName) override;

  //==============================================================================
  void getStateInformation(juce::MemoryBlock& destData) override;
  void setStateInformation(const void* data, int sizeInBytes) override;

private:
  //==============================================================================
  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ATKBassPreampAudioProcessor)

  ATK::InPointerFilter<float> inFilter;
  ATK::VolumeFilter<double> levelFilter;
  ATK::OversamplingFilter<double, ATK::Oversampling6points5order_4<double>> oversamplingFilter;
  ATK::Triode2Filter<double, ATK::DempwolfTriodeFunction<double>> overdriveFilter;
  ATK::IIRFilter<ATK::ButterworthLowPassCoefficients<double>> lowpassFilter;
  ATK::DecimationFilter<double> decimationFilter;
  ATK::IIRFilter<ATK::ToneStackCoefficients<double>> toneFilter;
  ATK::VolumeFilter<double> volumeFilter;
  ATK::DryWetFilter<double> dryWetFilter;
  ATK::OutPointerFilter<float> outFilter;

  juce::AudioProcessorValueTreeState parameters;

  float old_gain;
  float old_bass;
  float old_medium;
  float old_high;
  float old_volume;
  float old_drywet;
};
