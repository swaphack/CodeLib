#include "Slots.h"

alg::map::Slots::Slots()
{

}


alg::map::Slots::~Slots()
{

}

void alg::map::Slots::setSlots(const std::map<uint32_t, uint32_t>& slots)
{
	_slots = slots;
}

void alg::map::Slots::addSlot(uint32_t side, uint32_t slotIndex)
{
	
	_slots[side] = slotIndex;
}

void alg::map::Slots::removeSlot(uint32_t side)
{
	_slots.erase(side);
}

void alg::map::Slots::removellAllSlots()
{
	_slots.clear();
}

uint32_t alg::map::Slots::getSlot(uint32_t tag) const
{
	auto it = _slots.find(tag);
	if (it == _slots.end())
	{
		return 0;
	}

	return it->second;
}

const std::map<uint32_t, uint32_t>& alg::map::Slots::getAllSlots() const
{
	return _slots;
}

bool alg::map::Slots::matchSlots(const std::map<uint32_t, uint32_t>& slots) const
{
	if (slots.size() > _slots.size())
	{
		return false;
	}

	for (const auto& item : slots)
	{
		auto it = _slots.find(item.first);
		if (it == _slots.end() || it->second != item.second)
		{
			return false;
		}
	}

	return true;
}

bool alg::map::Slots::matchSlots(const std::map<uint32_t, std::set<uint32_t>>& slots) const
{
	if (slots.size() > _slots.size())
	{
		return false;
	}

	for (const auto& item : slots)
	{
		auto it = _slots.find(item.first);
		if (it == _slots.end())
		{
			return false;
		}

		if (item.second.find(it->second) == item.second.end())
		{
			return false;
		}
	}

	return true;
}

bool alg::map::Slots::matchModuleSlots(const Slots& slot) const
{
	return matchSlots(slot.getAllSlots());
}

