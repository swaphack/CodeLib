#pragma once

#include <vector>
#include <string>
#include <set>

namespace search
{	
	// Ŀ��
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
struct std::less<search::Target*>
{
	bool operator()(search::Target* _X, search::Target* _Y) const
	{
		return _X->getString() < _Y->getString();
	}
};