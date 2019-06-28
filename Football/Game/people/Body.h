#pragma once

#include "../struct/Vector.h"

#include "../base/Component.h"
#include "../enum/eProperty.h"

namespace game
{
	/**
	*	����
	*	�Խŵ�Ϊ����
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
		*	��ȡ����
		*/
		CREATE_COMPONENT_PROPERTY(float, Length);
		/**
		*	��ȡ���
		*/
		CREATE_COMPONENT_PROPERTY(float, Width);
		/**
		*	��ȡ�߶�
		*/
		CREATE_COMPONENT_PROPERTY(float, Height);
		/**
		*	��ȡx��λ��
		*/
		CREATE_COMPONENT_PROPERTY(float, PositionX);
		/**
		*	��ȡy��λ��
		*/
		CREATE_COMPONENT_PROPERTY(float, PositionY);
		/**
		*	��ȡz��λ��
		*/
		CREATE_COMPONENT_PROPERTY(float, PositionZ);
		/**
		*	�Ƿ������������ཻ
		*/
		virtual bool intersectBody(Body* pBody);
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