#include "Model.h"
#include "Resource/Detail/ModelDetail.h"
#include "Resource/Detail/MaterialDetail.h"
#include "Resource/Detail/MeshDetail.h"
#include "Graphic/import.h"
#include "Common/Shader/import.h"
#include "Common/Buffer/import.h"
#include "Common/View/import.h"
#include "Common/Node/import.h"

using namespace render;


Model::Model()
{
	_material = new Material;
	_mesh = new Mesh;
}

Model::~Model()
{
	SAFE_DELETE(_material);
	SAFE_DELETE(_mesh);
}

bool render::Model::init()
{
	if (!ColorNode::init())
	{
		return false;
	}

	_notify->addListen(ENP_MODEL_FRAME, [this](){
		_loadModel = true;
		if (_material)
		{
			_material->updateMatTexture();
		}
		if (_mesh)
		{
			_mesh->updateBufferData();
		}
	});
	return true;
}

void Model::drawSample()
{
	if (!_loadModel)
	{
		return;
	}
#if USE_BUFFER_OBJECT
	this->drawSampleWithBufferObject();
#else
	this->drawSampleWithClientArray();
#endif
}

void render::Model::setModelData(ModelDetail* detail)
{
	if (detail== nullptr)
	{
		return;
	}
	_material->setModelDetail(detail);
	_mesh->setModelDetail(detail);
	this->notify(ENP_MODEL_FRAME);
}

void render::Model::drawSampleWithClientArray()
{
	if (_mesh == nullptr)
	{
		return;
	}
	const std::map<int, MeshDetail*>& meshes = _mesh->getMeshes();
	for (auto item : meshes)
	{
		auto pMesh = item.second;

		const MeshMemoryData& normals = pMesh->getNormals();
		if (normals.getLength() > 0)
		{
			GLClientArrays::enableClientState(ClientArrayType::NORMAL_ARRAY);
			GLClientArrays::setNormalPointer(DataType::FLOAT, 0, normals.getValue());

		}
		const MeshMemoryData& vertices = pMesh->getVertices();
		if (vertices.getLength() > 0)
		{
			GLClientArrays::enableClientState(ClientArrayType::VERTEX_ARRAY);
			GLClientArrays::setVertexPointer(vertices.getTypeSize(), DataType::FLOAT, 0, vertices.getValue());

		}
		const MeshMemoryData& texcoords = pMesh->getUVs();
		if (texcoords.getLength() > 0)
		{
			GLClientArrays::enableClientState(ClientArrayType::TEXTURE_COORD_ARRAY);
			GLClientArrays::setTexCoordPointer(texcoords.getTypeSize(), DataType::FLOAT, 0, texcoords.getValue());
		}

		const MeshMemoryData& colors = pMesh->getColors();
		if (colors.getLength() > 0)
		{
			GLClientArrays::enableClientState(ClientArrayType::COLOR_ARRAY);
			GLClientArrays::setColorPointer(colors.getTypeSize(), DataType::FLOAT, 0, colors.getValue());
		}

		auto nMatID = pMesh->getMaterial();
		if (_material)
		{
			_material->applyMat(nMatID);
		}

		const MeshMemoryData& indices = pMesh->getIndices();
		if (indices.getLength() > 0)
		{
			GLClientArrays::drawElements(DrawMode::TRIANGLES, indices.getLength(), IndexDataType::UNSIGNED_INT, indices.getValue());
		}
		GLState::disable(EnableModel::TEXTURE_2D);

		GLClientArrays::disableClientState(ClientArrayType::VERTEX_ARRAY);
		GLClientArrays::disableClientState(ClientArrayType::NORMAL_ARRAY);
		GLClientArrays::disableClientState(ClientArrayType::TEXTURE_COORD_ARRAY);
		GLClientArrays::disableClientState(ClientArrayType::COLOR_ARRAY);

		//GLMatrix::multMatrix(inverse);
	}

	//PRINT("=============end=============\n");
}

void render::Model::drawSampleWithBufferObject()
{
	if (_mesh == nullptr || _material == nullptr)
	{
		return;
	}
	_mesh->draw(this, _material);
}

Material* render::Model::getMaterial()
{
	return _material;
}

Mesh* render::Model::getMesh()
{
	return _mesh;
}
