#pragma once

namespace script
{
	class Scope;

	class Document
	{
	public:
		Document();
		virtual ~Document();
	public:
		// �����ַ���
		bool loadString(const char* text);
		// ��ȡ��ǰָ��
		char* getPtr();
	private:
		// �ı�����ָ��
		char* m_pContent;
		// ƫ��λ��
		int m_nOffset;
		// �ı���С
		int m_nSize;
	};
}