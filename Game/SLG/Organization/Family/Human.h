#pragma once

#include "../macros.h"
#include "Family.h"

namespace slg
{
	// 性别
	enum SexType
	{
		// 男
		EST_MALE,
		// 女
		EST_FEMALE,
	};

	// 人类
	class Human : public Target, public LivingProtocol
	{
	public:
		Human();
		virtual ~Human();
	public:
		// 获取性别
		SexType getSexType();
		// 设置性别
		void setSexType(SexType sexType);
		// 获取家庭
		const Family* getFamily();
	private:
		// 性别
		SexType _sexType;
		// 家庭
		Family* _family;
	};
}