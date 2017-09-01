#pragma once

#include <map>

// 属性
class Property
{
public:
	Property();
	~Property();
public:
	// 获取值
	float GetValue(int key);
	// 设置值
	void SetValue(int key, float value);
	// 添加值
	void AddValue(int key, float value);
	// 清空所有值
	void Clear();

	inline const std::map<int, float>& getAttibutes() { return m_mapAttr; }
private:
	std::map<int, float> m_mapAttr;
};
