#pragma once

#include <map>

namespace tribe
{
	// ����
	class Property
	{
	public:
		Property();
		virtual ~Property();
	public:
		// ���������
		void addProperty(int propType, int val = 0);
		// �Ƴ�������
		void removeProperty(int propType);
		// ��ȡ����ֵ
		int getValue(int propType);
	protected:
	private:
		// ���Լ� {�������ͣ�����ֵ}
		std::map<int, int> _propValues;
	};
}