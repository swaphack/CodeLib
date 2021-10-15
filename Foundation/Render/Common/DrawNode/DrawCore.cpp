#include "DrawCore.h"

#include "Common/Shader/import.h"
#include "Common/DrawNode/DrawNode.h"
#include "Common/DrawNode/MultiDrawNode.h"
#include "Graphic/import.h"
#include "Common/VAO/import.h"
#include "Common/Buffer/import.h"
#include "Common/Scene/Camera.h"
#include "Common/Scene/Cameras.h"
#include "Common/Mesh/import.h"
#include "Common/Texture/import.h"
#include "3d/Environment/import.h"
#include "Common/DrawNode/DrawTextureCache.h"
#include "system.h"
#include "Common/Material/import.h"
#include "2d/Primitive/PrimitiveNode.h"
#include "macros.h"

render::DrawCore::DrawCore()
{
}

render::DrawCore::~DrawCore()
{
}

void render::DrawCore::render(DrawNode* node)
{
	if (node == nullptr) return;

	auto drawParameter = node->getDrawParameter();

	render(drawParameter);
}

void render::DrawCore::render(MultiDrawNode* node)
{
	if (node == nullptr) return;
	auto pMeshes = node->getMeshes();
	for (auto item : pMeshes->getMeshes())
	{
		auto drawParameter = node->getDrawParameter(item.first);
		render(drawParameter);
	}

	GLDebug::showError();
}

void render::DrawCore::render(DrawParameter* parameter)
{
	if (parameter == nullptr) return;

	auto program = parameter->program;
	auto mesh = parameter->mesh;
	if (mesh == nullptr) return;
	this->setTempMatrix(mesh->getMeshDetail()->getMatrix());
	if (program != nullptr)
	{
		this->beginApplyWithShader(parameter);

		DrawMode mode = mesh->getDrawMode();
		if (parameter->tessilation)
		{
			auto pro = dynamic_cast<TessilationProtocol*>(parameter->node);
			if (pro)
			{
				pro->updateTessilation();
				mesh->setDrawMode(DrawMode::PATCHES);
			}
		}

		GLDebug::showError();
		this->increaseDrawCall();
		mesh->drawWithBufferObject();

		if (parameter->tessilation)
		{
			mesh->setDrawMode(mode);
		}
		GLDebug::showError();
		this->endApplyWithShader(parameter);
	}
	else
	{
		this->beginApply(parameter);

		GLDebug::showError();
		mesh->drawWithClientArray();

		GLDebug::showError();
		this->endApply(parameter);
	}
	this->resetTempMatrix();
	GLDebug::showError();
}

void render::DrawCore::beginApply(DrawParameter* drawParameter)
{
	if (drawParameter == nullptr || drawParameter->material == nullptr || drawParameter->textureCache == nullptr)
	{
		return;
	}
	drawParameter->material->applyMaterial();

	const auto pDetail = drawParameter->material->getMaterialDetail();
	if (pDetail == nullptr)
	{
		return;
	}
	auto pTexture = drawParameter->textureCache->getTexture(pDetail->getAmbientTextureMap());
	if (pTexture)
	{
		pTexture->enableTexture(0);
	}
}

void render::DrawCore::endApply(DrawParameter* drawParameter)
{
	if (drawParameter == nullptr || drawParameter->material == nullptr || drawParameter->textureCache == nullptr)
	{
		return;
	}
	const auto pDetail = drawParameter->material->getMaterialDetail();
	if (pDetail == nullptr)
	{
		return;
	}
	auto pTexture = drawParameter->textureCache->getTexture(pDetail->getAmbientTextureMap());
	if (pTexture)
	{
		pTexture->unbindTexture();
	}
}

void render::DrawCore::beginApplyWithShader(DrawParameter* drawParameter)
{
	if (drawParameter == nullptr || drawParameter->program == nullptr || drawParameter->material == nullptr)
	{
		return;
	}

	drawParameter->program->use();
	GLDebug::showError();
	this->startUpdateShaderUniformValue(drawParameter);
	GLDebug::showError();
	this->startUpdateShaderVertexValue(drawParameter);
	GLDebug::showError();
	drawParameter->material->runProgramFunc();
	GLDebug::showError();
}

