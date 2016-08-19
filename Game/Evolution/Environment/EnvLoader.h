#pragma once

#include "../Config/import.h"

namespace nature
{
	/**
	* 元素周期表配置加载
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