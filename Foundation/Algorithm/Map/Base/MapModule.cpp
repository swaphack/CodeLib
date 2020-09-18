#include "MapModule.h"
#include "ModuleSlots.h"

alg::MapModule::MapModule()
{
	_slot = new ModuleSlots();
}

alg::MapModule::~MapModule()
{
	delete _slot;
}

alg::ModuleSlots* alg::MapModule::getSlot() const
{
	return _slot;
}

void alg::MapModule::setResourceID(uint32_t resID)
{
	_ressourceID = resID;
}

uint32_t alg::MapModule::getResourceID() const
{
	return _ressourceID;
}
