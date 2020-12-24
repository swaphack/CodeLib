#pragma once

#include "ui.h"

namespace ue
{

	// ���
	class Panel : public ui::CtrlFile
	{
	public:
		Panel();
		virtual ~Panel();
	public:
		virtual bool init();
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
	protected: // ���
		/**
		*	�����Ļ
		*/ 
		virtual bool onTouchBegan(float x, float y, bool include);
		/**
		*	����Ļ�ϻ���
		*/  
		virtual bool onTouchMoved(float x, float y, bool include);
		/**
		*	�뿪��Ļ
		*/   
		virtual bool onTouchEnded(float x, float y, bool include);
	protected:
		/**
		*	�����ؼ�
		*/
		template<typename T, typename = std::enable_if<std::is_base_of<ui::CtrlWidget, T>::value, T>::type>
		static T* createWidget()
		{
			auto pNode = CREATE_NODE(T);

			return pNode;
		}
		/**
		*	�����ļ�
		*/
		ui::CtrlWidget* createUIFile(const std::string& filepath);
		/**
		*	�����ļ����
		*/
		template<typename T, typename = std::enable_if<std::is_base_of<Panel, T>::value, T>::type>
		static T* createPanel(const std::string& filepath)
		{
			auto pFile = CREATE_NODE(T);
			pFile->setRootView(true);
			pFile->setFilePath(filepath);
			pFile->autoResize();

			return pFile;
		}


		/**
		*	�������
		*/
		template<typename T, typename = std::enable_if<std::is_base_of<SinglePanel, T>::value, T>::type>
		static T* showWithTarget(const ui::CtrlWidget* item, sys::CSSDirection eDir)
		{
			auto pFile = CREATE_NODE(T);
			pFile->setRootView(true);
			pFile->setFilePath(pFile->getPanelPath());
			pFile->autoResize();
			pFile->showWithTarget(item, eDir);

			return pFile;
		}
		/**
		*	�������
		*/
		template<typename T, typename = std::enable_if<std::is_base_of<SinglePanel, T>::value, T>::type>
		static T* show()
		{
			auto pFile = CREATE_NODE(T);
			pFile->setRootView(true);
			pFile->setFilePath(pFile->getPanelPath());
			pFile->autoResize();
			pFile->show();

			return pFile;
		}
	};
}
