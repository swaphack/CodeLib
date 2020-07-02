#pragma once

#include "PariticleNode.h"

namespace render
{
	class TransformFeedbackBufferObject;
	class VertexArrayBufferObject;
	class ShaderProgram;

	/**
	*	ʹ�÷��������ӽڵ�
	*/
	class TransformFeedbackParticleNode : public PariticleNode
	{
	public:
		TransformFeedbackParticleNode();
		virtual ~TransformFeedbackParticleNode();
	public:
		virtual bool init();
	protected:
		// ����ʱ��
		virtual void update(float dt);
		// �����ı�
		virtual void updateParticleParameter();
	public:
		/**
		*	���·���
		*/
		TransformFeedbackBufferObject* getUpdateObject() const;
		/**
		*	������ɫ��
		*/
		void loadShaderProgram(const std::string& vpath, const std::string& fpath);
	private:
		/**
		*	���·���
		*/
		TransformFeedbackBufferObject* _updateObject = nullptr;
		/**
		*	��Ⱦ����
		*/
		VertexArrayBufferObject* _renderObject = nullptr;
		/**
		*	��Ⱦ
		*/
		ShaderProgram* _shaderProgram = nullptr;
	};
}