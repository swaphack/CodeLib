#pragma once

#include "CtrlWidget.h"
#include "CtrlLayout.h"
#include "Common/Touch/TouchDelegate.h"

namespace render
{
	// 滑动方向
	enum class ScrollDirection
	{
		NONE,
		// 水平从左往右
		HORIZONTAL_LEFT_TO_RIGHT,
		// 水平从右往左
		HORIZONTAL_RIGHT_TO_LEFT,
		// 水平从上往下
		VERTICAL_TOP_TO_BOTTOM,
		// 水平从下往上
		VERTICAL_BOTTOM_TO_TOP,
	};

	class ScrollItem : public CtrlWidget
	{
	public:
		ScrollItem();
		virtual ~ScrollItem();
	public:
		// 添加项
		void addItem(Node* node, const math::Size& size);

	public:
		static ScrollItem* create(Node* node, const math::Size& size);
	};

	// 滑动
	class CtrlScrollView : public CtrlLayout, public TouchProtocol
	{
	public:
		CtrlScrollView();
		virtual ~CtrlScrollView();
	public:
		// 设置滑动方向
		void setScrollDirection(ScrollDirection direction);
		// 获取滑动方向
		ScrollDirection getScrollDirection();
		// 添加一个项
		void append(Node* item);
		void append(Node* item, const math::Size& size);
		// 移除一个项
		void remove(Node* item);
		// 移除所有项
		void removeAllItems();
		// 设置每个项的大小
		void setItemSize(const math::Size& size);
		void setItemSize(float width, float height);
		// 获取每个项的大小
		const math::Size& getItemSize();
	protected:
		// 点击处理
		void onBeginTouch(Node* node, float x, float y, bool include);
		void onMoveTouch(Node* node, float x, float y, bool include);
		void onEndTouch(Node* node, float x, float y, bool include);

		// 触摸处理
		virtual bool onTouchBegan(float x, float y, bool include);
		virtual bool onTouchMoved(float x, float y, bool include);
		virtual bool onTouchEnded(float x, float y, bool include);

		// 初始化滑动项
		virtual void initItems();
		// 初始化管理项
		virtual void initContent();
	protected:
		// 滑动方向
		ScrollDirection _scrollDirection;
		// 管理所有项的位置
		Node* _content;
		// 项
		std::vector<Node*> _nodes;
		// 点击位置
		math::Vector2 _touchPosition;
		// 项的大小
		math::Size _itemSize;
	};
}