#pragma once

#include <map>
#include "system.h"

namespace alg
{
	/**
	*	一对一 单向关联
	*/
	class OneToOneRelationship : public sys::Object
	{
	public:
		OneToOneRelationship();
		virtual ~OneToOneRelationship();
	public:
		/**
		*	添加关联
		*/
		void addRelation(const sys::Object* src, const sys::Object* dest);
		/**
		*	移除关联
		*/
		void removeRelation(const sys::Object* src);
		/**
		*	移除所有关联
		*/
		void removeAllRelations();
		/**
		*	获取关联
		*/
		const sys::Object* getRelation(const sys::Object* src);
	protected:
		// 关联关系
		std::map<sys::Object*, sys::Object*> _relations;
	};
}