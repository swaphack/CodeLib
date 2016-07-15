#pragma once

#include "macros.h"

namespace ui
{
	// ui界面接口
	class IUIFace
	{
	public:
		IUIFace();
		virtual ~IUIFace();
	public:
		// 加载xml配置
		void load(tinyxml2::XMLElement* pXmlNode);

		// 添加一条新的属性
		void addAttribute(const char* name);
		// 移除一条已有属性
		void removeAttribute(const char* name);
		// 修改属性值
		void setAttribute(const char* name, const char* value);
	protected:
	private:
	};
}