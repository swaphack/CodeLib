#pragma once

#include "Common/DrawNode/DrawNode3D.h"

namespace render
{
	/**
	*	网格
	*/
	class Grid : public DrawNode3D
	{
	public:
		Grid();
		virtual ~Grid();
	public:
		virtual bool init();
	public:
		/**
		*	设置方形宽度
		*/
		void setGridWidth(int width);
		/**
		*	设置方形宽度
		*/
		int getGridWidth() const;
	protected:
		void onGridChange();
	protected:
		int _gridWidth = 10;
	};
}