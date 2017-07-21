#pragma once

namespace game
{
	struct Vector;
	/**
	*	����
	*/
	class IBody
	{
	public:
		virtual ~IBody() {}
	public:
		/**
		*	��ȡ����
		*/
		virtual float getLength() = 0;
		/**
		*	��ȡ���
		*/
		virtual float getWidth() = 0;
		/**
		*	��ȡ�߶�
		*/
		virtual float getHeight() = 0;
		/**
		*	��ȡx��λ��
		*/
		virtual float getPositionX() = 0;
		/**
		*	��ȡy��λ��
		*/
		virtual float getPositionY() = 0;
		/**
		*	��ȡz��λ��
		*/
		virtual float getPositionZ() = 0;
		/**
		*	�Ƿ��������ཻ
		*/
		virtual bool intersectBody(IBody* pBody) = 0;
		/**
		*	��ȡλ��
		*/
		virtual const Vector& getPosition() = 0;
		/**
		*	����ĳһ��
		*/
		virtual void lookAt(const Vector& point) = 0;
	};
}