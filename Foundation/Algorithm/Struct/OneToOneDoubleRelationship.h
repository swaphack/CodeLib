#pragma once

#include <map>
#include "system.h"

namespace alg
{
	class OneToOneRelationship;
	/**
	*	һ��һ ˫�����
	*/
	class OneToOneDoubleRelationship : public sys::Object
	{
	public:
		OneToOneDoubleRelationship();
		virtual ~OneToOneDoubleRelationship();
	public:
		/**
		*	��ӹ���
		*/
		void addRelation(const sys::Object* src, const sys::Object* dest);
		/**
		*	�Ƴ�����
		*/
		void removeRelation(const sys::Object* src);
		/**
		*	�Ƴ����й���
		*/
		void removeAllRelations();
		/**
		*	��ȡ����
		*/
		const sys::Object* getRelation(const sys::Object* src);
	protected:
		// ������ϵ
		OneToOneRelationship* _srcRelations;
		// ������ϵ
		OneToOneRelationship* _destRelations;
	};
}