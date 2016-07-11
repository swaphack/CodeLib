#include "Arithmetical.h"
#include <cstring>
using namespace idea;

Arithmetical::Arithmetical()
{
	_alu = new ALU();
}

Arithmetical::~Arithmetical()
{

}

Result* Arithmetical::run(Event* e)
{
	if (e == nullptr || e->getMessage() == nullptr)
	{
		return nullptr;
	}

	Result* message = e->getMessage();

	ResultString* result = dynamic_cast<ResultString*>(message);
	if (result == nullptr)
	{
		return nullptr;
	}

	Result* value = _alu->eval(result->getValue());
	if (value == nullptr)
	{
		return nullptr;
	}

	return value;
}