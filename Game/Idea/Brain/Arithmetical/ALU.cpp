#include "ALU.h"

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

Result* ALU::eval(const char* text) const
{
	if (text == nullptr)
	{
		return nullptr;
	}


}