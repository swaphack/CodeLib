#pragma once

#include "macros.h"

namespace script
{
	// �ı�
	class Text : public Variable
	{
	public:
		Text();
		virtual ~Text();
	public:
		// ���ñ���ֵ
		void setValue(const char* value);
		// ��ȡ����ֵ
		const char* getValue();
	public: // ����
		// ��¡
		Text* clone();
		// �����µ��ڴ棬Ϊ������ֵ
		Text* alloct(const char* name);
	private:
		std::string m_strValue;
	};
}