#pragma once

namespace sys
{
	template<typename T_TARGET, typename T_FUNC>
	struct FuncHandler
	{
		T_TARGET target;
		T_FUNC handler;

		FuncHandler() :target(nullptr), handler(nullptr){}


		void hand(void* params)
		{
			if (!empty())
			{
				(target->*handler)(params);
			}
		}

		bool empty()
		{
			return target == nullptr || handler == nullptr;
		}

		void clean()
		{
			target = nullptr;
			handler = nullptr;
		}
	};
}