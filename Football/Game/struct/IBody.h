#pragma once

namespace game
{
	struct Vector;
	/**
	*	空间身体
	*/
	class IBody
	{
	public:
		virtual ~IBody() {}
	public:
		/**
		*	旋转到指定角度
		*/
		virtual void rotateTo(float angle) const = 0;
		/**
		*	旋转指定角度
		*/
		virtual void rotateBy(float angle) const = 0;
		/**
		*	获取朝向(旋转角度)
		*/
		virtual float getRotation() const = 0;
		/**
		*	移动到指定位置
		*/
		virtual void moveTo(const Vector& point) const = 0;
		/**
		*	移动增量
		*/
		virtual void moveBy(const Vector& point) const = 0;
		/**
		*	获取位置
		*/
		virtual const Vector& getPosition() const = 0;
		/**
		*	看向某一点
		*/
		virtual void lookAt(const Vector& point) const = 0;
	};
}