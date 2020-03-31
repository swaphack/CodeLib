#pragma once
#include <queue>
#include <cstdint>
namespace sys
{
	struct NetData;

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
		int32_t count();
		// �����Ƿ�Ϊ��
		bool empty();
		// �ͷŶ���Ԫ��
		void dispose();
	private:
		std::queue<NetData*> _datas;
	};
}