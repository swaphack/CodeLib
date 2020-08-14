#include "UniformShaderApply.h"

#include "Common/Shader/import.h"
#include "Common/Node/import.h"
#include "Graphic/import.h"
#include "Common/VAO/import.h"
#include "Common/Buffer/import.h"
#include "Common/View/Camera.h"
#include "Common/Mesh/import.h"
#include "Common/Texture/import.h"
#include "3d/Environment/import.h"
#include "Common/DrawNode/DrawTextureCache.h"
#include "system.h"
#include "Common/Material/import.h"
#include "2d/Primitive/PrimitiveNode.h"

render::UniformShaderApply::UniformShaderApply()
{

}

render::UniformShaderApply::~UniformShaderApply()
{

}

void render::UniformShaderApply::startUpdateShaderUniformValue(Node* node, ShaderProgram* program, Mesh* pMesh, Material* pMaterial, DrawTextureCache* textureCache)
{
	if (node == nullptr || program == nullptr || pMesh == nullptr || pMaterial == nullptr || textureCache == nullptr)
	{
		return;
	}

	updateEnvUniformVallue(node, program);
	updateMVPMatrixUniformValue(node, program);

	applyLightShader(node, program);

	updateMaterialUniformValue(program, pMaterial, textureCache);
	updateTexturesUnifromValue(program, pMaterial, textureCache);
}

void render::UniformShaderApply::startUpdateShaderVertexValue(ShaderProgram* program, Mesh* pMesh)
{
	if (pMesh == nullptr)
	{
		return;
	}

	if (program == nullptr)
	{
		return;
	}

	auto detail = pMesh->getMeshDetail();
	auto vao = pMesh->getVertexArrayObject();
	GLDebug::showError();
	vao->bindVertexArray();
	GLDebug::showError();
	vao->bindBuffer();
	GLDebug::showError();
	const sys::MeshMemoryData& vertices = detail->getVertices();
	const sys::MeshMemoryData& colors = detail->getColors();
	const sys::MeshMemoryData& texcoords = detail->getUVs();
	const sys::MeshMemoryData& normals = detail->getNormals();
	const sys::MeshMemoryData& tangents = detail->getTangents();
	const sys::MeshMemoryData& bitangents = detail->getBitangents();

	uint32_t nVerticeSize = vertices.getSize();
	uint32_t nColorSize = colors.getSize();
	uint32_t nUVSize = texcoords.getSize();
	uint32_t nNormalSize = normals.getSize();
	uint32_t nTangentSize = tangents.getSize();
	uint32_t nBitangentSize = bitangents.getSize();

	int nOffset = 0;
	for (auto item : _vertexAttribIndices)
	{
		if (item.first == VertexDataType::POSITION)
		{
			if (nVerticeSize == 0)
			{
				return;
			}
			auto pAttrib = program->getAttrib(item.second);
			if (pAttrib)
			{
				VertexAttribPointer* pointer = vao->getVertexAttrib<VertexAttribPointer>(pAttrib->getAttribID());
				pointer->enableVertexArrayAttrib();
				pointer->setVertexAttribPointer(vertices.getUnitSize(), VertexAttribPointerType::FLOAT, nOffset);
			}

			nOffset += nVerticeSize;
		}
		else if (item.first == VertexDataType::COLOR)
		{
			if (nColorSize == 0)
			{
				continue;
			}
			auto pAttrib = program->getAttrib(item.second);
			if (pAttrib)
			{
				VertexAttribPointer* pointer = vao->getVertexAttrib<VertexAttribPointer>(pAttrib->getAttribID());
				pointer->enableVertexArrayAttrib();
				pointer->setVertexAttribPointer(colors.getUnitSize(), VertexAttribPointerType::FLOAT, nOffset);
			}
			nOffset += nColorSize;
		}
		else if (item.first == VertexDataType::UV)
		{
			if (nUVSize == 0)
			{
				continue;
			}
			auto pAttrib = program->getAttrib(item.second);
			if (pAttrib)
			{
				VertexAttribPointer* pointer = vao->getVertexAttrib<VertexAttribPointer>(pAttrib->getAttribID());
				pointer->enableVertexArrayAttrib();
				pointer->setVertexAttribPointer(texcoords.getUnitSize(), VertexAttribPointerType::FLOAT, nOffset);
			}
			nOffset += nUVSize;
		}
		else if (item.first == VertexDataType::NORMAL)
		{
			if (nNormalSize == 0)
			{
				continue;
			}
			auto pAttrib = program->getAttrib(item.second);
			if (pAttrib)
			{
				VertexAttribPointer* pointer = vao->getVertexAttrib<VertexAttribPointer>(pAttrib->getAttribID());
				pointer->enableVertexArrayAttrib();
				pointer->setVertexAttribPointer(normals.getUnitSize(), VertexAttribPointerType::FLOAT, nOffset);
			}
			nOffset += nNormalSize;
		}
		else if (item.first == VertexDataType::TANGENT)
		{
			if (nTangentSize == 0)
			{
				continue;
			}
			auto pAttrib = program->getAttrib(item.second);
			if (pAttrib)
			{
				VertexAttribPointer* pointer = vao->getVertexAttrib<VertexAttribPointer>(pAttrib->getAttribID());
				pointer->enableVertexArrayAttrib();
				pointer->setVertexAttribPointer(tangents.getUnitSize(), VertexAttribPointerType::FLOAT, nOffset);
			}
			nOffset += nTangentSize;
		}
		else if (item.first == VertexDataType::BITANGENT)
		{
			if (nBitangentSize == 0)
			{
				continue;
			}
			auto pAttrib = program->getAttrib(item.second);
			if (pAttrib)
			{
				VertexAttribPointer* pointer = vao->getVertexAttrib<VertexAttribPointer>(pAttrib->getAttribID());
				pointer->enableVertexArrayAttrib();
				pointer->setVertexAttribPointer(bitangents.getUnitSize(), VertexAttribPointerType::FLOAT, nOffset);
			}
			nOffset += nBitangentSize;
		}
		GLDebug::showError();
	}

	GLDebug::showError();
}

