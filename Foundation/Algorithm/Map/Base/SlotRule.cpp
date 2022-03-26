#include "SlotRule.h"

alg::map::SlotRule::SlotRule()
{

}

alg::map::SlotRule::SlotRule(int count)
{
	this->init(count);
}

alg::map::SlotRule::~SlotRule()
{
}

void alg::map::SlotRule::init(int count)
{
	_table.init(count, count);
}

void alg::map::SlotRule::addRelation(uint32_t key, const std::vector<uint32_t>& targets, uint8_t value)
{
	;
	for (int i = 0; i < targets.size(); i++)
	{
		_table.setValue(key, targets[i], value);
		_table.setValue(targets[i], key, value);
	}
}

bool alg::map::SlotRule::getRelations(uint32_t key, uint8_t value, std::vector<uint32_t>& relations) const
{
	for (int i = 0; i < _table.getColumn(); i++)
	{
		if (hasRelation(key, i, value))
		{
			relations.push_back(_table.getValue(key, i));
		}
	}
	return relations.size() > 0;
}

bool alg::map::SlotRule::hasRelation(uint32_t src, uint32_t dest, uint8_t value) const
{
	return _table.equal(src, dest, value);
}

void alg::map::SlotRule::resetAllRelations(uint8_t value)
{
	for (int i = 0; i < _table.getRow(); i++)
	{
		for (int j = 0; j < _table.getColumn(); i++)
		{
			_table.setValue(i, j, value);
		}
	}
}
