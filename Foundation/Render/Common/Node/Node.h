#pragma once

#include "system.h"
#include "Notify.h"
#include "NodeProtocol.h"
#include <vector>

namespace render
{
	class ActionProxy;
	class TouchProxy;

	/**
	glLoadIdentity();
	glMultMatrixf(M);           //glScale*();
	glMultMatrixf(N);           //glRotate*()
	glMultMatrixf(L);           //glTranslate*();

	1.在OpenGL中所有的视图变换，模型变换 都是4×4矩阵，
	每个后续的glMultiMatrix*(N),或者变换函数,glTranslate*(),glRotate*(),等都是把一个新的4×4矩阵与当前的矩阵M相乘，
	不同的是：变换函数glTranslate*(),glRotate*()等会根据函数参数构造一个4×4矩阵，也设为N，两种情况产生相同的结果：M×N。
	注意这里的顺序，后续的矩阵是右乘当前矩阵。

	2.因为在opengl中坐标表示形式是：[x,y,z]T(表示转置)，或者齐次坐标下：[x,y,z,w]T标准化后[x/w,y/w,z/w,1.0]T 这就决定了矩阵也是列优先表示的。
	将上面的两个矩阵作用于点V,则表示为:M×N×V；满足矩阵相乘的条件：[4×4] * [4×1].

	*/
	// 绘制节点
	class Node : 
		public sys::Object, 
		public sys::Name,
		public sys::DirtyProtocol,
		public SpaceProtocol,
		public BodyProtocol
	{
	public:
		Node();
		virtual ~Node();
	public:
		// 务必调用，包含属性修改时通知
		virtual bool init();
	public:
		// 设置父节点
		void setParent(Node* node);
		// 获取父节点
		Node* getParent();
		// 从父节点移除
		void removeFromParent();
	public:
		// 添加子节点
		void addChild(Node* node);
		// 添加子节点
		void addChild(Node* node, int zOrder);
		// 移除子节点
		void removeChild(Node* node);
		// 移除所有子节点
		void removeAllChildren();
		// 根据id获取字节点
		Node* getChildByID(long id);
	public:
		// 设置标签
		void setTag(int tag);
		// 获取标签
		int getTag();
		// 根据标签获取字节点
		Node* getChildByTag(int tag);
	public:
		// 根据名称获取字节点
		Node* getChildByName(const std::string& name); 
	public:
		// 获取第一个子节点
		Node* getFirstChild();
	public:
		// 设置数据
		void setUserData(void* data);
		// 获取数据
		void* getUserData();
	public:
		// 设置z轴坐标
		void setZOrder(int z);
		// 获取z轴坐标
		int getZOrder();
	public:
		// 设置可见性
		void setVisible(bool status);
		// 是否可见
		bool isVisible();
	public:
		// 跳过绘制
		void setSkipDraw(bool status);
		// 是否跳过绘制
		bool isSkipDraw();
	public:
		// 更新节点, 更新节点逻辑
		virtual void updateNode();
	public:
		// 绘制节点 矩阵变换->测试和预处理->绘制当前界面
		virtual void drawNode();

		virtual void beforeDrawNode();

		virtual void afterDrawNode();
	protected:
		// 绘制,重写
		virtual void draw();

		void drawAllChildren();
	public:
		// 获取动作代理
		ActionProxy* getActionProxy();
	public:
		// 是否和父节点关联
		bool isRelativeWithParent();
		// 设置是否和父节点关联
		void setRelativeWithParent(bool status);
	public:
		// 获取触摸代理
		TouchProxy* getTouchProxy();
	public:
		// 世界矩阵
		const math::Matrix4x4& getWorldMatrix() const;
		// 相对父节点的矩阵
		const math::Matrix4x4& getLocalMatrix() const;
		// 将世界坐标转化为本地坐标
		math::Vector3 convertWorldPostitionToLocal(const math::Vector3& point);
		// 将本地坐标转化为世界坐标
		math::Vector3 convertLocalPostitionToWorld(const math::Vector3& point);

		virtual bool containTouchPoint(float x, float y) { return false; }
	protected:
		// 更新空间矩阵
		virtual void startUpdateTranform();
		// 逆转空间矩阵
		virtual void endUpdateTranform();
	public:
		// 将事件通知给所有节点
		void notifyToAll(NodeNotifyType id);
		// 将事件通知给节点
		void notify(NodeNotifyType id);
		// 广播事件
		void broadcastFunc(const std::function<void(Node*)>& func, bool recursive = false);
	protected:
		void notifyEvents();
	protected:
		// 对子节点进行排序
		virtual void sortChildren();
		// 空间物理坐标
		virtual void calSpaceData();
		// 空间属性发生改变
		virtual void onSpaceChange();
		// 物体属性发生改变
		virtual void onBodyChange();
		// 子节点发生改变
		virtual void onChildrenChange();

	private:
		// 使用矩阵计算空间变化属性
		void calRealSpaceByMatrix();
	protected:
		// opengl 位置
		math::Vector3 _obPosition;
		// opengl 旋转角度
		math::Vector3 _obRotation;
		// 标签
		int _tag = 0;
		// 数据
		void* _userData = nullptr;
		// z轴坐标
		int _zOrder = 0;
		// 父节点
		Node* _parent = nullptr;
		// 子节点
		std::vector<Node*> _children;
		// 跳过绘制
		bool _bSkipDraw = false;
		// 是否可见
		bool _bVisibled = false;
		// 是否可点击
		bool _bTouchEnabled = false;
		// 是否和父节点关联
		bool _bRelativeToParent = false;
		// 动作代理
		ActionProxy* _actionProxy;
		// 触摸代理
		TouchProxy* _touchProxy;
		// 通知
		Notify<NodeNotifyType>* _notify;
		// 相对于父节点的矩阵
		math::Matrix4x4 _localMatrix;
		// 逆矩阵
		math::Matrix4x4 _localInverseMatrix;
		// 实际在世界坐标系中的矩阵
		math::Matrix4x4 _worldMatrix;
		
	};


#define CREATE_NODE(NODE_TYPE) render::createNode<NODE_TYPE>()

	template<typename T, typename = std::enable_if<std::is_base_of<Node, T>::value, T>::type>
	T* createNode()
	{
		T* temp = new T();
		if (temp == nullptr)
		{
			return nullptr;
		}
		if (temp && temp->init() == false)
		{
			delete temp;
			return nullptr;
		}

		AUTO_RELEASE_OBJECT(temp);

		return temp;
	}
}
