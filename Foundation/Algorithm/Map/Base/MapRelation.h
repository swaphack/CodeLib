#pragma once

#include "MapObject.h"

namespace alg
{
	/**
	*	地图关系
	*/
	class MapRelation : public MapObject
	{
	public:
		MapRelation();
		virtual ~MapRelation();
	public:
		/**
		*	添加关联
		*/
		void addRelation(uint32_t nLength, uint32_t startIndex, ...);
		/**
		*	添加关联
		*/
		void addRelation(uint32_t nLength, uint32_t startIndex, va_list ap);
		/**
		*	添加关联
		*/
		void addRelation(uint32_t relationIndex);
		/**
		*	添加关联
		*/
		void addRelation(uint32_t relationIndex0, uint32_t relationIndex1);
		/**
		*	添加关联
		*/
		void addRelation(uint32_t relationIndex0, uint32_t relationIndex1, uint32_t relationIndex2);
		/**
		*	添加关联
		*/
		void addRelation(uint32_t nLength, uint32_t relationIndex[]);
		/**
		*	添加关联
		*/
		void addRelation(const std::vector<uint32_t>& relationIndex);
		/**
		*	移除关联
		*/
		void removeRelation(uint32_t relationIndex);
		/**
		*	移除所有关联
		*/
		void removeAllRelations();
		/**
		*	是否包含关联
		*/
		bool containRelation(uint32_t relationIndex) const;
		/**
		*	获取关联关联
		*/
		const std::vector<uint32_t>& getAllRelations() const;
	public:
		/**
		*	关联数量
		*/
		uint32_t getRelationCount() const;
		/**
		*	获取关联
		*/
		uint32_t getRelation(uint32_t index) const;
		/**
		*	获取关联
		*/
		int32_t getRelationIndex(uint32_t relationIndex) const;
	public:

	protected:
		// 关联
		std::vector<uint32_t> _relations;
	};
}