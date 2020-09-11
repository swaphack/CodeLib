#pragma once

#include "system.h"

namespace alg
{
	/**
	*	树关系 一对多
	*/
	class OneToManyRelationship : public sys::Object
	{
	public:
		OneToManyRelationship();
		virtual ~OneToManyRelationship();
	public:
		/**
		*	设置对象
		*/
		void setObject(const sys::Object* src);
		/**
		*	获取对象
		*/
		const sys::Object* getObject();
	public:
		/**
		*	添加关联
		*/
		void addRelation(const sys::Object* dest);
		/**
		*	移除关联
		*/
		void removeRelation(const sys::Object* dest);
		/**
		*	移除所有关联
		*/
		void removeAllRelations();
		/**
		*	是否有关联
		*/
		bool contains(const sys::Object* dest);
	protected:
		// 源
		sys::Object* _src;
		// 目标
		std::set<sys::Object*> _relations;
	};
}