void render::DrawCore::endApplyWithShader(DrawParameter* drawParameter)
{
	this->endUpdateShaderUniformValue(drawParameter);
	this->endUpdateShaderVertexValue(drawParameter);

	if (drawParameter->program)
	{
		drawParameter->program->unuse();
	}
}

void render::DrawCore::startUpdateShaderUniformValue(const DrawParameter* parameter)
{
	updateEnvUniformVallue(parameter);
	updateMatrixUniformValue(parameter);

	applyLightShader(parameter);

	updateMaterialUniformValue(parameter);
	updateTexturesUnifromValue(parameter);

	updateSelfDefinedUniformValue(parameter);
}

void render::DrawCore::startUpdateShaderVertexValue(const DrawParameter* parameter)
{
	if (parameter == nullptr || parameter->mesh == nullptr || parameter->program == nullptr
		|| parameter->material == nullptr || parameter->material->getMaterialSetting() == nullptr)
	{
		return;
	}

	auto detail = parameter->mesh->getMeshDetail();
	auto vao = parameter->mesh->getVertexArrayObject();
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
	const sys::MeshMemoryData& modelMatrices = parameter->mesh->getModelMatrices();

	uint32_t nVerticeSize = vertices.getSize();
	uint32_t nColorSize = colors.getSize();
	uint32_t nUVSize = texcoords.getSize();
	uint32_t nNormalSize = normals.getSize();
	uint32_t nTangentSize = tangents.getSize();
	uint32_t nBitangentSize = bitangents.getSize();
	uint32_t nModelMatricesSize = modelMatrices.getSize();

	auto program = parameter->program;

	int nOffset = 0;
	for (auto item : parameter->material->getMaterialSetting()->getAttribs())
	{
		if (item.first == VertexDataType::POSITION)
		{
			if (nVerticeSize == 0)
			{
				return;
			}
			program->bindAttribPointer(vao, item.second, 
				vertices.getUnitSize(), VertexAttribPointerType::FLOAT, nOffset);

			nOffset += nVerticeSize;
		}
		else if (item.first == VertexDataType::COLOR)
		{
			if (nColorSize == 0)
			{
				continue;
			}
			program->bindAttribPointer(vao, item.second,
				colors.getUnitSize(), VertexAttribPointerType::FLOAT, nOffset);
			nOffset += nColorSize;
		}
		else if (item.first == VertexDataType::UV)
		{
			if (nUVSize == 0)
			{
				continue;
			}
			program->bindAttribPointer(vao, item.second,
				texcoords.getUnitSize(), VertexAttribPointerType::FLOAT, nOffset);
			nOffset += nUVSize;
		}
		else if (item.first == VertexDataType::NORMAL)
		{
			if (nNormalSize == 0)
			{
				continue;
			}
			program->bindAttribPointer(vao, item.second,
				normals.getUnitSize(), VertexAttribPointerType::FLOAT, nOffset);
			nOffset += nNormalSize;
		}
		else if (item.first == VertexDataType::TANGENT)
		{
			if (nTangentSize == 0)
			{
				continue;
			}
			program->bindAttribPointer(vao, item.second,
				tangents.getUnitSize(), VertexAttribPointerType::FLOAT, nOffset);
			nOffset += nTangentSize;
		}
		else if (item.first == VertexDataType::BITANGENT)
		{
			if (nBitangentSize == 0)
			{
				continue;
			}
			program->bindAttribPointer(vao, item.second,
				bitangents.getUnitSize(), VertexAttribPointerType::FLOAT, nOffset);
			nOffset += nBitangentSize;
		}
		else if (item.first == VertexDataType::MODEL_MATRIX)
		{
			if (nModelMatricesSize == 0)
			{
				continue;
			}
			program->bindMat4AttribPointer(vao, item.second, nOffset);

			nOffset += nModelMatricesSize;
			/*
			glEnableVertexAttribArray(3);
			glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)0);
			glEnableVertexAttribArray(4);
			glVertexAttribPointer(4, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(sizeof(glm::vec4)));
			glEnableVertexAttribArray(5);
			glVertexAttribPointer(5, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(2 * sizeof(glm::vec4)));
			glEnableVertexAttribArray(6);
			glVertexAttribPointer(6, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(3 * sizeof(glm::vec4)));

			glVertexAttribDivisor(3, 1);
			glVertexAttribDivisor(4, 1);
			glVertexAttribDivisor(5, 1);
			glVertexAttribDivisor(6, 1);
			*/
		}
		GLDebug::showError();
	}

	GLDebug::showError();
}

