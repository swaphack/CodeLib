#pragma once

#include "Enum.h"
#include "ITimer.h"

// Ч��
class Effect : public IIntervalTimer
{
public:
	// ���
	int ID = 0;
	// ״̬
	Status Status = Status::NONE;
	// ʱ��
	float TotalTime = 0;
};

// ����Ч��
class AttributeEffect :public Effect
{
public:
	// ��������
	ATTRIBUTE Attribute;
	// �Ƿ�����
	bool Buff;
	// �̶�ֵ
	float Fixed;
	// �ٷֱ�ֵ
	float Percent;
};