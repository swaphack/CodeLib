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
		float getPositionX();

		float getPositionY();

		float getPositionZ();

		const math::Vector3& getPosition();
		// 设置缩放比
		void setScaleX(float x);

		void setScaleY(float y);

		void setScaleZ(float z);

		void setScale(float x, float y, float z);

		void setScale(const math::Vector3& scale);

		void setScale(float scale);
		// 获取缩放比
		float getScaleX();

		float getScaleY();

		float getScaleZ();

		const math::Vector3& getScale();
		// 设置旋转系数
		void setRotationX(float x);

		void setRotationY(float y);

		void setRotationZ(float z);

		void setRotation(float x, float y, float z);

		void setRotation(const math::Vector3& rotation);
		// 获取旋转系数
		float getRotationX();

		float getRotationY();

		float getRotationZ();

		const math::Vector3& getRotation();
	public:
		virtual void onSpaceChange() {}
	protected:
		// 位置坐标
		math::Vector3 _position;
		// 缩放比
		math::Vector3 _scale;
		// 旋转
		math::Vector3 _rotation;
	private:
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
		// 获取宽度
		float getAnchorPointX();
		// 获取高度
		float getAnchorPointY();
		// 获取深度
		float getAnchorPointZ();
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
}