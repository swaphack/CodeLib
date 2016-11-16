#pragma once

#include <functional>

namespace game
{
	typedef std::function<void(int type, float newValue, float lastValue)> PropertyHandler;

	/**
	*	����
	*/
	class Property
	{
	public:
		Property();
		~Property();
	public:
		/**
		*	������������
		*	@see eProperty
		*/
		void setType(int nType);
		/**
		*	��������
		*	@see eProperty
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
		*	��������ֵ
		*/
		void reset();
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
		// ����
		int m_nType;
		// ֵ
		float m_nValue;
		// ����ֵ�ı�ʱ����
		PropertyHandler m_pHandler;
	};
}