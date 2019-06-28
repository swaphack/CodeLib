#pragma once

#include "../struct/Vector.h"

#include "../base/Component.h"
#include "../enum/eProperty.h"

namespace game
{
	/**
	*	躯体
	*	以脚底为中心
	*/
	class Body : public Component
	{
	public:
		Body();
		virtual ~Body();
	public:
		CREATE_COMPONENT_TYPE();

		CREATE_COMPONENT_CLONE(Body);

		/**
		*	获取长度
		*/
		CREATE_COMPONENT_PROPERTY(float, Length);
		/**
		*	获取宽度
		*/
		CREATE_COMPONENT_PROPERTY(float, Width);
		/**
		*	获取高度
		*/
		CREATE_COMPONENT_PROPERTY(float, Height);
		/**
		*	获取x轴位置
		*/
		CREATE_COMPONENT_PROPERTY(float, PositionX);
		/**
		*	获取y轴位置
		*/
		CREATE_COMPONENT_PROPERTY(float, PositionY);
		/**
		*	获取z轴位置
		*/
		CREATE_COMPONENT_PROPERTY(float, PositionZ);
		/**
		*	是否与其他躯体相交
		*/
		virtual bool intersectBody(Body* pBody);
		/**
		*	获取位置
		*/
		virtual Vector getPosition();
		/**
		*	看向某一点
		*/
		virtual void lookAt(const Vector& point);
	};
}