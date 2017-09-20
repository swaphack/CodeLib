#pragma once

#include "macros.h"

namespace render
{
	// �������������
	struct ListenerBody 
	{
	public:
		// λ��
		sys::Vector3 position;
		// �ٶ�
		sys::Vector3 velocity;
		// ������
		sys::Vector3 forward;
		// ͷ������
		sys::Vector3 up;
	public:
		ListenerBody(){}
		ListenerBody(const sys::Vector3& position, const sys::Vector3& velocity, const sys::Vector3& forward, const sys::Vector3& up)
		{
			this->position = position;
			this->velocity = velocity;
			this->forward = forward;
			this->up = up;
		}
	};

	// ��Ƶ������
	class CtrlAudioListener : public Node
	{
	public:
		CtrlAudioListener();
		virtual ~CtrlAudioListener();
	public:
		virtual bool init();
		int getListenerID();

		void setVelocity(const sys::Vector3& velocity);
		const sys::Vector3& getVelocity();


		void setForward(const sys::Vector3& forward);
		const sys::Vector3& getForward();

		void setUp(const sys::Vector3& up);
		const sys::Vector3& getUp();
	protected:
		void onListenerChange();
	private:
		void updateListener();
	private:
		// ����������
		static int s_ListenerCount;
		// ���
		int _listenerID;

		ListenerBody _listenerBody;
	};
}