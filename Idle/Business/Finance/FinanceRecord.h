#pragma once

#include "../Core/import.h"
#include <map>

namespace business
{
	// 财务类型
	enum class FinanceType
	{
		// 收入
		Income,
		// 支出
		Expense,
	};

	// 财务项
	class FinanceRecord : public Object
	{
	public:
		FinanceRecord();
		virtual ~FinanceRecord();
	public:
		// 类型
		FinanceType getType();
		// 值
		void setValue(float value);
		float getValue();
		// 目标
		void setTarget(Object* pTarget);
		Object* getTarget();

		template<typename T, typename = std::enable_if<std::is_base_of<Object, T>::value, T>::type>
		T* getTarget()
		{
			return dynamic_cast<T*>(getTarget());
		}
	protected:
		// 设置类型
		void setType(FinanceType type);
	private:
		// 类型
		FinanceType m_eType = FinanceType::Income;
		// 值
		float m_nValue = 0;
		// 所属目标
		Object* m_pTarget = 0;
	};
}