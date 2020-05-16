#pragma once

#include "FragmentTestOp.h"
#include "Graphic/GLAPI/macros.h"

namespace render
{
	class FragmentLogicOp : public FragmentTestOp
	{
	public:
		FragmentLogicOp();
		virtual ~FragmentLogicOp();
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
