#pragma once

#include "IRole.h"

namespace game
{
	class IPropertySheet;
	class IFormation;

	/**
	*	教练
	*/
	class ICoach : public IRole
	{
	public:
		virtual ~ICoach() {}
	public:
		/**
		*	获取教练属性
		*/
		virtual const IPropertySheet* getCoachProperty() const = 0;
	};
}