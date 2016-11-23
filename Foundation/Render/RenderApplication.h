#pragma once

#include "system.h"
#include "Canvas.h"

namespace render
{
	// ��ȾӦ��
	class RenderApplication : public sys::Application
	{
	public:
		RenderApplication();
		virtual ~RenderApplication();
	public:
		virtual void init();
		virtual void update();
		virtual void dispose(); 
		// ����д
		virtual void show() {}
		// ����
		Canvas* getCanvas();

		// ���ô����С
		void setFrameSize(int width, int height);
		// ��ȡ
		sys::Size& getFrameSize();
		// ����ˢ�¼��
		void setRefreshInterval(float interval);
		// ��ȡˢ�¼��
		float getRefreshInterval();
	protected:
		// ��ʼ��·��
		void initFilePath();
		// ��ʼ����Ⱦ
		void initRender();
		// ������Ⱦ
		void disposeRender();
		// ��ʼ��Э�����
		void initProtocolManagers();
	protected:
		// ����
		Canvas* _canvas;
		// ���һ�ζ�ʱˢ�µ�����
		long _lastClock;
		// �����С
		sys::Size _frameSize;
		// ˢ�¼��
		float _refreshInterval;
	};
}