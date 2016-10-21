#include "Draw.h"

using namespace lottery;

Jackpot::Jackpot()
{

}

Jackpot::~Jackpot()
{
	this->clear();
}

const ItemDetail* Jackpot::pick(int nIndex)
{
	std::map<int, ItemDetail>::const_iterator iter = m_dictReward.find(nIndex);
	if (iter != m_dictReward.end())
	{
		return &iter->second;
	}

	return NULL;
}

void Jackpot::addReward(int nIndex, int nItemID, int nItemCount)
{
	ItemDetail detail;
	detail.ItemID = nItemID;
	detail.ItemCount = nItemCount;
	m_dictReward[nIndex] = detail;
}

void Jackpot::removeReward(int nIndex)
{
	m_dictReward.erase(nIndex);
}

void Jackpot::clear()
{
	m_dictReward.clear();
}


//////////////////////////////////////////////////////////////////////////


Probablity::Probablity()
{

}

Probablity::~Probablity()
{
	this->clear();
}

int Probablity::pick(float fProbablity)
{
	if (m_bDirty)
	{
		m_bDirty = false;

		float value = 0;

		m_vecDestProbablity.clear();

		std::map<int, float>::const_iterator iter = m_mapSrcProbablity.begin();
		while (iter != m_mapSrcProbablity.end())
		{
			value += iter->second;

			ProbablityDetail detail;
			detail.Index = iter->first;
			detail.Value = value;

			m_vecDestProbablity.push_back(detail);

			iter++;
		}
	}

	int count = m_vecDestProbablity.size();

	for (int i = 0; i < count; i++)
	{
		if (fProbablity < m_vecDestProbablity[i].Value)
		{
			return m_vecDestProbablity[i].Index;
		}
	}

	return -1;
}

void Probablity::addIndex(int nIndex, float fProbablity)
{
	m_bDirty = true;

	m_mapSrcProbablity[nIndex] = fProbablity;
}

void Probablity::removeIndex(int nIndex)
{
	m_bDirty = true;

	m_mapSrcProbablity.erase(nIndex);
}

void Probablity::clear()
{
	m_mapSrcProbablity.clear();
	m_vecDestProbablity.clear();
}


//////////////////////////////////////////////////////////////////////////

Draw::Draw()
:m_pJackpot(nullptr)
, m_pProbablity(nullptr)
, m_nIndex(0)
{

}

Draw::~Draw()
{
	if (m_pJackpot)
	{
		delete m_pJackpot;
	}

	if (m_pProbablity)
	{
		delete m_pProbablity;
	}
}

void Draw::setJackpot(IJackpot* pJackpot)
{
	if (pJackpot == nullptr)
	{
		return;
	}
	if (m_pJackpot)
	{
		delete m_pJackpot;
	}

	m_pJackpot = pJackpot;
}

IJackpot* Draw::getJackpot()
{
	return m_pJackpot;
}

void Draw::setProbablity(IProbablity* pPropbablity)
{
	if (pPropbablity == nullptr)
	{
		return;
	}
	if (m_pProbablity)
	{
		delete m_pProbablity;
	}

	m_pProbablity = pPropbablity;
}

IProbablity* Draw::getProbablity()
{
	return m_pProbablity;
}

const ItemDetail* Draw::pick(float fProbablity)
{
	if (m_pProbablity == nullptr || m_pJackpot == nullptr)
	{
		return nullptr;
	}

	int nIndex = -1;

	if (fProbablity >= 0)
	{
		nIndex = m_pProbablity->pick(fProbablity);
	}

	if (nIndex != -1)
	{
		return m_pJackpot->pick(nIndex);
	}

	return NULL;
}

void Draw::addReward(float fProbablity, int nItemID, int nItemCount)
{
	if (m_pProbablity == nullptr || m_pJackpot == nullptr)
	{
		return;
	}

	m_nIndex++;

	m_pProbablity->addIndex(m_nIndex, fProbablity);

	m_pJackpot->addReward(m_nIndex, nItemID, nItemCount);
}

void Draw::clear()
{
	if (m_pProbablity)
	{
		m_pProbablity->clear();
	}

	if (m_pJackpot)
	{
		m_pJackpot->clear();
	}

	m_nIndex = 0;
}
