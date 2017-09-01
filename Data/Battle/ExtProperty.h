#pragma once

#include <map>

// 带有额外属性的值
class ExtProperty
{
public:
	ExtProperty();
	~ExtProperty();
public:
	// 添加固定值
	void AddFixValue(int key, float value);
	// 添加百分比值
	void AddPercentValue(int key, float value);
	// 设置固定属性值
	void SetFixValue(int key, float value);
	// 设置百分比属性值
	void SetPercentValue(int key, float value);
	// 获取固定属性值
	float GetFixValue(int key);
	// 获取百分比属性值
	float GetPercentValue(int key);
	// 获取总值
	float GetValue(int key);
	// 清空
	void Clear();
private:
	// 固定属性值
	std::map<int, float> m_mapFixAttr;
	// 百分比属性值
	std::map<int, float> m_mapPercentAttr;
};