#pragma once

#include <string>
#include <map>

namespace math
{
	// �ű��ı�
	class ScriptText
	{
	public:
		ScriptText();
		virtual ~ScriptText();
	public:
		// �����ַ���
		bool loadString(const char* value);
		// �����ַ���
		const char* getString();
	protected:
		// ��׼���ַ�����ȥ���������õ��ַ�
		bool standardize(char* value);
	private:
		// �ַ���
		char* _value;
		// �����ڴ�
		int _capacity;
		// �α�ƫ����
		int _offset;
	};
}