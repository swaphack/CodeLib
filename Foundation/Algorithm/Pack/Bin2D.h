#pragma once

#include "mathlib.h"
#include <vector>
#include <map>

namespace alg
{
	/**
	*	2dװ��
	*/
	class Bin2D
	{
	public:
		struct Item
		{
			int id = 0;
			int width = 0;
			int height = 0;
			int x = 0;
			int y = 0;
			bool rotate = false;
		};
	public:
		Bin2D();
		~Bin2D();
	public:
		/**
		*	���ô�С
		*/
		void setSize(int width, int height);
		/**
		*	�����Ʒ
		*/
		void addItem(int id, int width, int height);
	public:
		/**
		*	���
		*/
		bool pack(std::vector<Item>& items);
	private:
		// ���
		int _width = 0;
		// �߶�
		int _height = 0;
		// ��Ʒ
		std::vector<Item> _items;
	};
}