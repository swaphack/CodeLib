#pragma once

#include <list>
#include <set>
#include "system.h"

namespace alg
{
	/**
	*	关联
	*/
	class Relation : public sys::Object
	{
	public:
		Relation();
		virtual ~Relation();
	public:
		/**
		*	设置名字
		*/
		void setName(const std::string& name);
		/**
		*	获取名字
		*/
		const std::string& getName() const;
		/**
		*	设置标记
		*/
		void setTag(int tag);
		/**
		*	获取标记
		*/
		int getTag() const;
	public:
		/**
		*	添加单向相邻点
		*/
		void addSingleRelation(Relation* node);
		/**
		*	移除单向相邻点
		*/
		void removeSingleRelation(Relation* node);
		/**
		*	添加双向相邻点
		*/
		void addDoubleRelation(Relation* node);
		/**
		*	移除双向相邻点
		*/
		void removeDoubleRelation(Relation* node);
		/**
		*	清空相邻点
		*/
		void clearAllRelations();
	public:
		/**
		*	查找节点
		*/
		Relation* findRelationByTag(int tag);
		/**
		*	查找节点
		*/
		Relation* findRelationByTagWithRecurse(int tag);
		/**
		*	查找节点
		*/
		Relation* findRelationByName(const std::string& name);
		/**
		*	查找节点
		*/
		Relation* findRelationByNameWithRecurse(const std::string& name);
	private:
		// 名字
		std::string _name;
		// 标记
		int _tag = 0;
		// 相邻点
		std::set<Relation*> _adjacents;		
		// 相关值
		std::map<std::string, float> _values;
	};
}