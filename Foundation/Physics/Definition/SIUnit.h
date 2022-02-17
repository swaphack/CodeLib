#pragma once

#include <string>
#include <map>

namespace phy
{
	// ������
	struct SIQuantity
	{
	public:
		SIQuantity();
		virtual ~SIQuantity();
	public:
		/**
		*	�Ƿ��Ǵ�����
		*/
		static bool isNumber(const std::string& symbol);
		/**
		*	�Ƿ��Ǵ���ĸ
		*/
		static bool isLetter(const std::string& symbol);
		/**
		*	�Ƿ��ǵ���
		*/
		static bool isWord(const std::string& symbol);
	public:
		/* 
		*	����
		*/ 
		const std::string& getName() const;
		/*
		*	����
		*/
		void setName(const std::string& name);
		/*
		*	����
		*/
		const std::string& getSymbol() const;
		/*
		*	����
		*/
		void setSymbol(const std::string& symbol);
		/*
		*	��λ
		*/
		const std::string& getUnit() const;
		/*
		*	��λ
		*/
		void setUnit(const std::string& unit);
	private:
		// ����
		std::string _name;
		// ����
		std::string _symbol;
		// ��λ
		std::string _unit;
	};

	// ����������
	struct SIBaseQuantity : public SIQuantity
	{
	public:
		SIBaseQuantity();
		virtual ~SIBaseQuantity();
	public:
		/**
		*	�Ƿ��ǻ�����λ
		*/
		static bool isBaseUnit(const std::string& symbol);
	};

	/**
	*	����������
	*	����ȷ���������ø���
	*	�����ٶ� m/s ��ʾΪms^(-1)
	*/  
	struct SIDerivedQuantity : public SIQuantity
	{
	public:
		SIDerivedQuantity();
		virtual ~SIDerivedQuantity();
	public:
		/**
		*	���ط���
		*/
		static std::map<std::string, int> loadQuantityFromText(const std::string& unitSymbol);
		/**
		*	תΪ����
		*/
		static std::string saveQuantityToText(const std::map<std::string, int>& units);
	public:
		/**
		*	�ӷ��ż��м���
		*/
		SIDerivedQuantity& loadUnit(const std::string& unitSymbol);
		/**
		*	���
		*/ 
		SIDerivedQuantity& combine(const std::string& sign, int power = 1);
		/**
		*	���
		*/
		SIDerivedQuantity& combine(const SIBaseQuantity& unit, int power = 1);
		/**
		*	���
		*/
		SIDerivedQuantity& combine(const SIDerivedQuantity& unit, int power = 1);
		/*
		*	���
		*/
		void clear();
		/*
		*	��λ����
		*/
		const std::map<std::string, int>& getUnitSymbol() const;
	protected:
		/**
		*	���
		*/
		void combineUnit(const std::string& sign, int power = 1);
		/*
		*	�������
		*/
		void calSign();
	protected:
		// ������λ
		std::map<std::string, int> _unitSymbol;
	};

	
}
