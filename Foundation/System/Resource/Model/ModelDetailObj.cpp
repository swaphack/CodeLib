#include "ModelDetailObj.h"
#include "mathlib.h"
#include "../extensions.h"
#include "IO/Directory.h"
#include "MaterialDetail.h"
#include "MeshDetail.h"

using namespace sys;

ModelDetailObj::ModelDetailObj()
{
}

ModelDetailObj::~ModelDetailObj()
{
}

bool ModelDetailObj::load(const std::string& fullpath)
{
	if (fullpath.empty())
	{
		return false;
	}
	// Initialize Loader
	objl::Loader loader;

	// Load .obj File
	bool loadout = loader.LoadFile(fullpath);
	if (!loadout)
	{
		return false;
	}

	std::string dir;
	Directory::getDirectory(fullpath, dir);

	std::map<std::string, int> mapMatID;

	for (int i = 0; i < loader.LoadedMaterials.size(); i++)
	{
		auto pMatData = &loader.LoadedMaterials[i];
		if (pMatData)
		{
			int id = i + 1;

			if (!pMatData->map_Ka.empty())
			{
				std::string fullpath = getTextureFullPath(pMatData->map_Ka, dir);
				this->addTexturePath(pMatData->map_Ka, fullpath);
// 				Texture2D* textureID = createTexture(pMatData->map_Ka, dir);
// 				if (textureID)
// 				{
// 					this->addTexture(pMatData->map_Ka, textureID);
// 				}
			}

			if (!pMatData->map_Kd.empty())
			{
				std::string fullpath = getTextureFullPath(pMatData->map_Kd, dir);
				this->addTexturePath(pMatData->map_Kd, fullpath);

// 				Texture2D* textureID = createTexture(pMatData->map_Kd, dir);
// 				if (textureID)
// 				{
// 					this->addTexture(pMatData->map_Kd, textureID);
// 				}
			}

			auto pMat = CREATE_OBJECT(MaterialDetail);
			pMat->setAmbientTextureMap(pMatData->map_Ka);
			pMat->setDiffuseTextureMap(pMatData->map_Kd);
			pMat->setSpecularTextureMap(pMatData->map_Ks);
			pMat->setAlphaTextureMap(pMatData->map_d);
			pMat->setBumpTextureMap(pMatData->map_bump);
			pMat->setName(pMatData->name);
			pMat->setAmbient(pMatData->Ka.X, pMatData->Ka.Y, pMatData->Ka.Z);
			pMat->setDiffuse(pMatData->Kd.X, pMatData->Kd.Y, pMatData->Kd.Z);
			pMat->setSpecular(pMatData->Ks.X, pMatData->Ks.Y, pMatData->Ks.Z);
			//pMat->setShiness(pMatData->Ns);
			this->addMaterial(pMatData->name, pMat);

			mapMatID[pMatData->name] = id;
		}
	}

	if (loader.LoadedMeshes.size() > 0)
	{
		int nCount = loader.LoadedMeshes.size();

		for (int j = 0; j < nCount; j++)
		{
			auto pData = &loader.LoadedMeshes[j];
			

			auto pMesh = CREATE_OBJECT(MeshDetail);
			pMesh->setName(pData->MeshName);

			this->addMesh(pData->MeshMaterial.name, pMesh);

			int nMatID = 0;
			auto it = mapMatID.find(pData->MeshMaterial.name);
			if (it != mapMatID.end())
			{
				nMatID = it->second;
				if (nMatID == 0)
				{
					int a = 1;
				}
			}

			pMesh->setMaterial(pData->MeshMaterial.name);

			int nVertCount = pData->Vertices.size();
			if (nVertCount > 0)
			{
				float* verticeData = (float*)pMesh->createVertices(nVertCount, sizeof(float), 3);

				float* normalData = (float*)pMesh->createNormals(nVertCount, sizeof(float), 3);

				float* texCoordData = (float*)pMesh->createUVs(nVertCount, sizeof(float), 2);

				float* colorData = (float*)pMesh->createColors(nVertCount, sizeof(float), 4);

				for (int i = 0; i < nVertCount; i++)
				{
					auto pVertex = &pData->Vertices[i];

					float pos[3] = { 0 };
					pos[0] = pVertex->Position.X;
					pos[1] = pVertex->Position.Y;
					pos[2] = pVertex->Position.Z;
					memcpy(verticeData + 3 * i, pos, 3 * sizeof(float));

					float color[4] = { 0 };
					color[0] = 1.0f;
					color[1] = 1.0f;
					color[2] = 1.0f;
					color[3] = 1.0f;
					memcpy(colorData + 4 * i, color, 4 * sizeof(float));

					*(texCoordData + 2 * i) = pVertex->TextureCoordinate.X;
					*(texCoordData + 2 * i + 1) = pVertex->TextureCoordinate.Y;

					float normal[3] = { 0 };
					normal[0] = pVertex->Normal.X;
					normal[1] = pVertex->Normal.Y;
					normal[2] = pVertex->Normal.Z;
					memcpy(normalData + 3 * i, normal, 3 * sizeof(float));
				}
			}
			
			int nIdxCount = pData->Indices.size();
			if (nIdxCount> 0)
			{
				uint32_t* indices = (uint32_t*)pMesh->createIndices(nIdxCount, sizeof(uint32_t), 1);
				for (int i = 0; i < nIdxCount; i++)
				{
					indices[i] = pData->Indices[i];
				}
			}
		}
	}
	
	return true;
}

