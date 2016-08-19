#pragma once

#include <string>
#include <map>

namespace chem
{
	// 元素信息
	struct ChemElementInfo 
	{
		// 编号
		int ID;
		// 符号
		std::string Symbol;
		// 名称
		std::string Name;
		// 原子数
		int AtomicNumber;
		// 相对原子质量
		float RelativeAtomicMass;

		ChemElementInfo()
		{
			ID = 0;
			Symbol = "";
			Name = "";
			AtomicNumber = 0;
			RelativeAtomicMass = 0;
		}
	};
	/**
	*	元素周期表
	*/
	class ChemPeriodicTable
	{
	private:
		ChemPeriodicTable();
		~ChemPeriodicTable();
	public:
		// 获取静态实例
		static ChemPeriodicTable* getInstance();
		// 添加元素
		void addElement(const ChemElementInfo& info);
		// 查找元素
		const ChemElementInfo* getElementByID(int elementID);
		// 查找元素
		const ChemElementInfo* getElementBySymbol(const char* symbol);
	private:
		// 静态实例
		static ChemPeriodicTable* s_pPeriodicTable;
		// 元素信息(id键)
		std::map<int, ChemElementInfo> _elementIDInfos;
		// 元素信息（符号键）
		std::map<std::string, ChemElementInfo> _elementSymbolInfos;
	};
}