#include "DBHelper.h"

using namespace db;



void DBHelper::getTypeString(FieldType type, std::string& value)
{
	switch (type)
	{
	case EFT_CHAR:
		value = PROPERTY_TYPE_CHAR_TEXT;
		break;
	case EFT_UCHAR:
		value = PROPERTY_TYPE_UCHAR_TEXT;
		break;
	case EFT_SHORT:
		value = PROPERTY_TYPE_SHORT_TEXT;
		break;
	case EFT_USHORT:
		value = PROPERTY_TYPE_USHORT_TEXT;
		break;
	case EFT_INT:
		value = PROPERTY_TYPE_INT_TEXT;
		break;
	case EFT_UINT:
		value = PROPERTY_TYPE_UINT_TEXT;
		break;
	case EFT_LONG:
		value = PROPERTY_TYPE_LONG_TEXT;
		break;
	case EFT_ULONG:
		value = PROPERTY_TYPE_ULONG_TEXT;
		break;
	case EFT_FLOAT:
		value = PROPERTY_TYPE_FLOAT_TEXT;
		break;
	case EFT_DOUBLE:
		value = PROPERTY_TYPE_DOUBLE_TEXT;
		break;
	case EFT_STRING:
		value = PROPERTY_TYPE_STRING_TEXT;
		break;
	default:
		break;
	}
}

int DBHelper::getTypeSize( FieldType type, int defaultSize )
{
	switch (type)
	{
	case EFT_NONE:
		return 0;
		break;
	case EFT_CHAR:
		return sizeof(char);
		break;
	case EFT_UCHAR:
		return sizeof(uchar);
		break;
	case EFT_SHORT:
		return sizeof(short);
		break;
	case EFT_USHORT:
		return sizeof(ushort);
		break;
	case EFT_INT:
		return sizeof(int);
		break;
	case EFT_UINT:
		return sizeof(uint);
		break;
	case EFT_LONG:
		return sizeof(long);
		break;
	case EFT_ULONG:
		return sizeof(ulong);
		break;
	case EFT_FLOAT:
		return sizeof(float);
		break;
	case EFT_DOUBLE:
		return sizeof(double);
		break;
	case EFT_STRING:
		return defaultSize;
		break;
	default:
		break;
	}

	return 0;
}

void DBHelper::getFieldValue(const char* ptr, FieldType type, long& offset, long length, std::string& value)
{
	switch (type)
	{
	case EFT_CHAR:
		char ct;
		getValueFromPtr<char>(ct, ptr, offset);
		DBHelper::getNumberString(ct, value);
		break;
	case EFT_UCHAR:
		uchar uct;
		getValueFromPtr<uchar>(uct, ptr, offset);
		DBHelper::getNumberString(uct, value);
		break;
	case EFT_SHORT:
		short st;
		getValueFromPtr<short>(st, ptr, offset);
		DBHelper::getNumberString(st, value);
		break;
	case EFT_USHORT:
		ushort ust;
		getValueFromPtr<ushort>(ust, ptr, offset);
		DBHelper::getNumberString(ust, value);
		break;
	case EFT_INT:
		int it;
		getValueFromPtr<int>(it, ptr, offset);
		DBHelper::getNumberString(it, value);
		break;
	case EFT_UINT:
		uint uit;
		getValueFromPtr<uint>(uit, ptr, offset);
		DBHelper::getNumberString((int)uit, value);
		break;
	case EFT_LONG:
		long lt;
		getValueFromPtr<long>(lt, ptr, offset);
		DBHelper::getNumberString(lt, value);
		break;
	case EFT_ULONG:
		ulong ult;
		getValueFromPtr<ulong>(ult, ptr, offset);
		DBHelper::getNumberString(ult, value);
		break;
	case EFT_FLOAT:
		float ft;
		getValueFromPtr<float>(ft, ptr, offset);
		DBHelper::getNumberString(ft, value);
		break;
	case EFT_DOUBLE:
		double dt;
		getValueFromPtr<double>(dt, ptr, offset);
		DBHelper::getNumberString(dt, value);
		break;
	case EFT_STRING:
		value = std::string(ptr + offset, length);
		offset += length;
		break;
	default:
		value = "";
		break;
	}
}

void DBHelper::getNumberString( int number, std::string& value )
{
	char str[255];
	itoa(number, str, 10);
	value = str;
}

void DBHelper::getNumberString(long number, std::string& value)
{
	char str[255];
	ltoa(number, str, 10);
	value = str;
}

void DBHelper::getNumberString(ulong number, std::string& value)
{
	char str[255];
	ultoa(number, str, 10);
	value = str;
}

void DBHelper::getNumberString(double number, std::string& value)
{
	char str[255];
	gcvt(number, 255, str);
	value = str;
}
