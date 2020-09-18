#pragma once

#include <cstdint>

namespace alg
{
	// 关系表
	template<const uint32_t Order>
	class RelationTable2D
	{
	public:
		RelationTable2D()
		{
			this->initRelationTable();
		}
		virtual ~RelationTable2D()
		{

		}
	public:
		/**
		*	设置值
		*/
		void set(uint32_t i, uint32_t j, bool value)
		{
			if (i < Order && j < Order)
			{
				_relation[i][j] = value;
			}
		}
		/**
		*	获取值
		*/
		bool get(uint32_t i, uint32_t j)
		{
			if (i < Order && j < Order)
			{
				return _relation[i][j];
			}

			return false;
		}
	protected:
		void initRelationTable()
		{
			for (uint32_t i = 0; i < Order; i++)
			{
				for (uint32_t j = 0; j < Order; j++)
				{
					_relation[i][j] = false;
				}
			}
		}
	private:
		bool _relation[Order][Order];
	};
}
