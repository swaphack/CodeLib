#pragma once

#include <cstdint>

namespace sys
{
	class Bit
	{
	public:
		Bit();
		~Bit();
	public:
		bool isZero(uint64 idx);
		void set(uint64 idx, bool value);
		void setZero(uint64 idx);
		void setOne(uint64 idx);
	private:
		uint64 _size;
	};
}