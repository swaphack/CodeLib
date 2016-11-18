#pragma once

#include "../Net/NetData.h"

#include <queue>

namespace sys
{
	// ���ݶ���
	class DataQueue
	{
	public:
		DataQueue();
		~DataQueue();
	public:
		// �������
		void push(NetData* data);
		// ���ֶ��ͷ�NetData����
		NetData* pop();
		// ����ͷԪ��
		NetData* top();
		// ������Ԫ�ظ���
		int count();
		// �����Ƿ�Ϊ��
		bool empty();
		// �ͷŶ���Ԫ��
		void dispose();
	private:
		std::queue<NetData*> _datas;
	};
}