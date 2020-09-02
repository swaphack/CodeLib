#pragma once

#include "FrameBufferNode.h"

namespace render
{
	class Texture2D;
	class ShaderProgram;

	/**
	*	��Ӱ
	*	��������Ƶ���Դ�����գ��������ͼ
	*	�ٽ����ɵ����ͼͶӰ��Ŀ��
	*/
	class ShadowMapping : public FrameBufferNode
	{
	public:
		ShadowMapping();
		virtual ~ShadowMapping();
	public:
		virtual bool init();
	public:
		/**
		*	ͶӰ��Ӱ��ɫ��
		*/
		void setCastShaderProgram(ShaderProgram* program);
		/**
		*	������Ӱ��ɫ��
		*/
		void setReceiveLightShaderProgram(ShaderProgram* program);
		/**
		*	������ɫ��
		*/
		void setRenderShaderProgram(ShaderProgram* program);
	public:
		virtual void beforeDrawNode();
		virtual void draw();
		virtual void afterDrawNode();
	protected:
		void updateShadowMapping();
	private:
		/**
		*	��������
		*/
		Texture2D* _texture = nullptr;
		/**
		*	���ؽڵ㣬��������Ӱ
		*/
		std::set<Node*> _setHideNode;
		// ��¼��Ӱ��ɫ��
		ShaderProgram* _castShaderProgram = nullptr;
		// ������ɫ��
		ShaderProgram* _renderShaderProgram = nullptr;
		// ������ɫ��
		ShaderProgram* _receiveLightShaderProgram = nullptr;
	};
}