#pragma once

#include "Object.h"
#include <map>

namespace business
{
	// 关系
	class Relation : public Object
	{
	protected:
		// 关系项
		struct RelationSlot
		{
			// 第二个对象
			Object* target = nullptr;
			// 关系值
			int value = 0;
			// 所属关系
			Relation* relation = nullptr;
			// 其他数据
			void* data = nullptr;
		};
	public:
		Relation();
		virtual ~Relation();
	public:
		// 设置类型
		void setType(int nType);
		// 获取类型
		int getType();
		// 添加对象
		void add(Object* pTarget, int nValue = 0, void* pData = nullptr);
		// 更新关系值
		void update(uint64_t nTargetID, int value);
		// 更新备注
		void update(uint64_t nTargetID, void* pData);
		// 更新关系值和备注
		void update(uint64_t nTargetID, int value, void* pData = nullptr);
		// 移除关系
		void remove(uint64_t nTargetID);
		// 查找对象
		Object* findTarget(uint64_t nTargetID);
		// 获取值
		int getValue(uint64_t nTargetID);
		// 清空
		void clear();
		// 数量
		int count();
	private:
		// 类型
		int m_nType = 0;
		// 对象
		std::map<uint64_t, RelationSlot*> m_mapRelation;
	};
}