void render::UniformShaderApply::endUpdateShaderUniformValue(ShaderProgram* program, Material* pMaterial, DrawTextureCache* textureCache)
{
	releaseMaterialUniformValue(program, pMaterial, textureCache);
	releaseTextureUniformValue(program, pMaterial, textureCache);
}

void render::UniformShaderApply::endUpdateShaderVertexValue(ShaderProgram* program, Mesh* pMesh)
{
	if (pMesh == nullptr)
	{
		return;
	}

	if (program == nullptr)
	{
		return;
	}

	auto vao = pMesh->getVertexArrayObject();
	for (auto item : _vertexAttribIndices)
	{
		auto pAttrib = program->getAttrib(item.second);
		if (!pAttrib) continue;
		VertexAttribPointer* pointer = vao->getVertexAttrib<VertexAttribPointer>(pAttrib->getAttribID());
		if (pointer)
		{
			pointer->disableVertexArrayAttrib();
		}
	}

	vao->unbindVertexArray();
	vao->unbindBuffer();
}

void render::UniformShaderApply::updateEnvUniformVallue(Node* node, ShaderProgram* program)
{
	if (program == nullptr || node == nullptr)
	{
		return;
	}
	math::Matrix4x4 viewMat = Camera::getMainCamera()->getViewMatrix();
	math::Vector3 viewPos = viewMat.getPosition();
	for (auto item : _mapEnvUniform)
	{
		auto pUniform = program->getUniform(item.second);
		if (!pUniform)
		{
			continue;
		}
		if (item.first == EnvUniformType::VIEW_POSITION)
		{
			pUniform->setValue3(1, viewPos.getValue());
		}
		else if (item.first == EnvUniformType::LIGHT_COUNT)
		{
			pUniform->setValue((int)G_ENVIRONMENT->getAllLights().size());
		}	
		else if (item.first == EnvUniformType::GAMMA)
		{
			pUniform->setValue(G_ENVIRONMENT->getGamma());
		}
		else if (item.first == EnvUniformType::POINT_SIZE)
		{
			auto pPrimitiveNode = node->as<PrimitiveNode>();
			if (pPrimitiveNode)
			{
				pUniform->setValue(pPrimitiveNode->getPointSize());
			}
		}
	}
}

void render::UniformShaderApply::updateMVPMatrixUniformValue(Node* node, ShaderProgram* program)
{
	if (program == nullptr || node == nullptr)
	{
		return;
	}

	math::Matrix4x4 projMat = Camera::getMainCamera()->getProjectMatrix();
	math::Matrix4x4 viewMat = Camera::getMainCamera()->getViewMatrix();
	math::Matrix4x4 modelMat = getWorldMatrix(node);

	math::Matrix3x3 normalMat = modelMat.getInverse().getTranspose();

	math::Vector3 viewPos = viewMat.getPosition();
	//viewPos.setZ(-viewPos.getZ());

	for (auto item : _mapMatrixUniform)
	{
		auto pUniform = program->getUniform(item.second);
		if (!pUniform)
		{
			continue;
		}
		if (item.first == MatrixUniformType::PROJECT_MATRIX)
		{
			pUniform->setMatrix4(projMat);
		}
		else if (item.first == MatrixUniformType::VIEW_MATRIX)
		{
			pUniform->setMatrix4(viewMat);
		}
		else if (item.first == MatrixUniformType::MODEL_MATRIX)
		{
			pUniform->setMatrix4(modelMat);
		}
		else if (item.first == MatrixUniformType::NORMAL_MATRIX)
		{
			pUniform->setMatrix3(normalMat);
		}

		GLDebug::showError();
	}
}

