#pragma once

#include "Common/Node/Node.h"
#include "Common/Action/SchedulerProtocol.h"

namespace render
{
	// �����ؼ�
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