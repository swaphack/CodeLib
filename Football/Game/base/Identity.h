#pragma once

#include <string>
#include <cstdint>

#include "Dictionary.h"

namespace game
{
	/**
	*	编号
	*/
	class Identity
	{
	public:
		Identity();
		virtual ~Identity();
	public:
		/**
		*	获取编号
		*/
		uint64_t getID();
		/**
		*	设置编号
		*/
		void setID(uint64_t nID);
	private:
		uint64_t _id = 0;
	};

	/**
	*	编号容器
	*/
	class IdentityContainer : public Dictionary<uint64_t, Identity*>
	{
	public:
		IdentityContainer();
		virtual ~IdentityContainer();
	public:
		/**
		*	添加项
		*/
		void add(Identity* value);
		/**
		*	移除项
		*/
		void remove(Identity* value);

		template<typename T,
			typename = std::enable_if<std::is_base_of<Identity, T>::value, T>::type>
		T* get(uint64_t id);
	protected:
		/**
		*	清除值
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