void render::DrawCore::endUpdateShaderUniformValue(const DrawParameter* parameter)
{
	GLState::setLineWidth(1);
	releaseMaterialUniformValue(parameter);
	releaseTextureUniformValue(parameter);
}

void render::DrawCore::endUpdateShaderVertexValue(const DrawParameter* parameter)
{
	if (parameter == nullptr || parameter->mesh == nullptr || parameter->program == nullptr
		|| parameter->material == nullptr || parameter->material->getMaterialSetting() == nullptr)
	{
		return;
	}

	auto program = parameter->program;

	auto vao = parameter->mesh->getVertexArrayObject();
	for (auto item : parameter->material->getMaterialSetting()->getAttribs())
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

void render::DrawCore::updateEnvUniformVallue(const DrawParameter* parameter)
{
	if (parameter == nullptr || parameter->program == nullptr || parameter->node == nullptr
		|| parameter->material == nullptr || parameter->material->getMaterialSetting() == nullptr)
	{
		return;
	}
	auto pCamera = getCamera(parameter->node);
	if (pCamera == nullptr)
	{
		return;
	}
	auto pPrimitiveNode = parameter->node->as<PrimitiveNode>();
	if (pPrimitiveNode)
	{
		GLState::setLineWidth(pPrimitiveNode->getPointSize());
	}
	auto program = parameter->program;
	math::Vector3 viewPos = pCamera->getWorldMatrix().getPosition();
	for (auto item : parameter->material->getMaterialSetting()->getEnvUniforms())
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
			if (pPrimitiveNode)
			{
				pUniform->setValue(pPrimitiveNode->getPointSize());
			}
		}
	}
}

void render::DrawCore::updateMatrixUniformValue(const DrawParameter* parameter)
{
	if (parameter == nullptr || parameter->node == nullptr || parameter->program == nullptr
		|| parameter->material == nullptr || parameter->material->getMaterialSetting() == nullptr)
	{
		return;
	}

	auto program = parameter->program;

	auto pCamera = getCamera(parameter->node);
	if (pCamera == nullptr)
	{
		return;
	}

	math::Matrix4x4 projMat = pCamera->getProjectMatrix();
	math::Matrix4x4 viewMat = pCamera->getViewMatrix();
	math::Matrix4x4 modelMat = getWorldMatrix(parameter->node);

	math::Matrix3x3 normalMat = modelMat.getInverse().getTranspose();

	for (auto item : parameter->material->getMaterialSetting()->getMatrixUniforms())
	{
		auto pUniform = program->getUniform(item.second);
		if (!pUniform)
		{
			continue;
		}
		if (item.first == MatrixUniformType::PROJECT_MATRIX)
		{
			pUniform->setMatrix4x4(projMat);
		}
		else if (item.first == MatrixUniformType::VIEW_MATRIX)
		{
			pUniform->setMatrix4x4(viewMat);
		}
		else if (item.first == MatrixUniformType::MODEL_MATRIX)
		{
			pUniform->setMatrix4x4(modelMat);
		}
		else if (item.first == MatrixUniformType::NORMAL_MATRIX)
		{
			pUniform->setMatrix3x3(normalMat);
		}

		GLDebug::showError();
	}
}

