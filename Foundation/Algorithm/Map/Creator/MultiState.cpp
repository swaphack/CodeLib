#include "MultiState.h"
#include <cassert>

alg::map::MultiState::MultiState()
{

}

alg::map::MultiState::~MultiState()
{

}

void alg::map::MultiState::set(const std::vector<uint32_t>& states)
{
	_states = states;
}

void alg::map::MultiState::add(uint32_t state)
{
	_states.push_back(state);
}

void alg::map::MultiState::remove(uint32_t state)
{
	auto it = std::find(_states.begin(), _states.end(), state);
	if (it != _states.end())
	{
		_states.erase(it);
	}
}

bool alg::map::MultiState::has(uint32_t state)
{
	auto it = std::find(_states.begin(), _states.end(), state);
	return it != _states.end();
}

uint32_t alg::map::MultiState::get(uint32_t index)
{
	assert(index < _states.size());

	return _states[index];
}

uint32_t alg::map::MultiState::getCount() const
{
	return _states.size();
}

bool alg::map::MultiState::isEmpty() const
{
	return _states.empty();
}

void alg::map::MultiState::removeAllStates()
{
	_states.clear();
}

const std::vector<uint32_t>& alg::map::MultiState::getAllStates() const
{
	return _states;
}

