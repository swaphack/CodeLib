#include "Material.h"
#include "Common/Shader/import.h"
#include "Common/Node/import.h"
#include "Graphic/import.h"
#include "Common/VAO/import.h"
#include "Common/Buffer/import.h"
#include "Common/View/Camera.h"
#include "Materials.h"
#include "Common/Mesh/import.h"
#include "Common/Texture/import.h"
#include "3d/Environment/import.h"
#include "Common/DrawNode/DrawTextureCache.h"

render::Material::Material()
{

}

render::Material::~Material()
{
	SAFE_RELEASE(_detail);
	SAFE_RELEASE(_shaderProgram);

}

void render::Material::setShaderProgram(ShaderProgram* shaderProgram)
{
	SAFE_RELEASE(_shaderProgram);
	SAFE_RETAIN(shaderProgram);

	_shaderProgram = shaderProgram;
}

render::ShaderProgram* render::Material::getShaderProgram()
{
	return _shaderProgram;
}

void render::Material::setMaterialDetail(sys::MaterialDetail* detail)
{
	SAFE_RELEASE(_detail);
	SAFE_RETAIN(detail);

	_detail = detail;
}

sys::MaterialDetail* render::Material::getMaterialDetail() const
{
	return _detail;
}

void render::Material::setProgramFunc(const ShaderProgramFunc& func)
{
	_programFunc = func;
}

void render::Material::addVertexData(VertexDataType vat, const std::string& name)
{
	_vertexAttribIndices[vat] = name;
}

std::string render::Material::getVertexName(VertexDataType vat) const
{
	auto it = _vertexAttribIndices.find(vat);
	if (it == _vertexAttribIndices.end())
	{
		return "";
	}

	return it->second;
}

void render::Material::removeVertexDatas()
{
	_vertexAttribIndices.clear();
}

void render::Material::addUniform(UniformType vut, const std::string& name)
{
	_vertexUniformIndices[vut] = name;
}

std::string render::Material::getUniformName(UniformType vut) const
{
	auto it = _vertexUniformIndices.find(vut);
	if (it == _vertexUniformIndices.end())
	{
		return "";
	}

	return it->second;
}

void render::Material::removeUniformDatas()
{
	_vertexUniformIndices.clear();
}
void render::Material::applyMaterial()
{
	if (_detail)
	{
		GLMaterial::setMaterialAmbient(FaceType::FRONT, _detail->getAmbient());
		GLMaterial::setMaterialDiffuse(FaceType::FRONT, _detail->getDiffuse());
		GLMaterial::setMaterialSpecular(FaceType::FRONT, _detail->getSpecular());
		GLMaterial::setMaterialShininess(FaceType::FRONT, _detail->getSpecularShiness());
		GLMaterial::setMaterialEmission(FaceType::FRONT, _detail->getEmission());
		GLDebug::showError();
	}
	else
	{
		static float matrialAmbient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
		static float matrialDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
		static float matrialSpecular[] = { 0.0f, 0.0f, 0.0f, 1.0f };
		static float matrialShiness = 0.0f;
		static float matrialEmission[] = { 0.0f, 0.0f, 0.0f, 1.0f };

		GLMaterial::setMaterialAmbient(FaceType::FRONT, matrialAmbient);
		GLMaterial::setMaterialDiffuse(FaceType::FRONT, matrialDiffuse);
		GLMaterial::setMaterialSpecular(FaceType::FRONT, matrialSpecular);
		GLMaterial::setMaterialShininess(FaceType::FRONT, matrialShiness);
		GLMaterial::setMaterialEmission(FaceType::FRONT, matrialEmission);
		GLDebug::showError();
	}
}

void render::Material::startUpdateShaderUniformValue(Node* node, DrawTextureCache* textureCache)
{
	if (_shaderProgram == nullptr)
	{
		return;
	}

	updateMVPMatrixUniformValue(node);

	updateNearestLightUniformValue(node);
	//updateAllLightsUniformValue(node);

	updateMaterialUniformValue(textureCache);
	updateTexturesUnifromValue(textureCache);
}

