#include "ModuleSlots.h"

alg::ModuleSlots::ModuleSlots()
{

}


alg::ModuleSlots::~ModuleSlots()
{

}

void alg::ModuleSlots::setSlots(const std::map<uint32_t, uint32_t>& slots)
{
	_slots = slots;
}

void alg::ModuleSlots::addSlot(uint32_t side, uint32_t slotIndex)
{
	
	_slots[side] = slotIndex;
}

void alg::ModuleSlots::removeSlot(uint32_t side)
{
	_slots.erase(side);
}

void alg::ModuleSlots::removellAllSlots()
{
	_slots.clear();
}

uint32_t alg::ModuleSlots::getSlot(uint32_t tag) const
{
	auto it = _slots.find(tag);
	if (it == _slots.end())
	{
		return 0;
	}

	return it->second;
}

const std::map<uint32_t, uint32_t>& alg::ModuleSlots::getAllSlots() const
{
	return _slots;
}

bool alg::ModuleSlots::matchSlots(const std::map<uint32_t, uint32_t>& slots) const
{
	if (slots.size() > _slots.size())
	{
		return false;
	}

	for (auto item : slots)
	{
		auto it = _slots.find(item.first);
		if (it == _slots.end() || it->second != item.second)
		{
			return false;
		}
	}

	return true;
}

bool alg::ModuleSlots::matchModuleSlots(const ModuleSlots& slot) const
{
	return matchSlots(slot.getAllSlots());
}

