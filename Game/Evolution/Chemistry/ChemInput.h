#pragma once

#include "macros.h"

namespace nature
{
	// Ͷ�뻯ѧ����
	class ChemInput
	{
	public:
		ChemInput();
		~ChemInput();
	public:
		// ��Ӳ���
		void addMatrial(NObject* pObject, float amount);
	protected:
	private:
	};
}