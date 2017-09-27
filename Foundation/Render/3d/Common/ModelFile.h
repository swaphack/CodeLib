#pragma once

#include <string>
#include <map>

#include "Resource/Config/import.h"
#include "Common/GL/pointer_common.h"

namespace render
{
	class Model;
	// ģ������
	struct T_ModelData
	{
		// ģ������
		std::string Name;
		// ����ͼƬ·��
		std::string ImagePath;
		// ����ͼƬ��ʽ
		ImageFormat Format;
		// ��������(��u,v ��ά��)
		T_Vertex TexCoords;
		// �������꣨x,y,z ��ά��
		T_Vertex Vertexes;
		// ���㷨�ߣ�x,y,z ��ά��
		T_Vertex Normals;
		// ������ɫ��r,g,b,a ��ɫ+alpha��
		T_Vertex Colors;
		// ��������(�����Σ����������һ��������)
		T_Indice Indices;
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
		Model* load(const char* filepath);
	protected:
		// ��������
		T_ModelData* loadData(const char* filepath);
		// ����ģ��
		Model* loadModel(T_ModelData* pData);
	private:
		// ��ȡ��������
		float* getFloatAry(const char* text, int count);
		ushort* getUShortAry(const char* text, int count);
	private:
		// ģ������
		std::map<std::string, T_ModelData> _modelDatas;
	};
}