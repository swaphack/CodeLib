#pragma once

#include "Panel/SinglePanel.h"
#include <functional>

namespace ue
{
	/**
	*  ���ļ����
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
		*	�ļ�·��
		*/
		virtual const char* getPanelPath();
		/**
		*	ѡ���ļ��ص�
		*/
		void setSelectFileFunc(const SelectFileFunc& func);
		/**
		*	�ļ���ʽ
		*/
		void setFileFormat(const std::vector<std::string>& vecFormat);
	protected:
		/**
		*	��ʼ��
		*/
		virtual void initUI();
		/**
		*	�¼���
		*/
		virtual void initEvent();
		/**
		*	��ʼ���ı�
		*/
		virtual void initText();
	protected:
		/**
		*	�ļ���ʽ�Ƿ�ƥ��
		*/
		bool isMatchFormat(const std::string& filepath);
		/**
		*	ѡ���ļ�
		*/
		void onSelectFile(const std::string& filepath);
	private:
		/**
		*	ѡ���ļ��ص�
		*/
		SelectFileFunc _selectFileFunc = nullptr;
		/**
		*	�ļ���ʽ
		*/
		std::vector<std::string> _fileFormats;
		/**
		*	ѡ���ļ�·��
		*/
		std::string _selectedFilepath;
	};
}
