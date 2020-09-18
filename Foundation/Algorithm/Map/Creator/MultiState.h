#pragma once

#include <cstdint>
#include <set>
#include <vector>

namespace alg
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
		*	���״̬
		*/
		void add(uint32_t status);
		/**
		*	�Ƴ�״̬
		*/
		void remove(uint32_t status);
		/**
		*	�Ƿ���״̬
		*/
		bool has(uint32_t status);
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
	private:
		// ״̬
		std::vector<uint32_t> _statusVec;
	};
}
