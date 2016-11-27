#pragma once

#include "CtrlModel.h"

#include <string>
#include <map>

namespace render
{
	// ģ������
	struct T_ModelData
	{
		// ģ������
		std::string Name;
		// ����ͼƬ·��
		std::string ImagePath;
		// ����ͼƬ��ʽ
		ImageFormat Format;
		// �������鳤��
		int VertexCount;
		// ��������
		float* TexCoords;
		// ��������
		float* Vertexes;
		// ���㷨��
		float* Normals;
		// ������ɫ
		float* Colors;
		// ������������
		int IndexCount;
		// ��������
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
	*	3dģ�������ļ�
	*	������
	*	1.���㣨x,y,z������
	*	2.���ߣ�x,y,z������
	*	3.��ɫ��r,g,b)ֵ 
	*	4.����UV����
	*	��������
	*/
	class ModelFile
	{
	private:
		ModelFile();
		~ModelFile();
	public:
		static ModelFile* getInstance();
		// �����ü���ģ��
		CtrlModel* load(const char* filepath);
	protected:
		// ��������
		T_ModelData* loadData(const char* filepath);
		// ����ģ��
		CtrlModel* loadModel(T_ModelData* pData);
	private:
		// ��ȡ��������
		float* getFloatAry(const char* text, int count);
		ushort* getUShortAry(const char* text, int count);
	private:
		// ģ������
		std::map<std::string, T_ModelData> _modelDatas;
	};
}