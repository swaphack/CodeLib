#pragma once

namespace game
{
	class Vector;
	/**
	*	躯体
	*/
	class IBody
	{
	public:
		virtual ~IBody() {}
	public:
		/**
		*	获取长度
		*/
		virtual float getLength() const = 0;
		/**
		*	获取宽度
		*/
		virtual float getWidth() const = 0;
		/**
		*	获取高度
		*/
		virtual float getHeight() const = 0;
		/**
		*	获取x轴位置
		*/
		virtual float getPositionX() const = 0;
		/**
		*	获取y轴位置
		*/
		virtual float getPositionY() const = 0;
		/**
		*	获取z轴位置
		*/
		virtual float getPositionZ() const = 0;
		/**
		*	是否与其他相交
		*/
		virtual bool intersectBody(const IBody* pBody) const = 0;
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