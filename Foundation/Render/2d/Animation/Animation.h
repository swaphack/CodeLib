#pragma once

#include "Common/Node/Node.h"
#include "Common/Action/SchedulerProtocol.h"

namespace render
{
	// 动画控件
	class Animation : 
		public Node
	{
	public:
		Animation();
		virtual ~Animation();
	public:
		virtual bool init();
	public:
		/**
		*	设置速度系数
		*/ 
		void setSpeedRatio(float ratio);
		/**
		*	获取速度系数
		*/ 
		float getSpeedRatio();
		/**
		*	设置帧率
		*/ 
		void setFrameRate(float ratio);
		/**
		*	获取帧率
		*/ 
		float getFrameRate();
		/**
		*	设置当前帧
		*/ 
		virtual void setFrame(int frame);
		/**
		*	获取当前帧
		*/ 
		int getFrame();
	protected:
		/**
		*	定时更新事件
		*/
		virtual void update(float interval);
	private:
		// 速度系数
		float _speedRatio;
		// 帧率
		float _frameRate;
		// 当前帧
		float _frame;
		// 间隔
		float _duration;
	};
}