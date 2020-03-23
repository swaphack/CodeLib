#pragma once

#include "DCColor.h"

namespace render
{
	/**
	*	����������
	*/
	class DCTextureBatch : public DCColor
	{
	public:
		// ����id
		int TextureID;
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
	protected:
		virtual void drawDC();
	public:
		static DCTextureBatch* create(int textureID,
			const sys::Color4B& color, uint8_t opacity, const BlendParam& blend,
			const T_Vertex* vertexes, const T_Vertex* normals, const T_Vertex* colors, const T_Vertex* coords,
			const T_Indice* indices);
	};
}