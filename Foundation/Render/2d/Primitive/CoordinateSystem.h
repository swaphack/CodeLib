#pragma once

#include "PrimitiveNode.h"

namespace render
{
	/**
	*	����ϵ
	*/
	class CoordinateSystem : public PrimitiveNode
	{
	public:
		CoordinateSystem();
		virtual ~CoordinateSystem();
	public:
		virtual bool init();
	public:
		/**
		*	��С�ı�
		*/
		virtual void onDrawNode2DBodyChange();
		/**
		*	��ɫ�ı�
		*/
		virtual void onDrawNode2DColorChange();
	protected:
	private:
	};
}
