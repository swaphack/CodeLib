#include "Probability.h"
#include <cassert>

math::Probability::Probability()
{
}

math::Probability::Probability(float p)
{
    _value = p;
}

math::Probability::Probability(float m, float n)
{
    assert(m / n);

    _value = m / n;
}

math::Probability::~Probability()
{
}

float math::Probability::getValue() const
{
    return _value;
}

float math::Probability::getInverse() const
{
    return 1.0f - _value;
}
