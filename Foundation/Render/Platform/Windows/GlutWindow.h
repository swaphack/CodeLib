#pragma once
#include "Platform/macros.h"
#include <string>

namespace render
{
	class RenderApplication;
	class DeviceProxy;

	class GlutWindow : public sys::WindowImpl, public sys::DeviceImpl
	{
	public:
		GlutWindow();
		virtual ~GlutWindow();
	public:
		void createWindow(const std::string& title, int width, int height, int millis, RenderApplication* render);
	public:
		void onUpdate();
		void onKeyboardDown(unsigned char key, int x, int y);
		void onKeyboardUp(unsigned char key, int x, int y);
		void onMouseDown(int button, int state, int x, int y);
		void onMouseMove(int x, int y);
		void onSizeChange(int width, int height);

		float getRefreshInterval();
	protected:
		// 重置外设
		virtual void initDevice();
	private:
		// 渲染
		RenderApplication* _render;
		// 设备代理
		DeviceProxy* _deviceProxy;
	};
}