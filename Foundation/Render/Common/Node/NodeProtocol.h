#pragma once

#include "mathlib.h"

namespace render
{
	// 空间属性
	class SpaceProtocol
	{
	public:
		SpaceProtocol();
		virtual ~SpaceProtocol();
	public:
		// 设置坐标
		void setPositionX(float x);

		void setPositionY(float y);

		void setPositionZ(float z);

		void setPosition(float x, float y);

		void setPosition(float x, float y, float z);

		void setPosition(const math::Vector3& position);

		void setPosition(const math::Vector2& position);
		// 获取坐标
		float getPositionX() const;

		float getPositionY() const;

		float getPositionZ() const;

		const math::Vector3& getPosition() const;
		// 设置缩放比
		void setScaleX(float x);

		void setScaleY(float y);

		void setScaleZ(float z);

		void setScale(float x, float y, float z);

		void setScale(const math::Vector2& scale);

		void setScale(const math::Vector3& scale);

		void setScale(float scale);
		// 获取缩放比
		float getScaleX() const;

		float getScaleY() const;

		float getScaleZ() const;

		const math::Vector3& getScale() const;
		// 设置旋转系数
		void setRotationX(float x);

		void setRotationY(float y);

		void setRotationZ(float z);

		void setRotation(float x, float y, float z);

		void setRotation(const math::Vector3& rotation);
		// 获取旋转系数
		float getRotationX() const;

		float getRotationY() const;

		float getRotationZ() const;

		const math::Vector3& getRotation() const;

		
	public:
		virtual void onSpaceChange() {}
	protected:
		// 位置坐标
		math::Vector3 _position;
		// 缩放比
		math::Vector3 _scale;
		// 旋转
		math::Vector3 _rotation;
	};


	// 物体属性
	class BodyProtocol
	{
	public:
		BodyProtocol();
		virtual ~BodyProtocol();
	public:
		// 设置锚点
		void setAnchorPoint(float x, float y, float z);
		// 设置锚点
		void setAnchorPoint(float x, float y);
		// 设置锚点
		void setAnchorPoint(const math::Vector3& anchor);
		// 设置锚点
		void setAnchorPoint(const math::Vector2& anchor);
		// 获取锚点
		const math::Vector3& getAnchorPoint();
		// 获取锚点
		float getAnchorPointX();
		// 设置锚点
		void setAnchorPointX(float value);
		// 获取锚点
		float getAnchorPointY();
		// 设置锚点
		void setAnchorPointY(float value);
		// 获取锚点
		float getAnchorPointZ();
		// 设置锚点
		void setAnchorPointZ(float value);
		// 设置宽度
		void setWidth(float w);
		// 设置高度
		void setHeight(float h);
		// 设置深度
		void setDepth(float d);
		// 设置体积
		void setVolume(float w, float h, float d);
		// 设置体积
		void setVolume(float w, float h);
		// 设置体积
		void setVolume(const math::Volume& volume);
		// 设置面积，默认深度
		void setVolume(const math::Size& size);
		// 获取宽度
		float getWidth();
		// 获取高度
		float getHeight();
		// 获取深度
		float getDepth();
		// 获取体积
		const math::Volume& getVolume();
		// 获取面积
		math::Size getSize();
	public:
		virtual void onBodyChange() {}
	protected:
		// 锚点
		math::Vector3 _anchor;
		// 体积
		math::Volume _volume;
	private:
	};

	// 方向属性
	class DirectionProtocol
	{
	public:
		enum class ZDirectionType
		{
			// 朝向屏幕内
			INSIDE,
			// 朝向屏幕外
			OUTSIDE,
		};
	public:
		DirectionProtocol();
		virtual ~DirectionProtocol();
	public:
		const math::Vector3& getUp() const;

		const math::Vector3& getRight() const;

		const math::Vector3& getFront() const;
	
		void setZDirection(ZDirectionType type);

		ZDirectionType getZDirection() const;

		const math::Vector3& getDefaultUp() const;

		const math::Vector3& getDefaultRight() const;

		const math::Vector3& getDefaultFront() const;
	protected:
		void setUp(const math::Vector3& up);
		void setRight(const math::Vector3& right);
		void setFront(const math::Vector3& front);
	protected:
		// 头方向
		math::Vector3 _up;
		// 右边方向
		math::Vector3 _right;
		// 前方
		math::Vector3 _front;

		ZDirectionType _zDirection = ZDirectionType::OUTSIDE;

		// 默认头方向
		math::Vector3 _defaultUp;
		// 默认右边方向
		math::Vector3 _defaultRight;
		// 默认前方
		math::Vector3 _defaultFront;
	};
	
}