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
	public:
		// ����
		char getNumberChar(sys::BoardKey key);
		// ���ְ�����
		char getPadNumberChar(sys::BoardKey key);
		// �ַ�
		char getLetterChar(sys::BoardKey key);
		// �ϵ�
		char getShiftChar(sys::BoardKey key);
		// �����ַ�
		char getFuncChar(sys::BoardKey key);
	public:
		// ���Ʒ�
		void setControlKey(sys::BoardKey key);
		// �ϵ�
		void setShiftEnable(bool enable);
		// �ϵ�
		bool isShiftEnabled() const;
		// ����
		void setControlEnable(bool enable);
		// ����
		bool isControlEnabled() const;
	private:
		// ����ת�ַ�
		std::map<sys::BoardKey, char> _keyChars;
		// ���Ƽ�
		std::map<sys::BoardKey, bool> _controlkeys;
		// �ϵ�
		bool _enableShift = false;
		// ����
		bool _enableControl = false;
	};

#define G_KEYCHAR sys::Instance<render::KeyChar>::getInstance()
}