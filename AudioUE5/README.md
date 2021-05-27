# Audio example for UE5

Demonstration of the Metasound feature added in UE5. Includes:

- Exploration of Metasounds, starting with a A440 generator
- Procedurally generated wind sound
- Setting float parameters from Blueprints
- Invoking triggers from Blueprints
- Changing submix reverb when entering an area (not using Audio Volumes, which
  will be deprecated according to the UE5 release notes)


## Panning Method
Per Aaron McLeran's comments in [Unreal Engine's Audio Rendering:
Retrospectives and Case Study Analysis](https://youtu.be/QwMAKXBTAC8?t=1178),
the panning method was changed from Linear (default setting) to Equal Power via
this setting in Config/DefaultEngine.ini:

```ini
[/Script/Engine.AudioSettings]
PanningMethod=EqualPower
MonoChannelUpmixMethod=EqualPower
```

## Credits

The EchoThief_FortWordenTunnel IR (impulse response) asset was created from the
[EchoThief](http://www.echothief.com/) library.

## See Also

- [New Audio Features](https://docs.unrealengine.com/5.0/en-US/AudioFeatures/)



