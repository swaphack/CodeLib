#pragma once

#include "system.h"

#include "../GL/import.h"
#include "../Tool/import.h"
#include "../Action/import.h"
#include "../Shader/import.h"
//#include "../Touch/TouchProxy.h"

namespace render
{
	//struct PSR;
	class TouchProxy;

	// 绘制节点
	class Node : public sys::Object, public DirtyProtocol
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

		// 设置数据
		void setUserData(void* data);
		// 获取数据
		void* getUserData();

		// 设置z轴坐标
		void setZOrder(float z);
		// 获取z轴坐标
		float getZOrder();
		// 设置坐标
		void setPosition(float x, float y, float z);
		// 获取坐标
		const sys::Vector& getPosition();
		// 设置缩放比
		void setScale(float x, float y, float z);
		// 获取缩放比
		const sys::Vector& getScale();
		// 设置旋转系数
		void setRotation(float x, float y, float z);
		// 获取旋转系数
		const sys::Vector& getRotation();

		// 设置描点
		void setAnchorPoint(float x, float y, float z);
		// 获取描点
		const sys::Vector& getAnchorPoint();
		// 设置体积
		void setVolume(float w, float h, float d);
		// 获取体积
		const sys::Volume& getVolume();

		// 设置可见性
		void setVisible(bool status);
		// 是否可见
		bool isVisible();
		
		// 绘制
		virtual void draw();
		// 遍历所有节点
		virtual void visit();
		// 获取动作代理
		ActionProxy* getActionProxy();

		// 是否和父节点关联
		bool isRelativeWithParent();
		// 设置是否和父节点关联
		void setRelativeWithParent(bool status);

		// 设置矩形框是否可见
		void setRectVisible(bool status);
		// 设置矩形框显示颜色
		void setRectColor(const sys::Color4B& color);

		// 点击是否命中
		bool containTouchPoint(float x, float y);
		// 获取触摸代理
		TouchProxy* getTouchProxy();
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
		// 显示绘制区域
		void drawRect();
	protected:
		sys::Vector _obPosition;
		// 标签
		int _tag;
		// 数据
		void* _userData;
		// z轴坐标
		float _zOrder;
		// 位置坐标
		sys::Vector _position;
		// 缩放比
		sys::Vector _scale;
		// 旋转
		sys::Vector _rotation;

		// 锚点
		sys::Vector _anchor;
		// 体积
		sys::Volume _volume;
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
		// 矩形框颜色
		sys::Color4B _rectColor;
		// 是否显示矩形框
		bool _bShowRect;
		// 空间坐标
		RectangeVertex _realSpaceVertex;
	};
}