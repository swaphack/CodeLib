#include "FragmentQuery.h"
#include "Graphic/import.h"

render::FragmentQuery::FragmentQuery(FragmentType type)
	:FragmentHandle(type)
{
	this->initQuery();
}

render::FragmentQuery::~FragmentQuery()
{
	this->releaseQuery();
}

uint32_t render::FragmentQuery::getQueryID()const
{
	return _queryID;
}

bool render::FragmentQuery::isValid() const
{
	return GLQuery::isQuery(_queryID);
}

void render::FragmentQuery::getResult(QueryParameter name, uint32_t* params)
{
	GLQuery::getQueryObject(_queryID, name, params);
}

void render::FragmentQuery::getResult(QueryParameter name, int32_t* params)
{
	GLQuery::getQueryObject(_queryID, name, params);
}

void render::FragmentQuery::update()
{
	int count = 1000;
	int queryReady = 0;
	int samples = 0;
	do
	{
		this->getResult(QueryParameter::QUERY_RESULT_AVAILABLE, &queryReady);
	} while (!queryReady && count--);

	if (queryReady)
	{
		this->getResult(QueryParameter::QUERY_RESULT, &samples);
		PRINT("Samples rendered : %d\n", samples);
	}
	else
	{
		samples = 1;
	}
}

void render::FragmentQuery::initQuery()
{
	_queryID = GLQuery::genQuery();
}

void render::FragmentQuery::releaseQuery()
{
	GLQuery::deleteQuery(_queryID);
	_queryID = 0;
}

/////////////////////////////////////////////////////////////
render::FragmentOcclusionQuery::FragmentOcclusionQuery()
	:FragmentQuery(FragmentType::OCCLUSION_QUERY)
{
}

render::FragmentOcclusionQuery::~FragmentOcclusionQuery()
{

}

void render::FragmentOcclusionQuery::setTarget(QueryTarget target)
{
	_queryTarget = target;
}

QueryTarget render::FragmentOcclusionQuery::getTarget()
{
	return _queryTarget;
}

void render::FragmentOcclusionQuery::begin()
{
	GLQuery::beginQuery(_queryTarget, getQueryID());
}

void render::FragmentOcclusionQuery::end()
{
	GLQuery::endQuery(_queryTarget);
}
/////////////////////////////////////////////////////////////

render::FragmentConditionRender::FragmentConditionRender()
	:FragmentQuery(FragmentType::CONDITION_RENDER)
{
}

render::FragmentConditionRender::~FragmentConditionRender()
{
}

void render::FragmentConditionRender::setMode(QueryMode mode)
{
	_queryMode = mode;
}

QueryMode render::FragmentConditionRender::getMode()
{
	return _queryMode;
}

void render::FragmentConditionRender::begin()
{
	GLQuery::beginConditionalRender(getQueryID(), _queryMode);
}

void render::FragmentConditionRender::end()
{
	GLQuery::endConditionalRender();
}
