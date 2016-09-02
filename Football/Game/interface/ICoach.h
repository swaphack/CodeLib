#pragma once

#include "IPerson.h"

namespace game
{
	class IPropertySheet;
	class IRole;
	class IFormation;

	/**
	*	����
	*/
	class ICoach : public IPerson
	{
	public:
		virtual ~ICoach() {}
	public:
		/**
		*	���ݽ�ɫ
		*/
		virtual const IRole* getRole() const = 0;
	};
}