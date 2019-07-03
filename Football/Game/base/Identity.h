#pragma once

#include <string>
#include <cstdint>

#include "Dictionary.h"

namespace game
{
	/**
	*	���
	*/
	class Identity
	{
	public:
		Identity();
		virtual ~Identity();
	public:
		/**
		*	��ȡ���
		*/
		uint64_t getID();
		/**
		*	���ñ��
		*/
		void setID(uint64_t nID);
	private:
		uint64_t _id = 0;
	};

	/**
	*	�������
	*/
	class IdentityContainer : public Dictionary<uint64_t, Identity*>
	{
	public:
		IdentityContainer();
		virtual ~IdentityContainer();
	public:
		/**
		*	�����
		*/
		void add(Identity* value);
		/**
		*	�Ƴ���
		*/
		void remove(Identity* value);

		template<typename T,
			typename = std::enable_if<std::is_base_of<Identity, T>::value, T>::type>
		T* get(uint64_t id);
	protected:
		/**
		*	���ֵ
		*/
		virtual void destoryValue(Identity* value);
	private:
	};

	template<typename T,
		typename = std::enable_if<std::is_base_of<Identity, T>::value, T>::type>
	T* IdentityContainer::get(uint64_t id)
	{
		auto pItem = this->find(id);
		if (pItem == nullptr)
		{
			return nullptr;
		}
		return static_cast<T*>(pItem);
	}

}