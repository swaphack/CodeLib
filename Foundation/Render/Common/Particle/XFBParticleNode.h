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
	*	����ϵͳ
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
		// ����,��д
		virtual void draw();

		virtual void update(float dt);
	public:
		/**
		*	���»���
		*/
		XFBUpdateParticle* getUpdateXFBObject() const;
		/**
		*	���ƻ���
		*/
		XFBRenderParticle* getRenderXFBObject() const;
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
		XFBUpdateParticle* _updateXFBObject;
		/**
		*	���Ƶ�
		*/
		XFBRenderParticle* _renderXFBObject;
		/**
		*	���Ӹ���
		*/
		int _particleCount = 0;

		TextureBufferObject* _geometryTBO = nullptr;
		TextureBuffer* _geometryBuffer = nullptr;

		VertexArrayObject* _renderVAO = nullptr;

		int _frameCount = 0;
	};
}