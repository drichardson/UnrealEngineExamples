# Memory Management
This project is a test to see how UE4 memory management works with
UPROPERTY pointers, naked pointers, and TWeakObjectPtr.

The test uses two actors in a level. One of the actors creates it's own components
and the second actor refers to the first actors components.

The first actor is then deleted so the effects on the second actor can be observed.

## Running the Test

1. Play in Editor
2. Delete the *DeleteMe* object in the World Outliner
3. Press stop.
4. Look at the Output Log.


### Result

1. Naked pointers are not nulled out, but IsValidLowLevel returns false.
2. UPROPERTY marked pointers and TWeakObjectPtr are nulled out.

## Suggestions

If you hold onto an object you are not the owner of then either store it in a TWeakObjectPtr
or UPROPERTY marked pointer and do a null check before access.

If you own the object - it was created with CreateDefaultSubobject in the constructor or
NewObject(this) somehwere else in your code, then naked pointers are fine (since you know
when they will become invalid).

## More Information

* [Objects](https://docs.unrealengine.com/en-us/Programming/UnrealArchitecture/Objects)
* [Unreal Object Handling](https://docs.unrealengine.com/en-US/Programming/UnrealArchitecture/Objects/Optimizations)
* [Smart Pointer Library](https://docs.unrealengine.com/en-us/Programming/UnrealArchitecture/SmartPointerLibrary)

