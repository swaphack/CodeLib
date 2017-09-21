#pragma once

#include "system.h"
#include "Notify.h"
#include "../GL/import.h"
#include "../Tool/import.h"
#include "../Action/import.h"
#include "../Shader/import.h"

namespace render
{
	//struct PSR;
	class TouchProxy;

#define CREATE_NODE(NODE_TYPE) createNode<NODE_TYPE>()

	template<typename T>
	T* createNode()
	{
		T* temp = new T();
		if (temp && temp->init() == false)
		{
			delete temp;
			return nullptr;
		}

		AUTO_RELEASE_OBJECT(temp);

		return temp;
	}

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
		// 务必调用，包含属性修改时通知
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
		void removeAllChildren();
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
		// 获取第一个子节点
		Node* getFirstChild();

		std::vector<sys::Object*>::iterator beginChild();
		std::vector<sys::Object*>::iterator endChild();

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
		// 绘制,重写
		virtual void draw();
		// 遍历所有节点
		virtual void visit();
		// 获取动作代理
		ActionProxy* getActionProxy();

		// 是否和父节点关联
		bool isRelativeWithParent();
		// 设置是否和父节点关联
		void setRelativeWithParent(bool status);

		// 点击是否命中
		virtual bool containTouchPoint(float x, float y);
		// 获取触摸代理
		TouchProxy* getTouchProxy();

		const RectangeVertex& getRectVertex();
	protected:
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
		// 子节点发生改变
		virtual void onChildrenChange();
	protected:
		// opengl 位置
		sys::Vector3 _obPosition;
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
		// 通知
		Notify* _notify;
	};
}
