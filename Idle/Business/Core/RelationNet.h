#pragma once

#include "Object.h"
#include <map>

namespace business
{
	class Relation;

	// 关系网
	class RelationNet
	{
	public:
		RelationNet(Object* pBody);
		virtual ~RelationNet();
	public:
		// 获取关系
		Relation* getRelation(int nRelationType);
		// 获取关系值
		int getRelationValue(int nRelationType, uint64_t nTargetID);

		// 创建关系
		void make(int nRelationType, Object* pTarget, int value);
		// 解除关系
		void dissolve(int nRelationType, Object* pTarget);
		// 清空
		void clear();
	protected:
	private:
		// 主体
		Object* m_pObject = nullptr;
		// 关系
		std::map<int, Relation*> m_mapRelation;
	};
}