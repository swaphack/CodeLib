#include "Polynomial.h"
#include <sstream>
#include <algorithm>

using namespace math;

PolynomialTerm::PolynomialTerm()
{

}

PolynomialTerm::PolynomialTerm(const PolynomialTerm& term)
{
	this->setCoefficient(term.getCoefficient());
	this->setExponentials(term.getExponentials());
}


PolynomialTerm::PolynomialTerm(float coefficient, const std::map<int, float>& exponentials)
{
	this->setCoefficient(coefficient);
	this->setExponentials(exponentials);
}

PolynomialTerm::~PolynomialTerm()
{

}

bool PolynomialTerm::isNull() const
{
	return _coefficient == 0 || _mapExponentials.size() == 0;
}

bool PolynomialTerm::hasSameExponentials(const PolynomialTerm& value)
{
	if (value.isNull())
	{
		return false;
	}
	if (_mapExponentials.size() != value.getExponentials().size())
	{
		return false;
	}

	for (auto item : value.getExponentials())
	{
		if (_mapExponentials.find(item.first) == _mapExponentials.end())
		{
			return false;
		}

		if (_mapExponentials[item.first] != item.second)
		{
			return false;
		}
	}

	return true;
}

bool PolynomialTerm::operator!=(const PolynomialTerm& value)
{
	return getCoefficient() != value.getCoefficient() || getID() != value.getID();
}

bool PolynomialTerm::operator==(const PolynomialTerm& value)
{
	return getCoefficient() == value.getCoefficient() && getID() == value.getID();
}

PolynomialTerm PolynomialTerm::operator*(const PolynomialTerm& value)
{
	float k = getCoefficient() * value.getCoefficient();
	std::map<int, float> mapTerm = value.getExponentials();
	for (auto item : _mapExponentials)
	{
		if (mapTerm.find(item.first) == mapTerm.end())
		{
			mapTerm[item.first] = item.second;
		}
		else
		{
			mapTerm[item.first] += item.second;
		}
	}

	return PolynomialTerm(k, mapTerm);
}

PolynomialTerm PolynomialTerm::operator-(const PolynomialTerm& value)
{
	if (this->getID() != value.getID())
	{
		return PolynomialTerm();
	}

	float k = getCoefficient() - value.getCoefficient();
	if (k == 0)
	{
		return PolynomialTerm();
	}

	return PolynomialTerm(k, _mapExponentials);
}

PolynomialTerm PolynomialTerm::operator+(const PolynomialTerm& value)
{
	if (this->getID() != value.getID())
	{
		return PolynomialTerm();
	}

	float k = getCoefficient() + value.getCoefficient();
	if (k == 0)
	{
		return PolynomialTerm();
	}

	return PolynomialTerm(k, _mapExponentials);
}

uint32_t getSDBMHash(const char *str)
{
	uint32_t hash = 0;

	while (*str)
	{
		// equivalent to: hash = 65599*hash + (*str++);
		hash = (*str++) + (hash << 6) + (hash << 16) - hash;
	}

	return (hash & 0x7FFFFFFF);
}

int PolynomialTerm::generateID()
{
	std::vector<int> vecID;
	std::map<int, float> exponentials = getExponentials();
	for (auto item : exponentials)
	{	
		vecID.push_back(item.first);
	}

	std::sort(vecID.begin(), vecID.end());

	std::ostringstream stream;
	for (auto item : vecID)
	{
		stream << item;
		stream << ",";
		stream << exponentials[item];
		stream << ";";
	}

	std::string value = stream.str();

	return getSDBMHash(value.c_str());
}

int PolynomialTerm::getID() const
{
	return _id;
}

float PolynomialTerm::getCoefficient() const
{
	return _coefficient;
}

void PolynomialTerm::setCoefficient(float value)
{
	_coefficient = value;
}

const std::map<int, float>& PolynomialTerm::getExponentials() const
{
	return _mapExponentials;
}

void PolynomialTerm::setExponentials(const std::map<int, float>& value)
{
	_mapExponentials = value;
	_id = this->generateID();
}

