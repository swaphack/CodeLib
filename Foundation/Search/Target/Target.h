#pragma once

#include <vector>
#include <string>
#include <set>

namespace search
{	
	// Ä¿±ê
	class Target
	{
	public:
		Target();
		virtual ~Target();
	public:
		virtual const char* getString();

		virtual void dispose();
	private:
		std::set<std::string*> _marks;
	}; 
}

template<>
struct std::less<Target*>
{
	bool operator()(Target* _X, Target* _Y) const
	{
		return _X->getString() < _Y->getString();
	}
};