void render::UniformShaderApply::updateMaterialUniformValue(ShaderProgram* program, Material* pMaterial, DrawTextureCache* textureCache)
{
	if (program == nullptr || pMaterial == nullptr)
	{
		return;
	}
	const auto pDetail = pMaterial->getMaterialDetail();
	if (pDetail == nullptr)
	{
		return;
	}
	GLDebug::showError();
	for (auto item : _mapMaterialUniform)
	{
		auto pUniform = program->getUniform(item.second);
		if (!pUniform)
		{
			continue;
		}
		if (item.first == MaterialUniformType::MATERIAL_EMISSION)
		{
			pUniform->setValue4(1, pDetail->getEmission());
		}
		else if (item.first == MaterialUniformType::MATERIAL_COLOR_AMBIENT)
		{
			pUniform->setValue4(1, pDetail->getAmbient());
		}
		else if (item.first == MaterialUniformType::MATERIAL_COLOR_DIFFUSE)
		{
			pUniform->setValue4(1, pDetail->getDiffuse());
		}
		else if (item.first == MaterialUniformType::MATERIAL_COLOR_SPECULAR)
		{
			pUniform->setValue4(1, pDetail->getSpecular());
		}
		else if (item.first == MaterialUniformType::MATERIAL_TEXTURE)
		{
			auto pTexture = textureCache->getTexture(pDetail->getAmbientTextureMap());
			if (pTexture == nullptr)
			{
				pTexture = Texture2D::getEmptyTexture();
			}
			if (pTexture)
			{
				pTexture->activeTexture(ActiveTextureName::TEXTURE0);
				pTexture->bindTexture();
				pTexture->enableTextureWithSampler(0);
				pUniform->setValue(0);
			}
			GLDebug::showError();
		}
		else if (item.first == MaterialUniformType::MATERIAL_TEXTURE_DIFFUSE)
		{
			auto pTexture = textureCache->getTexture(pDetail->getDiffuseTextureMap());
			if (pTexture == nullptr)
			{
				pTexture = Texture2D::getEmptyTexture();
			}
			if (pTexture)
			{
				pTexture->activeTexture(ActiveTextureName::TEXTURE1);
				pTexture->bindTexture();
				pTexture->enableTextureWithSampler(1);
				pUniform->setValue(1);
			}
			GLDebug::showError();
		}
		else if (item.first == MaterialUniformType::MATERIAL_TEXTURE_SPECULAR)
		{
			auto pTexture = textureCache->getTexture(pDetail->getSpecularTextureMap());
			if (pTexture == nullptr)
			{
				pTexture = Texture2D::getEmptyTexture();
			}
			if (pTexture)
			{
				pTexture->activeTexture(ActiveTextureName::TEXTURE2);
				pTexture->bindTexture();
				pTexture->enableTextureWithSampler(2);
				pUniform->setValue(2);
			}
			GLDebug::showError();
		}
		else if (item.first == MaterialUniformType::MATERIAL_TEXTURE_ALPHA)
		{
			auto pTexture = textureCache->getTexture(pDetail->getAlphaTextureMap());
			if (pTexture == nullptr)
			{
				pTexture = Texture2D::getEmptyTexture();
			}
			if (pTexture)
			{
				pTexture->activeTexture(ActiveTextureName::TEXTURE3);
				pTexture->bindTexture();
				pTexture->enableTextureWithSampler(3);
				pUniform->setValue(3);
			}
			GLDebug::showError();
		}
		else if (item.first == MaterialUniformType::MATERIAL_TEXTURE_BUMP)
		{
			auto pTexture = textureCache->getTexture(pDetail->getBumpTextureMap());
			if (pTexture == nullptr)
			{
				pTexture = Texture2D::getEmptyTexture();
			}
			if (pTexture)
			{
				pTexture->activeTexture(ActiveTextureName::TEXTURE4);
				pTexture->bindTexture();
				pTexture->enableTextureWithSampler(4);
				pUniform->setValue(4);
			}
			GLDebug::showError();
		}
		else if (item.first == MaterialUniformType::MATERIAL_TEXTURE_NORMAL)
		{
			auto pTexture = textureCache->getTexture(pDetail->getNormalTextureMap());
			if (pTexture == nullptr)
			{
				pTexture = Texture2D::getEmptyTexture();
			}
			if (pTexture)
			{
				pTexture->activeTexture(ActiveTextureName::TEXTURE5);
				pTexture->bindTexture();
				pTexture->enableTextureWithSampler(5);
				pUniform->setValue(5);
			}
			GLDebug::showError();
		}
		else if (item.first == MaterialUniformType::MATERIAL_TEXTURE_SHADOW)
		{
			auto pTexture = textureCache->getTexture(pDetail->getShadowTextureMap());
			if (pTexture == nullptr)
			{
				pTexture = Texture2D::getEmptyTexture();
			}
			if (pTexture)
			{
				pTexture->activeTexture(ActiveTextureName::TEXTURE6);
				pTexture->bindTexture();
				pTexture->enableTextureWithSampler(6);
				pUniform->setValue(6);
			}
			GLDebug::showError();
		}
		else if (item.first == MaterialUniformType::MATERIAL_SHININESS)
		{
			pUniform->setValue(pDetail->getSpecularShiness());
		}
		else if (item.first == MaterialUniformType::MATERIAL_STRENGTH)
		{
			pUniform->setValue(pDetail->getSpecularStrength());
		}
	}
}

