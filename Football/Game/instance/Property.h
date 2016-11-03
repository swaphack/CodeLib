#pragma once

#include <functional>

namespace game
{
	typedef std::function<void(int type, float newValue, float lastValue)> PropertyHandler;

	class Property
	{
	public:
		Property();
		~Property();
	public:
		/**
		*	������������
		*/
		void setType(int nType);
		/**
		*	��������
		*/
		int getType() const;
		/**
		*	��������ֵ
		*/
		void setValue(float fValue);
		/**
		*	��ȡ����ֵ
		*/
		float getValue() const;
		/**
		*	�ı�����ֵ
		*/
		void addValue(float value);
		/**
		*	�������Ըı�ʱ��֪ͨ
		*/
		void setChangedHandler(PropertyHandler handler);
		/**
		*	���Ըı�ʱ��֪ͨ
		*/
		PropertyHandler getChangedHandler();
		/**
		*	��¡
		*/
		Property* clone();
	protected:
		/**
		*	֪ͨ���Ըı�
		*/
		void onChangedHandler(float newValue);
	private:
		int m_nType;
		float m_nValue;
		PropertyHandler m_pHandler;
	};
}