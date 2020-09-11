#pragma once

#include <map>
#include "system.h"

namespace alg
{
	class OneToOneRelationship;
	/**
	*	一对一 双向关联
	*/
	class OneToOneDoubleRelationship : public sys::Object
	{
	public:
		OneToOneDoubleRelationship();
		virtual ~OneToOneDoubleRelationship();
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
		OneToOneRelationship* _srcRelations;
		// 关联关系
		OneToOneRelationship* _destRelations;
	};
}