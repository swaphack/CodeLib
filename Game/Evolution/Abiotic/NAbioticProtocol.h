#pragma once

#include "macros.h"

namespace nature
{
	/**
	*	������ͨ��
	*/
	class NAbioticProtocol
	{
	public:
		virtual ~NAbioticProtocol() {}
	public:
		// ��ȡ��ѧ�ṹ
		virtual ChemConstitution* getConstitution() = 0;
	private:
	};
}