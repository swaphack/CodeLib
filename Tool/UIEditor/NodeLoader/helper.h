#pragma once

#include "UIProxy.h"
#include <string>

namespace ui
{
	// �����ڵ�
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

	// ע�����
#define REGISTER_LOAER_NODE(NAME) \
	void registerNodeParser() \
	{ \
	G_UIPROXY->registerNodeParser(#NAME, this); \
	}
	
	// ��ʼ���ڵ���ط���
#define INIT_LOADER_NODE(T) \
	CREATE_LOADER_NODE(T) \
	REGISTER_LOAER_NODE(T) \
	T* getCastNode() { return static_cast<T*>(getNode()); }

	// ��ȡ��ǰ�ڵ㣺��������ظ���ͬ����������
#define GET_NODE getCastNode()

}