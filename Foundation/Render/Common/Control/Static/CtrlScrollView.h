#pragma once

#include "CtrlScissor.h"

namespace render
{
	// ��������
	enum ScrollDirection
	{
		ESD_NONE,
		// ˮƽ��������
		ESD_HORIZONTAL_LEFT,
		// ˮƽ��������
		ESD_HORIZONTAL_RIGHT,
		// ˮƽ��������
		ESD_VERTICAL_TOP,
		// ˮƽ��������
		ESD_VERTICAL_BOTTOM,
	};

	class ScrollItem : public Node
	{
	public:
		ScrollItem();
		virtual ~ScrollItem();
	public:
		// ������
		void addItem(Node* node, const sys::Size& size);

	public:
		static ScrollItem* create(Node* node, const sys::Size& size);
	};

	// ����
	class CtrlScrollView : public CtrlScissor, public TouchProtocol
	{
	public:
		CtrlScrollView();
		virtual ~CtrlScrollView();
	public:
		// ���û�������
		void setScrollDirection(ScrollDirection direction);
		// ��ȡ��������
		ScrollDirection getScrollDirection();
		// ����һ����
		void append(Node* item);
		void append(Node* item, const sys::Size& size);
		// �Ƴ�һ����
		void remove(Node* item);
		// �Ƴ�������
		void removeAllItems();
		// ����ÿ����Ĵ�С
		void setItemSize(const sys::Size& size);
		void setItemSize(float width, float height);
		// ��ȡÿ����Ĵ�С
		const sys::Size& getItemSize();
	protected:
		// �������
		void onBeginTouch(sys::Object* object, float x, float y);
		void onMoveTouch(sys::Object* object, float x, float y);
		void onEndTouch(sys::Object* object, float x, float y);

		// ��������
		virtual bool onTouchBegan(float x, float y);
		virtual void onTouchMoved(float x, float y);
		virtual void onTouchEnded(float x, float y);

		virtual void initSelf();
		// ��ʼ��������
		virtual void initItems();
		// ��ʼ��������
		virtual void initContent();
	protected:
		// ��������
		ScrollDirection _scrollDirection;
		// �����������λ��
		Node* _content;
		// ��
		std::vector<Node*> _nodes;
		// ���λ��
		sys::Point _touchPosition;
		// ��Ĵ�С
		sys::Size _itemSize;
	};
}