#pragma once

#include "Identity.h"

namespace game
{
	/**
	*	系统
	*/
	class ISystem : public Identity
	{
	public:
		virtual ~ISystem() {}
	public:
		/**
		*	是否开始
		*/
		virtual bool isBegan() const = 0;
		/**
		*	是否运行
		*/
		virtual bool isRunning() const = 0;
		/**
		*	是否暂停
		*/
		virtual bool isPaused() const = 0;
		/**
		*	是否结束
		*/
		virtual bool isEnded() const = 0;
		/**
		*	开始
		*/
		virtual bool start() = 0;
		/**
		*	暂停
		*/
		virtual bool pause() = 0;
		/**
		*	恢复
		*/
		virtual bool resume() = 0;
		/**
		*	结束
		*/
		virtual bool finish() = 0;
		/**
		*	更新
		*/
		virtual void update() = 0;
	};
}