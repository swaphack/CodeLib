#pragma once

#include <string>
#include <map>

namespace chem
{
	// Ԫ����Ϣ
	struct ChemElementInfo 
	{
		// ���
		int ID;
		// ����
		std::string Symbol;
		// ����
		std::string Name;
		// ԭ����
		int AtomicNumber;
		// ���ԭ������
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
	*	Ԫ�����ڱ�
	*/
	class ChemPeriodicTable
	{
	private:
		ChemPeriodicTable();
		~ChemPeriodicTable();
	public:
		// ��ȡ��̬ʵ��
		static ChemPeriodicTable* getInstance();
		// ���Ԫ��
		void addElement(const ChemElementInfo& info);
		// ����Ԫ��
		const ChemElementInfo* getElementByID(int elementID);
		// ����Ԫ��
		const ChemElementInfo* getElementBySymbol(const char* symbol);
	private:
		// ��̬ʵ��
		static ChemPeriodicTable* s_pPeriodicTable;
		// Ԫ����Ϣ(id��)
		std::map<int, ChemElementInfo> _elementIDInfos;
		// Ԫ����Ϣ�����ż���
		std::map<std::string, ChemElementInfo> _elementSymbolInfos;
	};
}