void render::UniformShaderApply::updateTexturesUnifromValue(ShaderProgram* program, Material* pMaterial, DrawTextureCache* textureCache)
{
	if (program == nullptr)
	{
		return;
	}
	const auto pDetail = pMaterial->getMaterialDetail();
	if (pDetail == nullptr)
	{
		return;
	}
	for (auto item : _mapTextureUniform)
	{
		auto pUniform = program->getUniform(item.second);
		if (!pUniform)
		{
			if (item.first == TextureUniformType::TEXTURE0)
			{
				return;
			}
			else
			{
				continue;
			}
		}
		if (item.first == TextureUniformType::TEXTURE0)
		{
			auto pTexture = textureCache->getTexture(pDetail->getAmbientTextureMap());
			if (pTexture == nullptr)
			{
				pTexture = Texture2D::getEmptyTexture();
			}
			if (pTexture)
			{
				pTexture->activeTexture(ActiveTextureName::TEXTURE0);
				pTexture->bindTexture();
				pTexture->enableTextureWithSampler(0);
				pUniform->setValue(0);
			}
		}
		else if (item.first == TextureUniformType::TEXTURE1)
		{
			auto pTexture = textureCache->getTexture(pDetail->getDiffuseTextureMap());
			if (pTexture == nullptr)
			{
				pTexture = Texture2D::getEmptyTexture();
			}
			if (pTexture)
			{
				pTexture->activeTexture(ActiveTextureName::TEXTURE1);
				pTexture->bindTexture();
				pTexture->enableTextureWithSampler(1);
				pUniform->setValue(1);
			}

			GLDebug::showError();
		}
		else if (item.first == TextureUniformType::TEXTURE2)
		{
			auto pTexture = textureCache->getTexture(pDetail->getSpecularTextureMap());
			if (pTexture == nullptr)
			{
				pTexture = Texture2D::getEmptyTexture();
			}
			if (pTexture)
			{
				pTexture->activeTexture(ActiveTextureName::TEXTURE2);
				pTexture->bindTexture();
				pTexture->enableTextureWithSampler(2);
				pUniform->setValue(2);
			}
		}
	}
}

void render::UniformShaderApply::releaseMaterialUniformValue(ShaderProgram* program, Material* pMaterial, DrawTextureCache* textureCache)
{
	if (program == nullptr || pMaterial == nullptr)
	{
		return;
	}

	const auto pDetail = pMaterial->getMaterialDetail();
	if (pDetail == nullptr)
	{
		return;
	}
	for (auto item : _mapMaterialUniform)
	{
		auto pUniform = program->getUniform(item.second);
		if (!pUniform)
		{
			continue;
		}
		if (item.first == MaterialUniformType::MATERIAL_TEXTURE)
		{
			auto pTexture = textureCache->getTexture(pDetail->getAmbientTextureMap());
			if (pTexture)
			{
				pTexture->unbindTexture();
				GLState::disable((EnableMode)pTexture->getTextureTarget());
			}

			GLDebug::showError();
		}
		else if (item.first == MaterialUniformType::MATERIAL_TEXTURE_DIFFUSE)
		{
			auto pTexture = textureCache->getTexture(pDetail->getDiffuseTextureMap());
			if (pTexture)
			{
				pTexture->unbindTexture();
				GLState::disable((EnableMode)pTexture->getTextureTarget());
			}

			GLDebug::showError();
		}
		else if (item.first == MaterialUniformType::MATERIAL_TEXTURE_SPECULAR)
		{
			auto pTexture = textureCache->getTexture(pDetail->getSpecularTextureMap());
			if (pTexture)
			{
				pTexture->unbindTexture();
				GLState::disable((EnableMode)pTexture->getTextureTarget());
			}
			GLDebug::showError();
		}
		else if (item.first == MaterialUniformType::MATERIAL_TEXTURE_ALPHA)
		{
			auto pTexture = textureCache->getTexture(pDetail->getAlphaTextureMap());
			if (pTexture)
			{
				pTexture->unbindTexture();
				GLState::disable((EnableMode)pTexture->getTextureTarget());
			}
			GLDebug::showError();
		}
		else if (item.first == MaterialUniformType::MATERIAL_TEXTURE_BUMP)
		{
			auto pTexture = textureCache->getTexture(pDetail->getBumpTextureMap());
			if (pTexture)
			{
				pTexture->unbindTexture();
				GLState::disable((EnableMode)pTexture->getTextureTarget());
			}
			GLDebug::showError();
		}
		else if (item.first == MaterialUniformType::MATERIAL_TEXTURE_NORMAL)
		{
			auto pTexture = textureCache->getTexture(pDetail->getNormalTextureMap());
			if (pTexture)
			{
				pTexture->unbindTexture();
				GLState::disable((EnableMode)pTexture->getTextureTarget());
			}
			GLDebug::showError();
		}
		else if (item.first == MaterialUniformType::MATERIAL_TEXTURE_SHADOW)
		{
			auto pTexture = textureCache->getTexture(pDetail->getShadowTextureMap());
			if (pTexture)
			{
				pTexture->unbindTexture();
				GLState::disable((EnableMode)pTexture->getTextureTarget());
			}
			GLDebug::showError();
		}

		GLDebug::showError();
	}
	GLDebug::showError();
}

