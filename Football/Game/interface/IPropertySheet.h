#pragma once

namespace game
{
	class IProperty;

	/**
	*	�����б�
	*/
	class IPropertySheet
	{
	public:
		virtual ~IPropertySheet() {}
	public:
		/**
		*	��ȡ����
		*/
		virtual const IProperty* getProperty(int nPropertyType) const = 0;
		/**
		*	�������
		*/
		virtual void addProperty(IProperty* pProperty) = 0;
		/**
		*	�Ƴ�����
		*/
		virtual void removeProperty(int nPropertyType) = 0;
	};
}