#pragma once

#include <map>

// ����
class Property
{
public:
	Property();
	~Property();
public:
	// ��ȡֵ
	float GetValue(int key);
	// ����ֵ
	void SetValue(int key, float value);
	// ���ֵ
	void AddValue(int key, float value);
	// �������ֵ
	void Clear();

	inline const std::map<int, float>& getAttibutes() { return m_mapAttr; }
private:
	std::map<int, float> m_mapAttr;
};
