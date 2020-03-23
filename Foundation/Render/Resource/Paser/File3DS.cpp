#include "File3DS.h"
#include "ext-config.h"
#include "mathlib.h"
#include "3d/Common/import.h"

using namespace render;

//////////////////////////////////////////////////////////////////////////
File3DS::File3DS()
{
	this->setModelFormat(EMRF_3DS);
}

File3DS::~File3DS()
{
}

void File3DS::load(const std::string& filename)
{
	std::string strFilepath = G_FILEPATH->getFilePath(filename);

	Lib3dsFile* pFile = lib3ds_file_open(strFilepath.c_str());

	if (!pFile)
	{
		PRINT("***ERROR***\nLoading file failed: %s\n", filename.c_str());
		return;
	}
	/*
	int include_meshes = 1;
	int include_cameras = 0;
	int include_lights = 0;
	float bmin[3];
	float bmax[3];
	float matrix[4][4];
	lib3ds_file_bounding_box_of_nodes(pFile, include_meshes, include_cameras, include_lights, bmin, bmax, matrix);
	math::Volume size(bmax[0] - bmin[0], bmax[1] - bmin[1], bmax[2] - bmin[2]);
	math::Vector3 center(bmax[0] + bmin[0], bmax[1] + bmin[1], bmax[2] + bmin[2]);
	center *= 0.5f;
	*/

	std::string dir;
	sys::Directory::getDirectory(filename, dir);
	for (int i = 0; i < pFile->nmaterials; i++)
	{
		auto pMatData = pFile->materials[i];
		if (pMatData)
		{
			int id = lib3ds_file_material_by_name(pFile, pMatData->name);

			if (pMatData->texture1_map.name[0])
			{
				int textureID = createTexture(pMatData->texture1_map.name, dir);
				if (textureID)
				{
					this->addTexture(pMatData->texture1_map.name, textureID);
				}
			}
			if (pMatData->texture1_mask.name[0])
			{
				int textureID = createTexture(pMatData->texture1_mask.name, dir);
				if (textureID)
				{
					this->addTexture(pMatData->texture1_mask.name, textureID);
				}

			}
			if (pMatData->texture2_map.name[0])
			{
				int textureID = createTexture(pMatData->texture2_map.name, dir);
				if (textureID)
				{
					this->addTexture(pMatData->texture2_map.name, textureID);
				}
			}
			if (pMatData->texture2_mask.name[0])
			{
				int textureID = createTexture(pMatData->texture2_mask.name, dir);
				if (textureID)
				{
					this->addTexture(pMatData->texture2_mask.name, textureID);
				}
			}

			auto pMat = CREATE_OBJECT(Material);
			pMat->setName(pMatData->name);
			pMat->setTexture1(pMatData->texture1_map.name);
			pMat->setTexture2(pMatData->texture2_map.name);
			pMat->setAmbient(pMatData->ambient[0], pMatData->ambient[1], pMatData->ambient[2]);
			pMat->setDiffuse(pMatData->diffuse[0], pMatData->diffuse[1], pMatData->diffuse[2]);
			pMat->setSpecular(pMatData->specular[0], pMatData->specular[1], pMatData->specular[2]);
			pMat->setShiness(pMatData->shininess);
			this->addMaterial(id, pMat);
		}
	}

	for (int i = 0; i < pFile->nmeshes; i++)
	{
		auto pMeshData = pFile->meshes[i];
		if (pMeshData)
		{
			int id = lib3ds_file_mesh_by_name(pFile, pMeshData->name);

			auto pMesh = CREATE_OBJECT(Mesh);

			if (pMeshData->nvertices)
			{
				if (pMeshData->vertices)
				{
					int nVerticeCount = 3 * pMeshData->nvertices;
					float* verticeData = new float[nVerticeCount];

					for (int j = 0; j < pMeshData->nvertices; j++)
					{
						float pos[3] = { 0 };
						pos[0] = pMeshData->vertices[j][0];
						pos[1] = pMeshData->vertices[j][1];
						pos[2] = pMeshData->vertices[j][2];
						Tool::convertToOGLPoisition(pos, pos);
						memcpy(verticeData + 3 * j, pos, 3 * sizeof(float));
					}

					pMesh->setVertices(nVerticeCount, verticeData);
					delete verticeData;
				}

				if (pMeshData->texcos)
				{
					int nTexCoordCount = 2 * pMeshData->nvertices;
					float* texCoordData = new float[nTexCoordCount];
					for (int j = 0; j < pMeshData->nvertices; j++)
					{
						memcpy(texCoordData + 2 * j, pMeshData->texcos[j], 2 * sizeof(float));
					}
					pMesh->setUVs(nTexCoordCount, texCoordData, 2);
					delete texCoordData;
				}
			}

			if (pMeshData->nfaces)
			{			

				std::map<int, std::vector<int>> mapMat;
				for (int j = 0; j < pMeshData->nfaces; j++)
				{
					int nMatID = pMeshData->faces[j].material;
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
							*(indices + j * 3) = pMeshData->faces[item1].index[0];
							*(indices + j * 3 + 1) = pMeshData->faces[item1].index[1];
							*(indices + j * 3 + 2) = pMeshData->faces[item1].index[2];
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

			this->addMesh(id, pMesh);
		}
	}

	lib3ds_file_free(pFile);
}
