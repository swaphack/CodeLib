#include "Statistic.h"

using namespace search;


void Statistic::addSearchCount(const std::string& key, int count )
{
	keySearchCounts[key] = keySearchCounts[key] + count;
}

void Statistic::setSearchCount(const std::string& key, int count )
{
	keySearchCounts[key] = count;
}
