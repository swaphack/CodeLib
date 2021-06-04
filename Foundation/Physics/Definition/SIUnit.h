#pragma once

#include <string>
#include <map>

namespace phy
{
	// ��λ
	struct SIUnit
	{
	public:
		SIUnit();
		virtual ~SIUnit();
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
	private:
		// ����
		std::string _name;

		// ����
		std::string _symbol;
	};

	// ������λ
	struct SIBaseUnit : public SIUnit
	{
	public:
		SIBaseUnit();
		virtual ~SIBaseUnit();
	public:
	};

	/**
	*	������λ
	*	����ȷ���������ø���
	*	�����ٶ� m/s ��ʾΪms^(-1)
	*/  
	struct SIDerivedUnit : public SIUnit
	{
	public:
		SIDerivedUnit();
		virtual ~SIDerivedUnit();
	public:
		/**
		*	���
		*/ 
		SIDerivedUnit& combine(const std::string& sign, int power = 1);
		/**
		*	���
		*/
		SIDerivedUnit& combine(const SIBaseUnit& unit, int power = 1);
		/**
		*	���
		*/
		SIDerivedUnit& combine(const SIDerivedUnit& unit, int power = 1);
		/*
		*	���
		*/
		void clear();
		/*
		*	��λ����
		*/
		const std::map<std::string, int>& getUnitSymbol() const;
	protected:
		/*
		*	�������
		*/
		void calSign();
	protected:
		// ������λ
		std::map<std::string, int> _unitSymbol;
	};

	
}
