#pragma once

#include "Net/NetData.h"

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
		void pushData(NetData* data);
		// ���ֶ��ͷ�NetData����
		NetData* popData();
		// ����ͷԪ��
		NetData* topData();
		// ������Ԫ�ظ���
		int32 count();
		// �����Ƿ�Ϊ��
		bool empty();
		// �ͷŶ���Ԫ��
		void dispose();
	private:
		std::queue<NetData*> _datas;
	};
}