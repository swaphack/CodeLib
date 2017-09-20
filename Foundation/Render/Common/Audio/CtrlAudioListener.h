#pragma once

#include "macros.h"

namespace render
{
	// 监听者躯体参数
	struct ListenerBody 
	{
	public:
		// 位置
		sys::Vector3 position;
		// 速度
		sys::Vector3 velocity;
		// 脸朝向
		sys::Vector3 forward;
		// 头顶方向
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

	// 音频监听者
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
		// 监听者数量
		static int s_ListenerCount;
		// 编号
		int _listenerID;

		ListenerBody _listenerBody;
	};
}