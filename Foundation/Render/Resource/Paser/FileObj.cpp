#include "FileObj.h"
#include "mathlib.h"
#include "3d/Common/import.h"
#include "ext-config.h"
#include "Common/Texture/Texture.h"
#include "Common/Tool/Tool.h"

#include "Resource/Detail/MaterialDetail.h"
#include "Resource/Detail/MeshDetail.h"

using namespace render;

FileObj::FileObj()
{
}

FileObj::~FileObj()
{
}

void FileObj::load(const std::string& filename)
{
	std::string strFilepath = G_FILEPATH->getFilePath(filename);

	// Initialize Loader
	objl::Loader loader;

	// Load .obj File
	bool loadout = loader.LoadFile(strFilepath);
	if (!loadout)
	{
		return;
	}

	std::string dir;
	sys::Directory::getDirectory(filename, dir);

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
			pMat->setName(pMatData->name);
			pMat->setAmbient(pMatData->Ka.X, pMatData->Ka.Y, pMatData->Ka.Z);
			pMat->setDiffuse(pMatData->Kd.X, pMatData->Kd.Y, pMatData->Kd.Z);
			pMat->setSpecular(pMatData->Ks.X, pMatData->Ks.Y, pMatData->Ks.Z);
			//pMat->setShiness(pMatData->Ns);
			this->addMaterial(id, pMat);

			mapMatID[pMatData->name] = id;
		}
	}

	if (loader.LoadedMeshes.size() > 0)
	{
		int nCount = loader.LoadedMeshes.size();

		for (int j = 0; j < nCount; j++)
		{
			auto pMesh = CREATE_OBJECT(MeshDetail);
			
			this->addMesh(j, pMesh);

			auto pData = &loader.LoadedMeshes[j];
			pMesh->setMeshName(pData->MeshName);

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

			pMesh->setMaterial(nMatID);

			int nVertCount = pData->Vertices.size();
			if (nVertCount > 0)
			{
				int nVerticeCount = 3 * nVertCount;
				float* verticeData = new float[nVerticeCount];

				int nNormalCount = 3 * nVertCount;
				float* normalData = new float[nNormalCount];

				int nTexCoordCount = 2 * nVertCount;
				float* texCoordData = new float[nTexCoordCount];

				for (int i = 0; i < nVertCount; i++)
				{
					auto pVertex = &pData->Vertices[i];

					float pos[3] = { 0 };
					pos[0] = pVertex->Position.X;
					pos[1] = pVertex->Position.Y;
					pos[2] = pVertex->Position.Z;
					Tool::convertToOGLPoisition(pos, pos);
					memcpy(verticeData + 3 * i, pos, 3 * sizeof(float));

					float normal[3] = { 0 };
					normal[0] = pVertex->Normal.X;
					normal[1] = pVertex->Normal.Y;
					normal[2] = pVertex->Normal.Z;
					memcpy(normalData + 3 * i, normal, 3 * sizeof(float));

					*(texCoordData + 2 * i) = pVertex->TextureCoordinate.X;
					*(texCoordData + 2 * i + 1) = pVertex->TextureCoordinate.Y;
				}

				pMesh->setVertices(nVerticeCount, verticeData);
				delete[] verticeData;

				pMesh->setNormals(nNormalCount, normalData);
				delete[] normalData;

				pMesh->setUVs(nTexCoordCount, texCoordData, 2);
				delete[] texCoordData;
			}
			
			int nIdxCount = pData->Indices.size();
			if (nIdxCount> 0)
			{
				uint32_t* indices = new uint32_t[nIdxCount];
				for (int i = 0; i < nIdxCount; i++)
				{
					indices[i] = pData->Indices[i];
				}
				pMesh->setIndices(nIdxCount, indices);
				delete[] indices;
			}
		}
	}
	
}

