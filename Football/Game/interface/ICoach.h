#pragma once

#include "IPerson.h"

namespace game
{
	class IPropertySheet;
	class IRole;
	class IFormation;

	/**
	*	½ÌÁ·
	*/
	class ICoach : public IPerson
	{
	public:
		virtual ~ICoach() {}
	public:
		/**
		*	°çÑÝ½ÇÉ«
		*/
		virtual const IRole* getRole() const = 0;
	};
}