#pragma once

namespace script
{
	class Script
	{
	public:
		Script();
		virtual ~Script();
	public:
		// ���ؽű�
		virtual bool load(const char* filepath);
		// ִ�нű�
		virtual int run();
	};
}