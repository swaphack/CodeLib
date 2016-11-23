#pragma once

#include "system.h"
#include "Canvas.h"

namespace render
{
	// 渲染应用
	class RenderApplication : public sys::Application
	{
	public:
		RenderApplication();
		virtual ~RenderApplication();
	public:
		virtual void init();
		virtual void update();
		virtual void dispose(); 
		// 需重写
		virtual void show() {}
		// 画布
		Canvas* getCanvas();

		// 设置窗体大小
		void setFrameSize(int width, int height);
		// 获取
		sys::Size& getFrameSize();
		// 设置刷新间隔
		void setRefreshInterval(float interval);
		// 获取刷新间隔
		float getRefreshInterval();
	protected:
		// 初始化路径
		void initFilePath();
		// 初始化渲染
		void initRender();
		// 销毁渲染
		void disposeRender();
		// 初始化协议管理
		void initProtocolManagers();
	protected:
		// 画布
		Canvas* _canvas;
		// 最后一次定时刷新的周期
		long _lastClock;
		// 窗体大小
		sys::Size _frameSize;
		// 刷新间隔
		float _refreshInterval;
	};
}