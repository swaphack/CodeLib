#pragma once

#include "system.h"
#include "Notify.h"
#include "Common/struct/import.h"

namespace render
{
	class ActionProxy;
	class TouchProxy;
	class ShaderProgram;

#define CREATE_NODE(NODE_TYPE) render::createNode<NODE_TYPE>()

	template<typename T>
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
		Node* getChildByName(const char* name); 
	public:
		// 获取第一个子节点
		Node* getFirstChild();
		std::vector<sys::Object*>::iterator beginChild();
		std::vector<sys::Object*>::iterator endChild();
	public:
		// 设置数据
		void setUserData(void* data);
		// 获取数据
		void* getUserData();
	public:
		// 设置z轴坐标
		void setZOrder(float z);
		// 获取z轴坐标
		float getZOrder();
	public:
		// 设置可见性
		void setVisible(bool status);
		// 是否可见
		bool isVisible();
	public:
		// 绘制,重写
		virtual void draw();
		// 遍历所有节点
		virtual void visit();
	protected:
		// 绘制节点
		void drawNode();
		// shader处理
		void handShaderProgram();
	public:
		// 获取动作代理
		ActionProxy* getActionProxy();
	public:
		// 是否和父节点关联
		bool isRelativeWithParent();
		// 设置是否和父节点关联
		void setRelativeWithParent(bool status);
	public:
		// 点击是否命中
		virtual bool containTouchPoint(float x, float y);
		// 获取触摸代理
		TouchProxy* getTouchProxy();
		// 矩形定点
		const RectVertex& getRectVertex();
	public:
		// 矩阵
		const math::Matrix44& getRealMatrix();
		// 矩阵
		const math::Matrix44& getMatrix();
	public:
		// 着色器程序
		void setProgram(ShaderProgram* program);
		// 着色器程序
		ShaderProgram* getProgram();
	protected:
		// 更新空间矩阵
		virtual void updateTranform();
		// 翻转空间矩阵
		virtual void inverseTranform();
	protected:
		void notifyEvents();
		void notify(int id);
	protected:
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
	private:
		// 使用矩阵计算空间变化属性
		void calRealSpaceByMatrix();
		// 使用常量计算空间变化属性
		void calRealSpaceByValue();
	protected:
		// opengl 位置
		math::Vector3 _obPosition;
		// 旋转角度
		math::Vector3 _obRotation;
		// 标签
		int _tag;
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
		RectVertex _rectVertex;
		// 空间坐标（实际）
		RectVertex _realSpaceVertex;
		// 实际躯体空间信息
		BodySpace _realBodySpace;
		// 通知
		Notify<int>* _notify;
		// 使用矩阵运算
		bool _bUseMatrix = true;
		// 相对于父节点的矩阵
		math::Matrix44 _mat44;
		// 逆矩阵
		math::Matrix44 _matInverse44;
		// 实际在世界坐标系中的矩阵
		math::Matrix44 _realMat44;
		// 着色器
		ShaderProgram* _program = nullptr;
	};
}
