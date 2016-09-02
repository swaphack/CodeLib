#pragma once

#include "../interface/IPropertySheet.h"

#include "Property.h"

#include <map>

namespace game
{
	class PropertySheet : public IPropertySheet
	{
	public:
		PropertySheet();
		virtual ~PropertySheet();
	public:
		virtual const IProperty* getProperty(int nPropertyType) const;

		virtual void addProperty(IProperty* pProperty);

		virtual void removeProperty(int nPropertyType);
	private:
		typedef std::map<int, IProperty*> Properties;

		Properties m_mProperties;
	};
}