//////////////////////////////////////////////////////////////////////////
Polynomial::Polynomial()
{

}

Polynomial::Polynomial(const Polynomial& value)
{
	_mapTerm = value.getTerms();
}

Polynomial::Polynomial(const std::vector<PolynomialTerm>& vecTerm)
{
	for (auto item : vecTerm)
	{
		int id = item.getID();
		_mapTerm[id] = item;
	}
}

Polynomial::~Polynomial()
{

}

void Polynomial::setCoefficientOfTerm(int id, float coefficient)
{
	if (!hasTerm(id))
	{
		return;
	}
	_mapTerm[id].setCoefficient(coefficient);
}

float Polynomial::getCoefficientOfTerm(int id)
{
	auto it = _mapTerm.find(id);
	if (it == _mapTerm.end())
	{
		return 0;
	}

	return it->second.getCoefficient();
}

void Polynomial::removeTerm(int id)
{
	_mapTerm.erase(id);
}

bool Polynomial::hasTerm(int id)
{
	return _mapTerm.find(id) != _mapTerm.end();
}

void Polynomial::setTerms(const std::map<int, PolynomialTerm>& mapTerm)
{
	_mapTerm = mapTerm;
}

const std::map<int, PolynomialTerm>& Polynomial::getTerms() const
{
	return _mapTerm;
}

PolynomialTerm Polynomial::getTerm(int id)
{
	if (_mapTerm.find(id) == _mapTerm.end())
	{
		return PolynomialTerm();
	}
	return _mapTerm[id];
}

Polynomial Polynomial::operator+(const Polynomial& value)
{
	std::map<int, PolynomialTerm> mapTerm = _mapTerm;
	for (auto item : value.getTerms())
	{
		int id = item.first;
		auto it = mapTerm.find(id);
		if (it == mapTerm.end())
		{
			mapTerm[id] = item.second;
		}
		else
		{
			PolynomialTerm term = item.second + mapTerm[id];
			if (term.isNull())
			{
				_mapTerm.erase(id);
			}
			else
			{
				_mapTerm[id] = term;
			}
		}
	}

	std::vector<PolynomialTerm> vecTerm;
	for (auto item : mapTerm)
	{
		vecTerm.push_back(item.second);
	}

	return Polynomial(vecTerm);
}

Polynomial Polynomial::operator-(const Polynomial& value)
{
	std::map<int, PolynomialTerm> mapTerm = _mapTerm;
	for (auto item : value.getTerms())
	{
		int id = item.first;
		auto it = mapTerm.find(id);
		if (it == mapTerm.end())
		{
			float k = -item.second.getCoefficient();
			mapTerm[id] = item.second;
			mapTerm[id].setCoefficient(k);
		}
		else
		{
			PolynomialTerm term = item.second - mapTerm[id];
			if (term.isNull())
			{
				_mapTerm.erase(id);
			}
			else
			{
				_mapTerm[id] = term;
			}
		}
	}

	std::vector<PolynomialTerm> vecTerm;
	for (auto item : mapTerm)
	{
		vecTerm.push_back(item.second);
	}

	return Polynomial(vecTerm);
}

Polynomial Polynomial::operator*(const Polynomial& value)
{
	std::map<int, PolynomialTerm> mapTerm;
	for (auto item0 : _mapTerm)
	{
		for (auto item1 : value.getTerms())
		{
			PolynomialTerm term = item0.second * item1.second;
			if (term.isNull())
			{
				continue;
			}
			int id = term.getID();
			if (mapTerm.find(id) == mapTerm.end())
			{
				mapTerm[id] = term;
			}
			else
			{
				float k = mapTerm[id].getCoefficient() + term.getCoefficient();
				if (k == 0)
				{
					_mapTerm.erase(id);
				}
				else
				{
					mapTerm[id].setCoefficient(k);
				}
			}
		}
	}
	std::vector<PolynomialTerm> vecTerm;
	for (auto item : mapTerm)
	{
		vecTerm.push_back(item.second);
	}
	return Polynomial(vecTerm);
}
