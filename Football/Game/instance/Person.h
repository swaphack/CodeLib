#pragma once

#include "../interface/IPerson.h"

#include "PropertySheet.h"

namespace game
{
	class Person : public IPerson
	{
	public:
		Person();
		virtual ~Person();
	public:
		void setGender(int nGender);

		virtual int getGender() const;

		void setBirthDay(int nBirthDay);

		virtual int getBirthDay() const;

		void setCountryID(int nCountryID);

		virtual int getCountryID() const;

		void setClubID(int nClubID);

		virtual int getClubID() const;

		void setTeamID(int nTeamID);

		virtual int getTeamID() const;

		virtual const IPropertySheet* getProperty() const;

		virtual void onBorn();

		virtual void onDead();
	private:
		int m_gender;
		int m_birthday;
		int m_countryID;
		int m_clubID;
		int m_teamID;
		IPropertySheet* m_propertySheet;
	};
}