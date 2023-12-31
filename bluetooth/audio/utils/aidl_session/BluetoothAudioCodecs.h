/*
 * Copyright (C) 2022 The Android Open Source Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include <aidl/android/hardware/bluetooth/audio/CodecCapabilities.h>
#include <aidl/android/hardware/bluetooth/audio/CodecConfiguration.h>
#include <aidl/android/hardware/bluetooth/audio/LeAudioCodecCapabilitiesSetting.h>
#include <aidl/android/hardware/bluetooth/audio/LeAudioConfiguration.h>
#include <aidl/android/hardware/bluetooth/audio/OpusConfiguration.h>
#include <aidl/android/hardware/bluetooth/audio/PcmCapabilities.h>
#include <aidl/android/hardware/bluetooth/audio/PcmConfiguration.h>
#include <aidl/android/hardware/bluetooth/audio/SessionType.h>

#include <vector>

namespace aidl {
namespace android {
namespace hardware {
namespace bluetooth {
namespace audio {

class BluetoothAudioCodecs {
 public:
  static std::vector<PcmCapabilities> GetSoftwarePcmCapabilities();
  static std::vector<CodecCapabilities> GetA2dpOffloadCodecCapabilities(
      const SessionType& session_type);

  static bool IsSoftwarePcmConfigurationValid(
      const PcmConfiguration& pcm_config);
  static bool IsOffloadCodecConfigurationValid(
      const SessionType& session_type, const CodecConfiguration& codec_config);

  static bool IsOffloadLeAudioConfigurationValid(
      const SessionType& session_type, const LeAudioConfiguration&);

  static std::vector<LeAudioCodecCapabilitiesSetting>
  GetLeAudioOffloadCodecCapabilities(const SessionType& session_type);

 private:
  template <typename T>
  struct identity {
    typedef T type;
  };
  template <class T>
  static bool ContainedInVector(const std::vector<T>& vector,
                                const typename identity<T>::type& target);
  template <class T>
  static bool ContainedInBitmask(const T& bitmask, const T& target);
  static bool IsSingleBit(uint32_t bitmasks, uint32_t bitfield);
  static bool IsOffloadSbcConfigurationValid(
      const CodecConfiguration::CodecSpecific& codec_specific);
  static bool IsOffloadAacConfigurationValid(
      const CodecConfiguration::CodecSpecific& codec_specific);
  static bool IsOffloadLdacConfigurationValid(
      const CodecConfiguration::CodecSpecific& codec_specific);
  static bool IsOffloadAptxConfigurationValid(
      const CodecConfiguration::CodecSpecific& codec_specific);
  static bool IsOffloadAptxHdConfigurationValid(
      const CodecConfiguration::CodecSpecific& codec_specific);
  static bool IsOffloadOpusConfigurationValid(
      const CodecConfiguration::CodecSpecific& codec_specific);
};

}  // namespace audio
}  // namespace bluetooth
}  // namespace hardware
}  // namespace android
}  // namespace aidl
