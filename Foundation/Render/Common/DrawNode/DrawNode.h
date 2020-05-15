#pragma once

#include "../Node/Node.h"
#include "DrawProtocol.h"

namespace render
{
	class Material;
	class Mesh;

	/**
	*	���ƽڵ�
	*/
	class DrawNode :  
		public Node, 
		public ColorProtocol, 
		public OpacityProtocol,
		public BlendProtocol
	{
	public:
		DrawNode();
		virtual ~DrawNode();
	public:
		virtual void draw();
	public:
		Material* getMaterial();
		Mesh* getMesh();
	protected:
		virtual void drawing();
	protected:
		void drawWithClientArray();
		void drawWithBufferObject();
	protected:
		// ����
		Material* _material = nullptr;
		// ����
		Mesh* _mesh = nullptr;
	};
}