#pragma once

#include "Element.h"
#include <string>
#include <map>

namespace chem
{
	/**
	*	Ԫ�����ڱ�
	*/
	class PeriodicTable
	{
	private:
		PeriodicTable();
		~PeriodicTable();
	public:
		// ��ȡ��̬ʵ��
		static PeriodicTable* getInstance();
		// ���Ԫ��
		void addElement(const Element& info);
		// ����Ԫ��
		const Element* getElementByID(int elementID);
		// ����Ԫ��
		const Element* getElementBySymbol(const char* symbol);
	private:
		// ��̬ʵ��
		static PeriodicTable* s_pPeriodicTable;
		// Ԫ����Ϣ(id��)
		std::map<int, Element> _elementIDInfos;
		// Ԫ����Ϣ�����ż���
		std::map<std::string, Element> _elementSymbolInfos;
	};
}