/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginEditor.h"
#include "PluginProcessor.h"

//==============================================================================
ATKBassPreampAudioProcessorEditor::ATKBassPreampAudioProcessorEditor(ATKBassPreampAudioProcessor& p,
    juce::AudioProcessorValueTreeState& paramState)
  : AudioProcessorEditor(&p)
  , processor(p)
  , paramState(paramState)
  , knob(juce::ImageFileFormat::loadFrom(BinaryData::KNB_Pitt_L_png, BinaryData::KNB_Pitt_L_pngSize), 55, 55, 101)
  , gain(paramState, "gain", "Gain", &knob)
  , lowStack(paramState, "bass", "Bass", &knob)
  , midStack(paramState, "medium", "Medium", &knob)
  , highStack(paramState, "high", "High", &knob)
  , volume(paramState, "volume", "Volume", &knob)
  , drywet(paramState, "drywet", "Dry/Wet", &knob)

{
  addAndMakeVisible(gain);
  addAndMakeVisible(lowStack);
  addAndMakeVisible(midStack);
  addAndMakeVisible(highStack);
  addAndMakeVisible(volume);
  addAndMakeVisible(drywet);

  bckgndImage = juce::ImageFileFormat::loadFrom(BinaryData::background_jpg, BinaryData::background_jpgSize);

  // Make sure that before the constructor has finished, you've set the
  // editor's size to whatever you need it to be.
  setSize(380, 300);
}

ATKBassPreampAudioProcessorEditor::~ATKBassPreampAudioProcessorEditor() = default;

void ATKBassPreampAudioProcessorEditor::paint(juce::Graphics& g)
{
  g.drawImageAt(bckgndImage, 0, 0);
  g.setFont(juce::Font("Times New Roman", 30.0f, juce::Font::bold | juce::Font::italic));
  g.setColour(juce::Colours::whitesmoke);
  g.drawText("Bass Preamp", 20, 10, 200, 30, juce::Justification::verticallyCentred);
  g.setFont(juce::Font("Times New Roman", 12.0f, juce::Font::bold));
  g.drawText(
      "Gain", 20, 170, 50, 30, juce::Justification::horizontallyCentred | juce::Justification::verticallyCentred);
  g.drawText("Low", 120, 90, 50, 30, juce::Justification::horizontallyCentred | juce::Justification::verticallyCentred);
  g.drawText(
      "Mid", 120, 170, 50, 30, juce::Justification::horizontallyCentred | juce::Justification::verticallyCentred);
  g.drawText(
      "High", 120, 250, 50, 30, juce::Justification::horizontallyCentred | juce::Justification::verticallyCentred);
  g.drawText(
      "Volume", 220, 170, 50, 30, juce::Justification::horizontallyCentred | juce::Justification::verticallyCentred);
  g.drawText(
      "Dry/Wet", 320, 170, 50, 30, juce::Justification::horizontallyCentred | juce::Justification::verticallyCentred);
}

void ATKBassPreampAudioProcessorEditor::resized()
{
  gain.setBounds(20, 120, 55, 55);
  lowStack.setBounds(120, 40, 55, 55);
  midStack.setBounds(120, 120, 55, 55);
  highStack.setBounds(120, 200, 55, 55);
  volume.setBounds(220, 120, 55, 55);
  drywet.setBounds(320, 120, 55, 55);
}
