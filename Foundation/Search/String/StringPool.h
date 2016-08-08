#pragma once

#include "system.h"

#include <map>
#include <string>


namespace search
{
	/*
	 * �ַ�����
	 * Ψһ�ַ���
	 */
	class StringPool
	{
	public:
		uint getHash(const char* str);
		// ��ȡ�ַ���
		std::string* getString(const char* str);
	protected:
		std::map<uint, std::string> _strings;
	};

	#define GET_STRING_PTR(str) (sys::Instance<StringPool>::getInstance()->getString(str))
}