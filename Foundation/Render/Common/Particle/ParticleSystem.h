#pragma once

#include "Common/Node/Node.h"

namespace render
{
	class ShaderProgram;
	class TransformFeedbackObject;
	class TransformFeedbackBuffer;
	class VertexArrayObject;
	class ParticleSystem;
	class TextureBufferObject;
	class TextureBuffer;

	typedef std::function<void(ParticleSystem* node, ShaderProgram* program)> ParticleShaderFunc;

	struct FeedbackProgram
	{
		ShaderProgram* program = nullptr;
		TransformFeedbackObject* feedback = nullptr;
		ParticleShaderFunc func = nullptr;
		VertexArrayObject* vao = nullptr;
		TransformFeedbackBuffer* buffer = nullptr;

		FeedbackProgram();
		~FeedbackProgram();

		void initShaderProgram(const std::string& vpath, const std::string& fpath);

		void doFunc(ParticleSystem* node);
	};

	/**
	*	����ϵͳ
	*/
	class ParticleSystem : public Node
	{
	public:
		ParticleSystem();
		virtual ~ParticleSystem();
	public:
		virtual bool init();
	protected:
		// ����,��д
		virtual void draw();
	public:
		/**
		*	���»���
		*/
		FeedbackProgram* getUpdateFeedback() const;
		/**
		*	���ƻ���
		*/
		FeedbackProgram* getRenderFeedback() const;
	public:
		/**
		*	���Ӹ���
		*/
		void setParticleCount(int count);
		/**
		*	���Ӹ���
		*/
		int getParticleCount() const;
		/**
		*	������
		*/
		uint32_t getTextureID();
	protected:
		void onParticleChange();
	
		/**
		*	���µ�
		*/
		FeedbackProgram _updateProgram;
		/**
		*	���Ƶ�
		*/
		FeedbackProgram _renderProgram;
		/**
		*	���Ӹ���
		*/
		int _particleCount = 100;

		TextureBufferObject* _renderTBO = nullptr;
		VertexArrayObject* _renderVAO = nullptr;
		TextureBuffer* _renderTB = nullptr;

		int _frameCount = 0;
	};
}