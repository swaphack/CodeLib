#pragma once

namespace script
{
	class Script
	{
	public:
		Script();
		virtual ~Script();
	public:
		// 加载脚本
		virtual bool load(const char* filepath);
		// 执行脚本
		virtual int run();
	};
}