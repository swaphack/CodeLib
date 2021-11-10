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
	// 渲染应用
	class RenderApplication : public sys::Application
	{
	public:
		RenderApplication();
		virtual ~RenderApplication();
	public:
		/**
		*	初始化
		*/
		virtual void init();
		/**
		*	更新
		*/
		virtual void update();
		/**
		*	释放
		*/
		virtual void dispose(); 
		/**
		*	显示 需重写
		*/ 
		virtual void show();
	public:
		/**
		*	画布
		*/ 
		Canvas* getCanvas() const;
		/**
		*	设置窗体大小
		*/ 
		void setFrameSize(int width, int height);
		/**
		*	获取窗体大小
		*/  
		const math::Size& getFrameSize() const;
		/**
		*	设置刷新间隔
		*/ 
		void setRefreshInterval(float interval);
		/**
		*	获取刷新间隔
		*/  
		float getRefreshInterval() const;
	public:
		/**
		*	添加窗体控制对象
		*/
		void addWndProtocol(WindowProtocol* obj);
		/**
		*	移除窗体控制对象
		*/
		void removeWndProtocol(WindowProtocol* obj);
		/**
		*	移除窗体控制对象
		*/
		void removeAllWndProtocols();
	public:
		/**
		*	静态对象
		*/
		static RenderApplication* getInstance();
	protected:
		/**
		*	初始化路径
		*/ 
		void initFilePath();
		/**
		*	初始化渲染
		*/  
		void initRender();
		/**
		*	销毁渲染
		*/ 
		void disposeRender();
		/**
		*	初始化协议管理
		*/  
		void initProtocolManagers();
	protected:
		// 画布
		Canvas* _canvas;
		// 最后一次定时刷新的周期
		uint64_t _lastClock = 0;
		// 刷新间隔
		float _refreshInterval = 0;
		// 刷新间隔
		std::set<WindowProtocol*> _windowProtocols;

		math::Size _frameSize;
	};
}