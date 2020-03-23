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
		// ��������
		virtual void initDevice();
	private:
		// ��Ⱦ
		RenderApplication* _render;
		// �豸����
		DeviceProxy* _deviceProxy;
	};
}