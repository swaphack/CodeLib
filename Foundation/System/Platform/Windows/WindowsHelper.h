#pragma once

#include <string>
#include <vector>

namespace sys
{
	// windows ��������
	class WindowsHelper
	{
	public:
		/**
		*	ѡ�����ļ�
		*/
		static std::vector<std::string> selectFiles(const std::string& path, const std::vector<std::string>& vecFormat);
		/**
		*	ѡ�񵥸��ļ�
		*/
		static std::string selectFile(const std::string& path, const std::vector<std::string>& vecFormat);
	};
}
