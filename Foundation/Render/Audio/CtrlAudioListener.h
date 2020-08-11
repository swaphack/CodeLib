#pragma once

#include "macros.h"
#include "AudioProtocol.h"

namespace render
{
	// ��Ƶ������
	class CtrlAudioListener : public Node
	{
	public:
		CtrlAudioListener();
		virtual ~CtrlAudioListener();
	public:
		virtual bool init();
		int getListenerID();

		void setVelocity(const math::Vector3& velocity);
		const math::Vector3& getVelocity();

		void setForward(const math::Vector3& forward);
		const math::Vector3& getForward();

		void setUp(const math::Vector3& up);
		const math::Vector3& getUp();
	protected:
		void onListenerChange();
	private:
		void updateListener();
	private:
		// ����������
		static int s_ListenerCount;
		// ���
		int _listenerID;

		AudioSpace _listenerBody;
	};
}