#pragma once

#include "Identity.h"

namespace game
{
	/**
	*	ϵͳ
	*/
	class ISystem : public Identity
	{
	public:
		virtual ~ISystem() {}
	public:
		/**
		*	�Ƿ�ʼ
		*/
		virtual bool isBegan() const = 0;
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
		virtual bool isEnded() const = 0;
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
		virtual bool finish() = 0;
		/**
		*	����
		*/
		virtual void update() = 0;
	};
}