#include "Model.h"
#include "Resource/Detail/ModelDetail.h"
#include "Resource/Detail/MaterialDetail.h"
#include "Resource/Detail/MeshDetail.h"
#include "Resource/Detail/FaceDetail.h"
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

	auto meshes = _modelDetail->getMeshes();
	for (auto item0 : meshes)
	{
		auto pMesh = item0.second;

		auto normals = pMesh->getNormals();
		if (normals.size > 0)
		{
			GLState::enableClientState(ClientArrayType::NORMAL_ARRAY);
			GLVertex::setNormalPointer(DataType::FLOAT, 0, normals.value);

		}
		auto vertices = pMesh->getVertices();
		if (vertices.size > 0)
		{
			GLState::enableClientState(ClientArrayType::VERTEX_ARRAY);
			GLVertex::setVertexPointer(vertices.unit, DataType::FLOAT, 0, vertices.value);

		}
		auto texcoords = pMesh->getUVs();
		if (texcoords.size > 0)
		{
			GLState::enableClientState(ClientArrayType::TEXTURE_COORD_ARRAY);
			GLVertex::setTexCoordPointer(texcoords.unit, DataType::FLOAT, 0, texcoords.value);
		}

		auto colors = pMesh->getColors();
		if (colors.size > 0)
		{
			GLState::enableClientState(ClientArrayType::COLOR_ARRAY);
			GLVertex::setColorPointer(colors.unit, DataType::FLOAT, 0, colors.value);

		}

		auto faces = pMesh->getFaces();
		for (auto item1 : faces)
		{
			//GLMatrix::multMatrix(item1.second->getMatrix().transpose());

			auto pFace = item1.second;
			auto nMatID = pFace->getMaterial();
			auto pMat = _modelDetail->getMaterial(nMatID);
			if (pMat)
			{
				pMat->apply();

				auto nTextureID1 = _modelDetail->getTexture(pMat->getTexture1());
				auto nTextureID2 = _modelDetail->getTexture(pMat->getTexture2());
				if (nTextureID1 || nTextureID1)
				{
					GLState::enable(EnableModel::TEXTURE_2D);
					if (nTextureID1) GLTexture::bindTexture2D(nTextureID1);
					//if (nTextureID2) GLTexture::bindTexture2D(nTextureID2);
				}
			}

			auto indices = pFace->getIndices();
			if (indices.size > 0)
			{
				GLVertex::drawElements(ShapeMode::TRIANGLES, indices.size, IndexDataType::UNSIGNED_SHORT, indices.value);
			}
			GLState::disable(EnableModel::TEXTURE_2D);
		}

		GLState::disableClientState(ClientArrayType::VERTEX_ARRAY);
		GLState::disableClientState(ClientArrayType::NORMAL_ARRAY);
		GLState::disableClientState(ClientArrayType::TEXTURE_COORD_ARRAY);
		GLState::disableClientState(ClientArrayType::COLOR_ARRAY);
	}
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
