#pragma once

#include "mathlib.h"

#include <vector>
#include <map>

namespace alg
{
	namespace space
	{
		/**
		*	һάװ���㷨
		*/
		class BinPacking1D
		{
		public:
			// �����ʽ
			enum class PackingMethod
			{
				// Next - Fit Decreasing Height
				NFDH,
				// First - Fit Decreasing Height
				FFDH,
				// Best - Fit Decreasing Height
				BFDH,
			};
		public:
			/**
			*	��Ʒ��Ϣ
			*/
			struct Item
			{
				// ��Ʒ���
				int32_t id = 0;
				// ����
				int32_t length = 0;
				// λ��
				int32_t x = 0;
				// �������ӱ��
				int32_t box = -1;

				bool operator==(const Item& item)
				{
					return id == item.id;
				}

				bool operator!=(const Item& item)
				{
					return id != item.id;
				}

				// ����
				void reset()
				{
					box = -1;
					x = 0;
				}
			};
			/**
			*	������Ϣ
			*/
			struct Box
			{
				// ���ӱ��
				int32_t id = 0;
				// ����
				int32_t length = 0;
				// ƫ��λ��
				int32_t offset = 0;
				// ����
				std::vector<Item> items;

				// ʣ��ռ�
				int32_t remain() const
				{
					return length - offset;
				}

				// �Ƿ��������Ʒ
				bool canAddItem(const Item& item)
				{
					return item.length + offset <= length;
				}
				// �����Ʒ
				void addItem(const Item& item)
				{
					Item temp = item;
					temp.box = id;
					temp.x = offset;
					offset += temp.length;
					items.push_back(temp);
				}
				// �Ƴ�������Ʒ
				void removeAllItems()
				{
					for (size_t i = 0; i < items.size(); i++)
					{
						items[i].reset();
					}
					items.clear();
				}
			};
		public:
			BinPacking1D();
			~BinPacking1D();
		public:
			/**
			*	�����Ʒ
			*/
			void addItem(int32_t id, int32_t length);
			/**
			*	�Ƴ���Ʒ
			*/
			void removeItem(int32_t id);
			/**
			*	�Ƴ�������Ʒ
			*/
			void removeAllItems();
			/**
			*	����Ʒ����������������Ʒ�����ȴӴ�С����
			*/
			void sortItems();
		public:
			/**
			*	���װ�䷽��
			*/
			bool getPackWay(int length, PackingMethod method, std::vector<Box>& boxes);
		protected:
			/**
			*	First - Fit Decreasing Height
			*/
			bool createPackWayWithFFDH(Box& box, const std::vector<Item>& items, std::vector<Item>& remains);
			/**
			*	Next - Fit Decreasing Height
			*/
			bool createPackWayWithNFDH(Box& box, const std::vector<Item>& items, std::vector<Item>& remains);
			/**
			*	Best - Fit Decreasing Height
			*/
			bool createPackWayWithBFDH(Box& box, const std::vector<Item>& items, std::vector<Item>& remains);
		private:
			/**
			*	��Ʒ
			*/
			std::vector<Item> _items;
		};
	}
}