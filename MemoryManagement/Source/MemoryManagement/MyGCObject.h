#pragma once

#include "CoreMinimal.h"
#include "GCObject.h"

class MyGCObject : public FGCObject
{
public:
	MyGCObject();
	~MyGCObject();

private:

	class UMyObject* MyObj;

	void AddReferencedObjects(FReferenceCollector& Collector) override;
	FString GetReferencerName() const override;
};
