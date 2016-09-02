#pragma once

#include "macros.h"

namespace render
{
	/**
	*	»æÖÆÃüÁî
	*/
	class DrawCommand
	{
	public:
		DrawCommand();
		virtual ~DrawCommand();
	public:
		/**
		*	»ñÈ¡ÃüÁîid
		*/
		int getID();
		/**
		*	ÉèÖÃÃüÁîid
		*/
		void setID(int id);
		/**
		*	»æÖÆ
		*/
		virtual void draw() = 0;
	private:
		// ÃüÁîid
		int _id;
	};
}