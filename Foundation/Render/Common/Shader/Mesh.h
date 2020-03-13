#pragma once

#include "system.h"
#include "../GL/pointer_common.h"
#include "../GL/texture_common.h"

namespace render
{
	// 纹理网格
	class Mesh : public sys::Object
	{
	public:
		Mesh();
		virtual ~Mesh();
	public:
		/** 
		*	设置顶点坐标信息
		*	@param size 数组长度
		*	@param vertexes 顶点坐标（xyz）
		*	@param size 每个元素大小 3
		*/
		void setVertices(int size, float* vertexes);
		/**
		*	设置法线坐标信息
		*	@param size 数组长度
		*	@param normals 法线坐标（xyz）
		*	@param size 每个元素大小 3
		*/
		void setNormals(int size, float* normals);
		/**
		*	设置颜色坐标信息
		*	@param size 数组长度
		*	@param colors 颜色（rgba 255）
		*	@param size 每个元素大小 3或4
		*/
		void setColors(int size, float* colors, int unitSize);
		/**
		*	设置纹理坐标信息
		*	@param size 数组长度
		*	@param texCoords 纹理坐标（uv）
		*	@param unitSize 每个元素大小 2或3
		*/
		void setUV(int size, float* texCoords, int unitSize);
		/**
		*	顶点数
		*/
		int getVertexCount();
		/**
		*	三角形数
		*/ 
		int getTriangleCount();
		/**
		*	设置三角形索引
		*	@param size 三角形顶点数
		*	@param indices 顶点索引
		*/
		void setIndices(int size, uint16_t* indices);
		/**
		*	设置材质
		*	@param matID 材质id
		*/
		void setMaterial(int matID);
		/**
		*	获取材质
		*	@param matID 材质id
		*/
		int getMaterial();
	public:
		/**
		*	绘制
		*	@param textureID 纹理id
		*	@param color 颜色
		*/
		void apply(int textureID, const sys::Color4B& color = sys::Color4B(), uint8_t opacity = 255, const BlendParam& blend = BlendParam());
		/**
		*	绘制
		*	@param textureID 纹理id
		*	@param color 颜色
		*/
		void apply(const sys::Color4B& color = sys::Color4B(), uint8_t opacity = 255, const BlendParam& blend = BlendParam());
	protected:
		// 顶点坐标 (x,y,z)
		T_Vertex _vertexes;
		// 法线坐标 (x,y,z)
		T_Vertex _normals;
		// 颜色 (r,g,b,a)
		T_Vertex _colors;
		// 纹理坐标 (x,y,z)
		T_Vertex _uvs;
		// 顶点索引
		T_Indice _indices;
		// 材质
		int _material = 0;
	};
}