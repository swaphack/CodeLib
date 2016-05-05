#pragma once

#include "macros.h"

namespace render
{
	// 2d�ı�
	class CtrlText : public ColorNode
	{
	public:
		CtrlText();
		virtual ~CtrlText();
	public:
		virtual void draw();
		// �����ֿ�·��
		void setFontPath(const char* fonturl);
		// ��ȡ�ֿ�·��
		const char* getFontPath();
		// ���������С
		void setFontSize(float size);
		// ��ȡ�����С
		float getFontSize();
		// ����ˮƽ�ּ��
		void setHorizontalDistance(float distance);
		// ��ȡ��ֱ���
		float getHorizontalDistance();
		// ����ˮƽ���
		void setVerticalDistance(float distance);
		// ��ȡ��ֱ���
		float getVerticalDistance();
		// ������ʾ���ı�
		void setString(const char* text);
		// ��ȡ��ʾ���ı�
		const char* getString();

		// ����ˮƽ���뷽ʽ
		void setHorizontalAlignment(HorizontalAlignment alignment);
		// ��ȡˮƽ���뷽ʽ
		HorizontalAlignment getHorizontalAlignment();
		// ���ô�ֱ���뷽ʽ
		void setVerticalAlignment(VerticalAlignment alignment);
		// ��ȡ��ֱ���뷽ʽ
		VerticalAlignment getVerticalAlignment();
		// ������ʾ����
		void setDimensions(float width, float height);
		// ��ȡ��ʾ����
		sys::Size getDimensions();
		// ������ɫ
		void setColor(sys::Color4B color);
		// ��ȡ��ɫ
		sys::Color4B getColor();
	protected:
		virtual void initSelf();
	private:
		// �ı��ṹ
		Ctrl_TextDefine _textDefine;
		// ����֡
		TexFrame* _texFrame;
		// ��������
		TextureRect _texRect;
	};
}