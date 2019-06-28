#pragma once

namespace game
{
	/**
	*	排行
	*/
	class IRank
	{
	public:
		virtual ~IRank() {}
	public:
		/**
		*	参与排名数
		*/
		virtual int count() const;
		/**
		*	重置排名，初始化
		*/
		virtual void reset() const;
		/**
		*	更新排名
		*/
		virtual void update() const;
		/**
		*	获取指定编号的排名
		*/
		virtual int getPosition(int nID) const;
		/**
		*	获取指定位置的排名id
		*/
		virtual int getID(int nPosition) const;
	};
}