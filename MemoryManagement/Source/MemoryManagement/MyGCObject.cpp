#include "MyGCObject.h"

#include "MMLog.h"
#include "MyObject.h"

MyGCObject::MyGCObject()
{
	UE_LOG(MMLog, Log, TEXT("MyGCObject::MyGCObject"));
	MyObj = NewObject<UMyObject>();
}

MyGCObject::~MyGCObject()
{
	UE_LOG(MMLog, Log, TEXT("MyGCObject::~MyGCObject"));
}

void MyGCObject::AddReferencedObjects(FReferenceCollector& Collector)
{
	Collector.AddReferencedObject(MyObj);
}

FString MyGCObject::GetReferencerName() const
{
	return "MyGCObject";
}
