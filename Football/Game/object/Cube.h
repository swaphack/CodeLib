#pragma once

#include "Object.h"

namespace game
{
	/**
	*	������
	*/
	class Cube : public Object
	{
	public:
		Cube();
		virtual ~Cube();
	public:
		CREATE_COMPONENT_TYPE();
		CREATE_COMPONENT_CLONE(Cube);
	protected:
	private:
	};
}