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
			*	开始
			*/
			void start();
			/**
			*	更新
			*/
			void update(float dt);
			/**
			*	暂停
			*/
			void pause();
			/**
			*	恢复
			*/;
			void resume();
			/**
			*	结束
			*/
			void finish();
			/**
			*	是否正在播放
			*/
			bool isPlaying() const;
			/**
			*	是否结束
			*/
			bool isOver() const;
			/**
			*	重置
			*/
			void reset();
		protected:
			/**
			*	开启
			*/
			virtual void onStart();
			/**
			*	更新
			*/
			virtual void onUpdate(float dt);
			/**
			*	结束
			*/
			virtual void onFinish();
			/**
			*	重置
			*/
			virtual void onReset();
		private:
			// 是否正在播放
			bool _bPlaying = false;
			// 工作状态
			WorkState _workState = WorkState::None;
		};
	}
}