#pragma once

#include "2d/UI/CtrlWidget.h"
#include "Common/Action/SchedulerProtocol.h"

namespace render
{
	class CtrlFrame;

	// �����ؼ�
	class CtrlAnimation : 
		public CtrlWidget,
		public SchedulerProtocol
	{
	public:
		CtrlAnimation();
		virtual ~CtrlAnimation();
	public:
		virtual bool init();
	public:
		// ��ʱ�����¼�,��Ҫ�޸�
		void updateAnimation(float interval);
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
		/**
		*	��ȡ��ǰ����
		*/ 
		CtrlFrame* getAnimationFrame();
	protected:
		/**
		*	��Ӷ�ʱ��
		*/
		virtual void registerScheduler();
		/**
		*	�Ƴ���ʱ��
		*/
		virtual void unregisterScheduler();
		/**
		*	��ʱ�����¼�
		*/
		virtual void update(float interval);
	protected:
		// ͼƬ֡
		CtrlFrame* _ctrlFrame = nullptr;
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