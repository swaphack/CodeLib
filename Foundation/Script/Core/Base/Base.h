#pragma once

#include "macros.h"
#include <string>

namespace script
{
	// ������
	enum AccessType
	{
		// ����
		E_ACCESSTYPE_PUBLIC,
		// ����
		E_ACCESSTYPE_PROTECTED,
		// �ڲ�
		E_ACCESSTYPE_INTERNAL,
		// ˽��
		E_ACCESSTYPE_PRIVATE,
	};

	class Base
	{
	public:
		Base();
		virtual ~Base();
	public:
		// ���÷���������
		int getAccessType();
		// ���÷���������
		void setAccessType(int nType);
		// ��ȡ����
		const std::string& getName();
		// ��������
		void setName(const std::string& name);
		// ����
		virtual void dispose();
	private:
		std::string m_strName;
		// ����������
		int m_nAccessType;
	};
}