void render::DrawCore::updateMaterialUniformValue(const DrawParameter* parameter)
{
	if (parameter == nullptr || parameter->node == nullptr || parameter->program == nullptr
		|| parameter->textureCache == nullptr
		|| parameter->material == nullptr || parameter->material->getMaterialSetting() == nullptr)
	{
		return;
	}

	const auto pDetail = parameter->material->getMaterialDetail();
	if (pDetail == nullptr)
	{
		return;
	}
	auto program = parameter->program;
	auto textureCache = parameter->textureCache;

	GLDebug::showError();
	for (auto item : parameter->material->getMaterialSetting()->getMaterialUniforms())
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
			if (pTexture == nullptr || !pTexture->isValid())
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
			if (pTexture == nullptr || !pTexture->isValid())
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
			if (pTexture == nullptr || !pTexture->isValid())
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
			if (pTexture == nullptr || !pTexture->isValid())
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
			if (pTexture == nullptr || !pTexture->isValid())
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
			if (pTexture == nullptr || !pTexture->isValid())
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
			if (pTexture == nullptr || !pTexture->isValid())
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

void render::DrawCore::updateTexturesUnifromValue(const DrawParameter* parameter)
{
	if (parameter->program == nullptr
		|| parameter->textureCache == nullptr
		|| parameter->material == nullptr || parameter->material->getMaterialSetting() == nullptr)
	{
		return;
	}

	const auto pDetail = parameter->material->getMaterialDetail();
	if (pDetail == nullptr)
	{
		return;
	}
	auto program = parameter->program;
	auto textureCache = parameter->textureCache;

	for (auto item : parameter->material->getMaterialSetting()->getTextureUniforms())
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
		TextureUniformType textureID = item.first;
		if (textureID == TextureUniformType::TEXTURE0)
		{
			auto pTexture = textureCache->getTexture(pDetail->getAmbientTextureMap());
			if (pTexture == nullptr || !pTexture->isValid())
			{
				pTexture = Texture2D::getEmptyTexture();
			}
			if (pTexture)
			{
				pTexture->activeTexture(ActiveTextureName::TEXTURE0);
				pTexture->bindTexture();
				pTexture->enableTextureWithSampler((int)textureID);
				pUniform->setValue((int)textureID);
			}
		}
		else if (textureID == TextureUniformType::TEXTURE1)
		{
			auto pTexture = textureCache->getTexture(pDetail->getDiffuseTextureMap());
			if (pTexture == nullptr || !pTexture->isValid())
			{
				pTexture = Texture2D::getEmptyTexture();
			}
			if (pTexture)
			{
				pTexture->activeTexture(ActiveTextureName::TEXTURE1);
				pTexture->bindTexture();
				pTexture->enableTextureWithSampler((int)textureID);
				pUniform->setValue((int)textureID);
			}

			GLDebug::showError();
		}
		else if (textureID == TextureUniformType::TEXTURE2)
		{
			auto pTexture = textureCache->getTexture(pDetail->getSpecularTextureMap());
			if (pTexture == nullptr || !pTexture->isValid())
			{
				pTexture = Texture2D::getEmptyTexture();
			}
			if (pTexture)
			{
				pTexture->activeTexture(ActiveTextureName::TEXTURE2);
				pTexture->bindTexture();
				pTexture->enableTextureWithSampler((int)textureID);
				pUniform->setValue((int)textureID);
			}
		}
		else if (textureID == TextureUniformType::TEXTURE3)
		{
			auto pTexture = textureCache->getTexture(pDetail->getAlphaTextureMap());
			if (pTexture == nullptr || !pTexture->isValid())
			{
				pTexture = Texture2D::getEmptyTexture();
			}
			if (pTexture)
			{
				pTexture->activeTexture(ActiveTextureName::TEXTURE3);
				pTexture->bindTexture();
				pTexture->enableTextureWithSampler((int)textureID);
				pUniform->setValue((int)textureID);
			}
		}
		else if (textureID == TextureUniformType::TEXTURE4)
		{
			auto pTexture = textureCache->getTexture(pDetail->getBumpTextureMap());
			if (pTexture == nullptr || !pTexture->isValid())
			{
				pTexture = Texture2D::getEmptyTexture();
			}
			if (pTexture)
			{
				pTexture->activeTexture(ActiveTextureName::TEXTURE4);
				pTexture->bindTexture();
				pTexture->enableTextureWithSampler((int)textureID);
				pUniform->setValue((int)textureID);
			}
		}
		else if (textureID == TextureUniformType::TEXTURE5)
		{
			auto pTexture = textureCache->getTexture(pDetail->getNormalTextureMap());
			if (pTexture == nullptr || !pTexture->isValid())
			{
				pTexture = Texture2D::getEmptyTexture();
			}
			if (pTexture)
			{
				pTexture->activeTexture(ActiveTextureName::TEXTURE5);
				pTexture->bindTexture();
				pTexture->enableTextureWithSampler((int)textureID);
				pUniform->setValue((int)textureID);
			}
		}
		else if (textureID == TextureUniformType::TEXTURE6)
		{
			auto pTexture = textureCache->getTexture(pDetail->getShadowTextureMap());
			if (pTexture == nullptr || !pTexture->isValid())
			{
				pTexture = Texture2D::getEmptyTexture();
			}
			if (pTexture)
			{
				pTexture->activeTexture(ActiveTextureName::TEXTURE6);
				pTexture->bindTexture();
				pTexture->enableTextureWithSampler((int)textureID);
				pUniform->setValue((int)textureID);
			}
		}
	}
}

