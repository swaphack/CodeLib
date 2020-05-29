#pragma once

#include "Common/Node/Node.h"
#include "ParticleXFbObject.h"

namespace render
{

	class ParticleSystem;
	class ShaderProgram;
	class TextureBuffer;
	class Texture;

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

		void initParticleSystem();
	protected:
		// 绘制,重写
		virtual void draw();
	public:
		/**
		*	更新回馈
		*/
		ParticleUpdateXFbObject* getUpdateXFBObject() const;
		/**
		*	绘制回馈
		*/
		ParticleRenderXFbObject* getRenderXFBObject() const;
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
		ParticleUpdateXFbObject* _updateXFBObject;
		/**
		*	绘制的
		*/
		ParticleRenderXFbObject* _renderXFBObject;
		/**
		*	粒子个数
		*/
		int _particleCount = 0;

		TextureBuffer* _geometryVBO = nullptr;
		Texture* _geometryTex = nullptr;

		VertexArrayObject* _renderVAO = nullptr;

		int _frameCount = 0;
	};
}