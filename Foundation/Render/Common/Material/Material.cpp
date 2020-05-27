#include "Material.h"
#include "Common/Shader/import.h"
#include "Common/Node/import.h"
#include "Graphic/import.h"
#include "Common/BufferObject/import.h"
#include "Common/Buffer/import.h"
#include "Common/View/Camera.h"
#include "Materials.h"
#include "Common/Mesh/import.h"
#include "Common/Texture/import.h"

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

void render::Material::addAttrib(VertexAttribType vat, const std::string& name)
{
	_vertexAttribIndices[vat] = name;
}

std::string render::Material::getAttribIndex(VertexAttribType vat) const
{
	auto it = _vertexAttribIndices.find(vat);
	if (it == _vertexAttribIndices.end())
	{
		return "";
	}

	return it->second;
}

void render::Material::removeAttribIndices()
{
	_vertexAttribIndices.clear();
}

void render::Material::addUniform(VertexUniformType vut, const std::string& name)
{
	_vertexUniformIndices[vut] = name;
}

std::string render::Material::getUniformIndex(VertexUniformType vut) const
{
	auto it = _vertexUniformIndices.find(vut);
	if (it == _vertexUniformIndices.end())
	{
		return "";
	}

	return it->second;
}

void render::Material::removeUniformIndices()
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

	math::Matrix44 projMat = Camera::getMainCamera()->getProjectMatrix();
	math::Matrix44 viewMat = Camera::getMainCamera()->getViewMatrix();
	math::Matrix44 modelMat = node->getWorldMatrix();

	for (auto item : _vertexUniformIndices)
	{
		auto pUniform = _shaderProgram->getUniform(item.second);
		if (!pUniform)
		{
			continue;
		}
		if (item.first == VertexUniformType::PROJECT_MATRIX)
		{
			pUniform->setMatrix4(projMat);
		}
		else if (item.first == VertexUniformType::VIEW_MATRIX)
		{
			pUniform->setMatrix4(viewMat);
		}
		else if (item.first == VertexUniformType::MODEL_VIEW)
		{
			pUniform->setMatrix4(modelMat);
		}

		else if (item.first == VertexUniformType::AMBIENT_TEXTURE)
		{
			auto pTexture = mats->getTexture(_detail->getAmbientTextureMap());
			if (pTexture)
			{
				pTexture->activeTexture(0);
				GLDebug::showError();
				pTexture->bindSampler(0);
				GLDebug::showError();
				pTexture->bindTexture();
				//pUniform->setValue(pTexture->getTextureID());
			}
			pUniform->setValue(0);
			GLDebug::showError();
		}
		else if (item.first == VertexUniformType::DIFFUSE_TEXTURE)
		{
			auto pTexture = mats->getTexture(_detail->getDiffuseTextureMap());
			if (pTexture)
			{
				pTexture->activeTexture(1);
				GLDebug::showError();
				pTexture->bindSampler(1);
				GLDebug::showError();
				pTexture->bindTexture();
				//pUniform->setValue(pTexture->getTextureID());
			}
			pUniform->setValue(1);

			GLDebug::showError();
		}
		else if (item.first == VertexUniformType::SPECULAR_TEXTURE)
		{
			auto pTexture = mats->getTexture(_detail->getSpecularTextureMap());
			if (pTexture)
			{
				pTexture->activeTexture(2);
				GLDebug::showError();
				pTexture->bindSampler(2);
				GLDebug::showError();
				pTexture->bindTexture();
				//pUniform->setValue(pTexture->getTextureID());
			}
			pUniform->setValue(2);

			GLDebug::showError();
		}

		GLDebug::showError();
	}

	runProgramFunc();

	GLDebug::showError();
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
		if (item.first == VertexAttribType::POSITION)
		{
			if (nVerticeSize > 0)
			{
				pointer->setVertexAttribPointer(vertices.getUnitSize(), VertexAttribPointerType::FLOAT, 0);
			}
		}
		else if (item.first == VertexAttribType::COLOR)
		{
			if (nColorSize > 0)
			{
				pointer->setVertexAttribPointer(colors.getUnitSize(), VertexAttribPointerType::FLOAT, nVerticeSize);
			}
		}
		else if (item.first == VertexAttribType::UV)
		{
			if (nUVSize > 0)
			{
				pointer->setVertexAttribPointer(texcoords.getUnitSize(), VertexAttribPointerType::FLOAT, nVerticeSize + nColorSize);
			}
		}
		else if (item.first == VertexAttribType::NORMAL)
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
		if (item.first == VertexUniformType::AMBIENT_TEXTURE)
		{
			auto pTexture = mats->getTexture(_detail->getAmbientTextureMap());
			if (pTexture)
			{
				pTexture->unbindTexture();
			}

			GLDebug::showError();
		}
		else if (item.first == VertexUniformType::DIFFUSE_TEXTURE)
		{
			auto pTexture = mats->getTexture(_detail->getDiffuseTextureMap());
			if (pTexture)
			{
				pTexture->unbindTexture();
			}

			GLDebug::showError();
		}
		else if (item.first == VertexUniformType::SPECULAR_TEXTURE)
		{
			auto pTexture = mats->getTexture(_detail->getSpecularTextureMap());
			if (pTexture)
			{
				pTexture->unbindTexture();
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

void render::Material::beginApply(Materials* mats)
{
	this->applyMaterial();

	auto pTexture = mats->getTexture(_detail->getAmbientTextureMap());
	if (pTexture)
	{
		pTexture->bindTextureUnit(0);
		pTexture->applyTextureSetting();
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

	this->applyMaterial();

	if (_shaderProgram)
	{
		_shaderProgram->use();
	}

	this->startUpdateShaderUniformValue(node, mats);
	this->startUpdateShaderVertexValue(pMesh);
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

