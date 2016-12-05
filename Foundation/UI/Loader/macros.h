#pragma once

#include "../UIBase/import.h"
#include "../Parser/import.h"

namespace ui
{
	// LOAD  ATTRIBUTE
#define LOAD_NAME() \
	GET_NODE->setName(getNodeProperty()->getName());
#define LOAD_ATTRIBUTE(NAME, FUNC, TEMP) \
	if (getNodeProperty()->getAttribute(NAME, TEMP)) GET_NODE->FUNC(TEMP);
#define LOAD_STRING_ATTRIBUTE(NAME, FUNC, TEMP) \
	if (getNodeProperty()->getAttribute(NAME, TEMP)) GET_NODE->FUNC(TEMP.c_str());
#define LOAD_CAST_ATTRIBUTE(NAME, FUNC, TEMP, TYPE) \
	if (getNodeProperty()->getAttribute(NAME, TEMP)) GET_NODE->FUNC(static_cast<TYPE>(TEMP));

	// SAVE ATTRIBUTE
#define SAVE_NAME() \
	getNodeProperty()->setName(GET_NODE->getName());
#define SAVE_ATTRIBUTE(NAME, FUNC) \
	getNodeProperty()->setAttribute(NAME, GET_NODE->FUNC());
#define SAVE_CAST_ATTRIBUTE(NAME, FUNC, TYPE)\
	getNodeProperty()->setAttribute(NAME, static_cast<TYPE>(GET_NODE->FUNC()));

	// CHANGE ATTRIBUTE
#define ADD_ATTRIBUTE_CHANGED(NAME, FUNC) \
	SAVE_ATTRIBUTE(NAME, FUNC) \

}
