#pragma once

#include <map>

// ���ж������Ե�ֵ
class ExtProperty
{
public:
	ExtProperty();
	~ExtProperty();
public:
	// ��ӹ̶�ֵ
	void AddFixValue(int key, float value);
	// ��Ӱٷֱ�ֵ
	void AddPercentValue(int key, float value);
	// ���ù̶�����ֵ
	void SetFixValue(int key, float value);
	// ���ðٷֱ�����ֵ
	void SetPercentValue(int key, float value);
	// ��ȡ�̶�����ֵ
	float GetFixValue(int key);
	// ��ȡ�ٷֱ�����ֵ
	float GetPercentValue(int key);
	// ��ȡ��ֵ
	float GetValue(int key);
	// ���
	void Clear();
private:
	// �̶�����ֵ
	std::map<int, float> m_mapFixAttr;
	// �ٷֱ�����ֵ
	std::map<int, float> m_mapPercentAttr;
};