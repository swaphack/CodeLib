#include "MapModule.h"
#include "MapSlot.h"

alg::MapModule::MapModule()
{
	_slot = new MapSlot();
}

alg::MapModule::~MapModule()
{
	delete _slot;
}

alg::MapSlot* alg::MapModule::getSlot() const
{
	return _slot;
}
