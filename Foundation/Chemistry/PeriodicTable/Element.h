#pragma once

#include <string>
#include <map>

namespace chem
{
	// Ԫ����Ϣ
	struct Element
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

		Element()
		{
			ID = 0;
			Symbol = "";
			Name = "";
			AtomicNumber = 0;
			RelativeAtomicMass = 0;
		}
	};
}