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
			*	��ȡ��������
			*/
			static WorkDataMap* getSharedData();
		};
	}
}