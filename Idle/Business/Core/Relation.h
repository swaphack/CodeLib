#pragma once

#include "Object.h"
#include <map>

namespace business
{
	// ��ϵ
	class Relation : public Object
	{
	protected:
		// ��ϵ��
		struct RelationSlot
		{
			// �ڶ�������
			Object* target = nullptr;
			// ��ϵֵ
			int value = 0;
			// ������ϵ
			Relation* relation = nullptr;
			// ��������
			void* data = nullptr;
		};
	public:
		Relation();
		virtual ~Relation();
	public:
		// ��������
		void setType(int nType);
		// ��ȡ����
		int getType();
		// ��Ӷ���
		void add(Object* pTarget, int nValue = 0, void* pData = nullptr);
		// ���¹�ϵֵ
		void update(uint64_t nTargetID, int value);
		// ���±�ע
		void update(uint64_t nTargetID, void* pData);
		// ���¹�ϵֵ�ͱ�ע
		void update(uint64_t nTargetID, int value, void* pData = nullptr);
		// �Ƴ���ϵ
		void remove(uint64_t nTargetID);
		// ���Ҷ���
		Object* findTarget(uint64_t nTargetID);
		// ��ȡֵ
		int getValue(uint64_t nTargetID);
		// ���
		void clear();
		// ����
		int count();
	private:
		// ����
		int m_nType = 0;
		// ����
		std::map<uint64_t, RelationSlot*> m_mapRelation;
	};
}