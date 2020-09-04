#pragma once

#include <list>
#include <set>
#include "system.h"

namespace alg
{
	/**
	*	����
	*/
	class Relation : public sys::Object
	{
	public:
		Relation();
		virtual ~Relation();
	public:
		/**
		*	��������
		*/
		void setName(const std::string& name);
		/**
		*	��ȡ����
		*/
		const std::string& getName() const;
		/**
		*	���ñ��
		*/
		void setTag(int tag);
		/**
		*	��ȡ���
		*/
		int getTag() const;
	public:
		/**
		*	��ӵ������ڵ�
		*/
		void addSingleRelation(Relation* node);
		/**
		*	�Ƴ��������ڵ�
		*/
		void removeSingleRelation(Relation* node);
		/**
		*	���˫�����ڵ�
		*/
		void addDoubleRelation(Relation* node);
		/**
		*	�Ƴ�˫�����ڵ�
		*/
		void removeDoubleRelation(Relation* node);
		/**
		*	������ڵ�
		*/
		void clearAllRelations();
	public:
		/**
		*	���ҽڵ�
		*/
		Relation* findRelationByTag(int tag);
		/**
		*	���ҽڵ�
		*/
		Relation* findRelationByTagWithRecurse(int tag);
		/**
		*	���ҽڵ�
		*/
		Relation* findRelationByName(const std::string& name);
		/**
		*	���ҽڵ�
		*/
		Relation* findRelationByNameWithRecurse(const std::string& name);
	private:
		// ����
		std::string _name;
		// ���
		int _tag = 0;
		// ���ڵ�
		std::set<Relation*> _adjacents;		
		// ���ֵ
		std::map<std::string, float> _values;
	};
}