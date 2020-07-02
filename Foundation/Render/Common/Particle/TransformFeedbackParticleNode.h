#pragma once

#include "PariticleNode.h"

namespace render
{
	class TransformFeedbackBufferObject;
	class VertexArrayBufferObject;
	class ShaderProgram;

	/**
	*	使用反馈的粒子节点
	*/
	class TransformFeedbackParticleNode : public PariticleNode
	{
	public:
		TransformFeedbackParticleNode();
		virtual ~TransformFeedbackParticleNode();
	public:
		virtual bool init();
	protected:
		// 更新时间
		virtual void update(float dt);
		// 参数改变
		virtual void updateParticleParameter();
	public:
		/**
		*	更新反馈
		*/
		TransformFeedbackBufferObject* getUpdateObject() const;
		/**
		*	加载着色器
		*/
		void loadShaderProgram(const std::string& vpath, const std::string& fpath);
	private:
		/**
		*	更新反馈
		*/
		TransformFeedbackBufferObject* _updateObject = nullptr;
		/**
		*	渲染数据
		*/
		VertexArrayBufferObject* _renderObject = nullptr;
		/**
		*	渲染
		*/
		ShaderProgram* _shaderProgram = nullptr;
	};
}