void render::DrawCore::releaseMaterialUniformValue(const DrawParameter* parameter)
{
	if (parameter == nullptr || parameter->program == nullptr
		|| parameter->textureCache == nullptr
		|| parameter->material == nullptr || parameter->material->getMaterialSetting() == nullptr)
	{
		return;
	}

	const auto pDetail = parameter->material->getMaterialDetail();
	if (pDetail == nullptr)
	{
		return;
	}
	auto program = parameter->program;
	auto textureCache = parameter->textureCache;
	for (auto item : parameter->material->getMaterialSetting()->getMaterialUniforms())
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

void render::DrawCore::releaseTextureUniformValue(const DrawParameter* parameter)
{
	if (parameter == nullptr || parameter->program == nullptr
		|| parameter->textureCache == nullptr
		|| parameter->material == nullptr || parameter->material->getMaterialSetting() == nullptr)
	{
		return;
	}

	const auto pDetail = parameter->material->getMaterialDetail();
	if (pDetail == nullptr)
	{
		return;
	}
	auto program = parameter->program;
	auto textureCache = parameter->textureCache;
	for (auto item : parameter->material->getMaterialSetting()->getTextureUniforms())
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


void render::DrawCore::applyLightShader(const DrawParameter* parameter)
{
	if (parameter == nullptr || parameter->node == nullptr) return;

	LightProtocol* pLight = parameter->node->as<LightProtocol>();
	if (pLight == nullptr)
	{
		return;
	}

	if (pLight->isSupportedLight())
	{
		if (pLight->isSupportedMultiLight())
		{
			updateAllLightsUniformValue(parameter);
		}
		else
		{
			updateNearestLightUniformValue(parameter);
		}
	}
}

void render::DrawCore::updateNearestLightUniformValue(const DrawParameter* parameter)
{
	if (parameter == nullptr || parameter->node == nullptr || parameter->program == nullptr
		|| parameter->material == nullptr || parameter->material->getMaterialSetting() == nullptr)
	{
		return;
	}

	if (!G_ENVIRONMENT->hasLight())
	{
		return;
	}

	auto pCamera = getCamera(parameter->node);
	if (pCamera == nullptr)
	{
		return;
	}

	math::Vector3 nodePos = getWorldMatrix(parameter->node).getPosition();
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
	const math::Matrix4x4& viewMat = pCamera->getViewMatrix();

	math::Vector3 viewPos = pCamera->getWorldMatrix().getPosition();
	math::Vector3 lightPos = pLight->getWorldMatrix().getPosition();

	math::Vector3 viewDirection = viewPos - nodePos;
	math::Vector3 lightDirection = lightPos - nodePos;
	math::Vector3 halfVector = lightDirection + viewDirection;
	halfVector.normalize();

	bool bSupportShadow = false;
	if (parameter->node->is<LightProtocol>())
	{
		bSupportShadow = parameter->node->as<LightProtocol>()->isCastShadow();
	}
	auto program = parameter->program;
	for (auto item : parameter->material->getMaterialSetting()->getSingleLightUniforms())
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
				math::Matrix4x4 lightProject = pCamera->getProjectMatrix();
				math::Vector3 center = lightPos + pLight->getFront();
				math::Matrix4x4 lightView = math::Matrix4x4::lookAt(lightPos, center, pLight->getUp());
				lightMatrix = lightProject * lightView;

				pUniform->setMatrix4x4(1, lightMatrix.getValue());
			}
		}
		GLDebug::showError();
	}
}

