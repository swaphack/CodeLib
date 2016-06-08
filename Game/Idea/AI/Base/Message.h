#pragma once

#include "Result.h"

namespace idea
{
	class Message
	{
	public:
		Message();
		virtual ~Message();
	public:
		Result* getResult();
		void setResult(Result* result);
	public:
		Result* _result;
	};
}