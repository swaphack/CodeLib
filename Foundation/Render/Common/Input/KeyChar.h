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
		// accii��תkey
		sys::BoardKey getKey(uint8_t ascii);

		char getChar(sys::BoardKey key);
		// ����
		char getNumber(sys::BoardKey key);
		// ���ְ�����
		char getPadNumber(sys::BoardKey key);

		// �ַ�
		char getLetter(sys::BoardKey key);

		// �����ַ�
		char getFuncChar(sys::BoardKey key);
		// ���Ʒ�
		void setControlKey(sys::BoardKey key);
	private:
		// ����ת�ַ�
		std::map<sys::BoardKey, char> _keyChars;
		// ���Ƽ�
		std::map<sys::BoardKey, bool> _controlkeys;
	};

#define G_KEYCHAR sys::Instance<KeyChar>::getInstance()
}