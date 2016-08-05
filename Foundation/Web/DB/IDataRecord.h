#pragma once

namespace web
{
	class IDataRecord
	{
	public:
		virtual ~IDataRecord() {}
	public:
		// ����ֵ
		virtual const char* getValue(const char* key) = 0;
		// ���ֵ
		virtual void setValue(const char* key, const char* value) = 0;
	};
}