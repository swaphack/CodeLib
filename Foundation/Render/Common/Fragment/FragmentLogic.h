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
		virtual void update();
	protected:
		virtual void saveData();
		virtual void reloadData();
	private:
		LogicOpCode _opCode = LogicOpCode::COPY;
		LogicOpCode _lastOpCode = LogicOpCode::COPY;
	};
}
