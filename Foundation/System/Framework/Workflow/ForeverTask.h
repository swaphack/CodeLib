#pragma once

#include "Task.h"

namespace sys
{
	/**
	*	永远执行的任务
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