void render::Material::startUpdateShaderVertexValue(Mesh* pMesh)
{
	if (pMesh == nullptr)
	{
		return;
	}

	if (_shaderProgram == nullptr)
	{
		return;
	}

	auto detail = pMesh->getMeshDetail();
	auto vao = pMesh->getVertexArrayObject();

	vao->bindVertexArray();
	vao->bindBuffer();

	const sys::MeshMemoryData& vertices = detail->getVertices();
	const sys::MeshMemoryData& colors = detail->getColors();
	const sys::MeshMemoryData& texcoords = detail->getUVs();
	const sys::MeshMemoryData& normals = detail->getNormals();

	uint32_t nVerticeSize = vertices.getSize();
	uint32_t nColorSize = colors.getSize();
	uint32_t nUVSize = texcoords.getSize();
	uint32_t nNormalSize = normals.getSize();

	for (auto item : _vertexAttribIndices)
	{
		auto pAttrib = _shaderProgram->getAttrib(item.second);
		if (!pAttrib) continue;
		VertexAttribPointer* pointer = vao->getVertexAttrib<VertexAttribPointer>(pAttrib->getAttribID());
		pointer->enableVertexArrayAttrib();
		GLDebug::showError();
		if (item.first == VertexDataType::POSITION)
		{
			if (nVerticeSize > 0)
			{
				pointer->setVertexAttribPointer(vertices.getUnitSize(), VertexAttribPointerType::FLOAT, 0);
			}
		}
		else if (item.first == VertexDataType::COLOR)
		{
			if (nColorSize > 0)
			{
				pointer->setVertexAttribPointer(colors.getUnitSize(), VertexAttribPointerType::FLOAT, nVerticeSize);
			}
		}
		else if (item.first == VertexDataType::UV)
		{
			if (nUVSize > 0)
			{
				pointer->setVertexAttribPointer(texcoords.getUnitSize(), VertexAttribPointerType::FLOAT, nVerticeSize + nColorSize);
			}
		}
		else if (item.first == VertexDataType::NORMAL)
		{
			if (nNormalSize > 0)
			{
				pointer->setVertexAttribPointer(normals.getUnitSize(), VertexAttribPointerType::FLOAT, nVerticeSize + nColorSize + nUVSize);
			}
		}
		GLDebug::showError();
	}

	GLDebug::showError();
}

