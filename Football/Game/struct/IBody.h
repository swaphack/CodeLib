#pragma once

namespace game
{
	struct Vector;
	/**
	*	�ռ�����
	*/
	class IBody
	{
	public:
		virtual ~IBody() {}
	public:
		/**
		*	��ת��ָ���Ƕ�
		*/
		virtual void rotateTo(float angle) const = 0;
		/**
		*	��תָ���Ƕ�
		*/
		virtual void rotateBy(float angle) const = 0;
		/**
		*	��ȡ����(��ת�Ƕ�)
		*/
		virtual float getRotation() const = 0;
		/**
		*	�ƶ���ָ��λ��
		*/
		virtual void moveTo(const Vector& point) const = 0;
		/**
		*	�ƶ�����
		*/
		virtual void moveBy(const Vector& point) const = 0;
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