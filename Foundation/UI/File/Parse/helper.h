#pragma once

#include "../UIProxy.h"

namespace ui
{
	// ע�����
#define REGISTER_LOAER_PARSER(NAME) \
	virtual void registerNodeParser() \
	{ \
	G_UIPROXY->registerNodeParser(#NAME, this); \
	}

}