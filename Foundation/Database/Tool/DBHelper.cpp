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
		return sizeof(int8_t);
		break;
	case EFT_UCHAR:
		return sizeof(uint8_t);
		break;
	case EFT_SHORT:
		return sizeof(int16_t);
		break;
	case EFT_USHORT:
		return sizeof(uint16_t);
		break;
	case EFT_INT:
		return sizeof(int32_t);
		break;
	case EFT_UINT:
		return sizeof(uint32_t);
		break;
	case EFT_LONG:
		return sizeof(long);
		break;
	case EFT_ULONG:
		return sizeof(uint64_t);
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
		uint8_t uct;
		getValueFromPtr<uint8_t>(uct, ptr, offset);
		sys::BitConvert::getNumberString(uct, value);
		break;
	case EFT_SHORT:
		int16_t st;
		getValueFromPtr<int16_t>(st, ptr, offset);
		sys::BitConvert::getNumberString(st, value);
		break;
	case EFT_USHORT:
		uint16_t ust;
		getValueFromPtr<uint16_t>(ust, ptr, offset);
		sys::BitConvert::getNumberString(ust, value);
		break;
	case EFT_INT:
		int it;
		getValueFromPtr<int>(it, ptr, offset);
		sys::BitConvert::getNumberString(it, value);
		break;
	case EFT_UINT:
		uint32_t uit;
		getValueFromPtr<uint32_t>(uit, ptr, offset);
		sys::BitConvert::getNumberString((int)uit, value);
		break;
	case EFT_LONG:
		long lt;
		getValueFromPtr<long>(lt, ptr, offset);
		sys::BitConvert::getNumberString(lt, value);
		break;
	case EFT_ULONG:
		uint64_t ult;
		getValueFromPtr<uint64_t>(ult, ptr, offset);
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