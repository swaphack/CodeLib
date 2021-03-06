#pragma once

#include "system.h"

namespace ui
{
	/**
	*	初始化节点加载方法
	*	@param TL 布局类型
	*	@param TW 控件类型
	*	@param NAME 解析节点的名称
	*/
#define INIT_LOADER_WIDGET(TL,TW, NAME) \
public:\
	virtual std::string getName() { return NAME; }\
	TW* getCastWidget() { return getWidget()->as<TW>(); }\
	virtual void initLayoutItem() { _layoutItem = CREATE_OBJECT(TL);  } \
	virtual void initWidget() { _node = CREATE_NODE(TW);  }

	// 获取当前节点：子类会隐藏父类同名函数
#define GET_WIDGET getCastWidget()
	// 获取当前布局项：子类会隐藏父类同名函数
#define GET_LAYOUTITEM getLayoutItem()
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
	if (getNodeProperty()->getAttribute(NAME, TEMP)) T->FUNC(TEMP);
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
	// CtrlWidget
#define LOAD_WIDGET_NAME() LOAD_NAME(GET_WIDGET)
#define LOAD_WIDGET_ATTRIBUTE(NAME, FUNC, TEMP) LOAD_ATTRIBUTE(GET_WIDGET, NAME, FUNC, TEMP)
#define LOAD_WIDGET_STRING_ATTRIBUTE(NAME, FUNC, TEMP) LOAD_STRING_ATTRIBUTE(GET_WIDGET, NAME, FUNC, TEMP)
#define LOAD_WIDGET_CAST_ATTRIBUTE(NAME, FUNC, TEMP, TYPE) LOAD_CAST_ATTRIBUTE(GET_WIDGET, NAME, FUNC, TEMP, TYPE)

#define SAVE_WIDGET_NAME() SAVE_NAME()
#define SAVE_WIDGET_ATTRIBUTE(NAME, FUNC) SAVE_ATTRIBUTE(GET_WIDGET, NAME, FUNC)
#define SAVE_WIDGET_CAST_ATTRIBUTE(NAME, FUNC, TYPE) SAVE_CAST_ATTRIBUTE(GET_WIDGET, NAME, FUNC, TYPE)

#define ADD_WIDGET_ATTRIBUTE(NAME, FUNC) ADD_ATTRIBUTE(GET_WIDGET, NAME, FUNC)

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

}
