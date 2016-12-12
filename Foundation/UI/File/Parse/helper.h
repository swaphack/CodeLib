#pragma once

namespace ui
{
	// �����ڵ�
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

	// ע�����
#define REGISTER_LOAER_WIDGET(NAME) \
	void registerNodeParser() \
	{ \
	G_UIPROXY->registerNodeParser(#NAME, this); \
	}

	// ��ʼ���ڵ���ط���
#define INIT_LOADER_WIDGET(T) \
	CREATE_LOADER_WIDGET(T) \
	REGISTER_LOAER_WIDGET(T) \
	T* getCastWidget() { return static_cast<T*>(getWidget()); }

	// ��ȡ��ǰ�ڵ㣺��������ظ���ͬ������
#define GET_WIDGET getCastWidget()

}