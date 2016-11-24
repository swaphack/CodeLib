#pragma once

#include "macros.h"

namespace render
{
	/**
	*	����������
	*/
	class DCTextureBatch : public DrawCommand
	{
	public:
		// ����id
		int TextureID;
		// ��ɫ
		sys::Color4F Color;

		// ������
		int VertexCount;
		// �������� (x,y,z)
		float* Vertexs;
		// ���� (x,y,z)
		float* Normals;
		// ��ɫ (r,g,b)
		float* Colors;
		// �������� (x,y,z)
		float* TexCoords;

		// ������
		int IndexCount;
		// ��������
		ushort* Indices;

		// ��ɫ����
		BlendParam Blend;
	public:
		DCTextureBatch();
		virtual ~DCTextureBatch();
	public:
		virtual void draw();

		static DCTextureBatch* create(int textureID,
			const sys::Color4B& color, uchar opacity, const BlendParam& blend,
			int vertexCount, float* normals, float* positions, float* colors, float* coords,
			int indexCount, ushort* indices);
	};
}