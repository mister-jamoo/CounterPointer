#include "PluginEditor.h"

PluginEditor::PluginEditor (PluginProcessor& p)
    : AudioProcessorEditor (&p), processorRef (p), apvts (p.getParameters())
{
    juce::ignoreUnused (processorRef);

    //    addAndMakeVisible (inspectButton);
    //
    //    // this chunk of code instantiates and opens the melatonin inspector
    //    inspectButton.onClick = [&] {
    //        if (!inspector)
    //        {
    //            inspector = std::make_unique<melatonin::Inspector> (*this);
    //            inspector->onClose = [this]() { inspector.reset(); };
    //        }
    //
    //        inspector->setVisible (true);
    //    };

    apvts.addParameterListener ("currentNote", this);

    noteNameLabel.setText (juce::String ("Hello"), juce::dontSendNotification);

    addAndMakeVisible (noteNameLabel);
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
}

PluginEditor::~PluginEditor()
{
    apvts.removeParameterListener ("currentNote", this);
}

void PluginEditor::parameterChanged (const juce::String& parameterID, float newValue)
{
    if (parameterID == "currentNote")
    {
        juce::MessageManager::callAsync ([this, newValue]() {
            
            noteNameLabel.setText (juce::String(newValue), juce::dontSendNotification);
        });
    }
}

void PluginEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
}

void PluginEditor::resized()
{
    //    inspectButton.setBounds (getLocalBounds().withSizeKeepingCentre(100, 50));
    layout.items.clear();
    layout.items.add (juce::FlexItem (noteNameLabel).withFlex (1.0f));
    layout.alignContent = juce::FlexBox::AlignContent::center;
    layout.performLayout (getLocalBounds());
}
