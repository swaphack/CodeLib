#include "ModelFile.h"
#include "Model.h"
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

Model* ModelFile::load(const char* filepath)
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

	Model* pModel = loadModel(pData);
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
			modelData.TexCoords.count = pElement->IntAttribute("count");
			modelData.TexCoords.size = pElement->IntAttribute("size");
			modelData.TexCoords.value = getFloatAry(pElement->GetText(), modelData.TexCoords.count);
		}
		else if (strcmp(pElement->Value(), "Vertexes") == 0)
		{
			modelData.Vertexes.count = pElement->IntAttribute("count");
			modelData.Vertexes.size = pElement->IntAttribute("size");
			modelData.Vertexes.value = getFloatAry(pElement->GetText(), modelData.Vertexes.count);
		}
		else if (strcmp(pElement->Value(), "Normals") == 0)
		{
			modelData.Normals.count = pElement->IntAttribute("count");
			modelData.Normals.size = pElement->IntAttribute("size");
			modelData.Normals.value = getFloatAry(pElement->GetText(), modelData.Normals.count);
		}
		else if (strcmp(pElement->Value(), "Colors") == 0)
		{
			modelData.Colors.count = pElement->IntAttribute("count");
			modelData.Colors.size = pElement->IntAttribute("size");
			modelData.Colors.value = getFloatAry(pElement->GetText(), modelData.Colors.count);
		}
		else if (strcmp(pElement->Value(), "Indices") == 0)
		{
			modelData.Indices.count = pElement->IntAttribute("count");
			modelData.Indices.value = getUShortAry(pElement->GetText(), modelData.Indices.count);
		}
		
		pRoot = pRoot->NextSibling();
	}

	delete pDoccument;

	return &modelData;
}

Model* ModelFile::loadModel(T_ModelData* pData)
{
	if (pData == nullptr)
	{
		return nullptr;
	}
	Model* pModel = CREATE_NODE(Model);

	if (!pData->ImagePath.empty())
	{
		ImageDefine imageDefine = { pData->ImagePath.c_str(), pData->Format };
		Texture2D* texture2D = G_TEXTURE_CACHE->getTexture2D(imageDefine);
		if (texture2D)
		{
			TexFrame* frame = new TexFrame();
			AUTO_RELEASE_OBJECT(frame);
			frame->setTextureWithRect(texture2D);
			pModel->setTexFrame(frame);
		}
	}
	pModel->getMesh()->setVertexes(pData->Vertexes.count, pData->Vertexes.value);
	pModel->getMesh()->setNormals(pData->Normals.count, pData->Normals.value);
	pModel->getMesh()->setColors(pData->Colors.count, pData->Colors.value, pData->Colors.size);
	pModel->getMesh()->setUV(pData->TexCoords.count, pData->TexCoords.value, pData->TexCoords.size);
	pModel->getMesh()->setIndices(pData->Indices.count, pData->Indices.value);

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
	int len = strAry.size();
	for (int i = 0; i < len; i++)
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
	int len = strAry.size();
	for (int i = 0; i < len; i++)
	{
		if (i < count)
		{
			data[i] = (ushort)atoi(strAry[i].getString());
		}
	}

	return data;
}
