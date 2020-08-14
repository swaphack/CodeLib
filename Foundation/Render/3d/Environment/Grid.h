#pragma once

#include "Common/DrawNode/DrawNode.h"

namespace render
{
	/**
	*	����
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
		*	���÷��ο��
		*/
		void setGridWidth(int width);
		/**
		*	���÷��ο��
		*/
		int getGridWidth() const;
	protected:
		void onGridChange();
	protected:
		int _gradWidth = 10;
	};
}