#pragma once

#include <map>
#include "../macros.h"

namespace game
{
	class IPlayer;
	/**
	*	λ������ {������(λ��,��Ա��}
	*/
	typedef std::map<int, std::pair<int, int> > IndexPosition;
	/**
	*	����
	*/
	class Formation : public Component
	{
	public:
		Formation();
		virtual ~Formation();
	public:
		CREATE_COMPONENT_TYPE();
		CREATE_COMPONENT_CLONE(Formation);
	public:
		/**
		*	��������
		*/
		CREATE_COMPONENT_PROPERTY(std::string, Describe);

	};
}