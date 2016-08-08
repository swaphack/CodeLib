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

void search::Content::addTarget(const char* key, Target* target)
{
	std::map<std::string*, Target*>::iterator iter = _targets.find(key);
	if (iter)
	{
		WARING
	}
}

void search::Content::removeTarget(const char* key)
{

}

Target* search::Content::findTarget(const char* key)
{

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
