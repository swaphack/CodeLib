#include "BitConvert.h"

using namespace sys;


BitConvert::BitConvert()
{

}

BitConvert::~BitConvert()
{

}

void BitConvert::getNumberString(int32 number, std::string& value)
{
	char str[255];
	itoa(number, str, 10);
	value = str;
}

void BitConvert::getNumberString(long number, std::string& value)
{
	char str[255];
	ltoa(number, str, 10);
	value = str;
}

void BitConvert::getNumberString(ulong number, std::string& value)
{
	char str[255];
	ultoa(number, str, 10);
	value = str;
}

void BitConvert::getNumberString(double number, std::string& value)
{
	char str[255];
	gcvt(number, 255, str);
	value = str;
}

