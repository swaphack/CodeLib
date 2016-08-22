#pragma once

#include "Element.h"
#include <string>
#include <map>

namespace chem
{
	/**
	*	元素周期表
	*/
	class PeriodicTable
	{
	private:
		PeriodicTable();
		~PeriodicTable();
	public:
		// 获取静态实例
		static PeriodicTable* getInstance();
		// 添加元素
		void addElement(const Element& info);
		// 查找元素
		const Element* getElementByID(int elementID);
		// 查找元素
		const Element* getElementBySymbol(const char* symbol);
	private:
		// 静态实例
		static PeriodicTable* s_pPeriodicTable;
		// 元素信息(id键)
		std::map<int, Element> _elementIDInfos;
		// 元素信息（符号键）
		std::map<std::string, Element> _elementSymbolInfos;
	};
}