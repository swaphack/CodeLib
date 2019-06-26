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
		// ��ɫ����
		BlendParam Blend;

		// �������� (x,y,z)
		T_Vertex* Vertexes;
		// ���� (x,y,z)
		T_Vertex* Normals;
		// ��ɫ (r,g,b)
		T_Vertex* Colors;
		// �������� (x,y,z)
		T_Vertex* TexCoords;
		// ��������
		T_Indice* Indices;
	public:
		DCTextureBatch();
		virtual ~DCTextureBatch();
	public:
		virtual void draw();

		static DCTextureBatch* create(int textureID,
			const sys::Color4B& color, uint8 opacity, const BlendParam& blend,
			const T_Vertex* vertexes, const T_Vertex* normals, const T_Vertex* colors, const T_Vertex* coords,
			const T_Indice* indices);
	};
}