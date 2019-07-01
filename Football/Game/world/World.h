#pragma once

namespace game
{
	class HumanSheet;
	class CountrySheet;
	/**
	*	世界
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
		*	人类
		*/
		const HumanSheet* getHumanSheet() const;
		/**
		*	国家
		*/
		const CountrySheet* getCountrySheet() const;

		void update();
	private:
		HumanSheet* m_humanSheet;
		CountrySheet* m_countrySheet;
	};
}