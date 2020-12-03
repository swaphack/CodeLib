#pragma once

#include "system.h"

namespace render
{
	class KeyChar
	{
	public:
		KeyChar();
		~KeyChar();
	public:
		// accii码转key
		sys::BoardKey getKey(uint8_t ascii);

		char getChar(sys::BoardKey key);
	public:
		// 数字
		char getNumberChar(sys::BoardKey key);
		// 数字板数字
		char getPadNumberChar(sys::BoardKey key);
		// 字符
		char getLetterChar(sys::BoardKey key);
		// 上档
		char getShiftChar(sys::BoardKey key);
		// 功能字符
		char getFuncChar(sys::BoardKey key);
	public:
		// 控制符
		void setControlKey(sys::BoardKey key);
		// 上档
		void setShiftEnable(bool enable);
		// 上档
		bool isShiftEnabled() const;
		// 控制
		void setControlEnable(bool enable);
		// 控制
		bool isControlEnabled() const;
	private:
		// 键盘转字符
		std::map<sys::BoardKey, char> _keyChars;
		// 控制键
		std::map<sys::BoardKey, bool> _controlkeys;
		// 上档
		bool _enableShift = false;
		// 控制
		bool _enableControl = false;
	};

#define G_KEYCHAR sys::Instance<render::KeyChar>::getInstance()
}