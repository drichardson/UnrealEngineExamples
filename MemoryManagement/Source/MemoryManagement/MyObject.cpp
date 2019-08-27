#include "MyObject.h"

#include "MMLog.h"

UMyObject::UMyObject()
{
	UE_LOG(MMLog, Log, TEXT("UMyObject::UMyObject"));

}

UMyObject::~UMyObject()
{
	UE_LOG(MMLog, Log, TEXT("UMyObject::~UMyObject"));
}
