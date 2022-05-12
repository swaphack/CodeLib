#pragma once

#include "system.h"

namespace alg
{
	namespace work
	{
		enum class WorkState
		{
			None,
			Running,
			End,
		};
		class WorkObject : public sys::Object
		{

		public:
			/**
			*	��ʼ
			*/
			void start();
			/**
			*	����
			*/
			void update(float dt);
			/**
			*	��ͣ
			*/
			void pause();
			/**
			*	�ָ�
			*/;
			void resume();
			/**
			*	����
			*/
			void finish();
			/**
			*	�Ƿ����ڲ���
			*/
			bool isPlaying() const;
			/**
			*	�Ƿ����
			*/
			bool isOver() const;
			/**
			*	����
			*/
			void reset();
		protected:
			/**
			*	����
			*/
			virtual void onStart();
			/**
			*	����
			*/
			virtual void onUpdate(float dt);
			/**
			*	����
			*/
			virtual void onFinish();
			/**
			*	����
			*/
			virtual void onReset();
		private:
			// �Ƿ����ڲ���
			bool _bPlaying = false;
			// ����״̬
			WorkState _workState = WorkState::None;
		};
	}
}