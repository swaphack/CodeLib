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
		case sys::BoardKey::K0: return '0';
		case sys::BoardKey::K1: return '1';
		case sys::BoardKey::K2: return '2';
		case sys::BoardKey::K3: return '3';
		case sys::BoardKey::K4: return '4';
		case sys::BoardKey::K5: return '5';
		case sys::BoardKey::K6: return '6';
		case sys::BoardKey::K7: return '7';
		case sys::BoardKey::K8: return '8';
		case sys::BoardKey::K9: return '9';
		default: return 0;
		}
	}
	// Êý×Ö°åÊý×Ö
	char getPadNumber(sys::BoardKey key)
	{
		if (_controlkeys[sys::BoardKey::KNUMLOCK] == false)
		{
			return 0;
		}
		switch (key)
		{
			case sys::BoardKey::KNUMPAD0: return '0';
			case sys::BoardKey::KNUMPAD1: return '1';
			case sys::BoardKey::KNUMPAD2: return '2';
			case sys::BoardKey::KNUMPAD3: return '3';
			case sys::BoardKey::KNUMPAD4: return '4';
			case sys::BoardKey::KNUMPAD5: return '5';
			case sys::BoardKey::KNUMPAD6: return '6';
			case sys::BoardKey::KNUMPAD7: return '7';
			case sys::BoardKey::KNUMPAD8: return '8';
			case sys::BoardKey::KNUMPAD9: return '9';
			default: return 0;
		}
	}

	// ×Ö·û
	char getLetter(sys::BoardKey key)
	{
		if (_controlkeys[sys::BoardKey::KCAPITAL])
		{
			switch (key)
			{
			case sys::BoardKey::KA: return 'A';
			case sys::BoardKey::KB: return 'B';
			case sys::BoardKey::KC: return 'C';
			case sys::BoardKey::KD: return 'D';
			case sys::BoardKey::KE: return 'E';
			case sys::BoardKey::KF: return 'F';
			case sys::BoardKey::KG: return 'G';
			case sys::BoardKey::KH: return 'H';
			case sys::BoardKey::KI: return 'I';
			case sys::BoardKey::KJ: return 'J';
			case sys::BoardKey::KK: return 'K';
			case sys::BoardKey::KL: return 'L';
			case sys::BoardKey::KM: return 'M';
			case sys::BoardKey::KN: return 'N';
			case sys::BoardKey::KO: return 'O';
			case sys::BoardKey::KP: return 'P';
			case sys::BoardKey::KQ: return 'Q';
			case sys::BoardKey::KR: return 'R';
			case sys::BoardKey::KS: return 'S';
			case sys::BoardKey::KT: return 'T';
			case sys::BoardKey::KU: return 'U';
			case sys::BoardKey::KV: return 'V';
			case sys::BoardKey::KW: return 'W';
			case sys::BoardKey::KX: return 'X';
			case sys::BoardKey::KY: return 'Y';
			case sys::BoardKey::KZ: return 'Z';
			default: return 0;
			}
		}
		else
		{
			switch (key)
			{
			case sys::BoardKey::KA: return 'a';
			case sys::BoardKey::KB: return 'b';
			case sys::BoardKey::KC: return 'c';
			case sys::BoardKey::KD: return 'd';
			case sys::BoardKey::KE: return 'e';
			case sys::BoardKey::KF: return 'f';
			case sys::BoardKey::KG: return 'g';
			case sys::BoardKey::KH: return 'h';
			case sys::BoardKey::KI: return 'i';
			case sys::BoardKey::KJ: return 'j';
			case sys::BoardKey::KK: return 'k';
			case sys::BoardKey::KL: return 'l';
			case sys::BoardKey::KM: return 'm';
			case sys::BoardKey::KN: return 'n';
			case sys::BoardKey::KO: return 'o';
			case sys::BoardKey::KP: return 'p';
			case sys::BoardKey::KQ: return 'q';
			case sys::BoardKey::KR: return 'r';
			case sys::BoardKey::KS: return 's';
			case sys::BoardKey::KT: return 't';
			case sys::BoardKey::KU: return 'u';
			case sys::BoardKey::KV: return 'v';
			case sys::BoardKey::KW: return 'w';
			case sys::BoardKey::KX: return 'x';
			case sys::BoardKey::KY: return 'y';
			case sys::BoardKey::KZ: return 'z';
			default: return 0;
			}
		}
	}

	// ¹¦ÄÜ×Ö·û
	char getFuncChar(sys::BoardKey key)
	{
		switch (key)
		{
		case sys::BoardKey::KSPACE: return ' ';
		default: return 0;
		}
	}

	void setControlKey(sys::BoardKey key)
	{
		if (key == sys::BoardKey::KCAPITAL || key == sys::BoardKey::KNUMLOCK)
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
	if (type != sys::ButtonStatus::BUTTON_DOWN)
	{
		return;
	}

	G_KEYCHAR->setControlKey(key);

	if (key == sys::BoardKey::KRETURN)
	{
		onInputKeyReturnHandler();
		return;
	}

	std::string text = this->getString();
	if (key == sys::BoardKey::KBACK)
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
