#pragma once

#include "CtrlWidget.h"
#include "CtrlLayout.h"
#include "Common/Input/TouchDelegate.h"

namespace render
{
	// ��������
	enum class ScrollDirection
	{
		NONE,
		// ˮƽ��������
		HORIZONTAL_LEFT_TO_RIGHT,
		// ˮƽ��������
		HORIZONTAL_RIGHT_TO_LEFT,
		// ˮƽ��������
		VERTICAL_TOP_TO_BOTTOM,
		// ˮƽ��������
		VERTICAL_BOTTOM_TO_TOP,
	};

	class ScrollItem : public CtrlWidget
	{
	public:
		ScrollItem();
		virtual ~ScrollItem();
	public:
		// �����
		void addItem(Node* node, const math::Size& size);

	public:
		static ScrollItem* create(Node* node, const math::Size& size);
	};

	// ����
	class CtrlScrollView : public CtrlLayout, public TouchProtocol
	{
	public:
		CtrlScrollView();
		virtual ~CtrlScrollView();
	public:
		// ���û�������
		void setScrollDirection(ScrollDirection direction);
		// ��ȡ��������
		ScrollDirection getScrollDirection();
		// ���һ����
		void append(Node* item);
		void append(Node* item, const math::Size& size);
		// �Ƴ�һ����
		void remove(Node* item);
		// �Ƴ�������
		void removeAllItems();
		// ����ÿ����Ĵ�С
		void setItemSize(const math::Size& size);
		void setItemSize(float width, float height);
		// ��ȡÿ����Ĵ�С
		const math::Size& getItemSize();
	protected:
		// �������
		void onBeginTouch(Node* node, float x, float y, bool include);
		void onMoveTouch(Node* node, float x, float y, bool include);
		void onEndTouch(Node* node, float x, float y, bool include);

		// ��������
		virtual bool onTouchBegan(float x, float y, bool include);
		virtual bool onTouchMoved(float x, float y, bool include);
		virtual bool onTouchEnded(float x, float y, bool include);

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
		math::Vector2 _touchPosition;
		// ��Ĵ�С
		math::Size _itemSize;
	};
}