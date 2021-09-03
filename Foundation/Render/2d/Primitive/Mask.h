#pragma once

#include "PrimitiveNode.h"
namespace render
{
	// узуж
	class Mask : public PrimitiveNode
	{
	public:
		Mask();
		virtual ~Mask();
	public:
		virtual bool init();
	protected:
		void onMaskBodyChange();
	};
}