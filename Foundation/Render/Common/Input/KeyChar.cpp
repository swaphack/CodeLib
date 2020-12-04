#include "KeyChar.h"

render::KeyChar::KeyChar()
{

}

render::KeyChar::~KeyChar()
{

}

sys::BoardKey render::KeyChar::getKey(uint8_t ascii)
{
	/*
	if (value == 20) return sys::BoardKey::KSPACE;
	else if (value >= 65 && value <= 90) return (sys::BoardKey)((uint8_t)sys::BoardKey::KA + value - 65);
	else if (value >= 97 && value <= 122) return (sys::BoardKey)((uint8_t)sys::BoardKey::KA + value - 97);
	else if (value >= 48 && value <= 57) return (sys::BoardKey)((uint8_t)sys::BoardKey::K0 + value - 48);
	*/

	uint8_t value = 0;
	if (ascii >= 'A' && ascii <= 'Z')
	{
		value = (0xA000 | ascii);
	}
	else if (ascii >= 'a' && ascii <= 'z')
	{
		value = (0xE000 | (ascii - 0x20));
	}
	else if (ascii >= '0' && ascii <= '9')
	{
		value = (0x2000 | (ascii));
	}
	else
	{
		switch (ascii)
		{
		case 0x0A: value = (0X2000 | VK_RETURN);		break;
		case 0x20: value = (0x2000 | VK_SPACE);			break;
		case 0x21: value = (0x6000 | 0x31);				break;
		case 0x22: value = (0x6000 | VK_OEM_7);			break;
		case 0x23: value = (0x6000 | 0x33);				break;
		case 0x24: value = (0x6000 | 0x34);				break;
		case 0x25: value = (0x6000 | 0x35);				break;
		case 0x26: value = (0x6000 | 0x37);				break;
		case 0x27: value = (0x2000 | VK_OEM_7);			break;
		case 0x28: value = (0x6000 | 0x39);				break;
		case 0x29: value = (0x6000 | 0x30);				break;
		case 0x2A: value = (0x6000 | 0x38);				break;
		case 0x2B: value = (0x6000 | VK_OEM_PLUS);		break;
		case 0x2C: value = (0x2000 | VK_OEM_COMMA);		break;
		case 0x2D: value = (0x2000 | VK_OEM_MINUS);		break;
		case 0x2E: value = (0x2000 | VK_OEM_PERIOD);	break;
		case 0x2F: value = (0x2000 | VK_OEM_2);			break;
		case 0x3A: value = (0x6000 | VK_OEM_1);			break;
		case 0x3B: value = (0x2000 | VK_OEM_1);			break;
		case 0x3C: value = (0x6000 | VK_OEM_COMMA);		break;
		case 0x3D: value = (0x2000 | VK_OEM_PLUS);		break;
		case 0x3E: value = (0x6000 | VK_OEM_PERIOD);	break;
		case 0x3F: value = (0x6000 | VK_OEM_2);			break;
		case 0x40: value = (0x6000 | 0x32);				break;
		case 0x5B: value = (0x2000 | VK_OEM_4);			break;
		case 0x5C: value = (0x2000 | VK_OEM_5);			break;
		case 0x5D: value = (0x2000 | VK_OEM_6);			break;
		case 0x5E: value = (0x6000 | 0x36);				break;
		case 0x5F: value = (0x6000 | VK_OEM_MINUS);		break;
		case 0x60: value = (0x2000 | VK_OEM_3);			break;
		case 0x7B: value = (0x6000 | VK_OEM_4);			break;
		case 0x7C: value = (0x6000 | VK_OEM_5);			break;
		case 0x7D: value = (0x6000 | VK_OEM_6);			break;
		case 0x7E: value = (0x6000 | VK_OEM_3);			break;
		default:value = (0x0000 & ascii);
		}
	}


	return (sys::BoardKey)value;
}

char render::KeyChar::getChar(sys::BoardKey key)
{
	char value = getPadNumberChar(key);
	if (value != 0) return value;

	value = getNumberChar(key);
	if (value != 0) return value;

	value = getLetterChar(key);
	if (value != 0) return value;

	value = getShiftChar(key);
	if (value != 0) return value;

	value = getFuncChar(key);
	if (value != 0) return value;
	return (char)0;
}

