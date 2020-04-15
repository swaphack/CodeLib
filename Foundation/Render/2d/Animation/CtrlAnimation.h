#pragma once

#include "Common/Node/Animation.h"

namespace render
{
	class CtrlFrame;
	class CtrlAudioSource;

	// 动画控件
	class CtrlAnimation : public Animation
	{
	public:
		CtrlAnimation();
		virtual ~CtrlAnimation();
	public:
		virtual bool init();

		virtual void draw();
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
		// 定时更新事件
		virtual void updateSelf(float interval);
		// 帧数改变
		virtual void onFrameChange();
	protected:
		// 图片帧
		CtrlFrame* _ctrlFrame;
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