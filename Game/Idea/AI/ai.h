#pragma once

#include "Base/import.h"
#include "Analysis/import.h"
#include "Solution/import.h"
#include "Experience/import.h"
#include "Study/import.h"

namespace idea
{
	// 人工智能
	class AI : public IWorker
	{
	public:
		AI();
		virtual ~AI();
	public:
		virtual Result* run(Event* e);
	protected:
	private:
		// 分析问题
		Analysis* _analysis;
		// 解决问题
		Solution* _solution;
		// 总结经验
		Experience* _experience;
		// 学习知识
		Study* _study;
	};
}