#include "Module.h"
#include "Slots.h"

alg::map::Module::Module()
{
	_slot = new Slots();
}

alg::map::Module::~Module()
{
	delete _slot;
}

alg::map::Slots* alg::map::Module::getModuleSlot() const
{
	return _slot;
}

void alg::map::Module::setResourceID(uint32_t resID)
{
	_ressourceID = resID;
}

uint32_t alg::map::Module::getResourceID() const
{
	return _ressourceID;
}