void render::Material::endUpdateShaderUniformValue(DrawTextureCache* textureCache)
{
	if (_shaderProgram == nullptr)
	{
		return;
	}

	for (auto item : _vertexUniformIndices)
	{
		auto pUniform = _shaderProgram->getUniform(item.second);
		if (!pUniform)
		{
			continue;
		}
		if (item.first == UniformType::TEXTURE0)
		{
			auto pTexture = textureCache->getTexture(_detail->getAmbientTextureMap());
			if (pTexture)
			{
				pTexture->unbindTexture();
				GLState::disable((EnableMode)pTexture->getTextureTarget());
			}

			GLDebug::showError();
		}
		else if (item.first == UniformType::TEXTURE1)
		{
			auto pTexture = textureCache->getTexture(_detail->getDiffuseTextureMap());
			if (pTexture)
			{
				pTexture->unbindTexture();
				GLState::disable((EnableMode)pTexture->getTextureTarget());
			}

			GLDebug::showError();
		}
		else if (item.first == UniformType::TEXTURE2)
		{
			auto pTexture = textureCache->getTexture(_detail->getSpecularTextureMap());
			if (pTexture)
			{
				pTexture->unbindTexture();
				GLState::disable((EnableMode)pTexture->getTextureTarget());
			}
			GLDebug::showError();
		}
		else if (item.first == UniformType::MATERIAL_TEXTURE)
		{
			auto pTexture = textureCache->getTexture(_detail->getAmbientTextureMap());
			if (pTexture)
			{
				pTexture->unbindTexture();
				GLState::disable((EnableMode)pTexture->getTextureTarget());
			}

			GLDebug::showError();
		}
		else if (item.first == UniformType::MATERIAL_TEXTURE_DIFFUSE)
		{
			auto pTexture = textureCache->getTexture(_detail->getDiffuseTextureMap());
			if (pTexture)
			{
				pTexture->unbindTexture();
				GLState::disable((EnableMode)pTexture->getTextureTarget());
			}

			GLDebug::showError();
		}
		else if (item.first == UniformType::MATERIAL_TEXTURE_SPECULAR)
		{
			auto pTexture = textureCache->getTexture(_detail->getSpecularTextureMap());
			if (pTexture)
			{
				pTexture->unbindTexture();
				GLState::disable((EnableMode)pTexture->getTextureTarget());
			}
			GLDebug::showError();
		}
		else if (item.first == UniformType::MATERIAL_TEXTURE_ALPHA)
		{
			auto pTexture = textureCache->getTexture(_detail->getAlphaTextureMap());
			if (pTexture)
			{
				pTexture->unbindTexture();
				GLState::disable((EnableMode)pTexture->getTextureTarget());
			}
			GLDebug::showError();
		}
		else if (item.first == UniformType::MATERIAL_TEXTURE_BUMP)
		{
			auto pTexture = textureCache->getTexture(_detail->getBumpTextureMap());
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

void render::Material::endUpdateShaderVertexValue(Mesh* pMesh)
{
	if (pMesh == nullptr)
	{
		return;
	}

	if (_shaderProgram == nullptr)
	{
		return;
	}

	auto vao = pMesh->getVertexArrayObject();
	for (auto item : _vertexAttribIndices)
	{
		auto pAttrib = _shaderProgram->getAttrib(item.second);
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

void render::Material::updateMVPMatrixUniformValue(Node* node)
{
	if (_shaderProgram == nullptr)
	{
		return;
	}

	math::Matrix4x4 projMat = Camera::getMainCamera()->getProjectMatrix();
	math::Matrix4x4 viewMat = Camera::getMainCamera()->getViewMatrix();
	math::Matrix4x4 modelMat = node->getWorldMatrix();

	math::Matrix3x3 normalMat = modelMat.getInverse().getTranspose();
	math::Matrix4x4 mvpMat = projMat * viewMat * modelMat;
	math::Matrix4x4 mvMat = viewMat * modelMat;

	math::Vector3 viewPos = viewMat.getPosition();
	//viewPos *= -1.0f;

	for (auto item : _vertexUniformIndices)
	{
		auto pUniform = _shaderProgram->getUniform(item.second);
		if (!pUniform)
		{
			continue;
		}
		if (item.first == UniformType::VIEW_POSITION)
		{
			pUniform->setValue3(1, viewPos.getValue());
		}
		else if (item.first == UniformType::PROJECT_MATRIX)
		{
			pUniform->setMatrix4(projMat);
		}
		else if (item.first == UniformType::VIEW_MATRIX)
		{
			pUniform->setMatrix4(viewMat);
		}
		else if (item.first == UniformType::MODEL_MATRIX)
		{
			pUniform->setMatrix4(modelMat);
		}
		else if (item.first == UniformType::NORMAL_MATRIX)
		{
			pUniform->setMatrix3(normalMat);
		}
		else if (item.first == UniformType::MVP_MATRIX)
		{
			pUniform->setMatrix4(mvpMat);
		}
		else if (item.first == UniformType::MV_MATRIX)
		{
			pUniform->setMatrix4(mvMat);
		}

		GLDebug::showError();
	}
}

void render::Material::updateNearestLightUniformValue(Node* node)
{
	if (node == nullptr)
	{
		return;
	}
	if (!G_ENVIRONMENT->hasLight())
	{
		return;
	}

	float fPos = -1;
	Light* pLight = nullptr;
	for (int i = 0; i < Light::getLightMaxCount(); i++)
	{
		auto pTempLight = G_ENVIRONMENT->getLight(i);
		if (pTempLight)
		{
			float fDistance = math::Vector3::distance(pTempLight->getPosition(), node->getPosition());
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

	//viewPos *= -1.0f;
	//lightPos *= -1.0f;

	math::Vector3 nodePos = node->getWorldMatrix().getPosition();
	math::Vector3 viewDirection = viewPos - nodePos;
	math::Vector3 lightDirection = lightPos - nodePos;
	math::Vector3 halfVector = lightDirection + viewDirection;
	halfVector.normalize();

	for (auto item : _vertexUniformIndices)
	{
		auto pUniform = _shaderProgram->getUniform(item.second);
		if (!pUniform)
		{
			continue;
		}
		
		if (item.first == UniformType::LIGHT_ENABLED)
		{
			pUniform->setValue(true);
		}
		else if (item.first == UniformType::LIGHT_LOCAL)
		{
			if (pLight->is<PointLight>() || pLight->is<SpotLight>())
			{
				pUniform->setValue(true);
			}
			else
			{
				pUniform->setValue(false);
			}
		}
		else if (item.first == UniformType::LIGHT_SPOT)
		{
			pUniform->setValue(pLight->is<SpotLight>());
		}
		else if (item.first == UniformType::LIGHT_POSITION)
		{
			pUniform->setValue3(1, lightPos.getValue());
		}
		else if (item.first == UniformType::LIGHT_DIRECTION)
		{
			auto pSpotLight = pLight->as<SpotLight>();
			if (pSpotLight)
			{
				pUniform->setValue3(1, pSpotLight->getDirection());
			}
			else
			{
				pUniform->setValue3(1, lightDirection.getValue());
			}
		}
		else if (item.first == UniformType::LIGHT_HALF_VECTOR)
		{
			pUniform->setValue3(1, halfVector.getValue());
		}
		else if (item.first == UniformType::LIGHT_COLOR)
		{
			pUniform->setValue4(1, pLight->getColor());
		}
		else if (item.first == UniformType::LIGHT_AMBIENT)
		{
			pUniform->setValue4(1, pLight->getAmbient());
		}
		else if (item.first == UniformType::LIGHT_SPOT_EXPONENT)
		{
			auto pSpotLight = pLight->as<SpotLight>();
			if (pSpotLight)
			{
				pUniform->setValue(pSpotLight->getExponent());
			}
		}
		else if (item.first == UniformType::LIGHT_SPOT_COST_CUTOFF)
		{
			auto pSpotLight = pLight->as<SpotLight>();
			if (pSpotLight)
			{
				pUniform->setValue(pSpotLight->getCutOff());
			}
		}
		else if (item.first == UniformType::LIGHT_CONSTANT_ATTENUATION)
		{
			auto pPointLight = pLight->as<PointLight>();
			if (pPointLight)
			{
				pUniform->setValue(pPointLight->getConstantAttenuation());
			}
		}
		else if (item.first == UniformType::LIGHT_LINEAR_ATTENUATION)
		{
			auto pPointLight = pLight->as<PointLight>();
			if (pPointLight)
			{
				pUniform->setValue(pPointLight->getLinearAttenuation());
			}
		}
		else if (item.first == UniformType::LIGHT_QUADRATIC_ATTENUATION)
		{
			auto pPointLight = pLight->as<PointLight>();
			if (pPointLight)
			{
				pUniform->setValue(pPointLight->getQuadraticAttenuation());
			}
		}
		GLDebug::showError();
	}
}

void render::Material::updateAllLightsUniformValue(Node* node)
{
	if (_shaderProgram == nullptr)
	{
		return;
	}

	if (!G_ENVIRONMENT->hasLight())
	{
		return;
	}

	const auto& mapLights = G_ENVIRONMENT->getAllLights();

	const math::Matrix4x4& viewMat = Camera::getMainCamera()->getViewMatrix();

	for (auto light : mapLights)
	{
		auto pLight = light.second;
		int index = light.first;

		math::Vector3 viewPos = viewMat.getPosition();
		math::Vector3 lightPos = pLight->getWorldMatrix().getPosition();
		//lightPos *= -1.0f;
		//viewPos *= -1.0f;

		math::Vector3 nodePos = node->getWorldMatrix().getPosition();
		math::Vector3 viewDirection = viewPos - nodePos;
		math::Vector3 lightDirection = lightPos - nodePos;
		math::Vector3 halfVector = lightDirection + viewDirection;

		for (auto item : _vertexUniformIndices)
		{
			std::string text = getCString(item.second.c_str(), index);
			auto pUniform = _shaderProgram->getUniform(item.second);
			if (!pUniform)
			{
				continue;
			}
			else if (item.first == UniformType::MULTI_LIGHT_ENABLED)
			{
				pUniform->setValue(true);
			}
			else if (item.first == UniformType::MULTI_LIGHT_LOCAL)
			{
				if (pLight->is<PointLight>() || pLight->is<SpotLight>())
				{
					pUniform->setValue(true);
				}
				else
				{
					pUniform->setValue(false);
				}
			}
			else if (item.first == UniformType::MULTI_LIGHT_SPOT)
			{
				pUniform->setValue(pLight->is<SpotLight>());
			}
			else if (item.first == UniformType::MULTI_LIGHT_POSITION)
			{
				pUniform->setValue3(1, lightPos.getValue());
			}
			else if (item.first == UniformType::MULTI_LIGHT_DIRECTION)
			{
				auto pSpotLight = pLight->as<SpotLight>();

				if (pSpotLight->is<SpotLight>())
				{
					pUniform->setValue3(1, pSpotLight->getDirection());
				}
				else
				{
					pUniform->setValue3(1, lightDirection.getValue());
				}
			}
			else if (item.first == UniformType::MULTI_LIGHT_HALF_VECTOR)
			{
				pUniform->setValue3(1, halfVector.getValue());
			}
			else if (item.first == UniformType::MULTI_LIGHT_COLOR)
			{
				pUniform->setValue4(1, pLight->getColor());
			}
			else if (item.first == UniformType::MULTI_LIGHT_AMBIENT)
			{
				pUniform->setValue4(1, pLight->getAmbient());
			}
			else if (item.first == UniformType::MULTI_LIGHT_SPOT_EXPONENT)
			{
				auto pSpotLight = pLight->as<SpotLight>();
				if (pSpotLight)
				{
					pUniform->setValue(pSpotLight->getExponent());
				}
			}
			else if (item.first == UniformType::MULTI_LIGHT_SPOT_COST_CUTOFF)
			{
				auto pSpotLight = pLight->as<SpotLight>();
				if (pSpotLight)
				{
					pUniform->setValue(pSpotLight->getCutOff());
				}
			}
			else if (item.first == UniformType::MULTI_LIGHT_CONSTANT_ATTENUATION)
			{
				auto pPointLight = pLight->as<PointLight>();
				if (pPointLight)
				{
					pUniform->setValue(pPointLight->getConstantAttenuation());
				}
			}
			else if (item.first == UniformType::MULTI_LIGHT_LINEAR_ATTENUATION)
			{
				auto pPointLight = pLight->as<PointLight>();
				if (pPointLight)
				{
					pUniform->setValue(pPointLight->getLinearAttenuation());
				}
			}
			else if (item.first == UniformType::MULTI_LIGHT_QUADRATIC_ATTENUATION)
			{
				auto pPointLight = pLight->as<PointLight>();
				if (pPointLight)
				{
					pUniform->setValue(pPointLight->getQuadraticAttenuation());
				}
			}
			GLDebug::showError();
		}
		GLDebug::showError();
	}
}

void render::Material::updateMaterialUniformValue(DrawTextureCache* textureCache)
{
	if (_shaderProgram == nullptr)
	{
		return;
	}

	for (auto item : _vertexUniformIndices)
	{
		auto pUniform = _shaderProgram->getUniform(item.second);
		if (!pUniform)
		{
			continue;
		}
		if (item.first == UniformType::MATERIAL_EMISSION)
		{
			pUniform->setValue4(1, _detail->getEmission());
		}
		else if (item.first == UniformType::MATERIAL_COLOR_AMBIENT)
		{
			pUniform->setValue4(1, _detail->getAmbient());
		}
		else if (item.first == UniformType::MATERIAL_COLOR_DIFFUSE)
		{
			pUniform->setValue4(1, _detail->getDiffuse());
		}
		else if (item.first == UniformType::MATERIAL_COLOR_SPECULAR)
		{
			pUniform->setValue4(1, _detail->getSpecular());
		}
		else if (item.first == UniformType::MATERIAL_TEXTURE)
		{
			auto pTexture = textureCache->getTexture(_detail->getAmbientTextureMap());
			if (pTexture)
			{
				pTexture->activeTexture(ActiveTextureName::TEXTURE0);
				pTexture->bindTexture();
				pTexture->enableTextureWithSampler(0);
				pUniform->setValue(0);
			}
			GLDebug::showError();
		}
		else if (item.first == UniformType::MATERIAL_TEXTURE_DIFFUSE)
		{
			auto pTexture = textureCache->getTexture(_detail->getDiffuseTextureMap());
			if (pTexture)
			{
				pTexture->activeTexture(ActiveTextureName::TEXTURE1);
				pTexture->bindTexture();
				pTexture->enableTextureWithSampler(1);
				pUniform->setValue(1);
			}
			else
			{
				pUniform->setValue(0);
			}
			GLDebug::showError();
		}
		else if (item.first == UniformType::MATERIAL_TEXTURE_SPECULAR)
		{
			auto pTexture = textureCache->getTexture(_detail->getSpecularTextureMap());
			if (pTexture)
			{
				pTexture->activeTexture(ActiveTextureName::TEXTURE2);
				pTexture->bindTexture();
				pTexture->enableTextureWithSampler(2);
				pUniform->setValue(2);
			}
			else
			{
				pUniform->setValue(0);
			}
			GLDebug::showError();
		}
		else if (item.first == UniformType::MATERIAL_TEXTURE_ALPHA)
		{
			auto pTexture = textureCache->getTexture(_detail->getAlphaTextureMap());
			if (pTexture)
			{
				pTexture->activeTexture(ActiveTextureName::TEXTURE3);
				pTexture->bindTexture();
				pTexture->enableTextureWithSampler(3);
				pUniform->setValue(3);
			}
			else
			{
				pUniform->setValue(0);
			}
			GLDebug::showError();
		}
		else if (item.first == UniformType::MATERIAL_TEXTURE_BUMP)
		{
			auto pTexture = textureCache->getTexture(_detail->getBumpTextureMap());
			if (pTexture)
			{
				pTexture->activeTexture(ActiveTextureName::TEXTURE4);
				pTexture->bindTexture();
				pTexture->enableTextureWithSampler(4);
				pUniform->setValue(4);
			}
			else
			{
				pUniform->setValue(0);
			}
			GLDebug::showError();
		}
		else if (item.first == UniformType::MATERIAL_SHININESS)
		{
			pUniform->setValue(_detail->getSpecularShiness());
		}
		else if (item.first == UniformType::MATERIAL_STRENGTH)
		{
			pUniform->setValue(_detail->getSpecularStrength());
		}
	}
}

void render::Material::updateTexturesUnifromValue(DrawTextureCache* textureCache)
{
	if (_shaderProgram == nullptr)
	{
		return;
	}

	for (auto item : _vertexUniformIndices)
	{
		auto pUniform = _shaderProgram->getUniform(item.second);
		if (!pUniform)
		{
			continue;
		}
		if (item.first == UniformType::TEXTURE0)
		{
			auto pTexture = textureCache->getTexture(_detail->getAmbientTextureMap());
			if (pTexture)
			{
				pTexture->activeTexture(ActiveTextureName::TEXTURE0);
				pTexture->bindTexture();
				pTexture->enableTextureWithSampler(0);
				pUniform->setValue(0);
			}
		}
		else if (item.first == UniformType::TEXTURE1)
		{
			auto pTexture = textureCache->getTexture(_detail->getDiffuseTextureMap());
			if (pTexture)
			{
				pTexture->activeTexture(ActiveTextureName::TEXTURE1);
				pTexture->bindTexture();
				pTexture->enableTextureWithSampler(1);
				pUniform->setValue(1);
			}
			else
			{
				pUniform->setValue(0);
			}

			GLDebug::showError();
		}
		else if (item.first == UniformType::TEXTURE2)
		{
			auto pTexture = textureCache->getTexture(_detail->getSpecularTextureMap());
			if (pTexture)
			{
				pTexture->activeTexture(ActiveTextureName::TEXTURE2);
				pTexture->bindTexture();
				pTexture->enableTextureWithSampler(2);
				pUniform->setValue(2);
			}
			else
			{
				pUniform->setValue(0);
			}
		}
	}
}

void render::Material::beginApply(DrawTextureCache* textureCache)
{
	this->applyMaterial();

	auto pTexture = textureCache->getTexture(_detail->getAmbientTextureMap());
	if (pTexture)
	{
		pTexture->enableTexture(0);
	}
#if 0
	nTextureID = this->getTexture(_detail->getDiffuseTextureMap());
	GLTexture::activeTexture(ActiveTextureName::TEXTURE1);
	GLTexture::bindTexture2D(nTextureID);

	nTextureID = this->getTexture(_detail->getSpecularTextureMap());
	GLTexture::activeTexture(ActiveTextureName::TEXTURE2);
	GLTexture::bindTexture2D(nTextureID);
#endif // 0
}

void render::Material::endApply(DrawTextureCache* textureCache)
{
	auto pTexture = textureCache->getTexture(_detail->getAmbientTextureMap());
	if (pTexture)
	{
		pTexture->unbindTexture();
	}
#if 0
	nTextureID = this->getTexture(_detail->getDiffuseTextureMap());
	GLTexture::activeTexture(ActiveTextureName::TEXTURE1);
	GLTexture::bindTexture2D(nTextureID);

	nTextureID = this->getTexture(_detail->getSpecularTextureMap());
	GLTexture::activeTexture(ActiveTextureName::TEXTURE2);
	GLTexture::bindTexture2D(nTextureID);
#endif // 0
}

void render::Material::beginApplyWithShader(Node* node, Mesh* pMesh, DrawTextureCache* textureCache)
{
	if (_shaderProgram == nullptr)
	{
		return;
	}

	//this->applyMaterial();

	if (_shaderProgram)
	{
		_shaderProgram->use();
	}

	this->startUpdateShaderUniformValue(node, textureCache);
	this->startUpdateShaderVertexValue(pMesh);

	runProgramFunc();
}

void render::Material::endApplyWithShader(Mesh* pMesh, DrawTextureCache* textureCache)
{
	this->endUpdateShaderUniformValue(textureCache);
	this->endUpdateShaderVertexValue(pMesh);

	if (_shaderProgram)
	{
		_shaderProgram->unuse();
	}
}

void render::Material::runProgramFunc()
{
	if (_programFunc != nullptr && _shaderProgram != nullptr)
	{
		_programFunc(_shaderProgram);
	}
}

