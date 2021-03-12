#pragma once

#include "2d/Base/DrawTexture2D.h"
#include "Common/Action/SchedulerProtocol.h"

namespace render
{
	class CtrlFrame;

	// �����ؼ�
	class CtrlAnimation : 
		public DrawTexture2D
	{
	public:
		CtrlAnimation();
		virtual ~CtrlAnimation();
	public:
		virtual bool init();
	public:
		/**
		*	�����ٶ�ϵ��
		*/ 
		void setSpeedRatio(float ratio);
		/**
		*	��ȡ�ٶ�ϵ��
		*/ 
		float getSpeedRatio();
		/**
		*	����֡��
		*/ 
		void setFrameRate(float ratio);
		/**
		*	��ȡ֡��
		*/ 
		float getFrameRate();
		/**
		*	���õ�ǰ֡
		*/ 
		virtual void setFrame(int frame);
		/**
		*	��ȡ��ǰ֡
		*/ 
		int getFrame();
	protected:
		/**
		*	��ʱ�����¼�
		*/
		virtual void update(float interval);
	private:
		// �ٶ�ϵ��
		float _speedRatio;
		// ֡��
		float _frameRate;
		// ��ǰ֡
		float _frame;
		// ���
		float _duration;
	};
}