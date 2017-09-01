#pragma once

#include "Enum.h"
#include "ITimer.h"

// 效果
class Effect : public IIntervalTimer
{
public:
	// 编号
	int ID = 0;
	// 状态
	Status Status = Status::NONE;
	// 时长
	float TotalTime = 0;
};

// 属性效果
class AttributeEffect :public Effect
{
public:
	// 属性类型
	ATTRIBUTE Attribute;
	// 是否增益
	bool Buff;
	// 固定值
	float Fixed;
	// 百分比值
	float Percent;
};