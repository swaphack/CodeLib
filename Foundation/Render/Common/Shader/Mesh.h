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
		*	@param size ���鳤��
		*	@param vertexes �������꣨xyz��
		*	@param size ÿ��Ԫ�ش�С 3
		*/
		void setVertices(int size, float* vertexes);
		/**
		*	���÷���������Ϣ
		*	@param size ���鳤��
		*	@param normals �������꣨xyz��
		*	@param size ÿ��Ԫ�ش�С 3
		*/
		void setNormals(int size, float* normals);
		/**
		*	������ɫ������Ϣ
		*	@param size ���鳤��
		*	@param colors ��ɫ��rgba 255��
		*	@param size ÿ��Ԫ�ش�С 3��4
		*/
		void setColors(int size, float* colors, int unitSize);
		/**
		*	��������������Ϣ
		*	@param size ���鳤��
		*	@param texCoords �������꣨uv��
		*	@param unitSize ÿ��Ԫ�ش�С 2��3
		*/
		void setUV(int size, float* texCoords, int unitSize);
		/**
		*	������
		*/
		int getVertexCount();
		/**
		*	��������
		*/ 
		int getTriangleCount();
		/**
		*	��������������
		*	@param size �����ζ�����
		*	@param indices ��������
		*/
		void setIndices(int size, uint16_t* indices);
		/**
		*	���ò���
		*	@param matID ����id
		*/
		void setMaterial(int matID);
		/**
		*	��ȡ����
		*	@param matID ����id
		*/
		int getMaterial();
	public:
		/**
		*	����
		*	@param textureID ����id
		*	@param color ��ɫ
		*/
		void apply(int textureID, const sys::Color4B& color = sys::Color4B(), uint8_t opacity = 255, const BlendParam& blend = BlendParam());
		/**
		*	����
		*	@param textureID ����id
		*	@param color ��ɫ
		*/
		void apply(const sys::Color4B& color = sys::Color4B(), uint8_t opacity = 255, const BlendParam& blend = BlendParam());
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
		// ����
		int _material = 0;
	};
}