#pragma once

namespace db
{
	// 属性类型
#define PROPERTY_TYPE_CHAR_TEXT "char"
#define PROPERTY_TYPE_UCHAR_TEXT "uint8"
#define PROPERTY_TYPE_SHORT_TEXT "int16"
#define PROPERTY_TYPE_USHORT_TEXT "uint16"
#define PROPERTY_TYPE_INT_TEXT "int"
#define PROPERTY_TYPE_UINT_TEXT "uint32"
#define PROPERTY_TYPE_LONG_TEXT "long"
#define PROPERTY_TYPE_ULONG_TEXT "ulong"
#define PROPERTY_TYPE_FLOAT_TEXT "float"
#define PROPERTY_TYPE_DOUBLE_TEXT "double"
#define PROPERTY_TYPE_STRING_TEXT "char"

	// 字段类型
	enum FieldType
	{
		EFT_NONE,
		EFT_CHAR,
		EFT_UCHAR,
		EFT_SHORT,
		EFT_USHORT,
		EFT_INT,
		EFT_UINT,
		EFT_LONG,
		EFT_ULONG,
		EFT_FLOAT,
		EFT_DOUBLE,
		EFT_STRING,
	};
}