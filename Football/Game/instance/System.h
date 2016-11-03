#pragma once

#include "../interface/ISystem.h"

namespace game
{
	class System : public ISystem
	{
	public:
		System();
		virtual ~System();
	public:
		virtual bool isStarted() const;

		virtual bool isRunning() const;

		virtual bool isPaused() const;

		virtual bool isFinished() const;

		virtual bool begin();

		virtual bool pause();

		virtual bool resume();

		virtual bool end();

		virtual void update();
	};
}