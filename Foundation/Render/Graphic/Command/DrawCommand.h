#pragma once

#include "macros.h"

namespace render
{
	/**
	*	��������
	*/
	class DrawCommand
	{
	public:
		DrawCommand();
		virtual ~DrawCommand();
	public:
		/**
		*	��ȡ����id
		*/
		int getID();
		/**
		*	��������id
		*/
		void setID(int id);
		/**
		*	����
		*/
		virtual void draw() = 0;
	private:
		// ����id
		int _id;
	};
}