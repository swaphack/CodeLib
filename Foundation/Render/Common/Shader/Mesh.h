#pragma once

#include "system.h"
#include "../GL/pointer_common.h"
#include "../GL/texture_common.h"

namespace render
{
	// ��������
	class Mesh : public sys::Object
	{
	public:
		Mesh();
		virtual ~Mesh();
	public:
		/** 
		*	���ö���������Ϣ
		*	@param count ���鳤��
		*	@param vertexes �������꣨xyz��
		*	@param size ÿ��Ԫ�ش�С 3
		*/
		void setVertexes(int count, float* vertexes);
		/**
		*	���÷���������Ϣ
		*	@param count ���鳤��
		*	@param normals �������꣨xyz��
		*	@param size ÿ��Ԫ�ش�С 3
		*/
		void setNormals(int count, float* normals);
		/**
		*	������ɫ������Ϣ
		*	@param count ���鳤��
		*	@param colors ��ɫ��rgba 255��
		*	@param size ÿ��Ԫ�ش�С 3��4
		*/
		void setColors(int count, float* colors, int size);
		/**
		*	��������������Ϣ
		*	@param count ���鳤��
		*	@param texCoords �������꣨uv��
		*	@param size ÿ��Ԫ�ش�С 2��3
		*/
		void setUV(int count, float* texCoords, int size);

		// ������
		int getVertexCount();

		// ��������
		int getTriangleCount();
		/**
		*	��������������
		*	@param count �����ζ�����
		*	@param indices ��������
		*/
		void setIndices(int count, ushort* indices);
		/**
		*	����
		*	@param textureID ����id
		*	@param color ��ɫ
		*/
		void apply(int textureID, const sys::Color4B& color, uchar opacity, const BlendParam& blend);
	protected:
		// �������� (x,y,z)
		T_Vertex _vertexes;
		// �������� (x,y,z)
		T_Vertex _normals;
		// ��ɫ (r,g,b,a)
		T_Vertex _colors;
		// �������� (x,y,z)
		T_Vertex _uvs;
		// ��������
		T_Indice _indices;
	};
}