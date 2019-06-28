#pragma once

#include "../club/Club.h"
#include "Creator.h"

namespace game
{
	class ClubSheet : public Creator<Club>
	{
	public:
		ClubSheet();
		virtual ~ClubSheet();
	protected:
	private:
	};
}