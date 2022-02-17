#include "SIUnit.h"

phy::SIQuantity::SIQuantity()
{
}

phy::SIQuantity::~SIQuantity()
{
}

bool phy::SIQuantity::isNumber(const std::string& symbol)
{
	const char* pszSymbol = symbol.c_str();
	char* ptr = (char*)pszSymbol;
	while (*ptr != '\0')
	{
		char c = *ptr;
		if (c == '-' || (c >= '0' && c <= '9'))
		{// Êý×Ö
			ptr++;
			continue;
		}
		break;
	}
	return *ptr == '\0';
}

bool phy::SIQuantity::isLetter(const std::string& symbol)
{
	const char* pszSymbol = symbol.c_str();
	char* ptr = (char*)pszSymbol;
	while (*ptr != '\0')
	{
		char c = *ptr;
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		{// ×ÖÄ¸
			ptr++;
			continue;
		}
		break;
	}
	return *ptr == '\0';
}

bool phy::SIQuantity::isWord(const std::string& symbol)
{
	const char* pszSymbol = symbol.c_str();
	char* ptr = (char*)pszSymbol;
	while (*ptr != '\0')
	{
		char c = *ptr;
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		{// ×ÖÄ¸
			ptr++;
			continue;
		}
		if (c == '-' || (c >= '0' && c <= '9'))
		{// Êý×Ö
			ptr++;
			continue;
		}
		break;
	}
	return *ptr == '\0';
}

const std::string& phy::SIQuantity::getName() const
{
	return _name;
}

const std::string& phy::SIQuantity::getSymbol() const
{
	return _symbol;
}

void phy::SIQuantity::setSymbol(const std::string& sign)
{
	_symbol = sign;
}

const std::string& phy::SIQuantity::getUnit() const
{
	return _unit;
}

void phy::SIQuantity::setUnit(const std::string& unit)
{
	_unit = unit;
}

void phy::SIQuantity::setName(const std::string& name)
{
	_name = name;
}

phy::SIBaseQuantity::SIBaseQuantity()
{
}

phy::SIBaseQuantity::~SIBaseQuantity()
{
}

bool phy::SIBaseQuantity::isBaseUnit(const std::string& symbol)
{
	return isLetter(symbol);
}

phy::SIDerivedQuantity::SIDerivedQuantity()
{
}

phy::SIDerivedQuantity::~SIDerivedQuantity()
{
}

std::map<std::string, int> phy::SIDerivedQuantity::loadQuantityFromText(const std::string& unitSymbol)
{
	std::map<std::string, int> data;
	const char* pszSymbol = unitSymbol.c_str();
	char* ptr = (char*)pszSymbol;
	std::string exp;
	std::string word;

	std::string tempExp;
	std::string tempWord;
	while (*ptr != '\0')
	{
		char c = *ptr;
		if (c == '-' || (c >= '0' && c <= '9'))
		{// Êý×Ö
			if (!tempWord.empty())
			{
				word = tempWord;
				tempWord.clear();
			}
			tempExp.push_back(c);
		}
		else
		{// ·ûºÅ
			if (!tempExp.empty())
			{
				exp = tempExp;
				tempExp.clear();
				if (!word.empty())
				{
					data[word] = atoi(exp.c_str());
				}
			}
			tempWord.push_back(c);
		}
		ptr++;
	}

	return data;
}

std::string phy::SIDerivedQuantity::saveQuantityToText(const std::map<std::string, int>& units)
{
	std::string symbol;

	for (const auto& item : units)
	{
		symbol.append(item.first).append(std::to_string(item.second));
	}

	return symbol;
}

phy::SIDerivedQuantity& phy::SIDerivedQuantity::loadUnit(const std::string& unitSymbol)
{
	_unitSymbol = loadQuantityFromText(unitSymbol);
	setUnit(unitSymbol);
	return *this;
}

phy::SIDerivedQuantity& phy::SIDerivedQuantity::combine(const std::string& sign, int power)
{
	combineUnit(sign, power);
	calSign();
	return *this;
}

phy::SIDerivedQuantity& phy::SIDerivedQuantity::combine(const SIBaseQuantity& unit, int power)
{
	this->combineUnit(unit.getSymbol(), power);
	calSign();
	return *this;
}

phy::SIDerivedQuantity& phy::SIDerivedQuantity::combine(const SIDerivedQuantity& unit, int power)
{
	for (const auto& item : unit.getUnitSymbol())
	{
		this->combineUnit(item.first, item.second);
	}
	calSign();
	return *this;
}
void phy::SIDerivedQuantity::clear()
{
	_unitSymbol.clear();
	calSign();
}

const std::map<std::string, int>& phy::SIDerivedQuantity::getUnitSymbol() const
{
	return _unitSymbol;
}

void phy::SIDerivedQuantity::combineUnit(const std::string& sign, int power)
{
	auto it = _unitSymbol.find(sign);
	if (it == _unitSymbol.end())
	{
		_unitSymbol.insert(std::make_pair(sign, power));
	}
	else
	{
		it->second += power;

		if (it->second == 0)
		{
			_unitSymbol.erase(it);
		}
	}
}

void phy::SIDerivedQuantity::calSign()
{
	std::string symbol = saveQuantityToText(_unitSymbol);

	this->setSymbol(symbol);
}
