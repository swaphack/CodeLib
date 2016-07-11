#pragma once

#include "Result.h"

#include <string>

namespace idea
{
	// ������Ϣ
	class Message : public sys::Object
	{
	public:
		Message();
		virtual ~Message();
	public:
		// ��ȡ����
		const char* getTitle();
		// ���ñ���
		void setTitle(const char* title);
		// ��ȡ��Ϣ��
		Result* getBody();
		// ������Ϣ��
		void setBody(Result* result);
		// ��ȡ��Ϣ����
		int getType();
		// ������Ϣ����
		void setType(int value);
	public:
		std::string _title;
		// ��Ϣ��
		Result* _body;
		// ��Ϣ����
		int _type;
	};
}