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
		CREATE_COMPONENT_PROPERTY(EBP_VOLUME_LENGTH, Length);
		/**
		*	��ȡ���
		*/
		CREATE_COMPONENT_PROPERTY(EBP_VOLUME_WIDTH, Width);
		/**
		*	��ȡ�߶�
		*/
		CREATE_COMPONENT_PROPERTY(EBP_VOLUME_HEIGHT, Height);
		/**
		*	��ȡx��λ��
		*/
		CREATE_COMPONENT_PROPERTY(EBP_POSITION_X, PositionX);
		/**
		*	��ȡy��λ��
		*/
		CREATE_COMPONENT_PROPERTY(EBP_POSITION_Y, PositionY);
		/**
		*	��ȡz��λ��
		*/
		CREATE_COMPONENT_PROPERTY(EBP_POSITION_Z, PositionZ);
		/**
		*	�Ƿ��������ཻ
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