#include "WorkData.h"

alg::work::WorkData::WorkData()
{
}

alg::work::WorkData::~WorkData()
{
	if (data != nullptr)
	{
		if(_releaseType == WorkDataType::Object)
		{
			SAFE_RELEASE((sys::Object*)data);
		}
		else if (_releaseType == WorkDataType::Value)
		{
			delete data;
		}
	}
}

void alg::work::WorkData::setData(const std::string& key, void* value)
{
	this->name = key;
	this->data = value;
	_releaseType = WorkDataType::None;
}

void alg::work::WorkData::setObjectData(const std::string& key, sys::Object* value)
{
	if (value != nullptr) SAFE_RETAIN(value);
	this->name = key;
	this->data = value;
	_releaseType = WorkDataType::Object;
}

alg::work::WorkDataType alg::work::WorkData::getDataType() const
{
	return _releaseType;
}
