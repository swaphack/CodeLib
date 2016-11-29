#pragma once

#include "macros.h"
#include "../Static/CtrlFrame.h"

namespace render
{
	// �����ؼ�
	class CtrlAnimation : public Animation
	{
	public:
		CtrlAnimation();
		virtual ~CtrlAnimation();
	public:
		virtual void draw();
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