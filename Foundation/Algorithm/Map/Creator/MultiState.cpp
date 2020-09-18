#include "MultiState.h"
#include <cassert>

alg::MultiState::MultiState()
{

}

alg::MultiState::~MultiState()
{

}

void alg::MultiState::add(uint32_t status)
{
	_statusVec.push_back(status);
}

void alg::MultiState::remove(uint32_t status)
{
	auto it = std::find(_statusVec.begin(), _statusVec.end(), status);
	if (it != _statusVec.end())
	{
		_statusVec.erase(it);
	}
}

bool alg::MultiState::has(uint32_t status)
{
	auto it = std::find(_statusVec.begin(), _statusVec.end(), status);
	return it != _statusVec.end();
}

uint32_t alg::MultiState::get(uint32_t index)
{
	assert(index < _statusVec.size());

	return _statusVec[index];
}

uint32_t alg::MultiState::getCount() const
{
	return _statusVec.size();
}

bool alg::MultiState::isEmpty() const
{
	return _statusVec.empty();
}

void alg::MultiState::removeAllStates()
{
	_statusVec.clear();
}

