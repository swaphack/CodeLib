#pragma once

#include "Step.h"
#include <vector>

namespace idea
{
	// 方法
	class Method : public IWorker
	{
	public:
		Method();
		virtual ~Method();
	public:
		// 添加步骤
		void addStep(Step* step);
		// 移除步骤
		void removeStep(Step* step);
		// 移除所有步骤
		void removeAllSteps();
		// 使用步骤尝试解决问题
		virtual Result* run(Event* e);
	private:
		// 步骤集
		std::vector<Step*> _steps;
	};
}