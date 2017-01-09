#pragma once

#include "../macros.h"

#include "../Parse/import.h"
#include "../../Layout/import.h"

namespace ui
{
	// 创建节点
#define CREATE_LOADER_WIDGET(T) \
	virtual Widget* getWidget() \
	{ \
	if (_node == nullptr) \
	{ \
	_node = new T(); \
	AUTO_RELEASE_OBJECT(_node); \
} \
	return _node; \
}

	/**
	*	初始化节点加载方法
	*	@param T 类名称
	*	@param NAME 解析节点的名称
	*/
#define INIT_LOADER_WIDGET(T, NAME) \
	CREATE_LOADER_WIDGET(T) \
	virtual const char* getName() { return NAME; }\
	T* getCastWidget() { return static_cast<T*>(getWidget()); }

	// 获取当前节点：子类会隐藏父类同名函数
#define GET_WIDGET getCastWidget()
	//////////////////////////////////////////////////////////////////////////

	// 创建节点
#define CREATE_LOADER_LAYOUTITEM(T) \
	virtual LayoutItem* getLayoutItem() \
	{ \
	if (m_pLayoutItem == nullptr) \
	{ \
	m_pLayoutItem = new T(); \
	AUTO_RELEASE_OBJECT(m_pLayoutItem); \
} \
	return m_pLayoutItem; \
}

	/**
	*	初始化节点加载方法
	*	@param T 类名称
	*	@param NAME 解析节点的名称
	*/
#define INIT_LOADER_LAYOUTITEM(T, NAME) \
	CREATE_LOADER_LAYOUTITEM(T) \
	virtual const char* getName() { return NAME; }\
	T* getCastLayoutItem() { return static_cast<T*>(getLayoutItem()); }

	// 获取当前节点：子类会隐藏父类同名函数
#define GET_LAYOUTITEM getCastLayoutItem()
//////////////////////////////////////////////////////////////////////////
	// LOAD  ATTRIBUTE
	/**
	*	设置名称
	*/
#define LOAD_NAME(T) \
	T->setName(getNodeProperty()->getName());
	/**
	*	设置属性
	*/
#define LOAD_ATTRIBUTE(T, NAME, FUNC, TEMP) \
	if (getNodeProperty()->getAttribute(NAME, TEMP)) T->FUNC(TEMP);
	/**
	*	设置属性类型为字符串
	*/
#define LOAD_STRING_ATTRIBUTE(T, NAME, FUNC, TEMP) \
	if (getNodeProperty()->getAttribute(NAME, TEMP)) T->FUNC(TEMP.c_str());
	/**
	*	设置属性类型为指定类型
	*/
#define LOAD_CAST_ATTRIBUTE(T, NAME, FUNC, TEMP, TYPE) \
	if (getNodeProperty()->getAttribute(NAME, TEMP)) T->FUNC(static_cast<TYPE>(TEMP));

	// SAVE ATTRIBUTE
	/**
	*	保存名称
	*/
#define SAVE_NAME() \
	getNodeProperty()->setName(getName());
	/**
	*	保存属性值
	*/
#define SAVE_ATTRIBUTE(T, NAME, FUNC) \
	getNodeProperty()->setAttribute(NAME, T->FUNC());
	/**
	*	保存属性类型为指定类型的值
	*/
#define SAVE_CAST_ATTRIBUTE(T, NAME, FUNC, TYPE)\
	getNodeProperty()->setAttribute(NAME, static_cast<TYPE>(T->FUNC()));

	// CHANGE ATTRIBUTE
#define ADD_ATTRIBUTE(T, NAME, FUNC) \
	SAVE_ATTRIBUTE(T, NAME, FUNC) \
//////////////////////////////////////////////////////////////////////////
	// widget
#define LOAD_WDIGET_NAME() LOAD_NAME(GET_WIDGET)
#define LOAD_WDIGET_ATTRIBUTE(NAME, FUNC, TEMP) LOAD_ATTRIBUTE(GET_WIDGET, NAME, FUNC, TEMP)
#define LOAD_WDIGET_STRING_ATTRIBUTE(NAME, FUNC, TEMP) LOAD_STRING_ATTRIBUTE(GET_WIDGET, NAME, FUNC, TEMP)
#define LOAD_WDIGET_CAST_ATTRIBUTE(NAME, FUNC, TEMP, TYPE) LOAD_CAST_ATTRIBUTE(GET_WIDGET, NAME, FUNC, TEMP, TYPE)

#define SAVE_WDIGET_NAME() SAVE_NAME()
#define SAVE_WDIGET_ATTRIBUTE(NAME, FUNC) SAVE_ATTRIBUTE(GET_WIDGET, NAME, FUNC)
#define SAVE_WDIGET_CAST_ATTRIBUTE(NAME, FUNC, TYPE) SAVE_CAST_ATTRIBUTE(GET_WIDGET, NAME, FUNC, TYPE)

#define ADD_WDIGET_ATTRIBUTE(NAME, FUNC) ADD_ATTRIBUTE(GET_WIDGET, NAME, FUNC)

	// layoutitem
#define LOAD_LAYOUTITEM_NAME() LOAD_NAME(GET_LAYOUTITEM)
#define LOAD_LAYOUTITEM_ATTRIBUTE(NAME, FUNC, TEMP) LOAD_ATTRIBUTE(GET_LAYOUTITEM, NAME, FUNC, TEMP)
#define LOAD_LAYOUTITEM_STRING_ATTRIBUTE(NAME, FUNC, TEMP) LOAD_STRING_ATTRIBUTE(GET_LAYOUTITEM, NAME, FUNC, TEMP)
#define LOAD_LAYOUTITEM_CAST_ATTRIBUTE(NAME, FUNC, TEMP, TYPE) LOAD_CAST_ATTRIBUTE(GET_LAYOUTITEM, NAME, FUNC, TEMP, TYPE)

#define SAVE_LAYOUTITEM_NAME() SAVE_NAME()
#define SAVE_LAYOUTITEM_ATTRIBUTE(NAME, FUNC) SAVE_ATTRIBUTE(GET_LAYOUTITEM, NAME, FUNC)
#define SAVE_LAYOUTITEM_CAST_ATTRIBUTE(NAME, FUNC, TYPE) SAVE_CAST_ATTRIBUTE(GET_LAYOUTITEM, NAME, FUNC, TYPE)

#define ADD_LAYOUTITEM_ATTRIBUTE(NAME, FUNC) ADD_ATTRIBUTE(GET_LAYOUTITEM, NAME, FUNC)

//////////////////////////////////////////////////////////////////////////
#define ELEMENT_NAME_WIDGET			"Widget"
#define ELEMENT_NAME_IMAGE			"Image"
#define ELEMENT_NAME_TEXT			"Text"

#define ELEMENT_NAME_LAYOUTITEM		"LayoutItem"
#define ELEMENT_NAME_LAYOUT			"Layout"
#define ELEMENT_NAME_HLAYOUT		"HLayout"
#define ELEMENT_NAME_VLAYOUT		"VLayout"

}
