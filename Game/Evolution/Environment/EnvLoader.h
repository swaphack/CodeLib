#pragma once

#include "../Config/import.h"

namespace nature
{
	/**
	* Ԫ�����ڱ����ü���
	*/
	class PeriodicTableLoader : public ConfigLoader
	{
	public:
		PeriodicTableLoader();
		virtual ~PeriodicTableLoader();
	public:
		virtual bool load();
	};

	//////////////////////////////////////////////////////////////////////////
}