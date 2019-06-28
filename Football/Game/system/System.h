#pragma once

namespace game
{
	class System
	{
	public:
		System();
		virtual ~System();
	public:
		bool isStarted() const;

		bool isRunning() const;

		bool isPaused() const;

		bool isFinished() const;

		bool start();

		bool pause();

		bool resume();

		bool stop();

		void update();
	};
}