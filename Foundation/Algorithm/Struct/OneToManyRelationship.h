#pragma once

#include "system.h"

namespace alg
{
	/**
	*	����ϵ һ�Զ�
	*/
	class OneToManyRelationship : public sys::Object
	{
	public:
		OneToManyRelationship();
		virtual ~OneToManyRelationship();
	public:
		/**
		*	���ö���
		*/
		void setObject(const sys::Object* src);
		/**
		*	��ȡ����
		*/
		const sys::Object* getObject();
	public:
		/**
		*	��ӹ���
		*/
		void addRelation(const sys::Object* dest);
		/**
		*	�Ƴ�����
		*/
		void removeRelation(const sys::Object* dest);
		/**
		*	�Ƴ����й���
		*/
		void removeAllRelations();
		/**
		*	�Ƿ��й���
		*/
		bool contains(const sys::Object* dest);
	protected:
		// Դ
		sys::Object* _src;
		// Ŀ��
		std::set<sys::Object*> _relations;
	};
}
