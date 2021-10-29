#pragma once

#include <cstdint>

namespace sys
{
	class Bit
	{
	public:
		Bit();
		virtual ~Bit();
	public:
		bool isZero(uint64_t idx) const;
		void set(uint64_t idx, uint8_t value);
		void setZero(uint64_t idx);
		void setOne(uint64_t idx);
	private:
		// 内存分配大小
		uint32_t m_nCapactiy = 0;
		// 数据
		uint8_t* m_pData = nullptr;
		// 长度
		uint64_t m_nLength = 0;
	};
}