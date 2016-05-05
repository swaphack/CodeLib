#include "Finance.h"

using namespace tribe;

Finace::Finace()
:_money(0)
{

}

Finace::~Finace()
{

}

void Finace::add(float money)
{
	_money += money;
}