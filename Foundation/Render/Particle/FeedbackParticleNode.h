#pragma once

#include "PariticleNode.h"

namespace render
{
	class XFeedback;
	class VertexArrayBufferObject;
	class ShaderProgram;

	/**
	*	ʹ�÷��������ӽڵ�
	*/
	class FeedbackParticleNode : public PariticleNode
	{
	public:
		FeedbackParticleNode();
		virtual ~FeedbackParticleNode();
	public:
		virtual bool init();
	protected:
		// ����ʱ��
		virtual void update(float dt);
		virtual void draw();
		// �����ı�
		virtual void updateParticleParameter();
	public:
		/**
		*	���·���
		*/
		XFeedback* getUpdateObject() const;
		/**
		*	������Ⱦ��ɫ��
		*/
		void loadRenderProgram(const std::string& vpath, const std::string& fpath);
		/**
		*	����xfb��ɫ��
		*/
		void loadXFBProgram(const std::string& vpath, const std::string& watchVarying);
	private:
		/**
		*	���·���
		*/
		XFeedback* _feedback = nullptr;
		/**
		*	��������
		*/
		VertexArrayBufferObject* _updateBufferObject = nullptr;
		/**
		*	��Ⱦ����
		*/
		VertexArrayBufferObject* _renderBufferObject = nullptr;
		/**
		*	��Ⱦ��ɫ��
		*/
		ShaderProgram* _renderProgram = nullptr;
	};
}