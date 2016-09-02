#pragma once

#include "../interface/IProperty.h"

namespace game
{
	class Property : public IProperty
	{
	public:
		Property();
		virtual ~Property();
	public:
		void setType(int nType);
		virtual int getType();
		void setValue(float fValue);
		virtual float getValue();
	private:
		int m_type;
		float m_value;
	};
}