void render::UniformShaderApply::releaseTextureUniformValue(ShaderProgram* program, Material* pMaterial, DrawTextureCache* textureCache)
{
	if (program == nullptr || pMaterial == nullptr)
	{
		return;
	}

	const auto pDetail = pMaterial->getMaterialDetail();
	if (pDetail == nullptr)
	{
		return;
	}
	for (auto item : _mapTextureUniform)
	{
		auto pUniform = program->getUniform(item.second);
		if (!pUniform)
		{
			continue;
		}
		if (item.first == TextureUniformType::TEXTURE0)
		{
			auto pTexture = textureCache->getTexture(pDetail->getAmbientTextureMap());
			if (pTexture)
			{
				pTexture->unbindTexture();
				GLState::disable((EnableMode)pTexture->getTextureTarget());
			}

			GLDebug::showError();
		}
		else if (item.first == TextureUniformType::TEXTURE1)
		{
			auto pTexture = textureCache->getTexture(pDetail->getDiffuseTextureMap());
			if (pTexture)
			{
				pTexture->unbindTexture();
				GLState::disable((EnableMode)pTexture->getTextureTarget());
			}

			GLDebug::showError();
		}
		else if (item.first == TextureUniformType::TEXTURE2)
		{
			auto pTexture = textureCache->getTexture(pDetail->getSpecularTextureMap());
			if (pTexture)
			{
				pTexture->unbindTexture();
				GLState::disable((EnableMode)pTexture->getTextureTarget());
			}
			GLDebug::showError();
		}
	}
}

void render::UniformShaderApply::addVertexData(VertexDataType vat, const std::string& name)
{
	_vertexAttribIndices[vat] = name;
}

std::string render::UniformShaderApply::getVertexName(VertexDataType vat) const
{
	auto it = _vertexAttribIndices.find(vat);
	if (it == _vertexAttribIndices.end())
	{
		return "";
	}

	return it->second;
}

void render::UniformShaderApply::beginApply(Material* pMaterial, DrawTextureCache* textureCache)
{
	if (pMaterial == nullptr || textureCache == nullptr)
	{
		return;
	}
	pMaterial->applyMaterial();

	const auto pDetail = pMaterial->getMaterialDetail();
	if (pDetail == nullptr)
	{
		return;
	}
	auto pTexture = textureCache->getTexture(pDetail->getAmbientTextureMap());
	if (pTexture)
	{
		pTexture->enableTexture(0);
	}
#if 0
	nTextureID = this->getTexture(pDetail->getDiffuseTextureMap());
	GLTexture::activeTexture(ActiveTextureName::TEXTURE1);
	GLTexture::bindTexture2D(nTextureID);

	nTextureID = this->getTexture(pDetail->getSpecularTextureMap());
	GLTexture::activeTexture(ActiveTextureName::TEXTURE2);
	GLTexture::bindTexture2D(nTextureID);
#endif // 0
}

void render::UniformShaderApply::endApply(Material* pMaterial, DrawTextureCache* textureCache)
{
	if (pMaterial == nullptr || textureCache == nullptr)
	{
		return;
	}
	const auto pDetail = pMaterial->getMaterialDetail();
	if (pDetail == nullptr)
	{
		return;
	}
	auto pTexture = textureCache->getTexture(pDetail->getAmbientTextureMap());
	if (pTexture)
	{
		pTexture->unbindTexture();
	}
#if 0
	nTextureID = this->getTexture(pDetail->getDiffuseTextureMap());
	GLTexture::activeTexture(ActiveTextureName::TEXTURE1);
	GLTexture::bindTexture2D(nTextureID);

	nTextureID = this->getTexture(pDetail->getSpecularTextureMap());
	GLTexture::activeTexture(ActiveTextureName::TEXTURE2);
	GLTexture::bindTexture2D(nTextureID);
#endif // 0
}

void render::UniformShaderApply::beginApplyWithShader(Node* node, ShaderProgram* program, Mesh* pMesh, Material* pMaterial, DrawTextureCache* textureCache)
{
	if (node == nullptr || program == nullptr || pMesh == nullptr || pMaterial == nullptr)
	{
		return;
	}

	program->use();
	GLDebug::showError();
	this->startUpdateShaderUniformValue(node, program, pMesh, pMaterial, textureCache);
	GLDebug::showError();
	this->startUpdateShaderVertexValue(program, pMesh);
	GLDebug::showError();
	pMaterial->runProgramFunc();
	GLDebug::showError();
}

void render::UniformShaderApply::endApplyWithShader(ShaderProgram* program, Mesh* pMesh, Material* pMaterial, DrawTextureCache* textureCache)
{
	if (program == nullptr || pMesh == nullptr || pMaterial == nullptr || textureCache == nullptr)
	{
		return;
	}

	this->endUpdateShaderUniformValue(program, pMaterial, textureCache);
	this->endUpdateShaderVertexValue(program, pMesh);

	if (program)
	{
		program->unuse();
	}
}

