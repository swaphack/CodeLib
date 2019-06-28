#pragma once

#include "Creator.h"
#include "../country/Country.h"

namespace game
{
	class CountrySheet : public Creator<Country>
	{
	public:
		CountrySheet();
		virtual ~CountrySheet();
	protected:
	private:
	};
}