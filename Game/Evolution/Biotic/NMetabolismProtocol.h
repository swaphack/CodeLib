#pragma once

#include "macros.h"

namespace nature
{

	// 新陈代谢
	class NMetabolismProtocol
	{
	public:
		virtual ~NMetabolismProtocol() {}
	public:
		// 同化, 需重写
		virtual bool input(NObject* pObject) = 0;
		// 注册异化回调
		virtual void setOutputHandler(NObject* pTarget, OutputCallback callback) {}
	};
}