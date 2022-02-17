#pragma once

#include <string>
#include <map>
#include <vector>

namespace phy
{
	struct SIBaseQuantity;
	struct SIDerivedQuantity;

	/**
	*	物理量
	*/
	class PhyQuantity
	{
	public:
		PhyQuantity();
		virtual ~PhyQuantity();
	public:
		static PhyQuantity* getInstance();
	public:
		/**
		*	添加基本单位
		*/
		bool addBaseUnit(const std::string& strName, const std::string& strSymbol, const std::string& strUnit);
		/**
		*	获取基本单位
		*/
		const SIBaseQuantity* getBaseUnit(const std::string& strName) const;
	public:
		/**
		*	添加导出单位
		*/
		bool addDerivedUnit(const std::string& strName, const std::string& strSymbol, const std::string& strUnit);
		/**
		*	获取导出单位
		*/
		const SIDerivedQuantity* getDerivedUnit(const std::string& strName) const;
	public:
		/**
		*	根据符号推导出相关导出单位
		*/
		bool deduceUnit(const std::string& strSymbol, std::vector<SIDerivedQuantity*>& vecDerivedUnits);
	protected:
		/**
		*	初始化
		*/
		void init();
		/**
		*	清空
		*/
		void cleanup();
	private:
		static PhyQuantity* _instance;
		// 基本单位
		std::map<std::string, SIBaseQuantity*> _baseUnits;
		// 导出单位
		std::map<std::string, SIDerivedQuantity*> _derivedUnits;
	};
}