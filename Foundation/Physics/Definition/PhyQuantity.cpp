#include "PhyQuantity.h"
#include "SIUnit.h"

phy::PhyQuantity* phy::PhyQuantity::_instance = nullptr;

phy::PhyQuantity::PhyQuantity()
{
	this->init();
}

phy::PhyQuantity::~PhyQuantity()
{
	this->cleanup();
}

phy::PhyQuantity* phy::PhyQuantity::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new phy::PhyQuantity();
	}
	return _instance;
}

bool phy::PhyQuantity::addBaseUnit(const std::string& strName, const std::string& strSymbol, const std::string& strUnit)
{
	if (!SIQuantity::isLetter(strSymbol)) return false;

	auto it = _baseUnits.find(strName);
	if (it != _baseUnits.end()) return false;

	auto baseUnit = new SIBaseQuantity();
	baseUnit->setName(strName);
	baseUnit->setSymbol(strSymbol);
	baseUnit->setUnit(strUnit);
	_baseUnits[strName] = baseUnit;

	return true;
}

const phy::SIBaseQuantity* phy::PhyQuantity::getBaseUnit(const std::string& strName) const
{
	auto it = _baseUnits.find(strName);
	if (it != _baseUnits.end()) return nullptr;
	return it->second;
}

bool phy::PhyQuantity::addDerivedUnit(const std::string& strName, const std::string& strSymbol, const std::string& strUnit)
{
	if (!SIQuantity::isWord(strSymbol)) return false;

	auto it = _derivedUnits.find(strName);
	if (it != _derivedUnits.end()) return false;

	auto derivedUnit = new SIDerivedQuantity();
	derivedUnit->setName(strName);
	derivedUnit->setSymbol(strSymbol);
	derivedUnit->loadUnit(strUnit);
	_derivedUnits[strName] = derivedUnit;

	return true;
}

const phy::SIDerivedQuantity* phy::PhyQuantity::getDerivedUnit(const std::string& strName) const
{
	auto it = _derivedUnits.find(strName);
	if (it != _derivedUnits.end()) return nullptr;
	return it->second;
}

bool phy::PhyQuantity::deduceUnit(const std::string& strSymbol, std::vector<SIDerivedQuantity*>& vecDerivedUnits)
{
	return false;
}

void phy::PhyQuantity::init()
{
	this->addBaseUnit("Time", "t", "s"); // 时间
	this->addBaseUnit("Length", "l", "m"); // 长度
	this->addBaseUnit("Mass", "m", "kg"); // 质量
	this->addBaseUnit("Temperature", "T", "K"); // 温度
	this->addBaseUnit("Current Intensity", "I", "A"); // 电流
	this->addBaseUnit("Luminous Intensity", "Ix", "cd"); // 光照强度(烛光,Candela)
	this->addBaseUnit("Mole", "n", "mol");  // 摩尔

	//this->addDerivedUnit();
}

void phy::PhyQuantity::cleanup()
{
	for (auto& item : _baseUnits)
	{
		delete item.second;
	}
	for (auto& item : _derivedUnits)
	{
		delete item.second;
	}
	_baseUnits.clear();
	_derivedUnits.clear();
}
