#pragma once

#include <string>
#include <map>

#include "Resource/Config/import.h"
#include "Common/GL/pointer_common.h"

namespace render
{
	class Model;
	// 模型数据
	struct T_ModelData
	{
		// 模型名称
		std::string Name;
		// 纹理图片路径
		std::string ImagePath;
		// 纹理图片格式
		ImageFormat Format;
		// 纹理坐标(（u,v 三维）)
		T_Vertex TexCoords;
		// 顶点坐标（x,y,z 三维）
		T_Vertex Vertexes;
		// 顶点法线（x,y,z 三维）
		T_Vertex Normals;
		// 顶点颜色（r,g,b,a 三色+alpha）
		T_Vertex Colors;
		// 顶点索引(三角形，三个点决定一个三角形)
		T_Indice Indices;
	};
	/**
	*	3d模型配置文件
	*	包含：
	*	1.顶点（x,y,z）坐标
	*	2.法线（x,y,z）坐标
	*	3.颜色（r,g,b)值 
	*	4.纹理UV坐标
	*	顶点序列
	*/
	class ModelFile
	{
	private:
		ModelFile();
		~ModelFile();
	public:
		static ModelFile* getInstance();
		// 从配置加载模型
		Model* load(const char* filepath);
	protected:
		// 加载数据
		T_ModelData* loadData(const char* filepath);
		// 加载模型
		Model* loadModel(T_ModelData* pData);
	private:
		// 获取浮点数组
		float* getFloatAry(const char* text, int count);
		ushort* getUShortAry(const char* text, int count);
	private:
		// 模型配置
		std::map<std::string, T_ModelData> _modelDatas;
	};
}