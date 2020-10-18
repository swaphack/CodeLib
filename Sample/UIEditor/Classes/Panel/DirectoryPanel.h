#pragma once

#include "Panel.h"

namespace ue
{
	// 目录栏
	class DirectoryPanel : public Panel
	{
	public:
		DirectoryPanel();
		virtual ~DirectoryPanel();
	public:
		virtual bool init();
	public:
		/**
		*	设置目录
		*/
		void setDirectory(const std::string& dir);
	protected:
		// 更新目录栏
		void updateDirectoryPanel();
	private:
		// 目录
		std::string _directory;
	};
}
