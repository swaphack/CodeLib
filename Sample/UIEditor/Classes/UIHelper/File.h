#pragma once

#include "Panel/SinglePanel.h"
#include <functional>

namespace ue
{
	/**
	*  打开文件面板
	*/
	class File : public SinglePanel
	{
	public:
		typedef std::function<void(const std::string& filepath)> SelectFileFunc;
	public:
		File ();
		virtual ~File ();
	public:
		/**
		*	文件路径
		*/
		virtual const char* getPanelPath();
		/**
		*	选中文件回调
		*/
		void setSelectFileFunc(const SelectFileFunc& func);
		/**
		*	文件格式
		*/
		void setFileFormat(const std::vector<std::string>& vecFormat);
	protected:
		/**
		*	初始化
		*/
		virtual void initUI();
		/**
		*	事件绑定
		*/
		virtual void initEvent();
		/**
		*	初始化文本
		*/
		virtual void initText();
	protected:
		/**
		*	文件格式是否匹配
		*/
		bool isMatchFormat(const std::string& filepath);
		/**
		*	选中文件
		*/
		void onSelectFile(const std::string& filepath);
	private:
		/**
		*	选中文件回调
		*/
		SelectFileFunc _selectFileFunc = nullptr;
		/**
		*	文件格式
		*/
		std::vector<std::string> _fileFormats;
		/**
		*	选中文件路径
		*/
		std::string _selectedFilepath;
	};
}
