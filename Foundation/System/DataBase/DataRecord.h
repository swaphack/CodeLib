#include "IDataRecord.h"

#include <map>

namespace sys
{
	// ���ݼ�¼
	class DataRecord : public IDataRecord
	{
	public:
		DataRecord();
		virtual ~DataRecord();
		
		/**
		*	��ȡָ��������ֵ
		*/
		virtual const char* getValue(const char* key);
		/**
		*	���ü�ֵ��
		*/
		virtual void setValue(const char* key, const char* value);
	private:
		// ��ֵ������
		std::map<std::string, std::string> _values;
	};
}