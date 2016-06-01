#pragma once

namespace slg
{
	// 等级
	class LevelProtocol
	{
	public:
		LevelProtocol();
		virtual ~LevelProtocol();
	public:
		void setLevel(int level);
		int getLevel();

		void setMaxLevel(int maxLevel);
		int getMaxLevel();

		void setExp(int exp);
		int getExp();

		void setMaxExp(int maxExp);
		int getMaxExp();
	private:
		// 当前等级
		int _level;
		// 当前经验
		int _exp;
		// 最大等级
		int _maxLevel;
		// 最大经验
		int _maxExp;
	};
}