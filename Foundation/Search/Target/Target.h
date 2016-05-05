#pragma once

#include <vector>
#include <string>

namespace search
{	
	// Ä¿±ê
	class Target
	{
	public:
		Target() {}
		virtual ~Target() {}
	public:
		virtual const char* getString() { return ""; }

		virtual void dispose() { delete this; }
	}; 

	// ×Ö·û´®
	class StringTarget : public Target
	{
	public:
		StringTarget(const char* text);
	public:
		void setString(const char* text);
		virtual const char* getString();
	protected:
	private:
		std::string _text;
	};
}