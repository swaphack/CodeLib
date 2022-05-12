#include "StaticData.h"
#include "WorkDataMap.h"

alg::work::WorkDataMap _sharedData;

alg::work::WorkDataMap* alg::work::StaticData::getSharedData()
{
	return &_sharedData;
}
