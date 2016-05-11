#pragma once

#include "../Framework/import.h"
#include "../Base/import.h"


#if PLATFORM_TARGET == EPT_WINDOWS
#include <windows.h>
#endif

namespace sys
{
	// 按钮状态
	enum ButtonStatus
	{
		// 按下按钮
		EBS_BUTTON_DOWN,
		// 放开按钮
		EBS_BUTTON_UP,
	};

	// 滚轮事件
	enum ScrollEvent
	{
		// 向上滑动滚轮
		ESE_SCORLL_UP,
		// 向下滑动滚轮
		ESE_SCORLL_DOWN,
	};

	// 鼠标键
	enum MouseKey
	{
		// 左按钮
		EMK_LEFTBUTTON,
		// 滚轮
		EMK_SCROLLBUTTON,
		// 右按钮
		EMK_RIGHTBUTTON,
	};

	// 按键
	enum BoardKey
	{
		EBK_LBUTTON = VK_LBUTTON,
		EBK_RBUTTON = VK_RBUTTON,
		EBK_CANCEL = VK_CANCEL,
		EBK_MBUTTON = VK_MBUTTON,

		EBK_XBUTTON1 = VK_XBUTTON1,
		EBK_XBUTTON2 = VK_XBUTTON2,

		EBK_BACK = VK_BACK,
		EBK_TAB = VK_TAB,

		EBK_CLEAR = VK_CLEAR,
		EBK_RETURN = VK_RETURN,

		EBK_SHIFT = VK_SHIFT,
		EBK_CONTROL = VK_CONTROL,
		EBK_MENU = VK_MENU,
		EBK_PAUSE = VK_PAUSE,
		EBK_CAPITAL = VK_CAPITAL,

		EBK_KANA = VK_KANA,
		EBK_HANGEUL = VK_HANGEUL,
		EBK_HANGUL = VK_HANGUL,
		EBK_JUNJA = VK_JUNJA,
		EBK_FINAL = VK_FINAL,
		EBK_HANJA = VK_HANJA,
		EBK_KANJI = VK_KANJI,

		EBK_ESCAPE = VK_ESCAPE,
		EBK_CONVERT = VK_CONVERT,
		EBK_NONCONVERT = VK_NONCONVERT,
		EBK_ACCEPT = VK_ACCEPT,
		EBK_MODECHANGE = VK_MODECHANGE,

		EBK_SPACE = VK_SPACE,
		EBK_PRIOR = VK_PRIOR,
		EBK_NEXT = VK_NEXT,
		EBK_END = VK_END,
		EBK_HOME = VK_HOME,
		EBK_LEFT = VK_LEFT,
		EBK_UP = VK_UP,
		EBK_RIGHT = VK_RIGHT,
		EBK_DOWN = VK_DOWN,
		EBK_SELECT = VK_SELECT,
		EBK_PRINT = VK_PRINT,
		EBK_EXECUTE = VK_EXECUTE,
		EBK_SNAPSHOT = VK_SNAPSHOT,
		EBK_INSERT = VK_INSERT,
		EBK_DELETE = VK_DELETE,
		EBK_HELP = VK_HELP,

		EBK_0 = 0X30,
		EBK_1,
		EBK_2,
		EBK_3,
		EBK_4,
		EBK_5,
		EBK_6,
		EBK_7,
		EBK_8,
		EBK_9,

		EBK_A = 0X41,
		EBK_B,
		EBK_C,
		EBK_D,
		EBK_E,
		EBK_F,
		EBK_G,
		EBK_H,
		EBK_I,
		EBK_J,
		EBK_K,
		EBK_L,
		EBK_M,
		EBK_N,
		EBK_O,
		EBK_P,
		EBK_Q,
		EBK_R,
		EBK_S,
		EBK_T,
		EBK_U,
		EBK_V,
		EBK_W,
		EBK_X,
		EBK_Y,
		EBK_Z,

		EBK_LWIN = VK_LWIN,
		EBK_RWIN = VK_RWIN,
		EBK_APPS = VK_APPS,

		EBK_SLEEP = VK_SLEEP,

		EBK_NUMPAD0 = VK_NUMPAD0,
		EBK_NUMPAD1 = VK_NUMPAD1,
		EBK_NUMPAD2 = VK_NUMPAD2,
		EBK_NUMPAD3 = VK_NUMPAD3,
		EBK_NUMPAD4 = VK_NUMPAD4,
		EBK_NUMPAD5 = VK_NUMPAD5,
		EBK_NUMPAD6 = VK_NUMPAD6,
		EBK_NUMPAD7 = VK_NUMPAD7,
		EBK_NUMPAD8 = VK_NUMPAD8,
		EBK_NUMPAD9 = VK_NUMPAD9,
		EBK_MULTIPLY = VK_MULTIPLY,
		EBK_ADD = VK_ADD,
		EBK_SEPARATOR = VK_SEPARATOR,
		EBK_SUBTRACT = VK_SUBTRACT,
		EBK_DECIMAL = VK_DECIMAL,
		EBK_DIVIDE = VK_DIVIDE,
		EBK_F1 = VK_F1,
		EBK_F2 = VK_F2,
		EBK_F3 = VK_F3,
		EBK_F4 = VK_F4,
		EBK_F5 = VK_F5,
		EBK_F6 = VK_F6,
		EBK_F7 = VK_F7,
		EBK_F8 = VK_F8,
		EBK_F9 = VK_F9,
		EBK_F10 = VK_F10,
		EBK_F11 = VK_F11,
		EBK_F12 = VK_F12,
		EBK_F13 = VK_F13,
		EBK_F14 = VK_F14,
		EBK_F15 = VK_F15,
		EBK_F16 = VK_F16,
		EBK_F17 = VK_F17,
		EBK_F18 = VK_F18,
		EBK_F19 = VK_F19,
		EBK_F20 = VK_F20,
		EBK_F21 = VK_F21,
		EBK_F22 = VK_F22,
		EBK_F23 = VK_F23,
		EBK_F24 = VK_F24,

