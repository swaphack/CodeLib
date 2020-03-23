#include "FileObj.h"
#include "mathlib.h"
#include "3d/Common/import.h"
#include "ext-config.h"

using namespace render;

FileObj::FileObj()
{
	this->setModelFormat(EMRF_OBJ);
}

FileObj::~FileObj()
{
}

void FileObj::load(const std::string& filename)
{
	std::string strFilepath = G_FILEPATH->getFilePath(filename);

	OBJECT* pObj = nullptr;
	int ret = LoadObj(pObj, (char*)strFilepath.c_str());
	if (ret)
	{
		return;
	}

	std::string dir;
	sys::Directory::getDirectory(filename, dir);

	for (int i = 0; i < pObj->nummat; i++)
	{
		auto pMatData = &pObj->materials[i];
		if (pMatData)
		{
			int id = i;

			if (pMatData->m_TextureMap1[0])
			{
				PRINT("m_TextureMap1 %s\n", pMatData->m_TextureMap1);
				int textureID = createTexture(pMatData->m_TextureMap1, dir);
				if (textureID)
				{
					this->addTexture(pMatData->m_TextureMap1, textureID);
				}
			}

			if (pMatData->m_TextureMap2[0])
			{
				PRINT("m_TextureMap2 %s\n", pMatData->m_TextureMap2);
				int textureID = createTexture(pMatData->m_TextureMap2, dir);
				if (textureID)
				{
					this->addTexture(pMatData->m_TextureMap2, textureID);
				}
			}

			auto pMat = CREATE_OBJECT(Material);
			pMat->setTexture1(pMatData->m_TextureMap1);
			pMat->setTexture2(pMatData->m_TextureMap2);
			pMat->setName(pMatData->m_MaterialName);
			pMat->setAmbient(pMatData->m_AmbientColor[0], pMatData->m_AmbientColor[1], pMatData->m_AmbientColor[2]);
			pMat->setDiffuse(pMatData->m_DiffuseColor[0], pMatData->m_DiffuseColor[1], pMatData->m_DiffuseColor[2]);
			pMat->setSpecular(pMatData->m_SpecularColor[0], pMatData->m_SpecularColor[1], pMatData->m_SpecularColor[2]);
			pMat->setShiness(pMatData->m_Shininess);
			this->addMaterial(id, pMat);
		}
	}


	auto pMesh = CREATE_OBJECT(Mesh);

	if (pObj->vertices)
	{
		int nVerticeCount = 3 * pObj->numverts;
		float* verticeData = new float[nVerticeCount];

		for (int j = 0; j < pObj->numverts; j++)
		{
			float pos[3] = { 0 };
			pos[0] = pObj->vertices[j].x;
			pos[1] = pObj->vertices[j].y;
			pos[2] = pObj->vertices[j].z;
			Tool::convertToOGLPoisition(pos, pos);
			memcpy(verticeData + 3 * j, pos, 3 * sizeof(float));
		}

		pMesh->setVertices(nVerticeCount, verticeData);
		delete verticeData;
	}

	if (pObj->normals)
	{
		int nNormalCount = 3 * pObj->numnorm;
		float* normalData = new float[nNormalCount];

		for (int j = 0; j < pObj->numverts; j++)
		{
			float pos[3] = { 0 };
			pos[0] = pObj->vertices[j].x;
			pos[1] = pObj->vertices[j].y;
			pos[2] = pObj->vertices[j].z;
			memcpy(normalData + 3 * j, pos, 3 * sizeof(float));
		}

		pMesh->setNormals(nNormalCount, normalData);
		delete normalData;
	}

	if (pObj->numtex)
	{
		int nTexCoordCount = 2 * pObj->numtex;
		float* texCoordData = new float[nTexCoordCount];
		for (int j = 0; j < pObj->numtex; j++)
		{
			*(texCoordData + 2 * j) = pObj->texturecoords[j].u;
			*(texCoordData + 2 * j + 1) = pObj->texturecoords[j].v;
		}
		pMesh->setUVs(nTexCoordCount, texCoordData, 2);
		delete texCoordData;
	}

	if (pObj->faces)
	{
		std::map<int, std::vector<int>> mapMat;
		for (int j = 0; j < pObj->numfaces; j++)
		{
			int nMatID = pObj->faces[j].matindex;
			auto it = mapMat.find(nMatID);
			if (it == mapMat.end())
			{
				mapMat[nMatID] = std::vector<int>();
			}
			mapMat[nMatID].push_back(j);
		}

		for (auto item0 : mapMat)
		{
			int nFaceCount = 3 * item0.second.size();
			if (nFaceCount > 0)
			{
				uint16_t* indices = new uint16_t[nFaceCount];
				int j = 0;
				for (auto item1 : item0.second)
				{
					*(indices + j * 3) = pObj->faces[item1].vert[0];
					*(indices + j * 3 + 1) = pObj->faces[item1].vert[1];
					*(indices + j * 3 + 2) = pObj->faces[item1].vert[2];
					j++;
				}

				Face* pFace = CREATE_OBJECT(Face);
				pFace->setMaterial(item0.first);
				pFace->setIndices(nFaceCount, indices);
				pMesh->addFace(item0.first, pFace);

				delete indices;
			}
		}
	}
	this->addMesh(0, pMesh);
	ReleaseObj(pObj);
}

