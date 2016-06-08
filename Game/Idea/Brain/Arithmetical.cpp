#include "Arithmetical.h"
#include <cstring>
using namespace idea;

namespace
{
	static const char* Signal_1 = { "+" };
	static const char* Signal_2 = { "-" };
	static const char* Signal_3 = { "*" };
	static const char* Signal_4 = { "/" };
	static const char* Signal_5 = { "&&" };
	static const char* Signal_6 = { "||" };
	static const char* Signal_7 = { "!" };
	static const char* Signal_8 = { "^" };
	static const char* Signal_9 = { "<<" };
	static const char* Signal_10 = { ">>" };
	static const char* Signal_11 = { ">" };
	static const char* Signal_12 = { ">=" };
	static const char* Signal_13 = { "<" };
	static const char* Signal_14 = { "<=" };
	static const char* Signal_15 = { "==" };
	static const char* Signal_16 = { "|" };
	static const char* Signal_17 = { "&" };
}

ALU::ALU()
{

}

ALU::~ALU()
{

}

ResultNumber* ALU::eval(const char* text) const
{
	if (text == nullptr)
	{
		return nullptr;
	}

	strstr()

}
//////////////////////////////////////////////////////////////////////////
Arithmetical::Arithmetical()
{

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

	Message* message = e->getMessage();

	ResultString* result = dynamic_cast<ResultString*>(message->getResult());
	if (result == nullptr)
	{
		return nullptr;
	}

	ResultNumber* value = getALU()->eval(result->getValue());
	if (value == nullptr)
	{
		return nullptr;
	}

	return value;
}

const ALU* Arithmetical::getALU()
{
	return &_alu;
}
