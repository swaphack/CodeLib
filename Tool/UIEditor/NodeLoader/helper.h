#pragma once

#include "UIProxy.h"
#include <string>

namespace ui
{
	// 创建节点
#define CREATE_LOADER_NODE(T) \
	virtual render::Node* getNode() \
	{ \
	if (_node == nullptr) \
	{ \
	_node = new T(); \
	AUTO_RELEASE_OBJECT(_node); \
	} \
	return _node; \
	} 

	// 注册解析
#define REGISTER_LOAER_NODE(NAME) \
	void registerNodeParser() \
	{ \
	G_UIPROXY->registerNodeParser(#NAME, this); \
	}
	
	// 初始化节点加载方法
#define INIT_LOADER_NODE(T) \
	CREATE_LOADER_NODE(T) \
	REGISTER_LOAER_NODE(T) \
	T* getCastNode() { return static_cast<T*>(getNode()); }

	// 获取当前节点：子类会隐藏父类同名函数名称
#define GET_NODE getCastNode()

}