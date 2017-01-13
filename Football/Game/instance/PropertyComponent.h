#pragma once

#include "Component.h"
#include "PropertySheet.h"

namespace game
{
	/**
	*	���Կؼ�
	*/
	class PropertyComponent : Component
	{
	public:
		/**
		*	���������ȡ���Ժ��������Է���, ����Ϊʵ������
		*	@param Enum ö��
		*	@param FunName ��������
		*	@param Type ����
		*/
#define CREATE_COMPONENT_PROPERTY2(Enum, FunName, Type) \
	public:\
	void set##FunName(Type value) { setPropertyValue((int)Enum, (Type)(value)); } \
	virtual Type get##FunName() { return (Type)(getPropertyValue((int)Enum)); }

		/**
		*	�����������, Ĭ��float����
		*	@param Enum ö��
		*	@param FunName ��������
		*/
#define CREATE_COMPONENT_PROPERTY(Enum, FunName) CREATE_COMPONENT_PROPERTY2(Enum, FunName, float)
	public:
		PropertyComponent();
		virtual ~PropertyComponent();
	public:
		/**
		*	��������ֵ
		*/
		void setPropertyValue(int key, float value);
		/**
		*	��������ֵ
		*/
		void setPropertyChangedHandler(int key, PropertyHandler handler);
		/**
		*	��ȡ����ֵ
		*/
		float getPropertyValue(int key);
	protected:
		PropertySheet* getPropertySheet();
	private:
		PropertySheet m_PropertySheet;
	};
}