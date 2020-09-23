#pragma once

#include <cstdint>
#include <set>
#include <vector>

namespace alg
{
	namespace map
	{
		/**
		*	��״̬
		*/
		class MultiState
		{
		public:
			MultiState();
			virtual ~MultiState();
		public:
			/**
			*	����״̬
			*/
			void set(const std::vector<uint32_t>& states);
			/**
			*	���״̬
			*/
			void add(uint32_t state);
			/**
			*	�Ƴ�״̬
			*/
			void remove(uint32_t state);
			/**
			*	�Ƿ���״̬
			*/
			bool has(uint32_t state);
			/**
			*	��ȡ״̬
			*/
			uint32_t get(uint32_t index);
			/**
			*	״̬����
			*/
			uint32_t getCount() const;
			/**
			*	�Ƿ�Ϊ��
			*/
			bool isEmpty() const;
			/**
			*	���
			*/
			void removeAllStates();
			/**
			*	����״̬
			*/
			const std::vector<uint32_t>& getAllStates() const;
		private:
			// ״̬
			std::vector<uint32_t> _states;
		};
	}
}