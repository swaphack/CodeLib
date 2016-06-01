#pragma once

#include <ctime>

namespace slg
{
	// ���ŵ�����
	class LivingProtocol
	{
	public:
		LivingProtocol();
		virtual ~LivingProtocol();
	public:
		// ��������
		time_t getBirthDay();
		// �Ƿ�����
		bool isDead();
		// ��������״̬
		void setDead(bool isDead);
	protected:
		void setBirthDay(time_t tt);
	private:
		// ��������ʱ���
		time_t _birthday;
		// �Ƿ�����
		bool _bDead;
	};
}