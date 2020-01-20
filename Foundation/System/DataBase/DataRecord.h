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
		virtual std::string getValue(const std::string& key);
		/**
		*	���ü�ֵ��
		*/
		virtual void setValue(const std::string& key, const std::string& value);
	private:
		// ��ֵ������
		std::map<std::string, std::string> _values;
	};
}