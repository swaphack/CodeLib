#pragma once
#include "Resource/Image/ImageDetail.h"

namespace sys
{
	// ÿ���ַ��洢������
	class FontCharDetail : public ImageDetail
	{
	public:
		FontCharDetail();
		~FontCharDetail();
	public:
		void setAdvance(float x, float y);
		void setAdvanceX(float x);
		void setAdvanceY(float y);
		int getAdvanceX() const;
		int getAdvanceY() const;
	public:
		//����ԭ��(0,0)������λͼ��������صľ���
		void setDelta(float x, float y);
		//����ԭ��(0, 0)������λͼ��������صľ���x
		void setDeltaX(float x);
		//����ԭ��(0, 0)������λͼ��������صľ���y
		void setDeltaY(float y);
		int getDeltaX() const;
		int getDeltaY() const;
	protected:
		// ʵ�ʱ�׼���-����,���
		int _advX = 0;
		int _advY = 0;

		// ����ԭ��(0,0)������λͼ��������ص�ˮƽ����.�����������ص���ʽ��ʾ�� 
		int _deltaX = 0;
		int _deltaY = 0;
	};
}