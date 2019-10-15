#pragma once

#include "Object.h"
#include <map>

namespace business
{
	class Relation;

	// ��ϵ��
	class RelationNet
	{
	public:
		RelationNet(Object* pBody);
		virtual ~RelationNet();
	public:
		// ��ȡ��ϵ
		Relation* getRelation(int nRelationType);
		// ��ȡ��ϵֵ
		int getRelationValue(int nRelationType, uint64_t nTargetID);

		// ������ϵ
		void make(int nRelationType, Object* pTarget, int value);
		// �����ϵ
		void dissolve(int nRelationType, Object* pTarget);
		// ���
		void clear();
	protected:
	private:
		// ����
		Object* m_pObject = nullptr;
		// ��ϵ
		std::map<int, Relation*> m_mapRelation;
	};
}