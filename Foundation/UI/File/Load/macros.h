#pragma once

#include "../macros.h"

#include "../Parse/import.h"

namespace ui
{
	// LOAD  ATTRIBUTE
	/**
	*	设置名称
	*/
#define LOAD_NAME() \
	GET_WIDGET->setName(getNodeProperty()->getName());
	/**
	*	设置属性
	*/
#define LOAD_ATTRIBUTE(NAME, FUNC, TEMP) \
	if (getNodeProperty()->getAttribute(NAME, TEMP)) GET_WIDGET->FUNC(TEMP);
	/**
	*	设置属性类型为字符串
	*/
#define LOAD_STRING_ATTRIBUTE(NAME, FUNC, TEMP) \
	if (getNodeProperty()->getAttribute(NAME, TEMP)) GET_WIDGET->FUNC(TEMP.c_str());
	/**
	*	设置属性类型为指定类型
	*/
#define LOAD_CAST_ATTRIBUTE(NAME, FUNC, TEMP, TYPE) \
	if (getNodeProperty()->getAttribute(NAME, TEMP)) GET_WIDGET->FUNC(static_cast<TYPE>(TEMP));

	// SAVE ATTRIBUTE
	/**
	*	保存名称
	*/
#define SAVE_NAME() \
	getNodeProperty()->setName(GET_WIDGET->getName());
	/**
	*	保存属性值
	*/
#define SAVE_ATTRIBUTE(NAME, FUNC) \
	getNodeProperty()->setAttribute(NAME, GET_WIDGET->FUNC());
	/**
	*	保存属性类型为指定类型的值
	*/
#define SAVE_CAST_ATTRIBUTE(NAME, FUNC, TYPE)\
	getNodeProperty()->setAttribute(NAME, static_cast<TYPE>(GET_WIDGET->FUNC()));

	// CHANGE ATTRIBUTE
#define ADD_ATTRIBUTE_CHANGED(NAME, FUNC) \
	SAVE_ATTRIBUTE(NAME, FUNC) \

}
