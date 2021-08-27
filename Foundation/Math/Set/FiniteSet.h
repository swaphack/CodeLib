#pragma once

#include <set>
#include <cstdint>
#include <map>

#include "Set.h"

namespace math
{
	/**
	*	���
	*	��ö��
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
		*	�Ƿ����Ԫ��
		*/
		virtual bool contains(const T& value) const
		{
			auto it = _elements.find(value);
			return it != _elements.end();
		}
	public:
		/**
		*	���Ԫ��
		*/
		void addElement(const T& value)
		{
			_elements.insert(value);
		}
		/**
		*	�Ƴ�Ԫ��
		*/
		void removeElement(const T& value)
		{
			_elements.erase(value);
		}
		/**
		*	�Ƴ�����Ԫ��
		*/
		void removeAllElements()
		{
			_elements.clear();
		}
		/**
		*	����Ԫ��
		*/
		const std::set<T>& getAllElements() const
		{
			return _elements;
		}
		/**
		*	Ԫ�ظ���
		*/
		int32_t getCount() const
		{
			return _elements.size();
		}
	public:
		/**
		*	�Ƿ�Ϊ��
		*/
		virtual bool isEmpty() const
		{
			return _elements.empty();
		}
		/**
		*	�Ӽ�
		*	�Ƿ���Ŀ����Ӽ�
		*	��ǰ��������Ԫ�ض��ڼ��� value ��
		*/
		bool isSubSetOrEqual(const FiniteSet& value) const
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
		*	���Ӽ�
		*	�Ƿ���Ŀ������Ӽ�
		*	��ǰ���ϵ�����Ԫ�ض��ڼ��� value �У������������ϲ���ͬ
		*/
		bool isSubSet(const FiniteSet& value) const
		{
			if (this->getCount() >= value.getCount())
			{
				return false;
			}

			if (this->isSubSetOrEqual(value))
			{
				return this->getCount() != value.getCount();
			}

			return false;
		}
		/**
		*	����
		*	�Ƿ���Ŀ��ĳ���
		*	���� value ������Ԫ�ض��ڵ�ǰ����
		*/
		bool isSupSetOrEqual(const FiniteSet& value) const
		{
			return value.isSubSetOrEqual(*this);
		}
		/**
		*	�泬��
		*	�Ƿ���Ŀ����泬��
		*	���� value �е�����Ԫ�ض��ڵ�ǰ�����У������������ϲ���ͬ
		*/
		bool isSupSet(const FiniteSet& value) const
		{
			return value.isSubSet(*this);
		}
		/**
		*	����
		*/
		FiniteSet getUnionSet(const FiniteSet& value) const
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
		*	����
		*/
		FiniteSet getIntersectSet(const FiniteSet& value) const
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
		*	����
		*	�ų�����Ŀ���Ԫ��
		*/
		FiniteSet getComplementarySet(const FiniteSet& value) const
		{
			FiniteSet set = *this;
			auto values = value.getAllElements();
			for (const auto& item : values)
			{
				if (this->contains(item))
				{
					set.removeElement(item);
				}
			}
			return set;
		}
		/**
		*	��̼�
		*	�ų�����Ŀ���Ԫ��
		*/
		FiniteSet getSuccessor() const
		{
			FiniteSet outter = *this;
			FiniteSet set = *this;
			outter.addElement(set);
			return set;
		}


		typedef std::pair<T, T> TUPLE2;
		/**
		*	�ѿ�����
		*/
		FiniteSet<TUPLE2> getCartesianProduct(const FiniteSet& target)
		{
			FiniteSet<TUPLE2> values;
			for (auto item0 : _elements)
			{
				for (auto item1 : target.getAllElements())
				{
					values.addElement(TUPLE(item0, item1));
				}
			}

			return values;
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
			if (this->isSubSetOrEqual(value) && value.isSubSetOrEqual(*this))
			{
				return true;
			}

			return false;
		}
		bool operator!=(const FiniteSet& value) const
		{
			if (!this->isSubSetOrEqual(value) || !value.isSubSetOrEqual(*this))
			{
				return true;
			}

			return false;
		}
	private:
		/**
		*	Ԫ��
		*/
		std::set<T> _elements;
	};
}