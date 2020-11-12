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
		bool isEnableShift() const;
	private:
		// 键盘转字符
		std::map<sys::BoardKey, char> _keyChars;
		// 控制键
		std::map<sys::BoardKey, bool> _controlkeys;
		// 上档
		bool _enableShift = false;
	};

#define G_KEYCHAR sys::Instance<KeyChar>::getInstance()
}