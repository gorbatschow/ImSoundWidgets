#pragma once
#include "SoundSetupWidgets.h"
#include <RtSoundClient.h>
#include <RtSoundIO.h>
#include <imw.h>
#include <memory>
#include <string>
#include <vector>

class SoundControlWidget : public RtSoundClient {
public:
  SoundControlWidget(std::weak_ptr<RtSoundIO> soundIO_);

  void paint();

private:
  std::weak_ptr<RtSoundIO> _soundIO;

public:
  struct Ui {
    Ui(std::weak_ptr<RtSoundIO> soundIO) : streamStatusLine{soundIO} {
      inputChannelsSpin.setValueLimitsA({1, 99});
      inputChannelsSpin.setValueLimitsB({0, 99});
      outputChannelsSpin.setValueLimitsA({1, 99});
      outputChannelsSpin.setValueLimitsB({0, 99});

      restartEngineBtn.setSameLine(true);
      stopStreamBtn.setSameLine(true);
      shotStreamBtn.setSameLine(true);
      streamStatusLine.setSameLine(true);
      realtimeCheck.setSameLine(true);
      minLatencyCheck.setSameLine(true);
      exclusiveCheck.setSameLine(true);
      numBuffersSpin.setWidth(100.0f);
      numBuffersSpin.setValueLimits({1, 9});
    }

    Imw::Button restartEngineBtn{"Restart"};
    Imw::Button startStreamBtn{"Start"};
    Imw::Button stopStreamBtn{"Stop"};
    Imw::Button shotStreamBtn{"Shot"};
    Imw::SpinBoxAB<int> inputChannelsSpin{"Num. Inputs / First Input"};
    Imw::SpinBoxAB<int> outputChannelsSpin{"Num. Outputs / First Output"};
    Imw::CheckBox realtimeCheck{"Realtime"};
    Imw::CheckBox minLatencyCheck{"Min. Latency"};
    Imw::CheckBox exclusiveCheck{"Exclusive"};
    Imw::SpinBox<int> numBuffersSpin{"Num. Buffers"};

    AudioApiCombo audioApiCombo;
    SampleRateCombo sampleRateCombo;
    BufferSizeInput bufferFramesInput;

    std::shared_ptr<SoundDeviceCombo> inputDeviceCombo{
        new SoundDeviceCombo(SoundDeviceCombo::InputOnly)};
    std::shared_ptr<SoundDeviceCombo> outputDeviceCombo{
        new SoundDeviceCombo(SoundDeviceCombo::OutputOnly)};

    StreamStatusLine streamStatusLine;
  };
  Ui ui{_soundIO};

  virtual void configureStream(RtSoundSetup &) override;
};