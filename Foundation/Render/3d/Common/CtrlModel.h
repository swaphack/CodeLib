#pragma once

#include "../macros.h"

namespace render
{
	// 模型
	class CtrlModel : public ColorNode
	{
	public:
		CtrlModel();
		virtual ~CtrlModel();
	public:
		virtual void draw();
		// 设置模型材质 
		void setMatrial(const Material* material);
		// 获取模型材质
		const Material* getMatrial() const;
		// 获取模型材质
		Material* getMatrial();
		
		// 设置所有面的纹理帧
		virtual void setTexFrame(const TexFrame* frame);

		// 设置顶点,法线，纹理坐标信息
		void setVertexes(int count, float* vertexes, float* normals, float* colors, float* texCoords);
		// 设置三角形索引
		void setIndices(int count, int* indices);
		// 顶点数
		int getVertexCount();
		// 三角形数
		int getTriangleCount();
	protected:
		virtual void initSelf();
	protected:
		// 模型材质
		Material* _material;
		// 纹理
		TexFrame* _texFrame;

		// 顶点数
		int _vertexCount;
		// 顶点坐标 (x,y,z)
		float* _vertexes;
		// 法线 (x,y,z)
		float* _normals;
		// 颜色 (r,g,b)
		float* _colors;
		// 纹理坐标 (x,y,z)
		float* _texCoords;
		
		// 三角形数
		int _triangleCount;
		// 顶点索引
		int* _indices;
	};
}