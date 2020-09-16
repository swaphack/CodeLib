#include "MapSlot.h"

alg::MapSlot::MapSlot()
{

}


alg::MapSlot::~MapSlot()
{

}

void alg::MapSlot::set(const std::map<uint32_t, uint32_t>& slots)
{
	_slots = slots;
}

void alg::MapSlot::set(uint32_t tag, uint32_t slotIndex)
{
	
	_slots[tag] = slotIndex;
}

void alg::MapSlot::remove(uint32_t tag)
{
	_slots.erase(tag);
}

void alg::MapSlot::removellAllSlots()
{
	_slots.clear();
}

uint32_t alg::MapSlot::get(uint32_t tag) const
{
	auto it = _slots.find(tag);
	if (it == _slots.end())
	{
		return 0;
	}

	return it->second;
}

const std::map<uint32_t, uint32_t>& alg::MapSlot::getSlots() const
{
	return _slots;
}

bool alg::MapSlot::match(const std::map<uint32_t, uint32_t>& slots) const
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

bool alg::MapSlot::match(const MapSlot& slot) const
{
	return match(slot.getSlots());
}

