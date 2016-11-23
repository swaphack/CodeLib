#pragma once

#include "system.h"

#include "../GL/import.h"
#include "../Tool/import.h"
#include "../Action/import.h"
#include "../Shader/import.h"

namespace render
{
	//struct PSR;
	class TouchProxy;

	// 绘制节点
	class Node : 
		public sys::Object, 
		public sys::Name,
		public DirtyProtocol, 
		public SpaceProtocol,
		public BodyProtocol
	{
	public:
		Node();
		virtual ~Node();
	public:
		virtual bool init();
		// 设置父节点
		void setParent(Node* node);
		// 获取父节点
		Node* getParent();
		// 从父节点移除
		void removeFromParent();
		// 添加子节点
		void addChild(Node* node);
		// 移除子节点
		void removeChild(Node* node);
		// 移除所有子节点
		void clearAllChildren();
		// 根据id获取字节点
		Node* getChildByID(long id);

		// 设置标签
		void setTag(int tag);
		// 获取标签
		int getTag();
		// 根据标签获取字节点
		Node* getChildByTag(int tag);

		// 根据名称获取字节点
		Node* getChildByName(const char* name); 

		// 设置数据
		void setUserData(void* data);
		// 获取数据
		void* getUserData();

		// 设置z轴坐标
		void setZOrder(float z);
		// 获取z轴坐标
		float getZOrder();

		// 设置可见性
		void setVisible(bool status);
		// 是否可见
		bool isVisible();
		// 数值计算
		//virtual void calculate();
		// 遍历所有节点
		virtual void visit();
		// 获取动作代理
		ActionProxy* getActionProxy();

		// 是否和父节点关联
		bool isRelativeWithParent();
		// 设置是否和父节点关联
		void setRelativeWithParent(bool status);

		// 点击是否命中
		bool containTouchPoint(float x, float y);
		// 获取触摸代理
		TouchProxy* getTouchProxy();

		const RectangeVertex& getRectVertex();
	protected:
		// 绘制,重写
		virtual void draw();
		// 更新空间位置
		virtual void updateTranform();
		// 更新自己
		virtual void updateSelf();
		// 重新初始化自己
		virtual void initSelf();
		// 对子节点进行排序
		virtual void sortChildren();
		// 空间物理坐标
		virtual void calRealSpaceInfo();
		// 空间属性发生改变
		virtual void onSpaceChange();
		// 物体属性发生改变
		virtual void onBodyChange();
	protected:
		// opengl 位置
		sys::Vector _obPosition;
		// 标签
		int _tag;
		// 名称
		std::string _name;
		// 数据
		void* _userData;
		// z轴坐标
		float _zOrder;
		// 父节点
		Node* _parent;
		// 子节点
		sys::List _children;
		// 是否可见
		bool _bVisibled;
		// 是否可点击
		bool _bTouchEnabled;
		// 是否和父节点关联
		bool _bRelative;
		// 动作代理
		ActionProxy* _actionProxy;
		// 触摸代理
		TouchProxy* _touchProxy;
		// 矩形框
		RectangeVertex _rectVertex;
		// 空间坐标
		RectangeVertex _realSpaceVertex;
	};
}