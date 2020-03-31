#pragma once

#include "CtrlFrame.h"
#include "Common/struct/protocol_common.h"
#include "Resource/Config/TextDefine.h"
#include "2d/ctrl_common.h"

namespace render
{
	// 2d�ı�
	/*
		������ָ�����������
		ˮƽ���뷽ʽ������룬�Ҷ��룬 ����

		��ָ��������ʾ
		��ֱ���뷽ʽ�������룬�׶��룬����
	*/
	class CtrlText : public CtrlFrame, public TextProtocol
	{
	public:
		CtrlText();
		virtual ~CtrlText();
	public:
		virtual bool init();
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
		// ��ȡˮƽ���
		float getHorizontalDistance();
		// ���ô�ֱ���
		void setVerticalDistance(float distance);
		// ��ȡ��ֱ���
		float getVerticalDistance();
		// ������ʾ���ı�
		void setString(const char* text);

		// �����ı�ˮƽ���뷽ʽ
		void setHorizontalAlignment(HorizontalAlignment alignment);
		// ��ȡ�ı�ˮƽ���뷽ʽ
		HorizontalAlignment getHorizontalAlignment();
		// �����ı���ֱ���뷽ʽ
		void setVerticalAlignment(VerticalAlignment alignment);
		// ��ȡ�ı���ֱ���뷽ʽ
		VerticalAlignment getVerticalAlignment();
		// ������ʾ����
		void setDimensions(float width, float height);
		// ������ʾ����
		void setDimensions(const math::Size& size);
		// ��ȡ��ʾ����
		math::Size getDimensions();
		// ������ɫ
		void setColor(const sys::Color4B& color);
	protected:
		virtual void onTextChange();
	private:
		// �ı��ṹ
		Ctrl_TextDefine _textDefine;
	};
}