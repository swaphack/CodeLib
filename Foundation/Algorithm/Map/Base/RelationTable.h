#pragma once

#include "Map/Base/MapObject.h"

namespace alg
{
	namespace map
	{
		/*
		*	关系二维表
		*/
		class RelationTable : public MapObject
		{
		public:
			RelationTable();
			RelationTable(uint32_t count);
			RelationTable(uint32_t column, const uint32_t row);
			virtual ~RelationTable();
		public:
			/**
			*	设置值a[i][j]
			*/
			void setValue(uint32_t i, uint32_t j, uint8_t value);
			/**
			*	获取值a[i][j]
			*/
			uint8_t getValue(uint32_t i, uint32_t j) const;

			/**
			*	获取关联的列
			*/
			bool getColumnValues(uint32_t column, uint8_t value, std::vector<uint32_t>& relations)  const;

			/**
			*	获取关联的行
			*/
			bool getRowValues(uint32_t row, uint8_t value, std::vector<uint32_t>& relations)  const;
			/**
			*	获取值a[i][j]
			*/
			bool equal(uint32_t i, uint32_t j, uint8_t value) const;
		public:
			/**
			*	初始化关系表
			*	column 列数
			*	row 行数
			*/
			void init(uint32_t column, const uint32_t row);
			/**
			*	清空
			*/
			void cleanup();
			/**
			*	列数
			*/
			int getColumn() const;
			/**
			*	行数
			*/
			int getRow() const;
		private:
			// 列数
			int _column = 0;
			// 行数
			int _row = 0;
			// 关系二维数组
			uint8_t* _relation = nullptr;
		};
	}
}
