#pragma once

#include <map>
#include "../macros.h"

namespace game
{
	class IPlayer;
	/**
	*	位置索引 {索引，(位置,球员）}
	*/
	typedef std::map<int, std::pair<int, int> > IndexPosition;
	/**
	*	阵型
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
		*	阵型描述
		*/
		CREATE_COMPONENT_PROPERTY(std::string, Describe);

	};
}