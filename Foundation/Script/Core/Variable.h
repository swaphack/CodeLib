#pragma once

#include "Base.h"
#include "Function.h"

#include <string>
#include <vector>
#include <map>

namespace script
{
	// ��������
	enum DataType
	{
		// ������
		E_DATATYPE_NONE,
		// ʵ��
		E_DATATYPE_REAL,
		// �ַ���
		E_DATATYPE_TEXT,
		// ��
		E_DATATYPE_NULL,
		// ���ݽṹ
		E_DATATYPE_STRUCT,
	};

	// ����
	class Variable : public Base
	{
	public:
		Variable();
		virtual ~Variable();
	public:
		// ��ȡ��������
		int getDataType();
		// ������������
		void setDataType(int nDataType);

		// ��Ӻ���,�����Ƴ�
		void addFunction(Function* pFunction);
		// �Ƴ�����
		void removeFunction(const char* name);
		// �Ƴ����к���
		void removeAllFunctions();
		// ��ȡ����
		Function* getFunction(const char* name);
		// ����
		virtual bool callFunction(const char* pFuncName, std::vector<Variable*> inputs, std::vector<Variable*>& outputs);
		// ����
		virtual void disponse();
	public: // ����
		// ��¡,�̳�
		Variable* clone();
		// �����µ��ڴ棬Ϊ������ֵ
		Variable* alloct(const char* name);
	protected:
		typedef std::map<std::string, Function*> Functions;

		// ��������
		int m_nDataType;
		// ��Ա����
		Functions m_pFunctions;
	};
}