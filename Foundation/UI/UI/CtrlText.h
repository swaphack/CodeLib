#pragma once

#include "CtrlWidget.h"
#include "TextProtocol.h"
#include "system.h"

namespace ui
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
	class CtrlText : public CtrlWidget, public TextProtocol
	{
	public:
		CtrlText();
		virtual ~CtrlText();
	public:
		virtual bool init();
		/**
		*	�����ֿ�·��
		*/ 
		void setFontPath(const std::string& filepath);
		/**
		*	��ȡ�ֿ�·��
		*/ 
		const std::string& getFontPath()  const;
		/**
		*	���������С
		*/ 
		void setFontSize(float size);
		/**
		*	��ȡ�����С
		*/  
		float getFontSize()  const;
		/**
		*	����ˮƽ�ּ��
		*/ 
		void setHorizontalDistance(float distance);
		/**
		*	��ȡˮƽ���
		*/  
		float getHorizontalDistance() const;
		/**
		*	���ô�ֱ���
		*/ 
		void setVerticalDistance(float distance);
		/**
		*	��ȡ��ֱ���
		*/  
		float getVerticalDistance() const;
		/**
		*	�Ӵ�
		*/  
		void setBorder(bool bBorder);
		/**
		*	�Ӵ�
		*/  
		bool isBorder() const;

		/**
		*	������ʾ���ı�
		*/ 
		virtual void setString(const std::string& text);

		/**
		*	�����ı�ˮƽ���뷽ʽ
		*/  
		void setTextHorizontalAlignment(sys::HorizontalAlignment alignment);
		/**
		*	��ȡ�ı�ˮƽ���뷽ʽ
		*/ 
		sys::HorizontalAlignment getTextHorizontalAlignment() const;
		/**
		*	�����ı���ֱ���뷽ʽ
		*/  
		void setTextVerticalAlignment(sys::VerticalAlignment alignment);
		/**
		*	��ȡ�ı���ֱ���뷽ʽ
		*/ 
		sys::VerticalAlignment getTextVerticalAlignment() const;
		/**
		*	������ʾ����
		*/ 
		void setDimensions(float width, float height);
		/**
		*	������ʾ����
		*/  
		void setDimensions(const math::Size& size);
		/**
		*	��ȡ��ʾ����
		*/ 
		math::Size getDimensions() const;
		/**
		*	������ɫ
		*/  
		void setTextColor(const phy::Color3B& color);
		/**
		*	��ɫ
		*/ 
		const phy::Color3B& getTextColor() const;
	public:
		/**
		*	������ɫ��
		*/
		virtual void setTexShaderProgram(render::ShaderProgram* shaderProgram);
		/**
		*	��Ⱦ�ڵ�
		*/
		render::DrawTexture2D* getRenderNode()  const;
	protected:
		/**
		*	����ͼƬ��Ϣ
		*/
		void getOrgin(const math::Size& size, math::Vector3& anchor, math::Vector3& position);

		virtual void onTextBodyChange();
		virtual void onTextTextureChange();
	private:
		// �ı��ṹ
		sys::TextDefine _textDefine;
		// 2d����
		render::DrawTexture2D* _texture2D = nullptr;
	};
}