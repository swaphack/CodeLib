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
		GLMaterial::setMaterialShininess(FaceType::FRONT, _detail->getShiness());
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

void render::Material::startUpdateShaderUniformValue(Node* node, Materials* mats)
{
	if (_shaderProgram == nullptr)
	{
		return;
	}

	updateMVPMatrixUniformValue(node);

	updateNearestLightUniformValue(node);
	updateAllLightsUniformValue();

	updateMaterialUniformValue(mats);
	updateTexturesUnifromValue(mats);
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

void render::Material::endUpdateShaderUniformValue(Materials* mats)
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
			auto pTexture = mats->getTexture(_detail->getAmbientTextureMap());
			if (pTexture)
			{
				pTexture->unbindTexture();
				GLState::disable((EnableMode)pTexture->getTextureTarget());
			}

			GLDebug::showError();
		}
		else if (item.first == UniformType::TEXTURE1)
		{
			auto pTexture = mats->getTexture(_detail->getDiffuseTextureMap());
			if (pTexture)
			{
				pTexture->unbindTexture();
				GLState::disable((EnableMode)pTexture->getTextureTarget());
			}

			GLDebug::showError();
		}
		else if (item.first == UniformType::TEXTURE2)
		{
			auto pTexture = mats->getTexture(_detail->getSpecularTextureMap());
			if (pTexture)
			{
				pTexture->unbindTexture();
				GLState::disable((EnableMode)pTexture->getTextureTarget());
			}
			GLDebug::showError();
		}
		else if (item.first == UniformType::MATERIAL_TEXTURE_AMBIENT)
		{
			auto pTexture = mats->getTexture(_detail->getAmbientTextureMap());
			if (pTexture)
			{
				pTexture->unbindTexture();
				GLState::disable((EnableMode)pTexture->getTextureTarget());
			}

			GLDebug::showError();
		}
		else if (item.first == UniformType::MATERIAL_TEXTURE_DIFFUSE)
		{
			auto pTexture = mats->getTexture(_detail->getDiffuseTextureMap());
			if (pTexture)
			{
				pTexture->unbindTexture();
				GLState::disable((EnableMode)pTexture->getTextureTarget());
			}

			GLDebug::showError();
		}
		else if (item.first == UniformType::MATERIAL_TEXTURE_SPECULAR)
		{
			auto pTexture = mats->getTexture(_detail->getSpecularTextureMap());
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

	const math::Matrix44& projMat = Camera::getMainCamera()->getProjectMatrix();
	const math::Matrix44& viewMat = Camera::getMainCamera()->getViewMatrix();
	const math::Matrix44& modelMat = node->getWorldMatrix();

	for (auto item : _vertexUniformIndices)
	{
		auto pUniform = _shaderProgram->getUniform(item.second);
		if (!pUniform)
		{
			continue;
		}

		if (item.first == UniformType::PROJECT_MATRIX)
		{
			pUniform->setMatrix4(projMat);
		}
		else if (item.first == UniformType::VIEW_MATRIX)
		{
			pUniform->setMatrix4(viewMat);
		}
		else if (item.first == UniformType::MODEL_VIEW)
		{
			pUniform->setMatrix4(modelMat);
		}
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
	for (uint32_t i = (uint32_t)LightName::LIGHT0; i < (uint32_t)LightName::LIGHT7; i++)
	{
		auto pTempLight = G_ENVIRONMENT->getLight((LightName)i);
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

	const math::Matrix44& viewMat = Camera::getMainCamera()->getViewMatrix();

	for (auto item : _vertexUniformIndices)
	{
		auto pUniform = _shaderProgram->getUniform(item.second);
		if (!pUniform)
		{
			continue;
		}
		if (item.first == UniformType::VIEW_POSITION)
		{
			pUniform->setValue3(1, viewMat.getPosition().getValue());
		}
		else if (item.first == UniformType::LIGHT_COLOR)
		{
			if (pLight)
			{
				pUniform->setValue4(1, pLight->getAmbient());
			}
		}
		else if (item.first == UniformType::LIGHT_AMBIENT)
		{
			if (pLight)
			{
				pUniform->setValue4(1, pLight->getAmbient());
			}
		}
		else if (item.first == UniformType::LIGHT_SPECULAR)
		{
			if (pLight)
			{
				pUniform->setValue4(1, pLight->getSpecular());
			}
		}
		else if (item.first == UniformType::LIGHT_DIFFUSE)
		{
			if (pLight)
			{
				pUniform->setValue4(1, pLight->getDiffuse());
			}
		}
		else if (item.first == UniformType::LIGHT_POSITION)
		{
			if (pLight)
			{
				pUniform->setValue3(1, pLight->getWorldMatrix().getPosition().getValue());
			}
		}
	}
}

void render::Material::updateAllLightsUniformValue()
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
	int nLightCount = mapLights.size();

	float* pLightAmbients = new float[4 * nLightCount];
	float* pLightDiffuses = new float[4 * nLightCount];
	float* pLightSpeculars = new float[4 * nLightCount];
	float* pLightPositions = new float[3 * nLightCount];

	int index = 0;
	for (auto item : mapLights)
	{
		memcpy(pLightAmbients + 4 * index, item.second->getAmbient(), 4 * nLightCount);
		memcpy(pLightDiffuses + 4 * index, item.second->getDiffuse(), 4 * nLightCount);
		memcpy(pLightSpeculars + 4 * index, item.second->getSpecular(), 4 * nLightCount);
		memcpy(pLightPositions + 3 * index, item.second->getWorldMatrix().getPosition().getValue(), 3 * nLightCount);

		index++;
	}

	const math::Matrix44& viewMat = Camera::getMainCamera()->getViewMatrix();

	for (auto item : _vertexUniformIndices)
	{
		auto pUniform = _shaderProgram->getUniform(item.second);
		if (!pUniform)
		{
			continue;
		}
		if (item.first == UniformType::VIEW_POSITION)
		{
			pUniform->setValue3(1, viewMat.getPosition().getValue());
		}
		else if (item.first == UniformType::LIGHT_COLORS)
		{
			pUniform->setValue4(nLightCount, pLightAmbients);
		}
		else if (item.first == UniformType::LIGHT_AMBIENTS)
		{
			pUniform->setValue4(nLightCount, pLightAmbients);
		}
		else if (item.first == UniformType::LIGHT_SPECULARS)
		{
			pUniform->setValue4(nLightCount, pLightSpeculars);
		}
		else if (item.first == UniformType::LIGHT_DIFFUSES)
		{
			pUniform->setValue4(nLightCount, pLightDiffuses);
		}
		else if (item.first == UniformType::LIGHT_POSITIONS)
		{
			pUniform->setValue4(nLightCount, pLightPositions);
		}
	}

	delete[] pLightAmbients;
	delete[] pLightSpeculars;
	delete[] pLightDiffuses;
	delete[] pLightPositions;
}

void render::Material::updateMaterialUniformValue(Materials* mats)
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
		if (item.first == UniformType::MATERIAL_COLOR_AMBIENT)
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
		else if (item.first == UniformType::MATERIAL_TEXTURE_AMBIENT)
		{
			auto pTexture = mats->getTexture(_detail->getAmbientTextureMap());
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
			auto pTexture = mats->getTexture(_detail->getDiffuseTextureMap());
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
			auto pTexture = mats->getTexture(_detail->getSpecularTextureMap());
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
		else if (item.first == UniformType::MATERIAL_SHININESS)
		{
			pUniform->setValue(_detail->getShiness());
		}
	}
}

void render::Material::updateTexturesUnifromValue(Materials* mats)
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
			auto pTexture = mats->getTexture(_detail->getAmbientTextureMap());
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
			auto pTexture = mats->getTexture(_detail->getDiffuseTextureMap());
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
			auto pTexture = mats->getTexture(_detail->getSpecularTextureMap());
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

void render::Material::beginApply(Materials* mats)
{
	this->applyMaterial();

	auto pTexture = mats->getTexture(_detail->getAmbientTextureMap());
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

void render::Material::endApply(Materials* mats)
{
	auto pTexture = mats->getTexture(_detail->getAmbientTextureMap());
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

void render::Material::beginApplyWithShader(Node* node, Mesh* pMesh, Materials* mats)
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

	this->startUpdateShaderUniformValue(node, mats);
	this->startUpdateShaderVertexValue(pMesh);

	runProgramFunc();
}

void render::Material::endApplyWithShader(Mesh* pMesh, Materials* mats)
{
	this->endUpdateShaderUniformValue(mats);
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

