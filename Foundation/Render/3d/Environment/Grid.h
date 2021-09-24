#pragma once

#include "Common/DrawNode/DrawNode3D.h"

namespace render
{
	/**
	*	����
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
		int _gridWidth = 10;
	};
}