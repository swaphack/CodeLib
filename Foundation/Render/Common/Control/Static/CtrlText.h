#pragma once

#include "macros.h"

namespace render
{
	// 2d�ı�
	/*
		������ָ�����������
		ˮƽ���뷽ʽ������룬�Ҷ��룬 ����

		��ָ��������ʾ
		��ֱ���뷽ʽ�������룬�׶��룬����
	*/
	class CtrlText : public ColorNode, public TextProtocol
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
		void setColor(const sys::Color4B& color);
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