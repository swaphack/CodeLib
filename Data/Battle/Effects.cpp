#include "Effects.h"
#include "Property.h"
#include "ExtProperty.h"

#include <vector>

Effects::Effects()
{
	m_pExtProperty = new ExtProperty();
}

Effects::~Effects()
{
	delete m_pExtProperty;
}

void Effects::AddEffect(const Effect& effect)
{
	RemoveEffect(effect);

	m_mapEffect[effect.ID] = effect;

	AddAttributeEffect(&effect);
	AddStatusEffect(&effect);
	AddEffectAttribute(&effect);
}

void Effects::RemoveEffect(const Effect& effect)
{
	if (m_mapEffect.find(effect.ID) != m_mapEffect.end())
	{
		RemoveAttributeEffect(&effect);
		RemoveStatusEffect(&effect);
		RemoveEffectAttribute(&effect);

		m_mapEffect.erase(effect.ID);
	}
}

void Effects::RemoveAllEffects()
{
	m_mapEffect.clear();
	m_mapAttributeEffect.clear();
	m_mapStatusEffect.clear();
}

bool Effects::HasStatus(Status status)
{
	if (m_mapStatusEffect.find(status) != m_mapStatusEffect.end())
	{
		return true;
	}

	return false;
}

void Effects::SetBaseProperty(Property* pProperty)
{
	if (pProperty == nullptr)
	{
		return;
	}

	const std::map<int, float>& attribute = pProperty->getAttibutes();
	for (std::map<int, float>::const_iterator cit = attribute.begin();
		cit != attribute.end();
		cit++)
	{
		m_pExtProperty->SetFixValue(cit->first, cit->second);
	}
}

float Effects::GetPropertyValue(ATTRIBUTE attribute)
{
	return m_pExtProperty->GetValue((int)attribute);
}



void Effects::AddAttributeEffect(const Effect* pEffect)
{
	if (pEffect == nullptr)
	{
		return;
	}

	if (pEffect->Status == Status::NONE)
	{
		return;
	}

	if (pEffect->Status != Status::ATTRIBUTE)
	{
		return;
	}

	AttributeEffect* pAttriEffect = static_cast<AttributeEffect*>((Effect*)pEffect);

	std::set<Effect*>* pValue = &m_mapAttributeEffect[pAttriEffect->Attribute];
	pValue->insert((Effect*)pEffect);
}

void Effects::RemoveAttributeEffect(const Effect* pEffect)
{
	if (pEffect == nullptr)
	{
		return;
	}

	if (pEffect->Status == Status::NONE)
	{
		return;
	}

	if (pEffect->Status != Status::ATTRIBUTE)
	{
		return;
	}

	AttributeEffect* pAttriEffect = static_cast<AttributeEffect*>((Effect*)pEffect);

	if (m_mapAttributeEffect.find(pAttriEffect->Attribute) == m_mapAttributeEffect.end())
	{
		return;
	}

	std::set<Effect*>* pValue = &m_mapAttributeEffect[pAttriEffect->Attribute];
	pValue->erase((Effect*)pEffect);
}

void Effects::AddStatusEffect(const Effect* pEffect)
{
	if (pEffect == nullptr)
	{
		return;
	}

	if (pEffect->Status == Status::NONE)
	{
		return;
	}

	if (pEffect->Status == Status::ATTRIBUTE)
	{
		return;
	}

	std::set<Effect*>* pValue = &m_mapStatusEffect[pEffect->Status];
	pValue->insert((Effect*)pEffect);
}

void Effects::RemoveStatusEffect(const Effect* pEffect)
{
	if (pEffect == nullptr)
	{
		return;
	}

	if (pEffect->Status == Status::NONE)
	{
		return;
	}

	if (pEffect->Status == Status::ATTRIBUTE)
	{
		return;
	}

	std::set<Effect*>* pValue = &m_mapStatusEffect[pEffect->Status];
	pValue->erase((Effect*)pEffect);
}

void Effects::AddEffectAttribute(const Effect* pEffect)
{
	if (pEffect == nullptr)
	{
		return;
	}

	if (pEffect->Status == Status::NONE)
	{
		return;
	}

	if (pEffect->Status != Status::ATTRIBUTE)
	{
		return;
	}

	AttributeEffect* pAttriEffect = static_cast<AttributeEffect*>((Effect*)pEffect);

	if (pAttriEffect->Buff)
	{
		m_pExtProperty->AddFixValue((int)pAttriEffect->Attribute, pAttriEffect->Fixed);
		m_pExtProperty->AddPercentValue((int)pAttriEffect->Attribute, pAttriEffect->Percent);
	}
	else
	{
		m_pExtProperty->AddFixValue((int)pAttriEffect->Attribute, -pAttriEffect->Fixed);
		m_pExtProperty->AddPercentValue((int)pAttriEffect->Attribute, -pAttriEffect->Percent);
	}
}

void Effects::RemoveEffectAttribute(const Effect* pEffect)
{
	if (pEffect == nullptr)
	{
		return;
	}

	if (pEffect->Status == Status::NONE)
	{
		return;
	}

	if (pEffect->Status != Status::ATTRIBUTE)
	{
		return;
	}

	AttributeEffect* pAttriEffect = static_cast<AttributeEffect*>((Effect*)pEffect);

	if (!pAttriEffect->Buff)
	{
		m_pExtProperty->AddFixValue((int)pAttriEffect->Attribute, pAttriEffect->Fixed);
		m_pExtProperty->AddPercentValue((int)pAttriEffect->Attribute, pAttriEffect->Percent);
	}
	else
	{
		m_pExtProperty->AddFixValue((int)pAttriEffect->Attribute, -pAttriEffect->Fixed);
		m_pExtProperty->AddPercentValue((int)pAttriEffect->Attribute, -pAttriEffect->Percent);
	}
}

void Effects::Update(float dt)
{
	std::vector<int> vecRemoveEffectID;

	for (std::map<int, Effect>::iterator it = m_mapEffect.begin();
		it != m_mapEffect.end();
		it++)
	{
		it->second.Update(dt);
		if (it->second.Finish())
		{
			vecRemoveEffectID.push_back(it->first);
		}
	}

	for (std::vector<int>::iterator it = vecRemoveEffectID.begin();
		it != vecRemoveEffectID.end();
		it ++)
	{
		this->RemoveEffect(m_mapEffect[*it]);
	}
}