void render::UniformShaderApply::applyLightShader(Node* node, ShaderProgram* program)
{
	LightProtocol* pLight = node->as<LightProtocol>();
	if (pLight == nullptr)
	{
		return;
	}

	if (pLight->isSupportedLight())
	{
		if (pLight->isSupportedMultiLight())
		{
			updateAllLightsUniformValue(node, program);
		}
		else
		{
			updateNearestLightUniformValue(node, program);
		}
	}
}

void render::UniformShaderApply::updateNearestLightUniformValue(Node* node, ShaderProgram* program)
{
	if (node == nullptr || program == nullptr)
	{
		return;
	}
	if (!G_ENVIRONMENT->hasLight())
	{
		return;
	}

	math::Vector3 nodePos = getWorldMatrix(node).getPosition();
	float fPos = -1;
	Light* pLight = nullptr;
	const auto& lights = G_ENVIRONMENT->getAllLights();
	for (auto& item : lights)
	{
		auto pTempLight = item.second;
		if (pTempLight)
		{
			float fDistance = math::Vector3::distance(pTempLight->getWorldMatrix().getPosition(), nodePos);
			if (fPos == -1 || fDistance < fPos)
			{
				fPos = fDistance;
				pLight = pTempLight;
			}
		}
	}
	if (!pLight)
	{
		return;
	}
	const math::Matrix4x4& viewMat = Camera::getMainCamera()->getViewMatrix();

	math::Vector3 viewPos = viewMat.getPosition();
	math::Vector3 lightPos = pLight->getWorldMatrix().getPosition();
	//viewPos.setZ(-viewPos.getZ());
	//viewPos *= -1.0f;
	//lightPos *= -1.0f;

	math::Vector3 viewDirection = viewPos - nodePos;
	math::Vector3 lightDirection = lightPos - nodePos;
	math::Vector3 halfVector = lightDirection + viewDirection;
	halfVector.normalize();

	bool bSupportShadow = false;
	if (node->is<LightProtocol>())
	{
		bSupportShadow = node->as<LightProtocol>()->isCastShadow();
	}

	for (auto item : _mapSingleLightUniform)
	{
		auto pUniform = program->getUniform(item.second);
		if (!pUniform)
		{
			continue;
		}

		if (item.first == SingleLightUniformType::LIGHT_ENABLED)
		{
			pUniform->setValue(1);
		}
		else if (item.first == SingleLightUniformType::LIGHT_LOCAL)
		{
			if (pLight->is<PointLight>() || pLight->is<SpotLight>())
			{
				pUniform->setValue(1);
			}
			else
			{
				pUniform->setValue(0);
			}
		}
		else if (item.first == SingleLightUniformType::LIGHT_SPOT)
		{
			pUniform->setValue(pLight->is<SpotLight>() ? 1 : 0);
		}
		else if (item.first == SingleLightUniformType::LIGHT_POSITION)
		{
			pUniform->setValue3(1, lightPos.getValue());
		}
		else if (item.first == SingleLightUniformType::LIGHT_DIRECTION)
		{
			auto pPointLight = pLight->as<PointLight>();
			if (pPointLight)
			{
				pUniform->setValue3(1, lightDirection.getValue());
			}
			else
			{
				auto pSpotLight = pLight->as<SpotLight>();
				if (pSpotLight)
				{
					pUniform->setValue3(1, pSpotLight->getDirection());
				}
				auto pDirLight = pLight->as<DirectionLight>();
				if (pDirLight)
				{
					pUniform->setValue3(1, pDirLight->getDirection());
				}
			}
		}
		else if (item.first == SingleLightUniformType::LIGHT_HALF_VECTOR)
		{
			pUniform->setValue3(1, halfVector.getValue());
		}
		else if (item.first == SingleLightUniformType::LIGHT_COLOR)
		{
			pUniform->setValue4(1, pLight->getColor());
		}
		else if (item.first == SingleLightUniformType::LIGHT_AMBIENT)
		{
			pUniform->setValue4(1, pLight->getAmbient());
		}
		else if (item.first == SingleLightUniformType::LIGHT_SPOT_EXPONENT)
		{
			auto pSpotLight = pLight->as<SpotLight>();
			if (pSpotLight)
			{
				pUniform->setValue(pSpotLight->getExponent());
			}
		}
		else if (item.first == SingleLightUniformType::LIGHT_SPOT_COST_CUTOFF)
		{
			auto pSpotLight = pLight->as<SpotLight>();
			if (pSpotLight)
			{
				pUniform->setValue(pSpotLight->getCutOff());
			}
		}
		else if (item.first == SingleLightUniformType::LIGHT_CONSTANT_ATTENUATION)
		{
			auto pPointLight = pLight->as<PointLight>();
			if (pPointLight)
			{
				pUniform->setValue(pPointLight->getConstantAttenuation());
			}
		}
		else if (item.first == SingleLightUniformType::LIGHT_LINEAR_ATTENUATION)
		{
			auto pPointLight = pLight->as<PointLight>();
			if (pPointLight)
			{
				pUniform->setValue(pPointLight->getLinearAttenuation());
			}
		}
		else if (item.first == SingleLightUniformType::LIGHT_QUADRATIC_ATTENUATION)
		{
			auto pPointLight = pLight->as<PointLight>();
			if (pPointLight)
			{
				pUniform->setValue(pPointLight->getQuadraticAttenuation());
			}
		}
		else if (item.first == SingleLightUniformType::LIGHT_SPACE_MATRIX)
		{
			if (bSupportShadow)
			{
				math::Matrix4x4 lightMatrix;
				math::Matrix4x4 lightProject = Camera::getMainCamera()->getProjectMatrix(0.1f, Camera::getMainCamera()->getViewParameter().zFar);
				math::Vector3 center = Camera::getMainCamera()->getCenterPosition();
				math::Matrix4x4 lightView = math::Matrix4x4::lookAt(lightPos, center, math::Vector3(0, 1, 0));
				lightMatrix = lightProject * lightView;

				pUniform->setMatrix4(1, lightMatrix.getValue());
			}
		}
		GLDebug::showError();
	}
}

