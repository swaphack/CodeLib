#include "CombineSlots.h"

alg::map::CombineSlots::CombineSlots()
{
}

alg::map::CombineSlots::~CombineSlots()
{
}

void alg::map::CombineSlots::addSlot(uint32_t side, uint32_t slotIndex)
{
	_slots[side].insert(slotIndex);
}

void alg::map::CombineSlots::addSlots(uint32_t side, const std::vector<uint32_t>& slotIndices)
{
	_slots[side].insert(slotIndices.begin(), slotIndices.end());
}

void alg::map::CombineSlots::removeSlot(uint32_t side)
{
	_slots.erase(side);
}

void alg::map::CombineSlots::removeSlot(uint32_t side, uint32_t slotIndex)
{
	_slots[side].erase(slotIndex);
	if (_slots[side].empty())
	{
		_slots.erase(side);
	}
}

void alg::map::CombineSlots::removellAllSlots()
{
	_slots.clear();
}

const std::set<uint32_t>* alg::map::CombineSlots::getSlots(uint32_t side) const
{
	auto it = _slots.find(side);
	if (it == _slots.end())
	{
		return nullptr;
	}
	return &(it->second);
}

const std::map<uint32_t, std::set<uint32_t>>& alg::map::CombineSlots::getAllSlots() const
{
	return _slots;
}

bool alg::map::CombineSlots::empty() const
{
	return _slots.empty();
}
