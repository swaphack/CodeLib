#include "Arithmetical.h"

using namespace idea;

Arithmetical::Arithmetical()
{

}

Arithmetical::~Arithmetical()
{

}

Result* Arithmetical::run(Event* e)
{
	if (e == nullptr)
	{
		return nullptr;
	}

	e->getMessage()
}
