#include "InferenceRule.h"

using namespace math;

InferenceRule::~InferenceRule()
{

}

bool InferenceRule::check(Proposition* a, Proposition* b)
{
	return false;
}


//////////////////////////////////////////////////////////////////////////

bool TautologyRule::check(Proposition* a, Proposition* b)
{
	return a->isTrue() || b->isTrue();
}

//////////////////////////////////////////////////////////////////////////
bool EqualRule::check(Proposition* a, Proposition* b)
{
	return a->isTrue() == b->isTrue();
}
