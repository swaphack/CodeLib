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
	*	����ϵͳ
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
		// ����,��д
		virtual void draw();
	public:
		/**
		*	���»���
		*/
		ParticleUpdateXFbObject* getUpdateXFBObject() const;
		/**
		*	���ƻ���
		*/
		ParticleRenderXFbObject* getRenderXFBObject() const;
	public:
		/**
		*	���Ӹ���
		*/
		void setParticleCount(int count);
		/**
		*	���Ӹ���
		*/
		int getParticleCount() const;
	protected:
		void renderParticles();
		/**
		*	���µ�
		*/
		ParticleUpdateXFbObject* _updateXFBObject;
		/**
		*	���Ƶ�
		*/
		ParticleRenderXFbObject* _renderXFBObject;
		/**
		*	���Ӹ���
		*/
		int _particleCount = 0;

		TextureBuffer* _geometryVBO = nullptr;
		Texture* _geometryTex = nullptr;

		VertexArrayObject* _renderVAO = nullptr;

		int _frameCount = 0;
	};
}