// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "MyPluginObject.h"

#include "MyLog.h"


UMyPluginObject::UMyPluginObject( const FObjectInitializer& ObjectInitializer )
	: Super( ObjectInitializer )
{
	UE_LOG(MyUObjectPlugin, Log, TEXT("UMyPluginObject::UMyPluginObject"));
}

void UMyPluginObject::Foo()
{
	UE_LOG(MyUObjectPlugin, Log, TEXT("UMyPluginObject::Foo"));
}
