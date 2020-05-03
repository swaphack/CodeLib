#include "system.h"

namespace render
{
	class TouchManager;
	class KeyboardManager;

	// �豸����
	class DeviceProxy : public sys::Object
	{
	public:
		DeviceProxy(const TouchManager* touchManager);
		~DeviceProxy();
	public:
		void onMouseButtonHandler(sys::MouseKey key, sys::ButtonStatus type, float x, float y);

		void onMouseMoveHandler(float x, float y);

		void onKeyBoardButtonHandler(sys::BoardKey key, sys::ButtonStatus type);

		void setTouchMananger(const TouchManager* touchManager);
	protected:
	private:
		// �����¼�
		TouchManager* _touchManager;
		// �����¼�
		KeyboardManager* _keyboardManager;
	};
}