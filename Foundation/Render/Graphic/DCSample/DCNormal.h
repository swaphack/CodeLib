#pragma once

#include "macros.h"

namespace render
{
	/**
	*	���Ʒ�������
	*/
	class DCNormal : public DrawCommand
	{
	public:
		sys::Vector* Normal;
	public:
		DCNormal();
		virtual ~DCNormal();
	public:
		virtual void draw();
	};
}