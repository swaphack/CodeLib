#pragma once

#include "CtrlModel.h"

#include <string>
#include <map>

namespace render
{
	// 模型数据
	struct T_ModelData
	{
		// 模型名称
		std::string Name;
		// 纹理图片路径
		std::string ImagePath;
		// 纹理图片格式
		ImageFormat Format;
		// 顶点数组长度
		int VertexCount;
		// 纹理坐标
		float* TexCoords;
		// 顶点坐标
		float* Vertexes;
		// 顶点法线
		float* Normals;
		// 顶点颜色
		float* Colors;
		// 顶点索引长度
		int IndexCount;
		// 顶点索引
		ushort* Indices;

		T_ModelData()
		{
			TexCoords = nullptr;
			Vertexes = nullptr;
			Normals = nullptr;
			Colors = nullptr;
			Indices = nullptr;
		}

		~T_ModelData()
		{
			SAFE_FREE(TexCoords);
			SAFE_FREE(Vertexes);
			SAFE_FREE(Normals);
			SAFE_FREE(Colors);
			SAFE_FREE(Indices);
		}
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
		CtrlModel* load(const char* filepath);
	protected:
		// 加载数据
		T_ModelData* loadData(const char* filepath);
		// 加载模型
		CtrlModel* loadModel(T_ModelData* pData);
	private:
		// 获取浮点数组
		float* getFloatAry(const char* text, int count);
		ushort* getUShortAry(const char* text, int count);
	private:
		// 模型配置
		std::map<std::string, T_ModelData> _modelDatas;
	};
}