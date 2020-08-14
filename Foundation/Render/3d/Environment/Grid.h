#pragma once

#include "Common/DrawNode/DrawNode.h"

namespace render
{
	/**
	*	网格
	*/
	class Grid : public DrawNode
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
		int _gradWidth = 10;
	};
}