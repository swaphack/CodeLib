#include "Model.h"
#include "Resource/Detail/ModelDetail.h"
#include "Resource/Detail/MaterialDetail.h"
#include "Resource/Detail/MeshDetail.h"
#include "Graphic/import.h"


using namespace render;


Model::Model()
{
}

Model::~Model()
{
	SAFE_DELETE(_modelDetail);
}

void Model::drawSample()
{
	if (_modelDetail == nullptr)
	{
		return;
	}

	//PRINT("=============begin=============\n");

	auto meshes = _modelDetail->getMeshes();
	for (auto item0 : meshes)
	{
		//auto mat = item0.second->getMatrix();
		//auto inverse = mat.getInverse();

		//GLMatrix::multMatrix(mat);

		auto pMesh = item0.second;
		

		auto normals = pMesh->getNormals();
		if (normals.size > 0)
		{
			GLClientArrays::enableClientState(ClientArrayType::NORMAL_ARRAY);
			GLClientArrays::setNormalPointer(DataType::FLOAT, 0, normals.value);

		}
		auto vertices = pMesh->getVertices();
		if (vertices.size > 0)
		{
			GLClientArrays::enableClientState(ClientArrayType::VERTEX_ARRAY);
			GLClientArrays::setVertexPointer(vertices.unit, DataType::FLOAT, 0, vertices.value);

		}
		auto texcoords = pMesh->getUVs();
		if (texcoords.size > 0)
		{
			GLClientArrays::enableClientState(ClientArrayType::TEXTURE_COORD_ARRAY);
			GLClientArrays::setTexCoordPointer(texcoords.unit, DataType::FLOAT, 0, texcoords.value);
		}

		auto colors = pMesh->getColors();
		if (colors.size > 0)
		{
			GLClientArrays::enableClientState(ClientArrayType::COLOR_ARRAY);
			GLClientArrays::setColorPointer(colors.unit, DataType::FLOAT, 0, colors.value);

		}

		auto nMatID = pMesh->getMaterial();
		auto pMat = _modelDetail->getMaterial(nMatID);
		if (pMat)
		{
			pMat->apply();

			auto nTextureID1 = _modelDetail->getTexture(pMat->getAmbientTextureMap());
			auto nTextureID2 = _modelDetail->getTexture(pMat->getDiffuseTextureMap());
			if (nTextureID1 || nTextureID2)
			{
				GLState::enable(EnableModel::TEXTURE_2D);
				if (nTextureID1) GLTexture::bindTexture2D(nTextureID1);
				else if (nTextureID2) GLTexture::bindTexture2D(nTextureID2);
			}
		}

		auto indices = pMesh->getIndices();
		if (indices.size > 0)
		{
			GLClientArrays::drawElements(ShapeMode::TRIANGLES, indices.size, IndexDataType::UNSIGNED_INT, indices.value);
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

void Model::setModelData(const ModelDetail* detail)
{
	SAFE_DELETE(_modelDetail);
	_modelDetail = (ModelDetail*)detail;
}

const ModelDetail* Model::getModelData()
{
	return _modelDetail;
}
