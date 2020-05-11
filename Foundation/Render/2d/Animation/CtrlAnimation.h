#pragma once

#include "2d/UI/CtrlWidget.h"
#include "Common/struct/protocol_common.h"

namespace render
{
	class CtrlFrame;
	class CtrlAudioSource;
	class Scheduler;

	// 动画控件
	class CtrlAnimation : 
		public CtrlWidget,
		public ControlProtocol
	{
	public:
		CtrlAnimation();
		virtual ~CtrlAnimation();
	public:
		virtual bool init();

		virtual void draw();
	public:
		// 开始
		virtual void start();
		// 恢复
		virtual void pause();
		// 暂停
		virtual void resume();
		// 结束
		virtual void stop();
		// 定时更新事件,不要修改
		void updateAnimation(float interval);
	public:
		// 设置速度系数
		void setSpeedRatio(float ratio);
		// 获取速度系数
		float getSpeedRatio();
		// 设置帧率
		void setFrameRate(float ratio);
		// 获取帧率
		float getFrameRate();
		// 设置当前帧
		virtual void setFrame(int frame);
		// 获取当前帧
		int getFrame();
		// 获取当前动画
		CtrlFrame* getMovie();
	protected:
		// 添加定时器
		void registerScheduler();
		// 移除定时器
		void unregisterScheduler();
		// 定时更新事件
		virtual void updateSelf(float interval);
		// 帧数改变
		virtual void onFrameChange();
	protected:
		// 图片帧
		CtrlFrame* _ctrlFrame = nullptr;
		// 定时器
		Scheduler* _scheduler = nullptr;
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