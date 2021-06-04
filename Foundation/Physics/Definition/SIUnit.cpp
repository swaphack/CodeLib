#include "SIUnit.h"

phy::SIUnit::SIUnit()
{
}

phy::SIUnit::~SIUnit()
{
}

const std::string& phy::SIUnit::getName() const
{
	return _name;
}

const std::string& phy::SIUnit::getSymbol() const
{
	return _symbol;
}

void phy::SIUnit::setSymbol(const std::string& sign)
{
	_symbol = sign;
}

void phy::SIUnit::setName(const std::string& name)
{
	_name = name;
}

phy::SIBaseUnit::SIBaseUnit()
{
}

phy::SIBaseUnit::~SIBaseUnit()
{
}

phy::SIDerivedUnit::SIDerivedUnit()
{
}

phy::SIDerivedUnit::~SIDerivedUnit()
{
}

phy::SIDerivedUnit& phy::SIDerivedUnit::combine(const std::string& sign, int power)
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

	calSign();

	return *this;
}

phy::SIDerivedUnit& phy::SIDerivedUnit::combine(const SIBaseUnit& unit, int power)
{
	this->combine(unit.getSymbol(), power);
	calSign();
	return *this;
}

phy::SIDerivedUnit& phy::SIDerivedUnit::combine(const SIDerivedUnit& unit, int power)
{
	for (const auto& item : unit.getUnitSymbol())
	{
		this->combine(item.first, item.second);
	}
	calSign();
	return *this;
}
void phy::SIDerivedUnit::clear()
{
	_unitSymbol.clear();
}

const std::map<std::string, int>& phy::SIDerivedUnit::getUnitSymbol() const
{
	return _unitSymbol;
}

void phy::SIDerivedUnit::calSign()
{
	std::string positiveSign;
	std::string nagativeSign;

	for (const auto& item : _unitSymbol)
	{
		if (item.second > 0)
		{
			if (item.second > 1) positiveSign += item.first + "^(" + std::to_string(item.second) + ")";
			else positiveSign += item.first;
		}
		else if (item.second < 0)
		{
			if (item.second < -1) nagativeSign += item.first + "^(" + std::to_string(abs(item.second)) + ")";
			else nagativeSign += item.first;
		}
	}


	if (nagativeSign.empty())
	{
		this->setSymbol(positiveSign);
	}
	else if (positiveSign.empty())
	{
		this->setSymbol("1 / " + nagativeSign);
	}
	else
	{
		this->setSymbol(positiveSign + "/" + nagativeSign);
	}
}
