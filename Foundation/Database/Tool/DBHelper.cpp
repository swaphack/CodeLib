#include "DBHelper.h"

#include "system.h"
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
		sys::BitConvert::getNumberString(ct, value);
		break;
	case EFT_UCHAR:
		uchar uct;
		getValueFromPtr<uchar>(uct, ptr, offset);
		sys::BitConvert::getNumberString(uct, value);
		break;
	case EFT_SHORT:
		short st;
		getValueFromPtr<short>(st, ptr, offset);
		sys::BitConvert::getNumberString(st, value);
		break;
	case EFT_USHORT:
		ushort ust;
		getValueFromPtr<ushort>(ust, ptr, offset);
		sys::BitConvert::getNumberString(ust, value);
		break;
	case EFT_INT:
		int it;
		getValueFromPtr<int>(it, ptr, offset);
		sys::BitConvert::getNumberString(it, value);
		break;
	case EFT_UINT:
		uint uit;
		getValueFromPtr<uint>(uit, ptr, offset);
		sys::BitConvert::getNumberString((int)uit, value);
		break;
	case EFT_LONG:
		long lt;
		getValueFromPtr<long>(lt, ptr, offset);
		sys::BitConvert::getNumberString(lt, value);
		break;
	case EFT_ULONG:
		ulong ult;
		getValueFromPtr<ulong>(ult, ptr, offset);
		sys::BitConvert::getNumberString(ult, value);
		break;
	case EFT_FLOAT:
		float ft;
		getValueFromPtr<float>(ft, ptr, offset);
		sys::BitConvert::getNumberString(ft, value);
		break;
	case EFT_DOUBLE:
		double dt;
		getValueFromPtr<double>(dt, ptr, offset);
		sys::BitConvert::getNumberString(dt, value);
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