#pragma once

#include "NObject.h"
#include "NProperty.h"
#include <map>

namespace nature
{
	class NPropertyProtocol : public NObject
	{
	public:
		NPropertyProtocol();
		~NPropertyProtocol();
	public:
		// ��ȡ����, ��������ڣ��򴴽�
		NProperty* getAndCreateProperty(int nPropertyID);
		// �Ƴ�����
		virtual void removeProperty(int nPropertyID);
		// �Ƴ���������
		virtual void removeAllProperties();
	protected:
		// ���Ըı�ʱ�����¼�
		virtual void onPropertyChanged(NProperty* pProperty);

		// ���Ըı�ʱ����,����д
		virtual void onPropertyChangedHandler(NProperty* pProperty);
	protected:
		// �����ֵ�
		std::map<int, NProperty*> _propertyDict;
	};
}