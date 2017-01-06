#pragma once

#include "../UIProxy.h"

namespace ui
{
	// ×¢²á½âÎö
#define REGISTER_LOAER_PARSER(NAME) \
	virtual void registerNodeParser() \
	{ \
	G_UIPROXY->registerNodeParser(#NAME, this); \
	}

}