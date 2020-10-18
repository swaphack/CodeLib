#pragma once

#include "Panel.h"

namespace ue
{
	// Ŀ¼��
	class DirectoryPanel : public Panel
	{
	public:
		DirectoryPanel();
		virtual ~DirectoryPanel();
	public:
		virtual bool init();
	public:
		/**
		*	����Ŀ¼
		*/
		void setDirectory(const std::string& dir);
	protected:
		// ����Ŀ¼��
		void updateDirectoryPanel();
	private:
		// Ŀ¼
		std::string _directory;
	};
}
