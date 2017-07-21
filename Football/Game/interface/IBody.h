#pragma once

namespace game
{
	struct Vector;
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
		virtual float getLength() = 0;
		/**
		*	获取宽度
		*/
		virtual float getWidth() = 0;
		/**
		*	获取高度
		*/
		virtual float getHeight() = 0;
		/**
		*	获取x轴位置
		*/
		virtual float getPositionX() = 0;
		/**
		*	获取y轴位置
		*/
		virtual float getPositionY() = 0;
		/**
		*	获取z轴位置
		*/
		virtual float getPositionZ() = 0;
		/**
		*	是否与其他相交
		*/
		virtual bool intersectBody(IBody* pBody) = 0;
		/**
		*	获取位置
		*/
		virtual const Vector& getPosition() = 0;
		/**
		*	看向某一点
		*/
		virtual void lookAt(const Vector& point) = 0;
	};
}