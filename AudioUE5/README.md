# Audio example for UE5


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

The IR (impulse response) asset created was created from the [EchoThief](http://www.echothief.com/) library.

## See Also

- [New Audio Features](https://docs.unrealengine.com/5.0/en-US/AudioFeatures/)



