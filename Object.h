#pragma once
#include "CoreMinimal.h"

class Object
{
public:

	virtual void Start();
	virtual void Update();
	virtual void Stop();

	template <typename Type>
	Type* Cast(Object* _object)
	{
		return dynamic_cast<Type*>(_object);
	}
};

