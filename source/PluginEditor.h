#pragma once

#include "BinaryData.h"
#include "PluginProcessor.h"
#include "melatonin_inspector/melatonin_inspector.h"

//==============================================================================
class PluginEditor : public juce::AudioProcessorEditor, public juce::AudioProcessorValueTreeState::Listener
{
public:
    explicit PluginEditor (PluginProcessor&);
    ~PluginEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    void parameterChanged (const juce::String& parameterID, float newValue) override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    PluginProcessor& processorRef;
    juce::AudioProcessorValueTreeState& apvts;
    
    juce::Label noteNameLabel;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> noteNameAttachment;
   
    juce::FlexBox layout;

    //    std::unique_ptr<melatonin::Inspector> inspector;
    //    juce::TextButton inspectButton { "Inspect the UI" };
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginEditor)
};
