#pragma once

#include "../interface/IBody.h"

#include "../struct/Vector.h"

#include "Component.h"
#include "../enum/eProperty.h"

namespace game
{
	/**
	*	身躯
	*	以脚底为中心
	*/
	class Body : public Component, public IBody
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
		CREATE_COMPONENT_PROPERTY(eSpaceProperty_Volume_Length, Length);
		/**
		*	获取宽度
		*/
		CREATE_COMPONENT_PROPERTY(eSpaceProperty_Volume_Width, Width);
		/**
		*	获取高度
		*/
		CREATE_COMPONENT_PROPERTY(eSpaceProperty_Volume_Height, Height);
		/**
		*	获取x轴位置
		*/
		CREATE_COMPONENT_PROPERTY(eSpaceProperty_Position_X, PositionX);
		/**
		*	获取y轴位置
		*/
		CREATE_COMPONENT_PROPERTY(eSpaceProperty_Position_Y, PositionY);
		/**
		*	获取z轴位置
		*/
		CREATE_COMPONENT_PROPERTY(eSpaceProperty_Position_Z, PositionZ);
		/**
		*	是否与其他相交
		*/
		virtual bool intersectBody(IBody* pBody);
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