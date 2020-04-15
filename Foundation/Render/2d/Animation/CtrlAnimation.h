#pragma once

#include "Common/Node/Animation.h"

namespace render
{
	class CtrlFrame;
	class CtrlAudioSource;

	// �����ؼ�
	class CtrlAnimation : public Animation
	{
	public:
		CtrlAnimation();
		virtual ~CtrlAnimation();
	public:
		virtual bool init();

		virtual void draw();
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
		// ��ʱ�����¼�
		virtual void updateSelf(float interval);
		// ֡���ı�
		virtual void onFrameChange();
	protected:
		// ͼƬ֡
		CtrlFrame* _ctrlFrame;
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