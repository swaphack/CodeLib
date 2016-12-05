#pragma once

#include "macros.h"

namespace render
{
	// ��������
	class Mesh : public sys::Object
	{
	public:
		Mesh();
		virtual ~Mesh();
	public:
		// ���ö���,���ߣ�����������Ϣ
		void setVertexes(int count, float* vertexes, float* normals, float* colors, float* texCoords);
		// ��������������
		void setIndices(int count, ushort* indices);
		// ������
		int getVertexCount();
		// ��������
		int getTriangleCount();

		void apply(int textureID, const sys::Color4B& color, uchar opacity, const BlendParam& blend);
	protected:
		// ������
		int _vertexCount;
		// �������� (x,y,z)
		float* _vertexes;
		// ���� (x,y,z)
		float* _normals;
		// ��ɫ (r,g,b)
		float* _colors;
		// �������� (x,y,z)
		float* _texCoords;

		// ��������
		int _triangleCount;
		// ��������
		ushort* _indices;
	};
}