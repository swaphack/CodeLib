#pragma once

namespace game
{
	class HumanSheet;
	class CountrySheet;
	/**
	*	����
	*/
	class World
	{
	private:
		World();
	public:
		virtual ~World();
	public:
		static World* getInstance();
		/**
		*	����
		*/
		const HumanSheet* getHumanSheet() const;
		/**
		*	����
		*/
		const CountrySheet* getCountrySheet() const;

		void update();
	private:
		HumanSheet* m_humanSheet;
		CountrySheet* m_countrySheet;
	};
}