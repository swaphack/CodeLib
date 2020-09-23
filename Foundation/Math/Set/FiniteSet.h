#pragma once

#include <set>
#include <cstdint>

#include "Set.h"

namespace math
{
	/**
	*	有穷集
	*	可枚举
	*/
	template<typename T>
	class FiniteSet : public Set
	{
	public:
		FiniteSet() 
		{

		}
		FiniteSet(const FiniteSet& value)
		{
			*this = value;
		}
		virtual ~FiniteSet()
		{

		}
	public:
		/**
		*	是否包含元素
		*/
		virtual bool contains(const T& value) const
		{
			auto it = _elements.find(value);
			return it != _elements.end();
		}
	public:
		/**
		*	添加元素
		*/
		void addElement(const T& value)
		{
			_elements.insert(value);
		}
		/**
		*	移除元素
		*/
		void removeElement(const T& value)
		{
			_elements.erase(value);
		}
		/**
		*	移除所有元素
		*/
		void removeAllElements()
		{
			_elements.clear();
		}
		/**
		*	所有元素
		*/
		const std::set<T>& getAllElements() const
		{
			return _elements;
		}
		/**
		*	元素个数
		*/
		int32_t getCount() const
		{
			return _elements.size();
		}
	public:
		/**
		*	是否为空
		*/
		virtual bool isNone() const
		{
			return _elements.empty();
		}
		/**
		*	子集
		*	是否是目标的子集
		*	当前集合所有元素都在集合 value 中
		*/
		bool isSubSetEqual(const FiniteSet& value) const
		{
			if (this->getCount() > value.getCount())
			{
				return false;
			}
			auto values = this->getAllElements();
			for (auto& item : values)
			{
				if (!value.contains(item))
				{
					return false;
				}
			}

			return true;
		}
		/**
		*	真子集
		*	是否是目标的真子集
		*	当前集合的所有元素都在集合 value 中，并且两个集合不等同
		*/
		bool isSubSet(const FiniteSet& value) const
		{
			if (this->getCount() >= value.getCount())
			{
				return false;
			}

			if (this->isSubSetEqual(value))
			{
				return this->getCount() != value.getCount();
			}

			return false;
		}
		/**
		*	超集
		*	是否是目标的超集
		*	集合 value 中所有元素都在当前集合
		*/
		bool isSupSetEqual(const FiniteSet& value) const
		{
			return value.isSubSetEqual(*this);
		}
		/**
		*	真超集
		*	是否是目标的真超集
		*	集合 value 中的所有元素都在当前集合中，并且两个集合不等同
		*/
		bool isSupSet(const FiniteSet& value) const
		{
			return value.isSubSet(*this);
		}
		/**
		*	并集
		*/
		FiniteSet unionAll(const FiniteSet& value) const
		{
			FiniteSet set = *this;
			auto values = value.getAllElements();
			for (auto& item : values)
			{
				if (!this->contains(item))
				{
					set.addElement(item);
				}
			}
			return set;
		}
		/**
		*	交集
		*/
		FiniteSet intersect(const FiniteSet& value) const
		{
			FiniteSet set;
			auto values = value.getAllElements();
			for (auto& item : values)
			{
				if (this->contains(item))
				{
					set.addElement(item);
				}
			}
			return set;
		}
		/**
		*	补集
		*	排除包含目标的元素
		*/
		FiniteSet complementary(const FiniteSet& value) const
		{
			FiniteSet set = *this;
			auto values = value.getAllElements();
			for (auto& item : values)
			{
				if (this->contains(item))
				{
					set.removeElement(item);
				}
			}
			return set;
		}
		/**
		*	后继集
		*	排除包含目标的元素
		*/
		FiniteSet successor() const
		{
			FiniteSet outter = *this;
			FiniteSet set = *this;
			outter.addElement(set);
			return set;
		}
	public:
		FiniteSet operator+(const T& value) const
		{
			FiniteSet set = *this;
			set.addElement(value);
			return set;
		}
		FiniteSet operator-(const T& value) const
		{
			FiniteSet set = *this;
			set.removeElement(value);
			return set;
		}
		FiniteSet& operator+=(const T& value)
		{
			this->addElement(value);
			return *this;
		}
		FiniteSet& operator-=(const T& value)
		{
			this->removeElement(value);
			return *this;
		}
	public:
		FiniteSet& operator=(const FiniteSet& value)
		{
			this->removeAllElements();
			auto allElements = value.getAllElements();
			for (auto& item : allElements)
			{
				this->addElement(item);
			}

			return *this;
		}
		bool operator==(const FiniteSet& value) const
		{
			if (this->isSubSetEqual(value) && value.isSubSetEqual(*this))
			{
				return true;
			}

			return false;
		}
		bool operator!=(const FiniteSet& value) const
		{
			if (!this->isSubSetEqual(value) || !value.isSubSetEqual(*this))
			{
				return true;
			}

			return false;
		}
	private:
		/**
		*	元素
		*/
		std::set<T> _elements;
	};
}