#pragma once

#include "../UIProxy.h"

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

	// 注册解析
#define REGISTER_LOAER_WIDGET(NAME) \
	virtual void registerNodeParser() \
	{ \
	G_UIPROXY->registerNodeParser(#NAME, this); \
	}

	/**
	*	初始化节点加载方法
	*	@param T 类名称
	*	@param Name 注册名称
	*/
#define INIT_LOADER_WIDGET(T, Name) \
	CREATE_LOADER_WIDGET(T) \
	REGISTER_LOAER_WIDGET(Name) \
	T* getCastWidget() { return static_cast<T*>(getWidget()); }

	/**
	*	初始化节点加载方法
	*	@param T 类名称
	*/
#define INIT_LOADER_WIDGET2(T) INIT_LOADER_WIDGET(T, T)

	// 获取当前节点：子类会隐藏父类同名函数
#define GET_WIDGET getCastWidget()

}