#pragma once

#include "../macros.h"

#include "../Parse/import.h"

namespace ui
{
	// LOAD  ATTRIBUTE
#define LOAD_NAME() \
	GET_WIDGET->setName(getNodeProperty()->getName());
#define LOAD_ATTRIBUTE(NAME, FUNC, TEMP) \
	if (getNodeProperty()->getAttribute(NAME, TEMP)) GET_WIDGET->FUNC(TEMP);
#define LOAD_STRING_ATTRIBUTE(NAME, FUNC, TEMP) \
	if (getNodeProperty()->getAttribute(NAME, TEMP)) GET_WIDGET->FUNC(TEMP.c_str());
#define LOAD_CAST_ATTRIBUTE(NAME, FUNC, TEMP, TYPE) \
	if (getNodeProperty()->getAttribute(NAME, TEMP)) GET_WIDGET->FUNC(static_cast<TYPE>(TEMP));

	// SAVE ATTRIBUTE
#define SAVE_NAME() \
	getNodeProperty()->setName(GET_WIDGET->getName());
#define SAVE_ATTRIBUTE(NAME, FUNC) \
	getNodeProperty()->setAttribute(NAME, GET_WIDGET->FUNC());
#define SAVE_CAST_ATTRIBUTE(NAME, FUNC, TYPE)\
	getNodeProperty()->setAttribute(NAME, static_cast<TYPE>(GET_WIDGET->FUNC()));

	// CHANGE ATTRIBUTE
#define ADD_ATTRIBUTE_CHANGED(NAME, FUNC) \
	SAVE_ATTRIBUTE(NAME, FUNC) \

}
