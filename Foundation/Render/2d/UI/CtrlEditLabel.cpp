#include "CtrlEditLabel.h"
#include "CtrlText.h"
#include <map>
using namespace render;

class KeyChar
{
public:
	KeyChar()
	{}
	~KeyChar()
	{}
public:
	char getChar(sys::BoardKey key)
	{
		char value = getPadNumber(key);
		if (value != 0) return value;

		value = getNumber(key);
		if (value != 0) return value;

		value = getLetter(key);
		if (value != 0) return value;

		value = getFuncChar(key);
		return value;
	}
	// Êý×Ö
	char getNumber(sys::BoardKey key)
	{
		switch (key)
		{
		case sys::EBK_0: return '0';
		case sys::EBK_1: return '1';
		case sys::EBK_2: return '2';
		case sys::EBK_3: return '3';
		case sys::EBK_4: return '4';
		case sys::EBK_5: return '5';
		case sys::EBK_6: return '6';
		case sys::EBK_7: return '7';
		case sys::EBK_8: return '8';
		case sys::EBK_9: return '9';
		default: return 0;
		}
	}
	// Êý×Ö°åÊý×Ö
	char getPadNumber(sys::BoardKey key)
	{
		if (_controlkeys[sys::EBK_NUMLOCK] == false)
		{
			return 0;
		}
		switch (key)
		{
			case sys::EBK_NUMPAD0: return '0';
			case sys::EBK_NUMPAD1: return '1';
			case sys::EBK_NUMPAD2: return '2';
			case sys::EBK_NUMPAD3: return '3';
			case sys::EBK_NUMPAD4: return '4';
			case sys::EBK_NUMPAD5: return '5';
			case sys::EBK_NUMPAD6: return '6';
			case sys::EBK_NUMPAD7: return '7';
			case sys::EBK_NUMPAD8: return '8';
			case sys::EBK_NUMPAD9: return '9';
			default: return 0;
		}
	}

	// ×Ö·û
	char getLetter(sys::BoardKey key)
	{
		if (_controlkeys[sys::EBK_CAPITAL])
		{
			switch (key)
			{
			case sys::EBK_A: return 'A';
			case sys::EBK_B: return 'B';
			case sys::EBK_C: return 'C';
			case sys::EBK_D: return 'D';
			case sys::EBK_E: return 'E';
			case sys::EBK_F: return 'F';
			case sys::EBK_G: return 'G';
			case sys::EBK_H: return 'H';
			case sys::EBK_I: return 'I';
			case sys::EBK_J: return 'J';
			case sys::EBK_K: return 'K';
			case sys::EBK_L: return 'L';
			case sys::EBK_M: return 'M';
			case sys::EBK_N: return 'N';
			case sys::EBK_O: return 'O';
			case sys::EBK_P: return 'P';
			case sys::EBK_Q: return 'Q';
			case sys::EBK_R: return 'R';
			case sys::EBK_S: return 'S';
			case sys::EBK_T: return 'T';
			case sys::EBK_U: return 'U';
			case sys::EBK_V: return 'V';
			case sys::EBK_W: return 'W';
			case sys::EBK_X: return 'X';
			case sys::EBK_Y: return 'Y';
			case sys::EBK_Z: return 'Z';
			default: return 0;
			}
		}
		else
		{
			switch (key)
			{
			case sys::EBK_A: return 'a';
			case sys::EBK_B: return 'b';
			case sys::EBK_C: return 'c';
			case sys::EBK_D: return 'd';
			case sys::EBK_E: return 'e';
			case sys::EBK_F: return 'f';
			case sys::EBK_G: return 'g';
			case sys::EBK_H: return 'h';
			case sys::EBK_I: return 'i';
			case sys::EBK_J: return 'j';
			case sys::EBK_K: return 'k';
			case sys::EBK_L: return 'l';
			case sys::EBK_M: return 'm';
			case sys::EBK_N: return 'n';
			case sys::EBK_O: return 'o';
			case sys::EBK_P: return 'p';
			case sys::EBK_Q: return 'q';
			case sys::EBK_R: return 'r';
			case sys::EBK_S: return 's';
			case sys::EBK_T: return 't';
			case sys::EBK_U: return 'u';
			case sys::EBK_V: return 'v';
			case sys::EBK_W: return 'w';
			case sys::EBK_X: return 'x';
			case sys::EBK_Y: return 'y';
			case sys::EBK_Z: return 'z';
			default: return 0;
			}
		}
	}

	// ¹¦ÄÜ×Ö·û
	char getFuncChar(sys::BoardKey key)
	{
		switch (key)
		{
		case sys::EBK_SPACE: return ' ';
		default: return 0;
		}
	}

	void setControlKey(sys::BoardKey key)
	{
		if (key == sys::EBK_CAPITAL || key == sys::EBK_NUMLOCK)
		{
			_controlkeys[key] = !_controlkeys[key];
		}
	}
private:
	// ¼üÅÌ×ª×Ö·û
	std::map<sys::BoardKey, char> _keyChars;
	// ¿ØÖÆ¼ü
	std::map<sys::BoardKey, bool> _controlkeys;
};

#define G_KEYCHAR sys::Instance<KeyChar>::getInstance()

//////////////////////////////////////////////////////////////////////////
CtrlEditLabel::CtrlEditLabel()
{
	_ctrlText = CREATE_OBJECT(CtrlText);
	this->addChild(_ctrlText);
}

CtrlEditLabel::~CtrlEditLabel()
{
	_ctrlText->release();
}

void CtrlEditLabel::setString(const std::string& text)
{
	TextProtocol::setString(text);
	if (_ctrlText)
	{
		_ctrlText->setString(text);
	}
}

CtrlText* CtrlEditLabel::getCtrlText()
{
	return _ctrlText;
}

void CtrlEditLabel::onInputHand(sys::BoardKey key, sys::ButtonStatus type)
{
	if (type != sys::EBS_BUTTON_DOWN)
	{
		return;
	}

	G_KEYCHAR->setControlKey(key);

	if (key == sys::EBK_RETURN)
	{
		onInputKeyReturnHandler();
		return;
	}

	std::string text = this->getString();
	if (key == sys::EBK_BACK)
	{
		onInputKeyBackHandler();
		return;
	}

	char value = G_KEYCHAR->getChar(key);
	if (value)
	{
		onInputKeyCharHandler(value);
	}
}

void CtrlEditLabel::onInputKeyBackHandler()
{
	std::string text = this->getString();
	text = text.substr(0, text.size() - 1);
	this->setString(text.c_str());
}

void CtrlEditLabel::onInputKeyReturnHandler()
{
	this->setKeyboardEnable(false);
}

void CtrlEditLabel::onInputKeyCharHandler(char value)
{
	std::string text = this->getString();
	text.append(1, value);
	this->setString(text.c_str());
}
