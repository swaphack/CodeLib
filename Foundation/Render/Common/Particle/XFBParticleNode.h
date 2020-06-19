#pragma once

#include "Common/Node/Node.h"
#include "XFBParticle.h"

namespace render
{
	class TextureBuffer;
	class XFBParticleNode;
	class ShaderProgram;
	class TextureBufferObject;
	class Texture;

	/**
	*	粒子系统
	*/
	class XFBParticleNode : public Node
	{
	public:
		XFBParticleNode();
		virtual ~XFBParticleNode();
	public:
		virtual bool init();

		void initParticleSystem();
	protected:
		// 绘制,重写
		virtual void draw();

		virtual void update(float dt);
	public:
		/**
		*	更新回馈
		*/
		XFBUpdateParticle* getUpdateXFBObject() const;
		/**
		*	绘制回馈
		*/
		XFBRenderParticle* getRenderXFBObject() const;
	public:
		/**
		*	粒子个数
		*/
		void setParticleCount(int count);
		/**
		*	粒子个数
		*/
		int getParticleCount() const;
	protected:
		void renderParticles();
		/**
		*	更新的
		*/
		XFBUpdateParticle* _updateXFBObject;
		/**
		*	绘制的
		*/
		XFBRenderParticle* _renderXFBObject;
		/**
		*	粒子个数
		*/
		int _particleCount = 0;

		TextureBufferObject* _geometryTBO = nullptr;
		TextureBuffer* _geometryBuffer = nullptr;

		VertexArrayObject* _renderVAO = nullptr;

		int _frameCount = 0;
	};
}