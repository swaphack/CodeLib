#pragma once

#include "../interface/IBody.h"

#include "../struct/Vector.h"

#include "Component.h"
#include "../enum/eProperty.h"

namespace game
{
	/**
	*	����
	*	�Խŵ�Ϊ����
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
		*	��ȡ����
		*/
		CREATE_COMPONENT_PROPERTY( SpaceType::Length, Length);
		/**
		*	��ȡ���
		*/
		CREATE_COMPONENT_PROPERTY( SpaceType::Width, Width);
		/**
		*	��ȡ�߶�
		*/
		CREATE_COMPONENT_PROPERTY( SpaceType::Height, Height);
		/**
		*	��ȡx��λ��
		*/
		CREATE_COMPONENT_PROPERTY(SpaceType::PositionX, PositionX);
		/**
		*	��ȡy��λ��
		*/
		CREATE_COMPONENT_PROPERTY(SpaceType::PositionY, PositionY);
		/**
		*	��ȡz��λ��
		*/
		CREATE_COMPONENT_PROPERTY(SpaceType::PositionZ, PositionZ);
		/**
		*	�Ƿ������������ཻ
		*/
		virtual bool intersectBody(IBody* pBody);
		/**
		*	��ȡλ��
		*/
		virtual Vector getPosition();
		/**
		*	����ĳһ��
		*/
		virtual void lookAt(const Vector& point);
	};
}