void render::UniformShaderApply::updateAllLightsUniformValue(Node* node, ShaderProgram* program)
{
	if (node == nullptr || program == nullptr)
	{
		return;
	}

	if (!G_ENVIRONMENT->hasLight())
	{
		return;
	}

	const auto& mapLights = G_ENVIRONMENT->getAllLights();

	const math::Matrix4x4& viewMat = Camera::getMainCamera()->getViewMatrix();
	bool bSupportShadow = false;
	if (node->is<LightProtocol>())
	{
		bSupportShadow = node->as<LightProtocol>()->isCastShadow();
	}
	for (auto light : mapLights)
	{
		auto pLight = light.second;
		int index = light.first;

		math::Vector3 viewPos = viewMat.getPosition();
		math::Vector3 lightPos = pLight->getWorldMatrix().getPosition();

		//viewPos.setZ(-viewPos.getZ());
		//lightPos *= -1.0f;
		//viewPos *= -1.0f;

		math::Vector3 nodePos = getWorldMatrix(node).getPosition();
		math::Vector3 viewDirection = viewPos - nodePos;
		math::Vector3 lightDirection = lightPos - nodePos;
		math::Vector3 halfVector = lightDirection + viewDirection;
		

		for (auto item : _mapMultiLightsUniform)
		{
			std::string text = getCString(item.second.c_str(), index);
			auto pUniform = program->getUniform(text);
			if (!pUniform)
			{
				continue;
			}
			else if (item.first == MultiLightsUniformType::MULTI_LIGHT_ENABLED)
			{
				pUniform->setValue(1);
			}
			else if (item.first == MultiLightsUniformType::MULTI_LIGHT_LOCAL)
			{
				if (pLight->is<PointLight>() || pLight->is<SpotLight>())
				{
					pUniform->setValue(1);
				}
				else
				{
					pUniform->setValue(0);
				}
			}
			else if (item.first == MultiLightsUniformType::MULTI_LIGHT_SPOT)
			{
				pUniform->setValue(pLight->is<SpotLight>() ? 1 : 0);
			}
			else if (item.first == MultiLightsUniformType::MULTI_LIGHT_POSITION)
			{
				pUniform->setValue3(1, lightPos.getValue());
			}
			else if (item.first == MultiLightsUniformType::MULTI_LIGHT_DIRECTION)
			{
				auto pPointLight = pLight->as<PointLight>();
				if (pPointLight)
				{
					pUniform->setValue3(1, lightDirection.getValue());
				}
				else
				{
					auto pSpotLight = pLight->as<SpotLight>();
					if (pSpotLight)
					{
						pUniform->setValue3(1, pSpotLight->getDirection());
					}
					auto pDirLight = pLight->as<DirectionLight>();
					if (pDirLight)
					{
						pUniform->setValue3(1, pDirLight->getDirection());
					}
				}
			}
			else if (item.first == MultiLightsUniformType::MULTI_LIGHT_HALF_VECTOR)
			{
				pUniform->setValue3(1, halfVector.getValue());
			}
			else if (item.first == MultiLightsUniformType::MULTI_LIGHT_COLOR)
			{
				pUniform->setValue4(1, pLight->getColor());
			}
			else if (item.first == MultiLightsUniformType::MULTI_LIGHT_AMBIENT)
			{
				pUniform->setValue4(1, pLight->getAmbient());
			}
			else if (item.first == MultiLightsUniformType::MULTI_LIGHT_SPOT_EXPONENT)
			{
				auto pSpotLight = pLight->as<SpotLight>();
				if (pSpotLight)
				{
					pUniform->setValue(pSpotLight->getExponent());
				}
			}
			else if (item.first == MultiLightsUniformType::MULTI_LIGHT_SPOT_COST_CUTOFF)
			{
				auto pSpotLight = pLight->as<SpotLight>();
				if (pSpotLight)
				{
					pUniform->setValue(pSpotLight->getCutOff());
				}
			}
			else if (item.first == MultiLightsUniformType::MULTI_LIGHT_CONSTANT_ATTENUATION)
			{
				auto pPointLight = pLight->as<PointLight>();
				if (pPointLight)
				{
					pUniform->setValue(pPointLight->getConstantAttenuation());
				}
			}
			else if (item.first == MultiLightsUniformType::MULTI_LIGHT_LINEAR_ATTENUATION)
			{
				auto pPointLight = pLight->as<PointLight>();
				if (pPointLight)
				{
					pUniform->setValue(pPointLight->getLinearAttenuation());
				}
			}
			else if (item.first == MultiLightsUniformType::MULTI_LIGHT_QUADRATIC_ATTENUATION)
			{
				auto pPointLight = pLight->as<PointLight>();
				if (pPointLight)
				{
					pUniform->setValue(pPointLight->getQuadraticAttenuation());
				}
			}
			else if (item.first == MultiLightsUniformType::MULTI_LIGHT_SPACE_MATRIX)
			{
				if (bSupportShadow)
				{
					math::Matrix4x4 lightMatrix;
					math::Matrix4x4 lightProject = Camera::getMainCamera()->getProjectMatrix(0.1f, Camera::getMainCamera()->getViewParameter().zFar);
					math::Vector3 center = Camera::getMainCamera()->getCenterPosition();
					math::Matrix4x4 lightView = math::Matrix4x4::lookAt(lightPos, center, math::Vector3(0, 1, 0));
					lightMatrix = lightProject * lightView;
					pUniform->setMatrix4(1, lightMatrix.getValue());
				}
			}
			GLDebug::showError();
		}
		GLDebug::showError();
	}
}

