#pragma once

#include "system.h"
#include "Context/import.h"
#include "String/import.h"
#include "Parser/import.h"
#include "Target/import.h"
#include "Statistic/import.h"

#include <string>
#include <set>

namespace search
{
	// ËÑË÷´úÀí
	class SearchProxy
	{
	public:
		SearchProxy();
		~SearchProxy();
	public:
		std::set<Target*> getTargets(const char* word);
	protected:
	private:
	};
}