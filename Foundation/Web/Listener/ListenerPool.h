#pragma once

#include "IActivityListener.h"

#include <map>

namespace web
{
	// ������
	class ListenerPool
	{
	public:
		ListenerPool();
		~ListenerPool();
	public:
		// ���һ������
		int addListener(IActivityListener* listener);		
		// ��ȡһ������
		IActivityListener* getListener(int id);
		// ������м���
		void clear();
		// �ɷ�
		virtual bool onDispatch(const char* sessionID, sys::DataQueue& dataQueue);
	private:
		// ������
		std::map<int, IActivityListener*> _listeners;
		// ����id
		int _increaseID;
	};
}