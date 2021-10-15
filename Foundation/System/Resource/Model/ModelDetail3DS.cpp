#include "ModelDetail3DS.h"
#include "../extensions.h"
#include "mathlib.h"
#include "Base/macros.h"
#include "MaterialDetail.h"
#include "MeshDetail.h"
#include "IO/Directory.h"
using namespace sys;

//////////////////////////////////////////////////////////////////////////
ModelDetail3DS::ModelDetail3DS()
{
}

ModelDetail3DS::~ModelDetail3DS()
{
}

bool ModelDetail3DS::load(const std::string& fullpath)
{

	Lib3dsFile* pFile = lib3ds_file_open(fullpath.c_str());

	if (!pFile)
	{
		PRINT("***ERROR***\nLoading file failed: %s\n", fullpath.c_str());
		return false;
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
	Directory::getDirectory(fullpath, dir);
	for (int i = 0; i < pFile->nmaterials; i++)
	{
		auto pMatData = pFile->materials[i];
		if (pMatData)
		{
			int id = lib3ds_file_material_by_name(pFile, pMatData->name);

			if (pMatData->texture1_map.name[0])
			{
				std::string fullpath = getTextureFullPath(pMatData->texture1_map.name, dir);
				this->addTexturePath(pMatData->texture1_map.name, fullpath);
			}
			if (pMatData->texture2_map.name[0])
			{
				std::string fullpath = getTextureFullPath(pMatData->texture2_map.name, dir);
				this->addTexturePath(pMatData->texture2_map.name, fullpath);
			}
			if (pMatData->bump_map.name[0])
			{
				std::string fullpath = getTextureFullPath(pMatData->bump_map.name, dir);
				this->addTexturePath(pMatData->bump_map.name, fullpath);
			}
			if (pMatData->specular_map.name[0])
			{
				std::string fullpath = getTextureFullPath(pMatData->specular_map.name, dir);
				this->addTexturePath(pMatData->specular_map.name, fullpath);
			}
			if (pMatData->opacity_map.name[0])
			{
				std::string fullpath = getTextureFullPath(pMatData->opacity_map.name, dir);
				this->addTexturePath(pMatData->opacity_map.name, fullpath);
			}

			auto pMat = CREATE_OBJECT(MaterialDetail);
			pMat->setName(pMatData->name);
			pMat->setAmbientTextureMap(pMatData->texture1_map.name);
			pMat->setDiffuseTextureMap(pMatData->texture2_map.name);
			pMat->setBumpTextureMap(pMatData->bump_map.name);
			pMat->setSpecularTextureMap(pMatData->specular_map.name);
			pMat->setAlphaTextureMap(pMatData->opacity_map.name);
			pMat->setAmbient(pMatData->ambient[0], pMatData->ambient[1], pMatData->ambient[2]);
			pMat->setDiffuse(pMatData->diffuse[0], pMatData->diffuse[1], pMatData->diffuse[2]);
			pMat->setSpecular(pMatData->specular[0], pMatData->specular[1], pMatData->specular[2]);
			pMat->setSpecularShiness(pMatData->shininess);
			pMat->setSpecularStrength(pMatData->shin_strength);
			this->addMaterial(pMatData->name, pMat);
		}
	}

	for (int i = 0; i < pFile->nmeshes; i++)
	{
		auto pMeshData = pFile->meshes[i];
		if (pMeshData)
		{
			auto pMesh = CREATE_OBJECT(MeshDetail);
			pMesh->setName(pMeshData->name);
			this->addMesh(pMeshData->name, pMesh);

			if (pMeshData->nvertices)
			{
				int nVertices = pMeshData->nvertices;
				if (pMeshData->vertices)
				{
					float* verticeData = (float*)pMesh->createVertices(nVertices, sizeof(float), 3);

					float* colorData = (float*)pMesh->createColors(nVertices, sizeof(float), 4);

					for (int j = 0; j < pMeshData->nvertices; j++)
					{
						float pos[3] = { 0 };
						pos[0] = pMeshData->vertices[j][0];
						pos[1] = pMeshData->vertices[j][1];
						pos[2] = pMeshData->vertices[j][2];
						memcpy(verticeData + 3 * j, pos, 3 * sizeof(float));

						float color[4] = { 0 };
						color[0] = 1.0f;
						color[1] = 1.0f;
						color[2] = 1.0f;
						color[3] = 1.0f;
						memcpy(colorData + 4 * i, color, 4 * sizeof(float));
					}
				}

				if (pMeshData->texcos)
				{
					float* texCoordData = (float*)pMesh->createUVs(nVertices, sizeof(float), 2);
					for (int j = 0; j < pMeshData->nvertices; j++)
					{
						memcpy(texCoordData + 2 * j, pMeshData->texcos[j], 2 * sizeof(float));
					}
				}
				else
				{
					float* texCoordData = (float*)pMesh->createUVs(nVertices, sizeof(float), 2);
					for (int j = 0; j < pMeshData->nvertices; j++)
					{
						float uv[3] = { 0 };
						uv[0] = 0;
						uv[1] = 0;
						memcpy(texCoordData + 2 * j, uv, 2 * sizeof(float));
					}
				}


			}

			if (pMeshData->nfaces)
			{	
				float* normalData = (float*)pMesh->createNormals(3 * pMeshData->nfaces, sizeof(float), 3);
				lib3ds_mesh_calculate_vertex_normals(pMeshData, (float(*)[3])normalData);

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
					auto pMatData = pFile->materials[item0.first];
					if (!pMatData)
					{
						continue;
					}
					pMesh->setMaterialName(pMatData->name);
					int nFaceCount = 3 * item0.second.size();
					if (nFaceCount > 0)
					{
						uint32_t* indices = (uint32_t*)pMesh->createIndices(nFaceCount, sizeof(uint32_t), 1);
						int j = 0;
						for (auto idx : item0.second)
						{
							*(indices + j * 3) = pMeshData->faces[idx].index[0];
							*(indices + j * 3 + 1) = pMeshData->faces[idx].index[1];
							*(indices + j * 3 + 2) = pMeshData->faces[idx].index[2];
							j++;
						}
					}
				}
			}

			pMesh->setMatrix(math::Matrix4x4(pMeshData->map_matrix));
		}
	}

	lib3ds_file_free(pFile);

	return true;
}
