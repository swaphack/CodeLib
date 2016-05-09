#pragma once

namespace sys
{
	template<typename T_TARGET, typename T_FUNC>
	struct FuncHandler
	{
		T_TARGET target;
		T_FUNC handler;

		FuncHandler() :target(nullptr), handler(nullptr){}


		void hand(...)
		{
			if (!empty())
			{
				(target->*handler)(...);
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