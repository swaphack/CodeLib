#pragma once

#include "NObject.h"
#include "NProperty.h"
#include <map>

namespace nature
{
	class NPropertyProtocol : public NObject
	{
	public:
		NPropertyProtocol();
		~NPropertyProtocol();
	public:
		// 获取属性, 如果不存在，则创建
		NProperty* getAndCreateProperty(int nPropertyID);
		// 移除属性
		virtual void removeProperty(int nPropertyID);
		// 移除所有属性
		virtual void removeAllProperties();
	protected:
		// 属性改变时触发事件
		virtual void onPropertyChanged(NProperty* pProperty);

		// 属性改变时处理,需重写
		virtual void onPropertyChangedHandler(NProperty* pProperty);
	protected:
		// 属性字典
		std::map<int, NProperty*> _propertyDict;
	};
}