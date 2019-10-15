#pragma once

#include "Dictionary.h"
#include <string>
#include <cstring>

namespace game
{
	template<typename T>
	class Hash
	{
	public:
		Hash();
		virtual ~Hash();
	public:
		void set(const std::string& key, const T& value);

		T& get(std::string& key);

		int count();

		void clear();
	};


}