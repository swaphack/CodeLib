#include "Person.h"

using namespace game;


Person::Person()
:m_gender(0)
, m_birthday(0)
, m_countryID(0)
, m_clubID(0)
, m_teamID(0)
{
	m_propertySheet = new PropertySheet();
}

Person::~Person()
{
	delete m_propertySheet;
}

void Person::setGender(int nGender)
{
	m_gender = nGender;
}

int Person::getGender() const
{
	return m_gender;
}

void Person::setBirthDay(int nBirthDay)
{
	m_birthday = nBirthDay;
}

int Person::getBirthDay() const
{
	return m_birthday;
}

void Person::setCountryID(int nCountryID)
{
	m_countryID = nCountryID;
}

int Person::getCountryID() const
{
	return m_countryID;
}

void Person::setClubID(int nClubID)
{
	m_clubID = nClubID;
}

int Person::getClubID() const
{
	return m_clubID;
}

void Person::setTeamID(int nTeamID)
{
	m_teamID = nTeamID;
}

int Person::getTeamID() const
{
	return m_teamID;
}

const IPropertySheet* Person::getProperty() const
{
	return m_propertySheet;
}

void Person::onBorn()
{

}

void Person::onDead()
{

}
