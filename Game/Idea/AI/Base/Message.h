#pragma once

#include "Result.h"

namespace idea
{
	class Message
	{
	public:
		Message(Result* result);
		~Message();
	public:
		Result* getResult();
	public:
		Result* _result;
	};
}