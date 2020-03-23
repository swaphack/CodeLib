#include "DCModel.h"

#include "Resource/Detail/ModelDetail.h"

using namespace render;

DCModel::DCModel()
{

}

DCModel::~DCModel()
{

}

void DCModel::drawDC()
{
	if (Detail == nullptr)
	{
		return;
	}
	SHOW_OPENGL_ERROR_MESSAGE();
	auto meshes = Detail->getMeshes();
	for (auto item0 : meshes)
	{
		auto pMesh = item0.second;

		auto normals = pMesh->getNormals();
		if (normals.size > 0)
		{
			glEnableClientState(GL_NORMAL_ARRAY);
			glNormalPointer(GL_FLOAT, 0, normals.value);
			SHOW_OPENGL_ERROR_MESSAGE();
		}
		auto vertices = pMesh->getVertices();
		if (vertices.size > 0)
		{
			glEnableClientState(GL_VERTEX_ARRAY);
			glVertexPointer(vertices.unit, GL_FLOAT, 0, vertices.value);
			SHOW_OPENGL_ERROR_MESSAGE();
		}
		auto texcoords = pMesh->getUVs();
		if (texcoords.size > 0)
		{
			glEnableClientState(GL_TEXTURE_COORD_ARRAY);
			glTexCoordPointer(texcoords.unit, GL_FLOAT, 0, texcoords.value);
			SHOW_OPENGL_ERROR_MESSAGE();
		}

		auto colors = pMesh->getColors();
		if (colors.size > 0)
		{
			glEnableClientState(GL_COLOR_ARRAY);
			glColorPointer(colors.unit, GL_FLOAT, 0, colors.value);
			SHOW_OPENGL_ERROR_MESSAGE();
		}

		auto faces = pMesh->getFaces();
		for (auto item1 : faces)
		{
			auto pFace = item1.second;
			auto nMatID = pFace->getMaterial();
			auto pMat = Detail->getMaterial(nMatID);
			if (pMat)
			{
				pMat->apply();

				auto nTextureID1 = Detail->getTexture(pMat->getTexture1());
				auto nTextureID2 = Detail->getTexture(pMat->getTexture2());
				if (nTextureID1 || nTextureID1)
				{
					glEnable(GL_TEXTURE_2D);
					if (nTextureID1) glBindTexture(GL_TEXTURE_2D, nTextureID1);
					if (nTextureID2) glBindTexture(GL_TEXTURE_2D, nTextureID2);
				}
			}

			auto indices = pFace->getIndices();
			if (indices.size > 0)
			{
				glDrawElements(GL_TRIANGLES, indices.size, GL_UNSIGNED_SHORT, indices.value);
				//SHOW_OPENGL_ERROR_MESSAGE();

				//glDrawElements(GL_TRIANGLE_STRIP, indices.size, GL_UNSIGNED_SHORT, indices.value);
			}
			glDisable(GL_TEXTURE_2D);
		}

		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_NORMAL_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		glDisableClientState(GL_COLOR_ARRAY);
	}
}


DCModel* DCModel::create(ModelDetail* detail, const sys::Color4B& color, uint8_t opacity, const BlendParam& blend)
{
	DCModel* pModel = sys::Instance<DCModel>::getInstance();
	pModel->initColor(color, opacity, blend);
	pModel->Detail = detail;
	return pModel;
}

