#pragma once

#include "Map/Base/MapObject.h"

namespace alg
{
	namespace map
	{
		/*
		*	关系二维表
		*/
		template<const uint32_t Column, const uint32_t Row>
		class RelationTable : public MapObject
		{
		public:
			RelationTable()
			{
				this->initRelationTable();
			}
			virtual ~RelationTable()
			{

			}
		public:
			/**
			*	设置值
			*/
			void setValue(uint32_t i, uint32_t j, uint8_t value)
			{
				if (i < Column && j < Row)
				{
					_relation[i][j] = value;
				}
			}
			/**
			*	获取值
			*/
			uint8_t getValue(uint32_t i, uint32_t j) const
			{
				if (i < Column && j < Row)
				{
					return _relation[i][j];
				}

				return 0;
			}

			/**
			*	获取关联的列
			*/
			bool getColumnRelations(uint32_t column, uint8_t value, std::vector<uint32_t>& relations)  const
			{
				if (column >= Column)
				{
					return false;
				}

				for (size_t i = 0; i < Column; i++)
				{
					if (getValue(i, column) == value)
					{
						relations.push_back(i);
					}
				}

				return relations.size() > 0;
			}

			/**
			*	获取关联的行
			*/
			bool getRowRelations(uint32_t row, uint8_t value, std::vector<uint32_t>& relations)  const
			{
				if (row >= Row)
				{
					return false;
				}

				for (size_t i = 0; i < Row; i++)
				{
					if (getValue(row, i) == value)
					{
						relations.push_back(i);
					}
				}

				return relations.size() > 0;
			}

		public:
			/**
			*	初始化关系表
			*/
			void initRelationTable()
			{
				for (uint32_t i = 0; i < Column; i++)
				{
					for (uint32_t j = 0; j < Row; j++)
					{
						_relation[i][j] = 0;
					}
				}
			}
		private:
			// 关系二维数组
			uint8_t _relation[Column][Row];
		};

		/*
		*	关系二维方阵表
		*/
		template<const uint32_t Count>
		class RelationSquareTable : public RelationTable<Count, Count>
		{
			typedef RelationTable<Count, Count> base;
		public:
			RelationSquareTable() {}
			virtual ~RelationSquareTable() {}
		public:
			/**
			*	设置值
			*/
			void setValue(uint32_t i, uint32_t j, uint8_t value)
			{
				base::setValue(i, j, value);
				base::setValue(j, i, value);
			}

			/**
			*	获取值
			*/
			bool equal(uint32_t i, uint32_t j, uint8_t value) const
			{
				return base::getValue(i, j) == value || base::getValue(j, i) == value;
			}

			/**
			*	获取关联的行
			*/
			bool getRelations(uint32_t index, uint8_t value, std::vector<uint32_t>& relations) const
			{
				if (index >= Count)
				{
					return false;
				}

				for (size_t i = 0; i < Count; i++)
				{
					if (base::getValue(index, i) == value)
					{
						relations.push_back(i);
					}
				}

				return relations.size() > 0;
			}
		};
	}
}
