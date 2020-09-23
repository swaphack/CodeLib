#pragma once

#include <cstdint>
#include <set>
#include <vector>

namespace alg
{
	namespace map
	{
		/**
		*	多状态
		*/
		class MultiState
		{
		public:
			MultiState();
			virtual ~MultiState();
		public:
			/**
			*	设置状态
			*/
			void set(const std::vector<uint32_t>& states);
			/**
			*	添加状态
			*/
			void add(uint32_t state);
			/**
			*	移除状态
			*/
			void remove(uint32_t state);
			/**
			*	是否有状态
			*/
			bool has(uint32_t state);
			/**
			*	获取状态
			*/
			uint32_t get(uint32_t index);
			/**
			*	状态数量
			*/
			uint32_t getCount() const;
			/**
			*	是否为空
			*/
			bool isEmpty() const;
			/**
			*	清空
			*/
			void removeAllStates();
			/**
			*	所有状态
			*/
			const std::vector<uint32_t>& getAllStates() const;
		private:
			// 状态
			std::vector<uint32_t> _states;
		};
	}
}