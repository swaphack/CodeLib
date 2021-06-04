#pragma once

#include <string>
#include <map>

namespace phy
{
	// 单位
	struct SIUnit
	{
	public:
		SIUnit();
		virtual ~SIUnit();
	public:
		/* 
		*	名称
		*/ 
		const std::string& getName() const;
		/*
		*	名称
		*/
		void setName(const std::string& name);
		/*
		*	符号
		*/
		const std::string& getSymbol() const;
		/*
		*	符号
		*/
		void setSymbol(const std::string& symbol);
	private:
		// 名称
		std::string _name;

		// 符号
		std::string _symbol;
	};

	// 基本单位
	struct SIBaseUnit : public SIUnit
	{
	public:
		SIBaseUnit();
		virtual ~SIBaseUnit();
	public:
	};

	/**
	*	导出单位
	*	用幂确定，除号用负数
	*	比如速度 m/s 表示为ms^(-1)
	*/  
	struct SIDerivedUnit : public SIUnit
	{
	public:
		SIDerivedUnit();
		virtual ~SIDerivedUnit();
	public:
		/**
		*	组合
		*/ 
		SIDerivedUnit& combine(const std::string& sign, int power = 1);
		/**
		*	组合
		*/
		SIDerivedUnit& combine(const SIBaseUnit& unit, int power = 1);
		/**
		*	组合
		*/
		SIDerivedUnit& combine(const SIDerivedUnit& unit, int power = 1);
		/*
		*	清空
		*/
		void clear();
		/*
		*	单位符号
		*/
		const std::map<std::string, int>& getUnitSymbol() const;
	protected:
		/*
		*	计算符号
		*/
		void calSign();
	protected:
		// 基本单位
		std::map<std::string, int> _unitSymbol;
	};

	
}
