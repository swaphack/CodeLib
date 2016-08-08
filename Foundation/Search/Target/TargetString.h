#pragma once

#include <vector>
#include <string>
#include "Target.h"

namespace search
{
	// ×Ö·û´®
	class TargetString : public Target
	{
	public:
		TargetString(const char* text);
	public:
		void setString(const char* text);
		virtual const char* getString();
	protected:
	private:
		std::string _text;
	};
}