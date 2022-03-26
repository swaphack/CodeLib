#pragma once

#include "Map/Base/MapObject.h"

namespace alg
{
	namespace map
	{
		/*
		*	��ϵ��ά��
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
			*	����ֵa[i][j]
			*/
			void setValue(uint32_t i, uint32_t j, uint8_t value);
			/**
			*	��ȡֵa[i][j]
			*/
			uint8_t getValue(uint32_t i, uint32_t j) const;

			/**
			*	��ȡ��������
			*/
			bool getColumnValues(uint32_t column, uint8_t value, std::vector<uint32_t>& relations)  const;

			/**
			*	��ȡ��������
			*/
			bool getRowValues(uint32_t row, uint8_t value, std::vector<uint32_t>& relations)  const;
			/**
			*	��ȡֵa[i][j]
			*/
			bool equal(uint32_t i, uint32_t j, uint8_t value) const;
		public:
			/**
			*	��ʼ����ϵ��
			*	column ����
			*	row ����
			*/
			void init(uint32_t column, const uint32_t row);
			/**
			*	���
			*/
			void cleanup();
			/**
			*	����
			*/
			int getColumn() const;
			/**
			*	����
			*/
			int getRow() const;
		private:
			// ����
			int _column = 0;
			// ����
			int _row = 0;
			// ��ϵ��ά����
			uint8_t* _relation = nullptr;
		};
	}
}