void render::DrawCore::updateAllLightsUniformValue(const DrawParameter* parameter)
{
	if (parameter == nullptr || parameter->node == nullptr || parameter->program == nullptr
		|| parameter->material == nullptr || parameter->material->getMaterialSetting() == nullptr)
	{
		return;
	}

	auto pCamera = getCamera(parameter->node);
	if (pCamera == nullptr)
	{
		return;
	}

	if (!G_ENVIRONMENT->hasLight())
	{
		return;
	}

	const auto& mapLights = G_ENVIRONMENT->getAllLights();

	const math::Matrix4x4& viewMat = pCamera->getViewMatrix();
	bool bSupportShadow = false;
	if (parameter->node->is<LightProtocol>())
	{
		bSupportShadow = parameter->node->as<LightProtocol>()->isCastShadow();
	}
	auto program = parameter->program;
	math::Vector3 viewPos = pCamera->getWorldMatrix().getPosition();
	for (auto light : mapLights)
	{
		auto pLight = light.second;
		int index = light.first;


		math::Vector3 lightPos = pLight->getWorldMatrix().getPosition();
		math::Vector3 nodePos = getWorldMatrix(parameter->node).getPosition();
		math::Vector3 viewDirection = viewPos - nodePos;
		math::Vector3 lightDirection = lightPos - nodePos;
		math::Vector3 halfVector = lightDirection + viewDirection;

		for (auto item : parameter->material->getMaterialSetting()->getMultiLightsUniforms())
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
					math::Matrix4x4 lightProject = pCamera->getProjectMatrix();
					math::Vector3 center = lightPos + pLight->getFront();
					math::Matrix4x4 lightView = math::Matrix4x4::lookAt(lightPos, center, pLight->getUp());
					lightMatrix = lightProject * lightView;
					pUniform->setMatrix4x4(1, lightMatrix.getValue());
				}
			}
			GLDebug::showError();
		}
		GLDebug::showError();
	}
}

void render::DrawCore::updateSelfDefinedUniformValue(const DrawParameter* parameter)
{
	if (parameter == nullptr || parameter->program == nullptr
		|| parameter->material == nullptr || parameter->material->getMaterialSetting() == nullptr)
	{
		return;
	}

	const auto pDetail = parameter->material->getMaterialDetail();
	if (pDetail == nullptr)
	{
		return;
	}
	auto program = parameter->program;
	for (auto item : parameter->material->getMaterialSetting()->getSelfDefinedUniforms())
	{
		auto pUniform = program->getUniform(item.first);
		if (!pUniform)
		{
			if (item.second.Type == MaterialSetting::UniformType::Integer)
			{
				pUniform->setValue(item.second.asInt());
			}
			else if (item.second.Type == MaterialSetting::UniformType::Float)
			{
				pUniform->setValue(item.second.asFloat());
			}
			else if (item.second.Type == MaterialSetting::UniformType::Vec2)
			{
				pUniform->setValue2(1, item.second.asVector2().getValue());
			}
			else if (item.second.Type == MaterialSetting::UniformType::Vec3)
			{
				pUniform->setValue3(1, item.second.asVector3().getValue());
			}
			else if (item.second.Type == MaterialSetting::UniformType::Vec4)
			{
				pUniform->setValue4(1, item.second.asVector4().getValue());
			}
			else if (item.second.Type == MaterialSetting::UniformType::Mat2x2)
			{
				pUniform->setMatrix2x2(item.second.asMatrix2x2().getValue());
			}
			else if (item.second.Type == MaterialSetting::UniformType::Mat3x3)
			{
				pUniform->setMatrix3x3(item.second.asMatrix3x3().getValue());
			}
			else if (item.second.Type == MaterialSetting::UniformType::Mat4x4)
			{
				pUniform->setMatrix4x4(4, item.second.asMatrix4x4().getValue());
			}
		}
	}
}

void render::DrawCore::setTempMatrix(const math::Matrix4x4& matrix)
{
	_tempMatrix = matrix;
}

void render::DrawCore::resetTempMatrix()
{
	_tempMatrix.loadIdentity();
}

math::Matrix4x4 render::DrawCore::getWorldMatrix(const Node* node)
{
	if (node == nullptr)
	{
		return math::Matrix4x4();
	}

	return _tempMatrix * node->getWorldMatrix();
}

