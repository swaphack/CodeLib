#pragma once

#include "macros.h"

namespace script
{
	// ��
	class None : public Variable
	{
	public:
		None();
		virtual ~None();
	public:
		// ��ȡ����ֵ
		void* getValue();
	public: // ����
		// ��¡
		None* clone();
		// �����µ��ڴ棬Ϊ������ֵ
		None* alloct(const char* name);
	};
}