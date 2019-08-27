#
# Built In Audio Example
#

Demonstrates the UE4 audio system and plugins shipped with the engine.

# Audio Occlusion Notes

An actor cannot occlude it's own audio. That is why the BP_AudioSource test spawns a separate
actor to play the audio rather than use a UAudioComponent.

See `FActiveSound::CheckOcclusion` for more information.