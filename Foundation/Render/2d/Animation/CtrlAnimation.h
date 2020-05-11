#pragma once

#include "2d/UI/CtrlWidget.h"
#include "Common/struct/protocol_common.h"

namespace render
{
	class CtrlFrame;
	class CtrlAudioSource;
	class Scheduler;

	// �����ؼ�
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
		// ��ʼ
		virtual void start();
		// �ָ�
		virtual void pause();
		// ��ͣ
		virtual void resume();
		// ����
		virtual void stop();
		// ��ʱ�����¼�,��Ҫ�޸�
		void updateAnimation(float interval);
	public:
		// �����ٶ�ϵ��
		void setSpeedRatio(float ratio);
		// ��ȡ�ٶ�ϵ��
		float getSpeedRatio();
		// ����֡��
		void setFrameRate(float ratio);
		// ��ȡ֡��
		float getFrameRate();
		// ���õ�ǰ֡
		virtual void setFrame(int frame);
		// ��ȡ��ǰ֡
		int getFrame();
		// ��ȡ��ǰ����
		CtrlFrame* getMovie();
	protected:
		// ��Ӷ�ʱ��
		void registerScheduler();
		// �Ƴ���ʱ��
		void unregisterScheduler();
		// ��ʱ�����¼�
		virtual void updateSelf(float interval);
		// ֡���ı�
		virtual void onFrameChange();
	protected:
		// ͼƬ֡
		CtrlFrame* _ctrlFrame = nullptr;
		// ��ʱ��
		Scheduler* _scheduler = nullptr;
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