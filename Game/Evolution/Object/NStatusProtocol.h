#pragma once

#include "NObject.h"
#include "NStatus.h"
#include <map>

namespace nature
{
	class NStatusProtocol : public NObject
	{
	public:
		NStatusProtocol();
		~NStatusProtocol();
	public:
		// 获取状态, 如果不存在，则创建
		NStatus* getAndCreateStatus(int nStatusID);
		// 移除状态
		virtual void removeStatus(int nStatusID);
		// 移除所有状态
		virtual void removeAllStatus();
	protected:
		// 状态改变时触发事件
		virtual void onStatusChanged(NStatus* pStatus);
		// 状态改变时处理，需重写
		virtual void onStatusChangedHandler(NStatus* pStatus);
	protected:
		// 状态字典
		std::map<int, NStatus*> _statusDict;
	};
}