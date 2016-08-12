#pragma once

#include "macros.h"

namespace nature
{
	/**
	*	非生物通性
	*/
	class NAbioticProtocol
	{
	public:
		virtual ~NAbioticProtocol() {}
	public:
		// 获取化学结构
		virtual ChemConstitution* getConstitution() = 0;
	private:
	};
}