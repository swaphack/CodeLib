#pragma once

#include "Human.h"

#include <map>

namespace slg
{
	class Human;
	// ¼ÒÍ¥
	class Family
	{
	public:
		Family();
		~Family();
	public:
		// ¸¸Ç×
		const Human* getFather();
		void setFather(const Human* father);

		// Ä¸Ç×
		const Human* getMonther();
		void setMonther(const Human* monther);

		// Ìí¼Óº¢×Ó
		void addChild(const Human* child);
		// ÒÆ³ýº¢×Ó
		void removeChild(const Human* child);
		// ²éÕÒº¢×Ó
		const Human* getChild(const char* name);
	protected:
		// ¸¸
		Human* _father;
		// Ä¸
		Human* _monther;
		// º¢×Ó
		std::map<std::string, Human*> _children;
	};
}