#pragma once

#include "../Object/import.h"

namespace nature
{
	typedef	void (NObject::*OutputCallback)(NObject* pObject);

	class NTimer
	{
	public:
		virtual ~NTimer() {}
		virtual void update(float dt) = 0;
	};
}