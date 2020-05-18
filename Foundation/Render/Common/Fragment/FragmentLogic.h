#pragma once

#include "FragmentHandle.h"
#include "Graphic/GLAPI/macros.h"

namespace render
{
	class FragmentLogic : public FragmentHandle
	{
	public:
		FragmentLogic();
		virtual ~FragmentLogic();
	public:
		void setOpCode(LogicOpCode code);
	public:
		virtual void begin();
		virtual void update();
		virtual void end();
	private:
		LogicOpCode _opCode = LogicOpCode::COPY;
	};
}
