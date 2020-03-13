#include "Model3DS.h"
#include "Resource/Paser/File3DS.h"
#include "ext-config.h"

using namespace render;

Model3DS::Model3DS()
{
	_modelLoader = new File3DS();
}

Model3DS::~Model3DS()
{
	delete _modelLoader;
}

void Model3DS::load(const std::string& filepath)
{
	_modelLoader->load(filepath.c_str());
	Lib3dsFile* pFile = (Lib3dsFile*)_modelLoader->get3dsFile();
	if (pFile == nullptr)
	{
		return;
	}
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

	std::string dir;
	sys::Directory::getDirectory(filepath, dir);
	for (int i = 0; i < pFile->nmaterials; i++)
	{
		auto pMatData = pFile->materials[i];
		if (pMatData)
		{
			int id = lib3ds_file_material_by_name(pFile, pMatData->name);

			if (pMatData->texture1_map.name[0])
			{
				PRINT("texture1_map %s\n", pMatData->texture1_map.name);
				//pMatData->user_id = createTexture(pMatData->texture1_map.name);
				createTexture(pMatData->texture1_map.name, dir);
			}
			if (pMatData->texture1_mask.name[0])
			{
				PRINT("texture1_mask %s\n", pMatData->texture1_mask.name);
				
			}
			if (pMatData->texture2_map.name[0])
			{
				PRINT("texture2_map %s\n", pMatData->texture2_map.name);
				//pMatData->user_id = createTexture(pMatData->texture1_map.name);
			}
			if (pMatData->texture2_mask.name[0])
			{
				PRINT("texture2_mask %s\n", pMatData->texture2_mask.name);
				//pMatData->user_id = createTexture(pMatData->texture1_map.name);
			}

			auto pMat = CREATE_OBJECT(Material);
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
			if (pMeshData->texcos)
			{
				pMesh->setUV(1, *pMeshData->texcos, 2);
			}
			if (pMeshData->vertices)
			{
				pMesh->setVertices(3, *pMeshData->vertices);
			}
			if (pMeshData->faces)
			{
				pMesh->setIndices(3, pMeshData->faces->index);
			}

			this->addMesh(id, pMesh);
		}
	}

	int a = 1;
}

void Model3DS::draw()
{
	auto pData = _modelLoader->get3dsFile();
	if (pData == nullptr)
	{
		return;
	}

	Lib3dsNode*	node = pData->nodes;
	if (node == nullptr)
	{
		return;
	}

	glPushAttrib(GL_CURRENT_BIT);//保存现有颜色属实性

	getDisplayListForEveryMat(node);

	glPopAttrib();//恢复前一属性
}

uint32_t Model3DS::createTexture(const std::string& strFileName, const std::string& dir)
{
	std::string fullpath = dir + "/" + strFileName;

	Texture2D* pTexture = G_TEXTURE_CACHE->createTexture2D(fullpath);
	if (pTexture == nullptr)
	{
		return 0;
	}

	int id = pTexture->getTextureID();

	this->addTexture(strFileName, id);

	return id;
}

void Model3DS::getDisplayListForEveryMat(Lib3dsNode* node)
{
	if (node == nullptr)
	{
		return;
	}

	Lib3dsFile* pFile = (Lib3dsFile*)_modelLoader->get3dsFile();
	if (pFile == nullptr)
	{
		return;
	}

	GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat shininess[] = { 100.0 };
	//facevector point;
	int i = 0;

	if (node->childs)
	{
		for (auto p = node->childs; p != nullptr; p = p->next)
		{
			getDisplayListForEveryMat(p);
		}
	}

	if (node->type == LIB3DS_NODE_MESH_INSTANCE)
	{
		Lib3dsMesh* pMesh = nullptr;
		if (strcmp(node->name, "$$$DUMMY") == 0)
		{
			return;
		}

		auto pMeshData = lib3ds_file_mesh_for_node(pFile, node);
		if (pMeshData == nullptr)
		{
			return;
		}

		float m[4][4] = {0};
		lib3ds_matrix_copy(m, pMeshData->matrix);
		lib3ds_matrix_inv(m);

		glPushMatrix();
		glMultMatrixf((float*)m);

		{
			int id = lib3ds_file_mesh_by_name(pFile, pMeshData->name);

			auto pMesh = this->getMesh(id);
			if (pMesh == nullptr)
			{
				return;
			}

			glPushMatrix();
			glMultMatrixf((float*)pMeshData->matrix);

			pMesh->apply();

			Lib3dsFace* pFace = pMeshData->faces;
			auto pMat = this->getMatrial(pFace->material);
			if (pMat == nullptr)
			{
				return;
			}
			pMat->apply();

			glPopMatrix();
		}

		glPopMatrix();
	}
}