render::Camera* render::DrawCore::getCamera(const Node* node)
{
	if (node == nullptr)
	{
		return nullptr;
	}
	return node->getCamera();
}

void render::DrawCore::beginRecordDrawCall()
{
	_drawCallCount = 0;
	_undrawCallCount = 0;
}

void render::DrawCore::increaseDrawCall()
{
	_drawCallCount++;
}

void render::DrawCore::increaseUnDrawCall()
{
	_undrawCallCount++;
}

void render::DrawCore::endRecordDrawCall()
{
	_oneDrawCallCount = _drawCallCount;
	_oneUnDrawCallCount = _undrawCallCount;
}

int render::DrawCore::getDrawCallCount()
{
	return _oneDrawCallCount;
}

int render::DrawCore::getUnDrawCallCount()
{
	return _oneUnDrawCallCount;
}

void render::DrawCore::addDrawParameter(DrawParameter* parameter)
{
	if (parameter == nullptr)
	{
		return;
	}

	bool bFind = false;
	for (auto& item : _batchDrawParameters)
	{
		if (isSameObject(item.root, parameter))
		{
			item.parameters.push_back(parameter);
			bFind = true;
			break;
		}
	}

	if (!bFind)
	{
		_batchDrawParameters.push_back(BatchDrawParameter(parameter));
	}

	bFind = false;
	for (auto& item : _packDrawParameters)
	{
		if (isSameMaterial(item.root, parameter))
		{
			item.parameters.push_back(parameter);
			bFind = true;
			break;
		}
	}
	if (!bFind)
	{
		_packDrawParameters.push_back(BatchDrawParameter(parameter));
	}
}

void render::DrawCore::removeAllDrawParameters()
{
	_batchDrawParameters.clear();
	_packDrawParameters.clear();
}

void render::DrawCore::batch()
{
	int unitSize = sizeof(float);
	size_t matrixSize = 16 * sizeof(float);
	for (auto& item : _batchDrawParameters)
	{
		int count = item.parameters.size();
		auto root = item.root;
		float* ptr = (float*)root->mesh->createModelMatrices(count, unitSize, 16);
		for (int i = 0; i < count; i++)
		{
			auto node = item.parameters[i]->node;
			memcpy(ptr + i * 16, node->getWorldMatrix().getValue(), matrixSize);
			node->setSkipDraw(true);
		}
		root->mesh->forceUpdateMeshData();
		root->node->setSkipDraw(false);
	}
	/*
	for (auto& item : _packDrawParameters)
	{
		int count = item.parameters.size();
		if (count == 1) continue;

		auto root = item.root;
		float* ptr = (float*)root->mesh->createModelMatrices(count, unitSize, 16);
		for (int i = 0; i < count; i++)
		{
			auto node = item.parameters[i]->node;
			memcpy(ptr + i * 16, node->getWorldMatrix().getValue(), matrixSize);
			node->setSkipDraw(true);
		}
		root->mesh->forceUpdateMeshData();
		root->node->setSkipDraw(false);
	}
	*/
}

void render::DrawCore::drawBatch()
{

}

void render::DrawCore::unbatch()
{
	int unitSize = sizeof(float);
	int matrixSize = 16 * sizeof(float);
	for (auto& item : _batchDrawParameters)
	{
		int count = item.parameters.size();
		auto root = item.root;

		root->mesh->createModelMatrices(0, 0, 0);
		root->mesh->forceUpdateMeshData();

		if (count == 1) continue;
		
		for (int i = 0; i < count; i++)
		{
			auto node = item.parameters[i]->node;
			node->setSkipDraw(false);
		}
	}

	this->removeAllDrawParameters();
}

bool render::DrawCore::isSameObject(DrawParameter* a, DrawParameter* b)
{
	if (a == nullptr || b == nullptr) return false;

	if (a->tessilation != b->tessilation) return false;
	if (!a->material->equals(*b->material)) return false;
	if (!a->mesh->equals(*b->mesh)) return false;

	return true;
}

bool render::DrawCore::isSameMaterial(DrawParameter* a, DrawParameter* b)
{
	if (a == nullptr || b == nullptr) return false;

	if (a->tessilation != b->tessilation) return false;
	if (!a->material->equals(*b->material)) return false;

	return true;
}
