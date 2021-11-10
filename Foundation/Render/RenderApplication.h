#pragma once

#include "system.h"
#include "Canvas.h"

#include <set>

namespace render
{
	class WindowProtocol
	{
	public:
		virtual ~WindowProtocol() {}
	public:
		virtual void onWindowSizeChange(const math::Size& size) = 0;
	};
	// ��ȾӦ��
	class RenderApplication : public sys::Application
	{
	public:
		RenderApplication();
		virtual ~RenderApplication();
	public:
		/**
		*	��ʼ��
		*/
		virtual void init();
		/**
		*	����
		*/
		virtual void update();
		/**
		*	�ͷ�
		*/
		virtual void dispose(); 
		/**
		*	��ʾ ����д
		*/ 
		virtual void show();
	public:
		/**
		*	����
		*/ 
		Canvas* getCanvas() const;
		/**
		*	���ô����С
		*/ 
		void setFrameSize(int width, int height);
		/**
		*	��ȡ�����С
		*/  
		const math::Size& getFrameSize() const;
		/**
		*	����ˢ�¼��
		*/ 
		void setRefreshInterval(float interval);
		/**
		*	��ȡˢ�¼��
		*/  
		float getRefreshInterval() const;
	public:
		/**
		*	��Ӵ�����ƶ���
		*/
		void addWndProtocol(WindowProtocol* obj);
		/**
		*	�Ƴ�������ƶ���
		*/
		void removeWndProtocol(WindowProtocol* obj);
		/**
		*	�Ƴ�������ƶ���
		*/
		void removeAllWndProtocols();
	public:
		/**
		*	��̬����
		*/
		static RenderApplication* getInstance();
	protected:
		/**
		*	��ʼ��·��
		*/ 
		void initFilePath();
		/**
		*	��ʼ����Ⱦ
		*/  
		void initRender();
		/**
		*	������Ⱦ
		*/ 
		void disposeRender();
		/**
		*	��ʼ��Э�����
		*/  
		void initProtocolManagers();
	protected:
		// ����
		Canvas* _canvas;
		// ���һ�ζ�ʱˢ�µ�����
		uint64_t _lastClock = 0;
		// ˢ�¼��
		float _refreshInterval = 0;
		// ˢ�¼��
		std::set<WindowProtocol*> _windowProtocols;

		math::Size _frameSize;
	};
}