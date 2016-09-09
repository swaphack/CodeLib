#pragma once

namespace game
{
	class Vector;
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
		virtual float getLength() const = 0;
		/**
		*	��ȡ���
		*/
		virtual float getWidth() const = 0;
		/**
		*	��ȡ�߶�
		*/
		virtual float getHeight() const = 0;
		/**
		*	��ȡx��λ��
		*/
		virtual float getPositionX() const = 0;
		/**
		*	��ȡy��λ��
		*/
		virtual float getPositionY() const = 0;
		/**
		*	��ȡz��λ��
		*/
		virtual float getPositionZ() const = 0;
		/**
		*	�Ƿ��������ཻ
		*/
		virtual bool intersectBody(const IBody* pBody) const = 0;
		/**
		*	��ȡλ��
		*/
		virtual const Vector& getPosition() const = 0;
		/**
		*	����ĳһ��
		*/
		virtual void lookAt(const Vector& point) const = 0;
	};
}