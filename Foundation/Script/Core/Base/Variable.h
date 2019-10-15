#pragma once

#include "Base.h"

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
		// ����
		E_DATATYPE_VARIABLE,
		// ʵ��
		E_DATATYPE_REAL,
		// �ַ���
		E_DATATYPE_TEXT,
		// ��
		E_DATATYPE_NULL,
		// ���ݽṹ
		E_DATATYPE_STRUCT,
	};

	class IVariable
	{
	public:
		virtual int getDataType() = 0;
		// �ж��Ƿ����
		virtual bool equal(const IVariable& var) = 0;
	};

	class Function;

	// ����
	class Variable : public Base, public IVariable
	{
	public:
		Variable();
		virtual ~Variable();
	public:
		// ��Ӻ���,�����Ƴ�
		void addFunction(Function* pFunction);
		// �Ƴ�����
		void removeFunction(const std::string& name);
		// �Ƴ����к���
		void removeAllFunctions();
		// ��ȡ����
		Function* getFunction(const std::string& name);
		// ���ú���
		virtual bool callFunction(const std::string& pFuncName, std::vector<Variable*>& inputs, std::vector<Variable*>& outputs);
		// ����
		virtual void dispose();
	public: // ��д
		// ��ȡ��������
		virtual int getDataType();
		// �ж��Ƿ����
		virtual bool equal(const IVariable& var);
	public: // ����
		// ��¡
		Variable* clone();
		// �����µ��ڴ棬Ϊ������ֵ
		Variable* alloct(const char* name);
	protected: 
		// ������������
		void setDataType(int nDataType);
		// ��ʼ��Ĭ�Ϻ���
		virtual void initFunctions();
	protected:
		typedef std::map<std::string, Function*> Functions;

		// ��������
		int m_nDataType;
		// ��Ա����
		Functions m_pFunctions;
	};

	// �Ƿ�ָ�����͵�����
	#define IS_DATATYPE(var, varType) (var->getDataType() == varType)
}