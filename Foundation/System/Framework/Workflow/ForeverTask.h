#pragma once

#include "Task.h"

namespace sys
{
	/**
	*	��Զִ�е�����
	*/
	class ForeverTask : public Task
	{
	public:
		ForeverTask();
		virtual ~ForeverTask();
	public:
		virtual bool isOver() const override;
	};
}
