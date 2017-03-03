#include "SearchProxy.h"
#include <set>

using namespace search;

#define ADD_SEARCH_STATISTIC(str) sys::Instance<Statistic>::getInstance()->addSearchCount(str);

SearchProxy::SearchProxy()
{

}


SearchProxy::~SearchProxy()
{

}

std::set<Target*> SearchProxy::getTargets( const char* word )
{
	std::set<Target*> targets;
	if (word == nullptr)
	{
		return targets;
	}

	TextParser* parser = new TextParser(word);

	const std::set<std::string>& keys = parser->getKeys();

	for (std::set<std::string>::iterator it = keys.begin();
		it != keys.end();
		it++)
	{
		ADD_SEARCH_STATISTIC((*it));

// 		std::set<Target*>* temp = sys::Instance<Content>::getInstance()->getTargetsByKey((*it).c_str());
// 		if (temp)
// 		{
// 			targets.insert(temp->begin(), temp->end());
// 		}
		
	}

	delete parser;

	return targets;
}