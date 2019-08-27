# Camera
Camera related experiments.

For each ULocalPlayer, [UGameViewportClient::Draw](https://api.unrealengine.com/INT/API/Runtime/Engine/Engine/UGameViewportClient/Draw/index.html) calls [ULocalPlayer::CalcSceneView](https://api.unrealengine.com/INT/API/Runtime/Engine/Engine/ULocalPlayer/CalcSceneView/index.html) which calls `ULocalPlayer::GetViewPoint` which calls `APlayerController::GetPlayerViewPoint` and `APlayerCameraManager::GetFOVAngle`.


`APlayerController::GetPlayerViewPoint` uses `APlayerController::GetViewTarget`, which in turn calls `APlayerCameraManager::GetViewTarget` to determine the camera position and orientation.

See also:

* [Camera Component](https://api.unrealengine.com/INT/API/Runtime/Engine/Camera/UCameraComponent/index.html)
* [Camera Animation](https://docs.unrealengine.com/en-US/Gameplay/Framework/Camera/Animations/index.html)
* [Camera Shake](https://www.youtube.com/watch?v=1nMKHwsXSCc)
* [Player Camera Manager](https://api.unrealengine.com/INT/API/Runtime/Engine/Camera/APlayerCameraManager/index.html)
  * Configured via [APlayerController::PlayerCameraManagerClass](https://api.unrealengine.com/INT/API/Runtime/Engine/GameFramework/APlayerController/PlayerCameraManagerClass/index.html)
* [Camera Modifier](https://api.unrealengine.com/INT/API/Runtime/Engine/Camera/UCameraModifier/index.html)
* [Post Process Component](https://api.unrealengine.com/INT/API/Runtime/Engine/Components/UPostProcessComponent/index.html)
* [Post Process Volumes](https://api.unrealengine.com/INT/API/Runtime/Engine/Engine/APostProcessVolume/index.html)
* [Post Process Settings](https://api.unrealengine.com/INT/API/Runtime/Engine/Engine/FPostProcessSettings/index.html)
* [ULocalPlayer::GetViewPoint](https://api.unrealengine.com/INT/API/Runtime/Engine/Engine/ULocalPlayer/GetViewPoint/index.html) - Calls [APlayerController::GetPlayerViewPoint](https://api.unrealengine.com/INT/API/Runtime/Engine/GameFramework/APlayerController/GetPlayerViewPoint/index.html) 

