#pragma once

#include "Message.h"

namespace script
{
#define ADD_TEXT(id, text) Message::getInstance()->addText(id, text);

	class Tip
	{
	public:
		static void init()
		{
			ADD_TEXT(1, "����ͬ����Ա��������");
			ADD_TEXT(2, "����ͬ����������");
			ADD_TEXT(3, "���ڸ���");
			ADD_TEXT(4, "�����ڸ���");
			ADD_TEXT(5, "����ĸ����뵱ǰ��ͬ");
			ADD_TEXT(6, "����ͬ����������");
			ADD_TEXT(7, "����������Ϊ0");
		}
	};
}