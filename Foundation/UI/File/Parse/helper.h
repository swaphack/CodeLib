#pragma once

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
	void registerNodeParser() \
	{ \
	G_UIPROXY->registerNodeParser(#NAME, this); \
	}

	// 初始化节点加载方法
#define INIT_LOADER_WIDGET(T) \
	CREATE_LOADER_WIDGET(T) \
	REGISTER_LOAER_WIDGET(T) \
	T* getCastWidget() { return static_cast<T*>(getWidget()); }

	// 获取当前节点：子类会隐藏父类同名函数
#define GET_WIDGET getCastWidget()

}