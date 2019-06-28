#pragma once

#include "../league/League.h"
#include "Creator.h"

namespace game
{
	class LeagueSheet : public Creator<League>
	{
	public:
		LeagueSheet();
		virtual ~LeagueSheet();
	protected:
	private:
	};
}