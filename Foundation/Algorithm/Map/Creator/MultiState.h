#pragma once

#include <cstdint>
#include <set>
#include <vector>

namespace alg
{
	/**
	*	¶à×´Ì¬
	*/
	class MultiState
	{
	public:
		MultiState();
		virtual ~MultiState();
	public:
		/**
		*	Ìí¼Ó×´Ì¬
		*/
		void add(uint32_t status);
		/**
		*	ÒÆ³ý×´Ì¬
		*/
		void remove(uint32_t status);
		/**
		*	ÊÇ·ñÓÐ×´Ì¬
		*/
		bool has(uint32_t status);
		/**
		*	»ñÈ¡×´Ì¬
		*/
		uint32_t get(uint32_t index);
		/**
		*	×´Ì¬ÊýÁ¿
		*/
		uint32_t getCount() const;
		/**
		*	ÊÇ·ñÎª¿Õ
		*/
		bool isEmpty() const;
		/**
		*	Çå¿Õ
		*/
		void removeAllStates();
	private:
		// ×´Ì¬
		std::vector<uint32_t> _statusVec;
	};
}
