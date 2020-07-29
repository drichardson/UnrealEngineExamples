# Tags and Gameplay Tags

Demonstrates actor tags (built into the Actor tag array) and [Gameplay
Tags](https://docs.unrealengine.com/en-US/Gameplay/Tags/index.html).

Gameplay tags are used by the Gameplay Ability System.

`UGameplayStatics::GetAllActorsWithTag` and
`UGameplayStatics::GetAllActorsOfClassWithTag` can be used with actor tags.
Note, however, that actor tags are not indexed, so both methods end up
iterating through a set of actors (all actors and all actors of a class,
respectively) and then comparing the search tag with the list of tags
associated with the actor for each actor in the set.

