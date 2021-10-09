#pragma once

#include <string>
#include <vector>

namespace sys
{
	// windows 辅助工具
	class WindowsHelper
	{
	public:
		/**
		*	选择多个文件
		*/
		static std::vector<std::string> selectFiles(const std::string& path, const std::vector<std::string>& vecFormat);
		/**
		*	选择单个文件
		*/
		static std::string selectFile(const std::string& path, const std::vector<std::string>& vecFormat);
	};
}
