#pragma once

#include <map>
#include "system.h"

namespace alg
{
	/**
	*	һ��һ �������
	*/
	class OneToOneRelationship : public sys::Object
	{
	public:
		OneToOneRelationship();
		virtual ~OneToOneRelationship();
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
		std::map<sys::Object*, sys::Object*> _relations;
	};
}