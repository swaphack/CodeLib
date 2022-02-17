#pragma once

#include <string>
#include <map>

namespace phy
{
	// 物理量
	struct SIQuantity
	{
	public:
		SIQuantity();
		virtual ~SIQuantity();
	public:
		/**
		*	是否是纯数字
		*/
		static bool isNumber(const std::string& symbol);
		/**
		*	是否是纯字母
		*/
		static bool isLetter(const std::string& symbol);
		/**
		*	是否是单词
		*/
		static bool isWord(const std::string& symbol);
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
		/*
		*	单位
		*/
		const std::string& getUnit() const;
		/*
		*	单位
		*/
		void setUnit(const std::string& unit);
	private:
		// 名称
		std::string _name;
		// 符号
		std::string _symbol;
		// 单位
		std::string _unit;
	};

	// 基本物理量
	struct SIBaseQuantity : public SIQuantity
	{
	public:
		SIBaseQuantity();
		virtual ~SIBaseQuantity();
	public:
		/**
		*	是否是基本单位
		*/
		static bool isBaseUnit(const std::string& symbol);
	};

	/**
	*	导出物理量
	*	用幂确定，除号用负数
	*	比如速度 m/s 表示为ms^(-1)
	*/  
	struct SIDerivedQuantity : public SIQuantity
	{
	public:
		SIDerivedQuantity();
		virtual ~SIDerivedQuantity();
	public:
		/**
		*	加载符号
		*/
		static std::map<std::string, int> loadQuantityFromText(const std::string& unitSymbol);
		/**
		*	转为符号
		*/
		static std::string saveQuantityToText(const std::map<std::string, int>& units);
	public:
		/**
		*	从符号集中加载
		*/
		SIDerivedQuantity& loadUnit(const std::string& unitSymbol);
		/**
		*	组合
		*/ 
		SIDerivedQuantity& combine(const std::string& sign, int power = 1);
		/**
		*	组合
		*/
		SIDerivedQuantity& combine(const SIBaseQuantity& unit, int power = 1);
		/**
		*	组合
		*/
		SIDerivedQuantity& combine(const SIDerivedQuantity& unit, int power = 1);
		/*
		*	清空
		*/
		void clear();
		/*
		*	单位符号
		*/
		const std::map<std::string, int>& getUnitSymbol() const;
	protected:
		/**
		*	组合
		*/
		void combineUnit(const std::string& sign, int power = 1);
		/*
		*	计算符号
		*/
		void calSign();
	protected:
		// 基本单位
		std::map<std::string, int> _unitSymbol;
	};

	
}
