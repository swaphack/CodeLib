#pragma once

#include "system.h"
#include "Notify.h"
#include "NodeProtocol.h"
#include "NotifyCenter.h"
#include "Common/Input/TouchProtocol.h"
#include "Common/Action/SchedulerProtocol.h"
#include <vector>

namespace render
{
	class ActionProxy;

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
		public BodyProtocol,
		public DirectionProtocol,
		public TouchProtocol,
		public SchedulerProtocol,
		public DrawNodeProtocol
	{
	public:
		Node();
		virtual ~Node();
	public:
		// 务必调用，包含属性修改时通知
		virtual bool init();
		// 遍历和绘制
		virtual void visit();
	public:
		// 设置父节点
		void setParent(Node* node);
		// 获取父节点
		Node* getParent() const;
		// 从父节点移除
		void removeFromParent();
		// 从父节点移除，是否清空
		virtual void removeFromParentWithCleanup(bool clean);
		// 清空
		virtual void cleanup();
		// 设置场景
		void setChildrenScene(Scene* scene);
	public:
		// 添加子节点
		virtual void addChild(Node* node);
		// 添加子节点
		virtual void addChild(Node* node, int zOrder);
		// 移除子节点
		void removeChild(Node* node);
		// 移除所有子节点
		void removeAllChildren();
		// 根据id获取子节点
		Node* getChildByID(long id) const;
	public:
		// 设置标签
		void setTag(int tag);
		// 获取标签
		int getTag() const;
		// 根据标签获取子节点
		Node* getChildByTag(int tag) const;
	public:
		// 根据名称获取子节点
		Node* getChildByName(const std::string& name) const;
	public:
		// 获取子节点个数
		int getChildrenCount() const;
		// 获取第一个子节点
		Node* getFirstChild() const;
		// 按照索引查找子节点
		Node* getChildAt(int index) const;
		// 子节点所在索引
		int indexOfChild(const Node* node) const;
		// 是否是目标的后代节点
		bool isDescendantsOf(const Node* parent) const;
		// 所有子节点
		const std::vector<Node*>& getAllChildren() const;
		// 所有子节点
		std::vector<Node*>& getAllChildren();
		// 遍历所有子节点
		void foreachChild(const std::function<void(Node*)>& handler);
		// 遍历所有子节点
		void foreachChildWitchRecrusive(const std::function<void(Node*)>& handler);
	public:
		// 设置数据
		void setUserData(void* data);
		// 获取数据
		void* getUserData() const;
	public:
		// 设置z轴坐标, 父节点是否重新绘制
		void setZOrder(int z, bool dirty = true);
		// 获取z轴坐标
		int getZOrder()  const;
	public:
		// 设置可见性
		void setVisible(bool status);
		// 是否可见
		bool isVisible()  const;
		// 是否可见(递归检测其父节点是否可见)
		bool isRecursiveVisible()  const;
	public:
		// 跳过绘制
		void setSkipDraw(bool status);
		// 是否跳过绘制
		bool isSkipDraw()  const;
		// 跳过绘制孩子节点
		void setSkipDrawChildren(bool status);
		// 是否跳过绘制孩子节点
		bool isSkipDrawChildren()  const;
	public:
		// 更新节点, 更新节点逻辑
		virtual void updateNode();
	public:
		// 绘制节点 矩阵变换->测试和预处理->绘制当前界面
		virtual void drawNode();
		// 绘制前
		virtual void beforeDrawNode();
		// 绘制后
		virtual void afterDrawNode();
	protected:
		// 绘制,重写
		virtual void draw();

		virtual void drawAllChildren();
	public:
		// 获取动作代理
		ActionProxy* getActionProxy();
		/**
		*	定时执行一次
		*/
		void scheduleOnce(float delayTime, const std::function<void(float interval)>& func);
		/**
		*	定时执行
		*/
		void scheduleUpdate(float delayTime, float totalTime, float intervalTime, const std::function<void(float interval)>& func);
		/**
		*	定时永久执行
		*/
		void scheduleForever(float delayTime, float intervalTime, const std::function<void(float interval)>& func);
	public:
		/**
		*	开启定时器
		*/
		virtual void scheduleUpdate();
		/**
		*	关闭定时器
		*/
		virtual void unscheduleUpdate();
		/**
		*	定时更新
		*/
		virtual void update(float dt);
	public:
		// 是否和父节点关联
		bool isRelativeWithParent() const;
		// 设置是否和父节点关联
		void setRelativeWithParent(bool status);
		// 获取裁剪的父节点
		Node* getFirstClippingNodeOfParents() const;
	public:
		// 世界矩阵
		const math::Matrix4x4& getWorldMatrix() const;
		// 世界转本地矩阵
		const math::Matrix4x4& getWorldInverseMatrix() const;
		// 相对父节点的矩阵
		const math::Matrix4x4& getLocalMatrix() const;
		// 将世界坐标转化为本地坐标
		math::Vector3 convertWorldToLocalPoint(const math::Vector3& point) const;
		// 将本地坐标转化为世界坐标
		math::Vector3 convertLocalToWorldPoint(const math::Vector3& point) const;
	public:
		// 在目标节点的前方
		bool isInFrontOfNode(const Node* target) const;
		// 是否点击点落在该节点上
		virtual bool containPoint(const math::Vector2& touchPoint);
	public:
		// 添加事件监听
		void addNotifyListener(NodeNotifyType id, const NotifyDelegate& func);
		// 添加事件监听
		void addNotifyListener(NodeNotifyType id, void* target, const NotifyDelegate& func);
		// 移除事件监听
		void removeNotifyListener(NodeNotifyType id, void* target);
		// 将事件通知给所有节点
		void notifyToAll(NodeNotifyType id);
		// 将事件通知给节点
		void notify(NodeNotifyType id);
		// 广播事件
		void broadcastFunc(const std::function<void(Node*)>& func, bool recursive = false);
		// 通知事件
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
		// 计算旋转后的方向
		void calDirectionWithRotate();
	public:
		// 设置是否裁剪
		void setClippingEnabled(bool status);
		// 是否裁剪
		bool isClippingEnabled() const;
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
		// 跳过绘制孩子节点
		bool _bSkipDrawChildren = false;
		// 是否可见
		bool _bVisibled = false;
		// 是否开启裁剪
		bool _bClippingEnabled = false;
		// 是否和父节点关联
		bool _bRelativeToParent = false;
		// 通知
		NodeNotify* _notify = nullptr;
		// 相对于父节点的矩阵
		math::Matrix4x4 _localMatrix;
		// 逆矩阵
		math::Matrix4x4 _localInverseMatrix;
		// 实际在世界坐标系中的矩阵
		math::Matrix4x4 _worldMatrix;
		// 实际在世界坐标系中的逆矩阵
		math::Matrix4x4 _worldInverseMatrix;
	protected:
		// 动作代理
		ActionProxy* _actionProxy = nullptr;
		
	};


#define CREATE_NODE(NODE_TYPE) render::createNode<NODE_TYPE>()

	template<typename T, typename = std::enable_if<std::is_base_of<render::Node, T>::value, T>::type>
	T* createNode()
	{
		T* temp = new T();
		if (temp == nullptr)
		{
			return nullptr;
		}
		if (temp->init() == false)
		{
			delete temp;
			return nullptr;
		}

		AUTO_RELEASE_OBJECT(temp);

		return temp;
	}
}
