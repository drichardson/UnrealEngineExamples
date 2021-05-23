# Unreal Engine Audio Example

Demonstrates the UE4 audio system and plugins shipped with the engine including:

- Attenuation
- Audio Volumes (volume in the 3D -not audio level- sense)
- Effects
- Sound Class Mixes
- Sound Classes
- Sound Cues
- Sound Waves
- Submixes

Demonstrates features like listener focus, occlusion, and air absorption, and
how to play audio across level transitions.

When the AudioTest level loads, the level blueprint runs a bunch of audio debug
commands to display info on screen during play. See [Audio Console
Commands](https://docs.unrealengine.com/en-US/WorkingWithMedia/Audio/AudioConsoleCommands/index.html)
for more information.

## Implementation

C:/UnrealEngine/UE_4.26/Engine/Source/Runtime/AudioMixer/Public/AudioMixerBlueprintLibrary.h

### High Level Sound Engine Implementation

Sound assets (e.g. USoundWave, USoundCue, USoundAttenuation) are implemented in
the Engine module here:

Engine/Source/Runtime/Engine/Classes/Sound

### Low Level AudioMixer Engine Implementation

[Audio Mixer](https://docs.unrealengine.com/en-US/WorkingWithMedia/Audio/AudioMixer/index.html)
is the name of the current audio rendering system in UE4. For more details,
watch [Unreal Engine's Audio Rendering: Retrospectives and Case Study Analysis
| GDC2019](https://www.youtube.com/watch?v=QwMAKXBTAC8). The gist is that the
majority of audio processing is implemented in a platform agnostic way so that
mixing in the engine produces similar results regardless of platform.

The platform agnostic parts of Audio Mixer are implemented in the following UE4
engine modules:

- Engine/Source/Runtime/AudioMixer
- Engine/Source/Runtime/AudioMixerCore

You can find platform specific Audio Mixer code by looking for classes that
implement `IAudioMixerPlatformInterface`, or by looking for modules with the
AudioMixer prefix. For example:


- Engine/Source/Runtime/Android/AudioMixerAndroid
- Engine/Source/Runtime/Windows/AudioMixerXAudio2
- Engine/Source/Runtime/Apple/AudioMixerCoreAudio


## Credits

The IR (impulse response) asset created for the ChapelReverbSubmix was made
with the [Tobiasz 'unfa' Karoń's](https://freesound.org/people/unfa/) recording
[IR-02 (gunshot in a chapel MIXED)](https://freesound.org/people/unfa/sounds/182806/).

## See Also

- [XAudio2 Introduction](https://docs.microsoft.com/en-us/windows/win32/xaudio2/xaudio2-introduction)
