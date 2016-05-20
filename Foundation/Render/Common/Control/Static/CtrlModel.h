#pragma once

#include "macros.h"

namespace render
{
	// 3dģ��
	class CtrlModel : public ColorNode
	{
	public:
		CtrlModel();
		virtual ~CtrlModel();
	public:
		virtual void draw();
		// ����ģ�Ͳ���
		void setMatrial(Material* material);
		// ��ȡģ�Ͳ���
		Material* getMatrial();
		
		// ���������������֡
		virtual void setTexFrame(TexFrame* frame);
	protected:
		virtual void initSelf();
	protected:
		// ģ�Ͳ���
		Material* _material;
		// ����
		TexFrame* _texFrame;
	};
}