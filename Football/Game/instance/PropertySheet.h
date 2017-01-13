#pragma once


#include "Property.h"

#include <map>
#include <functional>

namespace game
{
	/**
	*	�����б�
	*/
	class PropertySheet
	{
	public:
		PropertySheet();
		~PropertySheet();
	public:
		/**
		*	��ȡ����
		*/
		Property* getProperty(int nPropertyType);
		/**
		*	�������
		*	����µ�����ǰ�����ж��Ƿ����
		*/
		void addProperty(Property* pProperty);
		/**
		*	�Ƴ�����
		*/
		void removeProperty(int nPropertyType);
		/**
		*	�Ƴ���������
		*/
		void removeAllProperties();
		/**
		*	����
		*/
		void foreach(const std::function<void(Property*)>& handler);
		/**
		*	��¡
		*/
		PropertySheet* clone();
	private:
		typedef std::map<int, Property*> Properties;
		// ���Լ���
		Properties m_mProperties;
	};
}