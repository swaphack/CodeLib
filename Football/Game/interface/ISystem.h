#pragma once

#include "Identity.h"

namespace game
{
	/**
	*	ϵͳ
	*/
	class ISystem
	{
	public:
		virtual ~ISystem() {}
	public:
		/**
		*	�Ƿ�ʼ
		*/
		virtual bool isStarted() const = 0;
		/**
		*	�Ƿ�����
		*/
		virtual bool isRunning() const = 0;
		/**
		*	�Ƿ���ͣ
		*/
		virtual bool isPaused() const = 0;
		/**
		*	�Ƿ����
		*/
		virtual bool isFinished() const = 0;
		/**
		*	��ʼ
		*/
		virtual bool start() = 0;
		/**
		*	��ͣ
		*/
		virtual bool pause() = 0;
		/**
		*	�ָ�
		*/
		virtual bool resume() = 0;
		/**
		*	����
		*/
		virtual bool stop() = 0;
		/**
		*	����
		*/
		virtual void update() = 0;
	};
}