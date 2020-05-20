#include "Material.h"
#include "Graphic/import.h"
#include "Common/Shader/import.h"
#include "Common/Buffer/import.h"
#include "Common/View/import.h"
#include "Common/Texture/import.h"
#include "Common/BufferObject/import.h"

using namespace render;

render::Material::Material()
{

}

render::Material::~Material()
{
	this->removeAllTextures();

	SAFE_RELEASE(_shaderProgram);
}

void render::Material::setModelDetail(const sys::ModelDetail* modelDetail)
{
	if (modelDetail == nullptr)
	{
		return;
	}

	this->removeAllMaterials();

	this->_texturePaths = modelDetail->getTexturePaths();
	for (auto item : modelDetail->getMaterials())
	{
		this->addMaterial(item.first, item.second);
	}
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

void Material::addMaterial(int id, sys::MaterialDetail* material)
{
	if (material == nullptr)
	{
		return;
	}

	this->removeMaterial(id);

	SAFE_RETAIN(material);

	_materials[id] = material;
}

void Material::removeMaterial(int id)
{
	auto it = _materials.find(id);
	if (it == _materials.end())
	{
		return;
	}

	SAFE_RELEASE(it->second);
	_materials.erase(it);
}

void Material::removeAllMaterials()
{
	for (auto it : _materials)
	{
		SAFE_RELEASE(it.second);
	}
	_materials.clear();
}

sys::MaterialDetail* Material::getMaterial(int id)
{
	auto it = _materials.find(id);
	if (it == _materials.end())
	{
		return nullptr;
	}

	return it->second;
}

const std::map<int, sys::MaterialDetail*>& render::Material::getMaterials() const
{
	return _materials;
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

void render::Material::startUpdateShaderUniformValue(Node* node)
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

		GLDebug::showError();
	}

	runProgramFunc();

	GLDebug::showError();
}

