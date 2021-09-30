#pragma once

#include "mathlib.h"

#include <vector>
#include <map>

namespace alg
{
	/**
	*	��ά��װ��
	*/
	class Container2D
	{
	public:
		/**
		*	��ά����
		*/
		struct Item
		{
			int boxID = 0;

			math::Size Size;
		};
	public:
		Container2D();
		~Container2D();
	public:
		/**
		*	���ô�С
		*/
		void setSize(const math::Size& size);
		/**
		*	��ȡ��С
		*/
		const math::Size& getSize() const;
	public:
		/**
		*	�����Ʒ
		*/
		void addItem(const Container2D::Item& item);
		/**
		*	�Ƴ���Ʒ
		*/
		void removeItem(const Container2D::Item& item);
		/**
		*	�Ƴ�������Ʒ
		*/
		void removeAllItems();
	public:
		/**
		*	��ó��з���
		*/
		bool getLayoutWay(std::map<int, math::Vector2>& positions);
	private:
		/**
		*	λ��
		*/
		math::Size _containerSize;
		/**
		*	��Ʒ
		*/
		std::map<int, Item> _items;
	};
}