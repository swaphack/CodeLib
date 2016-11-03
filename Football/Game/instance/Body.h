#pragma once

#include "../interface/IBody.h"

#include "../struct/Vector.h"

namespace game
{
	/**
	*	�Խŵ�Ϊ����
	*/
	class Body : public IBody
	{
	public:
		Body();
		virtual ~Body();
	public:
		/**
		*	���ó���
		*/
		void setLength(float value);
		/**
		*	��ȡ����
		*/
		virtual float getLength() const;
		/**
		*	���ÿ��
		*/
		void setWidth(float value);
		/**
		*	��ȡ���
		*/
		virtual float getWidth() const;
		/**
		*	���ø߶�
		*/
		void setHeight(float value);
		/**
		*	��ȡ�߶�
		*/
		virtual float getHeight() const;
		/**
		*	����x��λ��
		*/
		void setPositionX(float value);
		/**
		*	��ȡx��λ��
		*/
		virtual float getPositionX() const;
		/**
		*	����y��λ��
		*/
		void setPositionY(float value);
		/**
		*	��ȡy��λ��
		*/
		virtual float getPositionY() const;
		/**
		*	����z��λ��
		*/
		void setPositionZ(float value);
		/**
		*	��ȡz��λ��
		*/
		virtual float getPositionZ() const;
		/**
		*	�Ƿ��������ཻ
		*/
		virtual bool intersectBody(const IBody* pBody) const;
		/**
		*	��ȡλ��
		*/
		virtual const Vector& getPosition() const;
		/**
		*	����ĳһ��
		*/
		virtual void lookAt(const Vector& point);
	public:
		// ����
		Vector m_vPosition;
		// ���
		Vector m_vVolume;
	};
}