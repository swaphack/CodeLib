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
			ADD_TEXT(1, "存在同名成员变量名称");
			ADD_TEXT(2, "存在同名函数名称");
			ADD_TEXT(3, "存在父域");
			ADD_TEXT(4, "不存在父域");
			ADD_TEXT(5, "子域的父域与当前域不同");
			ADD_TEXT(6, "存在同名子域名称");
			ADD_TEXT(7, "被除数不能为0");
		}
	};
}