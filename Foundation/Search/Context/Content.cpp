#include "system.h"

#include "Content.h"
#include "../String/import.h"
#include "../Target/import.h"


using namespace search;

Content::Content()
{

}

Content::~Content()
{
	this->removeAllTargets();
}

void Content::addTarget(const char* key, Target* target)
{
	std::string* pString = GET_STRING_PTR(key);
	if (_targets.find(pString) != _targets.end()) 
	{

	}
}

void Content::removeTarget(const char* key)
{

}

Target* Content::findTarget(const char* key)
{
	return nullptr;
}

void Content::removeAllTargets()
{
	std::map<std::string*, Target*>::iterator it = _targets.begin();
	for (; it != _targets.end(); it++)
	{
		it->second->dispose();
	}

	_targets.clear();
}
