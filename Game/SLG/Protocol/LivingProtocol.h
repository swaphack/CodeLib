#pragma once

#include <ctime>

namespace slg
{
	// 活着的生物
	class LivingProtocol
	{
	public:
		LivingProtocol();
		virtual ~LivingProtocol();
	public:
		// 出生日期
		time_t getBirthDay();
		// 是否死亡
		bool isDead();
		// 设置死亡状态
		void setDead(bool isDead);
	protected:
		void setBirthDay(time_t tt);
	private:
		// 出生日期时间戳
		time_t _birthday;
		// 是否死亡
		bool _bDead;
	};
}