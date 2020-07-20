#pragma once

#include "Common/DrawNode/MultiDrawNode.h"

namespace render
{
	class MultiModel : public MultiDrawNode
	{
	public:
		MultiModel();
		virtual ~MultiModel();
	public:
		virtual bool init();
	protected:
	private:
	};
}