void render::Material::startUpdateShaderVertexValue(VertexArrayObject* data, sys::MeshDetail* pMesh)
{
	if (data == nullptr || pMesh == nullptr)
	{
		return;
	}

	if (_shaderProgram == nullptr)
	{
		return;
	}

	const sys::MeshMemoryData& vertices = pMesh->getVertices();
	const sys::MeshMemoryData& colors = pMesh->getColors();
	const sys::MeshMemoryData& texcoords = pMesh->getUVs();
	const sys::MeshMemoryData& normals = pMesh->getNormals();

	uint32_t nVerticeSize = vertices.getSize();
	uint32_t nColorSize = colors.getSize();
	uint32_t nUVSize = texcoords.getSize();
	uint32_t nNormalSize = normals.getSize();

	for (auto item : _vertexAttribIndices)
	{
		auto pAttrib = _shaderProgram->getAttrib(item.second);
		if (!pAttrib) continue;
		VertexAttribPointer* pointer = data->getVertexAttrib<VertexAttribPointer>(pAttrib->getAttribID());
		pointer->enableVertexArrayAttrib();

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

void render::Material::applyMaterial(uint32_t nMatID) const
{
	auto it = _materials.find(nMatID);
	if (it == _materials.end())
	{
		return;
	}

	auto pMat = it->second;
	if (pMat)
	{
		GLMaterial::setMaterialAmbient(FaceType::FRONT, pMat->getAmbient());
		GLMaterial::setMaterialDiffuse(FaceType::FRONT, pMat->getDiffuse());
		GLMaterial::setMaterialSpecular(FaceType::FRONT, pMat->getSpecular());
		GLMaterial::setMaterialShininess(FaceType::FRONT, pMat->getShiness());
		GLMaterial::setMaterialEmission(FaceType::FRONT, pMat->getEmission());
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

	auto nTextureID = this->getTexture(pMat->getAmbientTextureMap());
	GLTexture::activeTexture(ActiveTextureName::TEXTURE0);
	GLTexture::bindTexture2D(nTextureID);
#if 0
	nTextureID = this->getTexture(pMat->getDiffuseTextureMap());
	GLTexture::activeTexture(ActiveTextureName::TEXTURE1);
	GLTexture::bindTexture2D(nTextureID);

	nTextureID = this->getTexture(pMat->getSpecularTextureMap());
	GLTexture::activeTexture(ActiveTextureName::TEXTURE2);
	GLTexture::bindTexture2D(nTextureID);
#endif // 0
}

void render::Material::applyMaterialWithShader(uint32_t nMatID) const
{
	auto it = _materials.find(nMatID);
	if (it == _materials.end())
	{
		return;
	}

	auto pMat = it->second;
	if (pMat)
	{
		GLMaterial::setMaterialAmbient(FaceType::FRONT, pMat->getAmbient());
		GLMaterial::setMaterialDiffuse(FaceType::FRONT, pMat->getDiffuse());
		GLMaterial::setMaterialSpecular(FaceType::FRONT, pMat->getSpecular());
		GLMaterial::setMaterialShininess(FaceType::FRONT, pMat->getShiness());
		GLMaterial::setMaterialEmission(FaceType::FRONT, pMat->getEmission());
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
	}

	GLState::enable(EnableMode::TEXTURE_2D);

	for (auto item : _vertexUniformIndices)
	{
		auto pUniform = _shaderProgram->getUniform(item.second);
		if (!pUniform)
		{
			continue;
		}
		if (item.first == VertexUniformType::AMBIENT_TEXTURE)
		{
			auto nTextureID = this->getTexture(pMat->getAmbientTextureMap());
			GLTexture::activeTexture(ActiveTextureName::TEXTURE0);
			GLTexture::bindTexture2D(nTextureID);
			pUniform->setValue(0);

			GLDebug::showError();
		}
		else if (item.first == VertexUniformType::DIFFUSE_TEXTURE)
		{
			auto nTextureID = this->getTexture(pMat->getDiffuseTextureMap());

			GLTexture::activeTexture(ActiveTextureName::TEXTURE1);
			GLTexture::bindTexture2D(nTextureID);
			pUniform->setValue(1);

			GLDebug::showError();
		}
		else if (item.first == VertexUniformType::SPECULAR_TEXTURE)
		{
			auto nTextureID = this->getTexture(pMat->getSpecularTextureMap());
			GLTexture::activeTexture(ActiveTextureName::TEXTURE2);
			GLTexture::bindTexture2D(nTextureID);
			pUniform->setValue(2);

			GLDebug::showError();
		}
		GLDebug::showError();
	}
}

void render::Material::updateMatTexture()
{
	if (_texturePaths.empty())
	{
		return;
	}
	for (auto item : _texturePaths)
	{
		Texture2D* pTexture = this->createTexture(item.second);
		if (pTexture)
		{
			this->addTexture(item.first, pTexture);
		}
	}
	_texturePaths.clear();
}

void render::Material::setProgramFunc(const ShaderProgramFunc& func)
{
	_programFunc = func;
}

void render::Material::runProgramFunc()
{
	if (_programFunc != nullptr && _shaderProgram != nullptr)
	{
		_programFunc(_shaderProgram);
	}
}

void render::Material::endUpdateShaderVertexValue(VertexArrayObject* data)
{
	for (auto item : _vertexAttribIndices)
	{
		auto pAttrib = _shaderProgram->getAttrib(item.second);
		if (!pAttrib) continue;
		VertexAttribPointer* pointer = data->getVertexAttrib<VertexAttribPointer>(pAttrib->getAttribID());
		if (pointer)
		{

			pointer->disableVertexArrayAttrib();
		}
	}
}

void render::Material::endUpdateShaderUniformValue()
{
	ShaderProgram::useNone();

	GLDebug::showError();
}

void Material::addTexture(const std::string& name, const Texture2D* id)
{
	if (id == nullptr)
	{
		return;
	}
	this->removeTexture(name);

	Texture2D* pid = (Texture2D*)id;
	SAFE_RETAIN(pid);

	_textures[name] = pid;
}

void Material::removeTexture(const std::string& name)
{
	auto it = _textures.find(name);
	if (it == _textures.end())
	{
		return;
	}

	SAFE_RELEASE(it->second);

	_textures.erase(it);
}

void Material::removeAllTextures()
{
	for (auto item : _textures)
	{
		SAFE_RELEASE(item.second);
	}
	_textures.clear();
}

int Material::getTexture(const std::string& name) const
{
	auto it = _textures.find(name);
	if (it == _textures.end())
	{
		return 0;
	}

	return it->second->getTextureID();
}

Texture2D* Material::createTexture(const std::string& strFullpath)
{
	if (strFullpath.empty())
	{
		return nullptr;
	}
	Texture2D* pTexture = G_TEXTURE_CACHE->createTexture2D(strFullpath);
	return pTexture;
}