void render::UniformShaderApply::removeVertexDatas()
{
	_vertexAttribIndices.clear();
}

std::string render::UniformShaderApply::getUniformName(MultiLightsUniformType vut) const
{
	auto it = _mapMultiLightsUniform.find(vut);
	if (it == _mapMultiLightsUniform.end())
	{
		return "";
	}

	return it->second;
}

std::string render::UniformShaderApply::getUniformName(SingleLightUniformType vut) const
{
	auto it = _mapSingleLightUniform.find(vut);
	if (it == _mapSingleLightUniform.end())
	{
		return "";
	}

	return it->second;
}

void render::UniformShaderApply::addUniform(MultiLightsUniformType vut, const std::string& name)
{
	_mapMultiLightsUniform[vut] = name;
}

std::string render::UniformShaderApply::getUniformName(MaterialUniformType vut) const
{
	auto it = _mapMaterialUniform.find(vut);
	if (it == _mapMaterialUniform.end())
	{
		return "";
	}

	return it->second;
}

void render::UniformShaderApply::addUniform(SingleLightUniformType vut, const std::string& name)
{
	_mapSingleLightUniform[vut] = name;
}

std::string render::UniformShaderApply::getUniformName(TextureUniformType vut) const
{
	auto it = _mapTextureUniform.find(vut);
	if (it == _mapTextureUniform.end())
	{
		return "";
	}

	return it->second;
}

void render::UniformShaderApply::addUniform(MaterialUniformType vut, const std::string& name)
{
	_mapMaterialUniform[vut] = name;
}

std::string render::UniformShaderApply::getUniformName(MatrixUniformType vut) const
{
	auto it = _mapMatrixUniform.find(vut);
	if (it == _mapMatrixUniform.end())
	{
		return "";
	}

	return it->second;
}

void render::UniformShaderApply::addUniform(TextureUniformType vut, const std::string& name)
{
	_mapTextureUniform[vut] = name;
}

std::string render::UniformShaderApply::getUniformName(EnvUniformType vut) const
{
	auto it = _mapEnvUniform.find(vut);
	if (it == _mapEnvUniform.end())
	{
		return "";
	}

	return it->second;
}

void render::UniformShaderApply::addUniform(MatrixUniformType vut, const std::string& name)
{
	_mapMatrixUniform[vut] = name;
}

void render::UniformShaderApply::addUniform(EnvUniformType vut, const std::string& name)
{
	_mapEnvUniform[vut] = name;
}

void render::UniformShaderApply::removeUniformDatas()
{
	_mapEnvUniform.clear();
	_mapTextureUniform.clear();
	_mapMaterialUniform.clear();
	_mapMatrixUniform.clear();
	_mapSingleLightUniform.clear();
	_mapMultiLightsUniform.clear();
}

void render::UniformShaderApply::setTempMatrix(const math::Matrix4x4& matrix)
{
	_tempMatrix = matrix;
}

void render::UniformShaderApply::reloadTempMatrix()
{
	_tempMatrix.loadIdentity();
}

math::Matrix4x4 render::UniformShaderApply::getWorldMatrix(const Node* node)
{
	if (node == nullptr)
	{
		return math::Matrix4x4();
	}

	return _tempMatrix * node->getWorldMatrix();
}

