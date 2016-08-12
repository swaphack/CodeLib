#pragma once

#include "NProperty.h"
#include "NStatus.h"
#include "NMark.h"
#include <string>

namespace nature
{
	class INObject
	{
	public:
		virtual ~INObject() {}
	public:
		// 初始化
		virtual bool init() = 0;
		// 毁灭
		virtual void destory() = 0;
	};

	// 自然对象
	class NObject : public INObject
	{
	public:
		NObject();
		virtual ~NObject();
	public:
		// 初始化
		virtual bool init();
		// 毁灭
		virtual void destory();
	};
}