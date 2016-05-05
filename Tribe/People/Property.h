#pragma once

#include <map>

namespace tribe
{
	// 属性
	class Property
	{
	public:
		Property();
		virtual ~Property();
	public:
		// 添加新属性
		void addProperty(int propType, int val = 0);
		// 移除旧属性
		void removeProperty(int propType);
		// 获取属性值
		int getValue(int propType);
	protected:
	private:
		// 属性集 {属性类型，属性值}
		std::map<int, int> _propValues;
	};
}