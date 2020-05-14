#include "Model.h"
#include "Graphic/import.h"
#include "Common/Shader/import.h"
#include "Common/Buffer/import.h"
#include "Common/View/import.h"
#include "Common/DrawNode/import.h"

using namespace render;


Model::Model()
{
}

Model::~Model()
{
}

bool render::Model::init()
{
	if (!DrawNode::init())
	{
		return false;
	}

	_notify->addListen(NodeNotifyType::MODEL, [this](){
		_loadModel = true;
		if (_material)
		{
			_material->updateMatTexture();
		}
		if (_mesh)
		{
			_mesh->initBufferData();
		}
	});
	return true;
}

void Model::drawing()
{
	if (!_loadModel)
	{
		return;
	}
	
	DrawNode::drawing();
}

void render::Model::setModelData(sys::ModelDetail* detail)
{
	if (detail== nullptr)
	{
		return;
	}
	_material->setModelDetail(detail);
	_mesh->setModelDetail(detail);
	this->notify(NodeNotifyType::MODEL);
}

void render::Model::drawSampleWithClientArray()
{
	if (_mesh == nullptr)
	{
		return;
	}
	const std::map<int, sys::MeshDetail*>& meshes = _mesh->getMeshes();
	for (auto item : meshes)
	{
		auto pMesh = item.second;

		const sys::MeshMemoryData& normals = pMesh->getNormals();
		if (normals.getLength() > 0)
		{
			GLClientArrays::enableClientState(ClientArrayType::NORMAL_ARRAY);
			GLClientArrays::setNormalPointer(DataType::FLOAT, 0, normals.getValue());

		}
		const sys::MeshMemoryData& vertices = pMesh->getVertices();
		if (vertices.getLength() > 0)
		{
			GLClientArrays::enableClientState(ClientArrayType::VERTEX_ARRAY);
			GLClientArrays::setVertexPointer(vertices.getTypeSize(), DataType::FLOAT, 0, vertices.getValue());

		}
		const sys::MeshMemoryData& texcoords = pMesh->getUVs();
		if (texcoords.getLength() > 0)
		{
			GLClientArrays::enableClientState(ClientArrayType::TEXTURE_COORD_ARRAY);
			GLClientArrays::setTexCoordPointer(texcoords.getTypeSize(), DataType::FLOAT, 0, texcoords.getValue());
		}

		const sys::MeshMemoryData& colors = pMesh->getColors();
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

		const sys::MeshMemoryData& indices = pMesh->getIndices();
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


