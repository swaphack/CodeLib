#pragma once

#include <string>

namespace math
{
	// ����
	class Symbol
	{
	public:
		Symbol() {}
		virtual ~Symbol() {}
	public:
		// ��������
		inline void setName(const char* value) { _name = value; }
		// ��ȡ����
		inline const char* getName() { return _name.c_str(); }
	private:
		// ��������
		std::string _name;
	};
}