#ifndef SETTINGS_CONVERTERS_H
#define SETTINGS_CONVERTERS_H

#include "gaggia_settings.h"
#include "nanopb_cpp.h"
#include "settings.pb.h"

using namespace NanoPb::Converter;

/**
 * The below classes are converters that map our own classes to/from protobuf objects.
 * The protobuf objects are autogenerated at build time  based on the *.proto definition files
 * (see settings.proto and profile.proto).
 */

class BoilerSettingsConverter : public NanoPb::Converter::MessageConverter<BoilerSettingsConverter, BoilerSettings, BoilerSettingsDto, BoilerSettingsDto_fields> {
public:
  static ProtoType encoderInit(const LocalType& local) {
    return BoilerSettingsDto{
      .steamSetPoint = local.steamSetPoint,
      .offsetTemp = local.offsetTemp,
      .hpwr = local.hpwr,
      .mainDivider = local.mainDivider,
      .brewDivider = local.brewDivider,
    };
  };

  static ProtoType decoderInit(LocalType& local) {
    return BoilerSettingsDto{};
  };

  static bool decoderApply(const ProtoType& proto, LocalType& local) {
    local.steamSetPoint = proto.steamSetPoint;
    local.offsetTemp = proto.offsetTemp;
    local.hpwr = proto.hpwr;
    local.mainDivider = proto.mainDivider;
    local.brewDivider = proto.brewDivider;
    return true;
  };
};

class LedSettingsConverter : public NanoPb::Converter::MessageConverter<LedSettingsConverter, LedSettings, LedSettingsDto, LedSettingsDto_fields> {
public:
  static ProtoType encoderInit(const LocalType& local) {
    return LedSettingsDto{
      .state = local.state,
      .has_color = true,
      .color = LedSettingsDto_Color {
        .R = local.color.R,
        .G = local.color.G,
        .B = local.color.B,
      },
    };
  };

  static ProtoType decoderInit(LocalType& local) {
    return LedSettingsDto{};
  };

  static bool decoderApply(const ProtoType& proto, LocalType& local) {
    local.state = proto.state;
    local.color.R = proto.color.R;
    local.color.G = proto.color.G;
    local.color.B = proto.color.B;
    return true;
  };
};

class SystemSettingsConverter : public NanoPb::Converter::MessageConverter<SystemSettingsConverter, SystemSettings, SystemSettingsDto, SystemSettingsDto_fields> {
public:
  static ProtoType encoderInit(const LocalType& local) {
    return SystemSettingsDto{
      .powerLineFrequency = local.powerLineFrequency,
      .pumpFlowAtZero = local.pumpFlowAtZero,
      .scalesF1 = local.scalesF1,
      .scalesF2 = local.scalesF2,
      .lcdSleep = local.lcdSleep,
      .warmupState = local.warmupState,
    };
  };

  static ProtoType decoderInit(LocalType& local) {
    return SystemSettingsDto{};
  };

  static bool decoderApply(const ProtoType& proto, LocalType& local) {
    local.powerLineFrequency = proto.powerLineFrequency;
    local.pumpFlowAtZero = proto.pumpFlowAtZero;
    local.scalesF1 = proto.scalesF1;
    local.scalesF2 = proto.scalesF2;
    local.warmupState = proto.warmupState;
    local.lcdSleep = proto.lcdSleep;
    return true;
  };
};

class BrewSettingsConverter : public NanoPb::Converter::MessageConverter<BrewSettingsConverter, BrewSettings, BrewSettingsDto, BrewSettingsDto_fields> {
public:
  static ProtoType encoderInit(const LocalType& local) {
    return BrewSettingsDto{
      .homeOnShotFinish = local.homeOnShotFinish,
      .brewDeltaState = local.brewDeltaState,
      .basketPrefill = local.basketPrefill,
    };
  };

  static ProtoType decoderInit(LocalType& local) {
    return BrewSettingsDto{};
  };

  static bool decoderApply(const ProtoType& proto, LocalType& local) {
    local.homeOnShotFinish = proto.homeOnShotFinish;
    local.brewDeltaState = proto.brewDeltaState;
    local.basketPrefill = proto.basketPrefill;

    return true;
  };
};

class GaggiaSettingsConverter : public NanoPb::Converter::MessageConverter<GaggiaSettingsConverter, GaggiaSettings, GaggiaSettingsDto, GaggiaSettingsDto_fields> {
public:
  static ProtoType encoderInit(const LocalType& local) {
    return GaggiaSettingsDto{
      .has_boiler = true,
      .boiler = BoilerSettingsConverter::encoderInit(local.boiler),
      .has_system = true,
      .system = SystemSettingsConverter::encoderInit(local.system),
      .has_brew = true,
      .brew = BrewSettingsConverter::encoderInit(local.brew),
      .has_led = true,
      .led = LedSettingsConverter::encoderInit(local.led),
    };
  };

  static ProtoType decoderInit(LocalType& local) {
    return GaggiaSettingsDto{
      .boiler = BoilerSettingsConverter::decoderInit(local.boiler),
      .system = SystemSettingsConverter::decoderInit(local.system),
      .brew = BrewSettingsConverter::decoderInit(local.brew),
      .led = LedSettingsConverter::decoderInit(local.led),
    };
  };

  static bool decoderApply(const ProtoType& proto, LocalType& local) {
    BoilerSettingsConverter::decoderApply(proto.boiler, local.boiler);
    SystemSettingsConverter::decoderApply(proto.system, local.system);
    BrewSettingsConverter::decoderApply(proto.brew, local.brew);
    LedSettingsConverter::decoderApply(proto.led, local.led);
    return true;
  };
};

#endif
