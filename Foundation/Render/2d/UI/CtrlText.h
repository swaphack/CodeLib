#pragma once

#include "CtrlFrame.h"
#include "TextProtocol.h"
#include "system.h"

namespace render
{
	/**
	*	2d�ı�
	*
	*	������ָ�����������
	*	ˮƽ���뷽ʽ������룬�Ҷ��룬 ����
	*
	*	��ָ��������ʾ
	*	��ֱ���뷽ʽ�������룬�׶��룬����
	*/
	class CtrlText : public CtrlFrame, public TextProtocol
	{
	public:
		CtrlText();
		virtual ~CtrlText();
	public:
		virtual bool init();
		// �����ֿ�·��
		void setFontPath(const std::string& fonturl);
		// ��ȡ�ֿ�·��
		const std::string& getFontPath()  const;
		// ���������С
		void setFontSize(float size);
		// ��ȡ�����С
		float getFontSize()  const;
		// ����ˮƽ�ּ��
		void setHorizontalDistance(float distance);
		// ��ȡˮƽ���
		float getHorizontalDistance() const;
		// ���ô�ֱ���
		void setVerticalDistance(float distance);
		// ��ȡ��ֱ���
		float getVerticalDistance() const;
		// �Ӵ�
		void setBorder(bool bBorder);
		// �Ӵ�
		bool isBorder() const;

		// ������ʾ���ı�
		virtual void setString(const std::string& text);

		// �����ı�ˮƽ���뷽ʽ
		void setHorizontalAlignment(sys::HorizontalAlignment alignment);
		// ��ȡ�ı�ˮƽ���뷽ʽ
		sys::HorizontalAlignment getHorizontalAlignment() const;
		// �����ı���ֱ���뷽ʽ
		void setVerticalAlignment(sys::VerticalAlignment alignment);
		// ��ȡ�ı���ֱ���뷽ʽ
		sys::VerticalAlignment getVerticalAlignment() const;
		// ������ʾ����
		void setDimensions(float width, float height);
		// ������ʾ����
		void setDimensions(const math::Size& size);
		// ��ȡ��ʾ����
		math::Size getDimensions() const;
		// ������ɫ
		void setTextColor(const sys::Color3B& color);
		// ��ɫ
		const sys::Color3B& getTextColor() const;
	protected:
		math::Vector3 getOrgin(const math::Size& size);
		virtual void onTextChange();
	private:
		// �ı��ṹ
		sys::TextDefine _textDefine;
	};
}