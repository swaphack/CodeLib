#pragma once

#include <string>
#include <map>
#include <vector>

namespace phy
{
	struct SIBaseQuantity;
	struct SIDerivedQuantity;

	/**
	*	������
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
		*	��ӻ�����λ
		*/
		bool addBaseUnit(const std::string& strName, const std::string& strSymbol, const std::string& strUnit);
		/**
		*	��ȡ������λ
		*/
		const SIBaseQuantity* getBaseUnit(const std::string& strName) const;
	public:
		/**
		*	��ӵ�����λ
		*/
		bool addDerivedUnit(const std::string& strName, const std::string& strSymbol, const std::string& strUnit);
		/**
		*	��ȡ������λ
		*/
		const SIDerivedQuantity* getDerivedUnit(const std::string& strName) const;
	public:
		/**
		*	���ݷ����Ƶ�����ص�����λ
		*/
		bool deduceUnit(const std::string& strSymbol, std::vector<SIDerivedQuantity*>& vecDerivedUnits);
	protected:
		/**
		*	��ʼ��
		*/
		void init();
		/**
		*	���
		*/
		void cleanup();
	private:
		static PhyQuantity* _instance;
		// ������λ
		std::map<std::string, SIBaseQuantity*> _baseUnits;
		// ������λ
		std::map<std::string, SIDerivedQuantity*> _derivedUnits;
	};
}