		EBK_NUMLOCK = VK_NUMLOCK,
		EBK_SCROLL = VK_SCROLL,

		EBK_OEM_NEC_EQUAL = VK_OEM_NEC_EQUAL,


		EBK_OEM_FJ_JISHO = VK_OEM_FJ_JISHO,
		EBK_OEM_FJ_MASSHOU = VK_OEM_FJ_MASSHOU,
		EBK_OEM_FJ_TOUROKU = VK_OEM_FJ_TOUROKU,
		EBK_OEM_FJ_LOYA = VK_OEM_FJ_LOYA,
		EBK_OEM_FJ_ROYA = VK_OEM_FJ_ROYA,


		EBK_LSHIFT = VK_LSHIFT,
		EBK_RSHIFT = VK_RSHIFT,
		EBK_LCONTROL = VK_LCONTROL,
		EBK_RCONTROL = VK_RCONTROL,
		EBK_LMENU = VK_LMENU,
		EBK_RMENU = VK_RMENU,


		EBK_BROWSER_BACK = VK_BROWSER_BACK,
		EBK_BROWSER_FORWARD = VK_BROWSER_FORWARD,
		EBK_BROWSER_REFRESH = VK_BROWSER_REFRESH,
		EBK_BROWSER_STOP = VK_BROWSER_STOP,
		EBK_BROWSER_SEARCH = VK_BROWSER_SEARCH,
		EBK_BROWSER_FAVORITES = VK_BROWSER_FAVORITES,
		EBK_BROWSER_HOME = VK_BROWSER_HOME,

		EBK_VOLUME_MUTE = VK_VOLUME_MUTE,
		EBK_VOLUME_DOWN = VK_VOLUME_DOWN,
		EBK_VOLUME_UP = VK_VOLUME_UP,
		EBK_MEDIA_NEXT_TRACK = VK_MEDIA_NEXT_TRACK,
		EBK_MEDIA_PREV_TRACK = VK_MEDIA_PREV_TRACK,
		EBK_MEDIA_STOP = VK_MEDIA_STOP,
		EBK_MEDIA_PLAY_PAUSE = VK_MEDIA_PLAY_PAUSE,
		EBK_LAUNCH_MAIL = VK_LAUNCH_MAIL,
		EBK_LAUNCH_MEDIA_SELECT = VK_LAUNCH_MEDIA_SELECT,
		EBK_LAUNCH_APP1 = VK_LAUNCH_APP1,
		EBK_LAUNCH_APP2 = VK_LAUNCH_APP2,


		EBK_OEM_1 = VK_OEM_1,
		EBK_OEM_PLUS = VK_OEM_PLUS,
		EBK_OEM_COMMA = VK_OEM_COMMA,
		EBK_OEM_MINUS = VK_OEM_MINUS,
		EBK_OEM_PERIOD = VK_OEM_PERIOD,
		EBK_OEM_2 = VK_OEM_2,
		EBK_OEM_3 = VK_OEM_3,

		EBK_OEM_4 = VK_OEM_4,
		EBK_OEM_5 = VK_OEM_5,
		EBK_OEM_6 = VK_OEM_6,
		EBK_OEM_7 = VK_OEM_7,
		EBK_OEM_8 = VK_OEM_8,


		EBK_OEM_AX = VK_OEM_AX,
		EBK_OEM_102 = VK_OEM_102,
		EBK_ICO_HELP = VK_ICO_HELP,
		EBK_ICO_00 = VK_ICO_00,

		EBK_PROCESSKEY = VK_PROCESSKEY,

		EBK_ICO_CLEAR = VK_ICO_CLEAR,

		EBK_PACKET = VK_PACKET,

		EBK_OEM_RESET = VK_OEM_RESET,
		EBK_OEM_JUMP = VK_OEM_JUMP,
		EBK_OEM_PA1 = VK_OEM_PA1,
		EBK_OEM_PA2 = VK_OEM_PA2,
		EBK_OEM_PA3 = VK_OEM_PA3,
		EBK_OEM_WSCTRL = VK_OEM_WSCTRL,
		EBK_OEM_CUSEL = VK_OEM_CUSEL,
		EBK_OEM_ATTN = VK_OEM_ATTN,
		EBK_OEM_FINISH = VK_OEM_FINISH,
		EBK_OEM_COPY = VK_OEM_COPY,
		EBK_OEM_AUTO = VK_OEM_AUTO,
		EBK_OEM_ENLW = VK_OEM_ENLW,
		EBK_OEM_BACKTAB = VK_OEM_BACKTAB,

		EBK_ATTN = VK_ATTN,
		EBK_CRSEL = VK_CRSEL,
		EBK_EXSEL = VK_EXSEL,
		EBK_EREOF = VK_EREOF,
		EBK_PLAY = VK_PLAY,
		EBK_ZOOM = VK_ZOOM,
		EBK_NONAME = VK_NONAME,
		EBK_PA1 = VK_PA1,
		EBK_OEM_CLEAR = VK_OEM_CLEAR,
	};
}

