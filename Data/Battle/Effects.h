#pragma once

#include "Effect.h"
#include <map>
#include <set>

class Property;
class ExtProperty;

// ��Ч����
class Effects : public ITimer
{
public:
	Effects();
	~Effects();
public:
	// ���Ч��
	void AddEffect(const Effect& effect);
	// �Ƴ�Ч��
	void RemoveEffect(const Effect& effect);
	// �Ƴ�����Ч��
	void RemoveAllEffects();
	// �Ƿ�ӵ��ĳ��״̬
	bool HasStatus(Status status);

	// ���û�������
	void SetBaseProperty(Property* pProperty);
	// ��ȡ����ֵ
	float GetPropertyValue(ATTRIBUTE attribute);

	// ��д
	virtual void Update(float dt);
protected:
	// �������Ч��
	void AddAttributeEffect(const Effect* pEffect);
	// �Ƴ�����Ч��
	void RemoveAttributeEffect(const Effect* pEffect);
	// ���״̬Ч��
	void AddStatusEffect(const Effect* pEffect);
	// �Ƴ�״̬Ч��
	void RemoveStatusEffect(const Effect* pEffect);

	// ���Ч������
	void AddEffectAttribute(const Effect* pEffect);
	// �Ƴ�Ч������
	void RemoveEffectAttribute(const Effect* pEffect);
private:
	// ����Ч��
	std::map<int, Effect> m_mapEffect;

	// ��������
	ExtProperty* m_pExtProperty;
	// ��������
	std::map<ATTRIBUTE, std::set<Effect*> > m_mapAttributeEffect;
	// ״̬����
	std::map<Status, std::set<Effect*> > m_mapStatusEffect;
};