char render::KeyChar::getNumberChar(sys::BoardKey key)
{
	if (isShiftEnabled())
	{
		switch (key)
		{
		case sys::BoardKey::K0: return ')';
		case sys::BoardKey::K1: return '!';
		case sys::BoardKey::K2: return '@';
		case sys::BoardKey::K3: return '#';
		case sys::BoardKey::K4: return '$';
		case sys::BoardKey::K5: return '%';
		case sys::BoardKey::K6: return '^';
		case sys::BoardKey::K7: return '&';
		case sys::BoardKey::K8: return '*';
		case sys::BoardKey::K9: return '(';
		default: break;
		}
	}
	else
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
		default: break;
		}
	}

	return 0;
}

char render::KeyChar::getPadNumberChar(sys::BoardKey key)
{
	switch (key)
	{
	case sys::BoardKey::KMULTIPLY: return '*';
	case sys::BoardKey::KADD: return '+';
	case sys::BoardKey::KSUBTRACT: return '-';
	case sys::BoardKey::KDIVIDE: return '/';
	default:
		break;
	}

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
	case sys::BoardKey::KDECIMAL: return '.';
	default: return 0;
	}
}


char render::KeyChar::getLetterChar(sys::BoardKey key)
{
	bool big = _controlkeys[sys::BoardKey::KCAPITAL];
	if (isShiftEnabled()) big = !big;

	if (big)
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
		default: break;
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
		default: break;
		}
	}
	return 0;
}

char render::KeyChar::getShiftChar(sys::BoardKey key)
{
	if (isShiftEnabled())
	{
		switch (key)
		{

		case sys::BoardKey::KOEM_MINUS: return '_';
		case sys::BoardKey::KOEM_PLUS: return '+';
		case sys::BoardKey::KOEM_COMMA: return '<';
		case sys::BoardKey::KOEM_PERIOD: return '>';
		case sys::BoardKey::KOEM_1: return ':';
		case sys::BoardKey::KOEM_2: return '?';
		case sys::BoardKey::KOEM_3: return '~';
		case sys::BoardKey::KOEM_4: return '{';
		case sys::BoardKey::KOEM_5: return '|';
		case sys::BoardKey::KOEM_6: return '}';
		case sys::BoardKey::KOEM_7: return '"';
		default: break;
		}
	}
	else
	{
		switch (key)
		{

		case sys::BoardKey::KOEM_MINUS: return '-';
		case sys::BoardKey::KOEM_PLUS: return '=';
		case sys::BoardKey::KOEM_COMMA: return ',';
		case sys::BoardKey::KOEM_PERIOD: return '.';
		case sys::BoardKey::KOEM_1: return ';';
		case sys::BoardKey::KOEM_2: return '/';
		case sys::BoardKey::KOEM_3: return '`';
		case sys::BoardKey::KOEM_4: return '[';
		case sys::BoardKey::KOEM_5: return '\\';
		case sys::BoardKey::KOEM_6: return ']';
		case sys::BoardKey::KOEM_7: return '\'';
		default: break;
		}
	}
	return 0;
}

char render::KeyChar::getFuncChar(sys::BoardKey key)
{
	switch (key)
	{
	case sys::BoardKey::KSPACE: return ' ';
	default: return 0;
	}
}

void render::KeyChar::setControlKey(sys::BoardKey key)
{
	if (key == sys::BoardKey::KCAPITAL || key == sys::BoardKey::KNUMLOCK)
	{
		auto it = _controlkeys.find(key);
		if (it == _controlkeys.end())
		{
			_controlkeys[key] = true;
		}
		else
		{
			_controlkeys[key] = !_controlkeys[key];
		}
	}
}

void render::KeyChar::setShiftEnable(bool enable)
{
	_enableShift = enable;
}

bool render::KeyChar::isShiftEnabled() const
{
	return _enableShift;
}

void render::KeyChar::setControlEnable(bool enable)
{
	_enableControl = enable;
}

bool render::KeyChar::isControlEnabled() const
{
	return _enableControl;
}

void render::KeyChar::setAltEnable(bool enable)
{
	_enableAlt = enable;
}

bool render::KeyChar::isAltEnabled() const
{
	return _enableAlt;
}
