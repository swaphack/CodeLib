#pragma once


#include "Property.h"

#include <map>
#include <functional>

namespace game
{
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
		void foreach(std::function<void(Property*)> handler);
		/**
		*	��¡
		*/
		PropertySheet* clone();
	private:
		typedef std::map<int, Property*> Properties;

		Properties m_mProperties;
	};
}