#include "ModelFile.h"
#include "system.h"
#include "text.h"
using namespace render;

ModelFile::ModelFile()
{

}

ModelFile::~ModelFile()
{

}

ModelFile* ModelFile::getInstance()
{
	static ModelFile* s_ModelFile = nullptr;
	if (s_ModelFile == nullptr)
	{
		s_ModelFile = new ModelFile();
	}

	return s_ModelFile;
}

CtrlModel* ModelFile::load(const char* filepath)
{
	if (filepath == nullptr)
	{
		return nullptr;
	}

	T_ModelData* pData = loadData(filepath);
	if (pData == nullptr)
	{
		return nullptr;
	}

	CtrlModel* pModel = loadModel(pData);
	if (pModel == nullptr)
	{
		return nullptr;
	}

	return pModel;
}

T_ModelData* ModelFile::loadData(const char* filepath)
{
	const char* fullpath = G_FILEPATH->getFilePath(filepath);
	if (fullpath == nullptr)
	{
		return nullptr;
	}

	if (_modelDatas.find(fullpath) != _modelDatas.end())
	{
		return &_modelDatas[fullpath];
	}

	tinyxml2::XMLDocument* pDoccument = new tinyxml2::XMLDocument();
	tinyxml2::XMLError error = pDoccument->LoadFile(fullpath);
	if (error != tinyxml2::XML_SUCCESS)
	{
		delete pDoccument;
		return nullptr;
	}

	tinyxml2::XMLNode* pRoot = pDoccument->RootElement();

	T_ModelData& modelData = _modelDatas[fullpath];
	tinyxml2::XMLElement* pElement;

	pElement = (tinyxml2::XMLElement*)pRoot;
	modelData.Name = pElement->Attribute("Name");
	modelData.VertexCount = atoi(pElement->Attribute("VertexCount"));
	modelData.IndexCount = atoi(pElement->Attribute("IndexCount"));

	pRoot = pRoot->FirstChild();
	while (pRoot)
	{
		pElement = (tinyxml2::XMLElement*)pRoot;
		if (strcmp(pElement->Value(), "Image") == 0)
		{
			modelData.ImagePath = pElement->Attribute("ImagePath");
			modelData.Format = (ImageFormat)atoi(pElement->Attribute("Format"));
		}
		else if (strcmp(pElement->Value(), "TexCoords") == 0)
		{
			modelData.TexCoords = getFloatAry(pElement->GetText(), modelData.VertexCount);
		}
		else if (strcmp(pElement->Value(), "Vertexes") == 0)
		{
			modelData.Vertexes = getFloatAry(pElement->GetText(), modelData.VertexCount);
		}
		else if (strcmp(pElement->Value(), "Normals") == 0)
		{
			modelData.Normals = getFloatAry(pElement->GetText(), modelData.VertexCount);
		}
		else if (strcmp(pElement->Value(), "Colors") == 0)
		{
			modelData.Colors = getFloatAry(pElement->GetText(), modelData.VertexCount);
		}
		else if (strcmp(pElement->Value(), "Indices") == 0)
		{
			modelData.Indices = getUShortAry(pElement->GetText(), modelData.IndexCount);
		}
		
		pRoot = pRoot->NextSibling();
	}

	return &modelData;
}

CtrlModel* ModelFile::loadModel(T_ModelData* pData)
{
	if (pData == nullptr)
	{
		return nullptr;
	}
	ImageDefine imageDefine = { pData->ImagePath.c_str(), pData->Format };
	Texture2D* texture2D = G_TEXTURE_CACHE->getTexture2D(imageDefine);
	if (texture2D == nullptr)
	{
		return nullptr;
	}

	TexFrame* frame = new TexFrame();
	AUTO_RELEASE_OBJECT(frame);
	frame->setTextureWithRect(texture2D);

	CtrlModel* pModel = new CtrlModel();
	pModel->setTexFrame(frame);

	pModel->setVertexes(pData->VertexCount, pData->Vertexes, pData->Normals, pData->Colors, pData->TexCoords);
	pModel->setIndices(pData->IndexCount, pData->Indices);

	return pModel;
}

float* ModelFile::getFloatAry(const char* text, int count)
{
	sys::String value = text;
	value = value.trim();
	std::vector<sys::String> strAry;
	value.split(',', strAry);

	float* data = (float*)malloc(count * sizeof(float));
	memset(data, 0, count * sizeof(float));
	for (int i = 0; i < strAry.size(); i++)
	{
		if (i < count)
		{
			data[i] = (float)atof(strAry[i].getString());
		}
	}

	return data;
}

ushort* ModelFile::getUShortAry(const char* text, int count)
{
	sys::String value = text;
	value = value.trim();
	std::vector<sys::String> strAry;
	value.split(',', strAry);

	ushort* data = (ushort*)malloc(count * sizeof(ushort));
	memset(data, 0, count * sizeof(ushort));
	for (int i = 0; i < strAry.size(); i++)
	{
		if (i < count)
		{
			data[i] = (ushort)atoi(strAry[i].getString());
		}
	}

	return data;
}
