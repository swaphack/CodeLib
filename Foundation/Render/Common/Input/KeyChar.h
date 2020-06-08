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
		// acciiÂë×ªkey
		sys::BoardKey getKey(uint8_t ascii);

		char getChar(sys::BoardKey key);
		// Êı×Ö
		char getNumber(sys::BoardKey key);
		// Êı×Ö°åÊı×Ö
		char getPadNumber(sys::BoardKey key);

		// ×Ö·û
		char getLetter(sys::BoardKey key);

		// ¹¦ÄÜ×Ö·û
		char getFuncChar(sys::BoardKey key);
		// ¿ØÖÆ·û
		void setControlKey(sys::BoardKey key);
	private:
		// ¼üÅÌ×ª×Ö·û
		std::map<sys::BoardKey, char> _keyChars;
		// ¿ØÖÆ¼ü
		std::map<sys::BoardKey, bool> _controlkeys;
	};

#define G_KEYCHAR sys::Instance<KeyChar>::getInstance()
}