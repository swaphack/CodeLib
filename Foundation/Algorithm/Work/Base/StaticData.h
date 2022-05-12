#pragma once

namespace alg
{
	namespace work
	{
		class WorkDataMap;

		class StaticData
		{
		public:
			/**
			*	获取共享数据
			*/
			static WorkDataMap* getSharedData();
		};
	}
}