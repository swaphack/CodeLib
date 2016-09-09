#pragma once

#include "IRole.h"

namespace game
{
	class IPropertySheet;
	class IFormation;

	/**
	*	����
	*/
	class ICoach : public IRole
	{
	public:
		virtual ~ICoach() {}
	public:
		/**
		*	��ȡ��������
		*/
		virtual const IPropertySheet* getCoachProperty() const = 0;
	};
}