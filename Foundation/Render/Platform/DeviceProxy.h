#include "system.h"

namespace render
{
	class TouchManager;
	class KeyboardManager;

	// 设备代理
	class DeviceProxy : public sys::Object
	{
	public:
		DeviceProxy();
		~DeviceProxy();
	public:
		void onMouseButtonHandler(sys::MouseKey key, sys::ButtonStatus type, float x, float y);

		void onMouseMoveHandler(float x, float y);

		void onMouseScrollHandler(sys::ScrollEvent evt, float param);

		void onKeyBoardButtonHandler(sys::BoardKey key, sys::ButtonStatus type);
	protected:
	};
}