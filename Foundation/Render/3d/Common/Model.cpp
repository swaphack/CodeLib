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

	const std::map<int, MeshDetail*>& meshes = _modelDetail->getMeshes();
	for (auto item0 : meshes)
	{
		//auto mat = item0.second->getMatrix();
		//auto inverse = mat.getInverse();

		//GLMatrix::multMatrix(mat);

		auto pMesh = item0.second;
		

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

void Model::setModelData(const ModelDetail* detail)
{
	SAFE_DELETE(_modelDetail);
	_modelDetail = (ModelDetail*)detail;
}

const ModelDetail* Model::getModelData()
{
	return _modelDetail;
}
