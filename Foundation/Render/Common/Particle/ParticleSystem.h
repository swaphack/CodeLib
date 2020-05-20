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
	*	粒子系统
	*/
	class ParticleSystem : public Node
	{
	public:
		ParticleSystem();
		virtual ~ParticleSystem();
	public:
		virtual bool init();
	protected:
		// 绘制,重写
		virtual void draw();
	public:
		/**
		*	更新回馈
		*/
		FeedbackProgram* getUpdateFeedback() const;
		/**
		*	绘制回馈
		*/
		FeedbackProgram* getRenderFeedback() const;
	public:
		/**
		*	粒子个数
		*/
		void setParticleCount(int count);
		/**
		*	粒子个数
		*/
		int getParticleCount() const;
		/**
		*	纹理编号
		*/
		uint32_t getTextureID();
	protected:
		void onParticleChange();
	
		/**
		*	更新的
		*/
		FeedbackProgram _updateProgram;
		/**
		*	绘制的
		*/
		FeedbackProgram _renderProgram;
		/**
		*	粒子个数
		*/
		int _particleCount = 100;

		TextureBufferObject* _renderTBO = nullptr;
		VertexArrayObject* _renderVAO = nullptr;
		TextureBuffer* _renderTB = nullptr;

		int _frameCount = 0;
	};
}