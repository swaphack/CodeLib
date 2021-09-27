#pragma once

#include "PariticleNode.h"

namespace render
{
	class XFeedback;
	class VertexArrayBufferObject;
	class ShaderProgram;

	/**
	*	使用反馈的粒子节点
	*/
	class FeedbackParticleNode : public PariticleNode
	{
	public:
		FeedbackParticleNode();
		virtual ~FeedbackParticleNode();
	public:
		virtual bool init();
	protected:
		// 更新时间
		virtual void update(float dt);
		virtual void draw();
		// 参数改变
		virtual void updateParticleParameter();
	public:
		/**
		*	更新反馈
		*/
		XFeedback* getUpdateObject() const;
		/**
		*	加载渲染着色器
		*/
		void loadRenderProgram(const std::string& vpath, const std::string& fpath);
		/**
		*	加载xfb着色器
		*/
		void loadXFBProgram(const std::string& vpath, const std::string& watchVarying);
	private:
		/**
		*	更新反馈
		*/
		XFeedback* _feedback = nullptr;
		/**
		*	更新数据
		*/
		VertexArrayBufferObject* _updateBufferObject = nullptr;
		/**
		*	渲染数据
		*/
		VertexArrayBufferObject* _renderBufferObject = nullptr;
		/**
		*	渲染着色器
		*/
		ShaderProgram* _renderProgram = nullptr;
	};
}