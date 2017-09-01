#pragma once

#include "Effect.h"
#include <map>
#include <set>

class Property;
class ExtProperty;

// 特效集合
class Effects : public ITimer
{
public:
	Effects();
	~Effects();
public:
	// 添加效果
	void AddEffect(const Effect& effect);
	// 移除效果
	void RemoveEffect(const Effect& effect);
	// 移除所有效果
	void RemoveAllEffects();
	// 是否拥有某种状态
	bool HasStatus(Status status);

	// 设置基础属性
	void SetBaseProperty(Property* pProperty);
	// 获取属性值
	float GetPropertyValue(ATTRIBUTE attribute);

	// 重写
	virtual void Update(float dt);
protected:
	// 添加属性效果
	void AddAttributeEffect(const Effect* pEffect);
	// 移除属性效果
	void RemoveAttributeEffect(const Effect* pEffect);
	// 添加状态效果
	void AddStatusEffect(const Effect* pEffect);
	// 移除状态效果
	void RemoveStatusEffect(const Effect* pEffect);

	// 添加效果属性
	void AddEffectAttribute(const Effect* pEffect);
	// 移除效果属性
	void RemoveEffectAttribute(const Effect* pEffect);
private:
	// 所有效果
	std::map<int, Effect> m_mapEffect;

	// 额外属性
	ExtProperty* m_pExtProperty;
	// 属性特性
	std::map<ATTRIBUTE, std::set<Effect*> > m_mapAttributeEffect;
	// 状态特性
	std::map<Status, std::set<Effect*> > m_mapStatusEffect;
};