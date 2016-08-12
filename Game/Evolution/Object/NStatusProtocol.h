#pragma once

#include "NObject.h"
#include "NStatus.h"
#include <map>

namespace nature
{
	class NStatusProtocol : public NObject
	{
	public:
		NStatusProtocol();
		~NStatusProtocol();
	public:
		// ��ȡ״̬, ��������ڣ��򴴽�
		NStatus* getAndCreateStatus(int nStatusID);
		// �Ƴ�״̬
		virtual void removeStatus(int nStatusID);
		// �Ƴ�����״̬
		virtual void removeAllStatus();
	protected:
		// ״̬�ı�ʱ�����¼�
		virtual void onStatusChanged(NStatus* pStatus);
		// ״̬�ı�ʱ��������д
		virtual void onStatusChangedHandler(NStatus* pStatus);
	protected:
		// ״̬�ֵ�
		std::map<int, NStatus*> _statusDict;
	};
}