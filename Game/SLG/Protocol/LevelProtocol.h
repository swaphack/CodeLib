#pragma once

namespace slg
{
	// �ȼ�
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
		// ��ǰ�ȼ�
		int _level;
		// ��ǰ����
		int _exp;
		// ���ȼ�
		int _maxLevel;
		// �����
		int _maxExp;
	};
}