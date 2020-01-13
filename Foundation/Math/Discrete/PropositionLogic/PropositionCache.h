#pragma once

#include "Basic/Collection/NodeCache.h"
#include "Proposition.h"

namespace math
{
	/**
	*	���⻺��
	*/
	class PropositionCache : public NodeCache
	{
	public:
		PropositionCache();
		virtual ~PropositionCache();
	public:
		/**
		*	�����ڵ�
		*/
		template<typename T, typename = typename std::enable_if<std::is_base_of<Proposition, T>::value, T>::type>
		T* createProposition()
		{
			T* t = new T();
			t->setInstanceID(++_instanceID);
			this->addNode(t);
			return t;
		}
	private:
		static uint64_t _instanceID;
	};
}