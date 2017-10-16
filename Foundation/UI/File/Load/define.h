#pragma once

#include "File/Parse/import.h"
#include "Layout/import.h"
#include "macros.h"

namespace ui
{
	/**
	*	��ʼ���ڵ���ط���
	*	@param TL ��������
	*	@param TW �ռ�����
	*	@param NAME �����ڵ������
	*/
#define INIT_LOADER_WIDGET(TL,TW, NAME) \
public:\
	virtual const char* getName() { return NAME; }\
	TW* getCastWidget() { return static_cast<TW*>(getWidget()); }\
	TL* getCastLayoutItem() { return static_cast<TL*>(getLayoutItem()); } \
	virtual void initLayoutItem() { _layoutItem = new TL();} \
	virtual void initWidget() {_node = CREATE_NODE(TW);}

	// ��ȡ��ǰ�ڵ㣺��������ظ���ͬ������
#define GET_WIDGET getCastWidget()
	// ��ȡ��ǰ�������������ظ���ͬ������
#define GET_LAYOUTITEM getCastLayoutItem()
//////////////////////////////////////////////////////////////////////////
	// LOAD  ATTRIBUTE
	/**
	*	��������
	*/
#define LOAD_NAME(T) \
	T->setName(getNodeProperty()->getName());
	/**
	*	��������
	*/
#define LOAD_ATTRIBUTE(T, NAME, FUNC, TEMP) \
	if (getNodeProperty()->getAttribute(NAME, TEMP)) T->FUNC(TEMP);
	/**
	*	������������Ϊ�ַ���
	*/
#define LOAD_STRING_ATTRIBUTE(T, NAME, FUNC, TEMP) \
	if (getNodeProperty()->getAttribute(NAME, TEMP)) T->FUNC(TEMP.c_str());
	/**
	*	������������Ϊָ������
	*/
#define LOAD_CAST_ATTRIBUTE(T, NAME, FUNC, TEMP, TYPE) \
	if (getNodeProperty()->getAttribute(NAME, TEMP)) T->FUNC(static_cast<TYPE>(TEMP));

	// SAVE ATTRIBUTE
	/**
	*	��������
	*/
#define SAVE_NAME() \
	getNodeProperty()->setName(getName());
	/**
	*	��������ֵ
	*/
#define SAVE_ATTRIBUTE(T, NAME, FUNC) \
	getNodeProperty()->setAttribute(NAME, T->FUNC());
	/**
	*	������������Ϊָ�����͵�ֵ
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
#define ELEMENT_NAME_LAYOUT			"Layout"
#define ELEMENT_NAME_NODE			"Node"
#define ELEMENT_NAME_IMAGE			"Image"
#define ELEMENT_NAME_TEXT			"Text"
}
