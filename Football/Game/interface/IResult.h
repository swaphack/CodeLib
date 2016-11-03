#pragma once

#include "Identity.h"

namespace game
{
	// 比赛结果
	class IResult
	{
	public:
		virtual ~IResult();
	public:
		// 主队分数
		virtual int getHostScore() const = 0;
		// 客队分数
		virtual int getVisiterScore() const = 0;
	};
}