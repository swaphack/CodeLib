#include "WorkDataMap.h"

void alg::work::WorkDataMap::setData(const std::string& name, void* data)
{
	_data[name] = WorkData();
	_data[name].setData(name, data);
}

void alg::work::WorkDataMap::setObjectData(const std::string& name, sys::Object* data)
{
	_data[name] = WorkData();
	_data[name].setObjectData(name, data);
}



void* alg::work::WorkDataMap::getData(const std::string& name) const
{
	auto pWorkData = getWorkData(name);
	if (pWorkData == nullptr) return nullptr;
	return pWorkData->data;
}

sys::Object* alg::work::WorkDataMap::getObjectData(const std::string& name) const
{
	auto pWorkData = getWorkData(name);
	if (pWorkData == nullptr) return nullptr;
	if (pWorkData->getDataType() != WorkDataType::Object) return nullptr;
	return (sys::Object*)pWorkData->data;
}

void alg::work::WorkDataMap::removeData(const std::string& name)
{
	_data.erase(name);
}

void alg::work::WorkDataMap::clear()
{
	_data.clear();
}

const alg::work::WorkData* alg::work::WorkDataMap::getWorkData(const std::string& name) const
{
	auto it = _data.find(name);
	if (it == _data.end())
		return nullptr;
	return &it->second;
}
