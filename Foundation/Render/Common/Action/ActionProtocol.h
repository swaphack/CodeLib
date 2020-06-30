#pragma once

namespace render
{
	// 动作状态
	enum class ActionStatus
	{
		NONE,		// 无状态
		RUNNING,	// 正在运行中
		PAUSE,		// 暂停
		STOP,		// 停止
	};

	// 用于系统类
	class ActionProtocol
	{
	public:
		ActionProtocol();
		virtual ~ActionProtocol();
	public:
		// 暂停
		virtual void pause();
		// 恢复
		virtual void resume();
		// 开始
		virtual void start();
		// 停止
		virtual void stop();
		// 是否结束
		bool isFinish() const;
		// 是否正在运行
		bool isRunning() const;
	protected:
		// 动作状态
		ActionStatus _actionStatus;
	};
}
