#pragma once

#include "../Core/import.h"
#include <map>

namespace business
{
	// ��������
	enum class FinanceType
	{
		// ����
		Income,
		// ֧��
		Expense,
	};

	// ������
	class FinanceRecord : public Object
	{
	public:
		FinanceRecord();
		virtual ~FinanceRecord();
	public:
		// ����
		FinanceType getType();
		// ֵ
		void setValue(float value);
		float getValue();
		// Ŀ��
		void setTarget(Object* pTarget);
		Object* getTarget();

		template<typename T, typename = std::enable_if<std::is_base_of<Object, T>::value, T>::type>
		T* getTarget()
		{
			return dynamic_cast<T*>(getTarget());
		}
	protected:
		// ��������
		void setType(FinanceType type);
	private:
		// ����
		FinanceType m_eType = FinanceType::Income;
		// ֵ
		float m_nValue = 0;
		// ����Ŀ��
		Object* m_pTarget = 0;
	};
}