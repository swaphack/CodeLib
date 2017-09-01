#pragma once

class Property;

// 数值计算
class NumCalculation
{
public:
	// 攻击
	static float Attack(Property* src, Property* dest);
	// 攻击间隔
	static float AtkInterval(Property* src);
};


