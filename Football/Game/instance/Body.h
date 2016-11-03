#pragma once

#include "../interface/IBody.h"

#include "../struct/Vector.h"

namespace game
{
	/**
	*	以脚底为中心
	*/
	class Body : public IBody
	{
	public:
		Body();
		virtual ~Body();
	public:
		/**
		*	设置长度
		*/
		void setLength(float value);
		/**
		*	获取长度
		*/
		virtual float getLength() const;
		/**
		*	设置宽度
		*/
		void setWidth(float value);
		/**
		*	获取宽度
		*/
		virtual float getWidth() const;
		/**
		*	设置高度
		*/
		void setHeight(float value);
		/**
		*	获取高度
		*/
		virtual float getHeight() const;
		/**
		*	设置x轴位置
		*/
		void setPositionX(float value);
		/**
		*	获取x轴位置
		*/
		virtual float getPositionX() const;
		/**
		*	设置y轴位置
		*/
		void setPositionY(float value);
		/**
		*	获取y轴位置
		*/
		virtual float getPositionY() const;
		/**
		*	设置z轴位置
		*/
		void setPositionZ(float value);
		/**
		*	获取z轴位置
		*/
		virtual float getPositionZ() const;
		/**
		*	是否与其他相交
		*/
		virtual bool intersectBody(const IBody* pBody) const;
		/**
		*	获取位置
		*/
		virtual const Vector& getPosition() const;
		/**
		*	看向某一点
		*/
		virtual void lookAt(const Vector& point);
	public:
		// 坐标
		Vector m_vPosition;
		// 体积
		Vector m_vVolume;
	};
}