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
#include <list>

//#define UPDATE_NODE_COUNT 100

render::DrawCore::DrawCore()
{
}

render::DrawCore::~DrawCore()
{
	removeAllDrawParameters();
}

void render::DrawCore::setDrawType(DrawType type)
{
	_drawType = type;
}

render::DrawCore::DrawType render::DrawCore::getDrawType() const
{
	return _drawType;
}

void render::DrawCore::setDebugDrawMode(DrawMode mode)
{
	_debugDrawMode = mode;
}

DrawMode render::DrawCore::getDebugDrawMode() const
{
	return _debugDrawMode;
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
	for (const auto& item : pMeshes->getMeshes())
	{
		auto drawParameter = node->getDrawParameter(item.first);
		render(drawParameter);
	}

	GLDebug::showError();
}

void render::DrawCore::render(DrawParameter* parameter)
{
	if (parameter == nullptr || parameter->material == nullptr) return;

	auto program = parameter->material->getShaderProgram();
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
		this->addVertexCount(mesh->getMeshDetail()->getVertices().getVerticeCount());
		this->drawWithBufferObject(parameter);

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
		this->drawWithClientArray(parameter);

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
	if (drawParameter == nullptr || drawParameter->material == nullptr)
	{
		return;
	}
	if (drawParameter->material->getShaderProgram())
		drawParameter->material->getShaderProgram()->use();
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
	if (drawParameter == nullptr || drawParameter->material == nullptr)
	{
		return;
	}
	this->endUpdateShaderUniformValue(drawParameter);
	this->endUpdateShaderVertexValue(drawParameter);

	if (drawParameter->material->getShaderProgram())
		drawParameter->material->getShaderProgram()->unuse();
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
	if (parameter == nullptr || parameter->mesh == nullptr
		|| parameter->material == nullptr
		|| parameter->material->getMaterialSetting() == nullptr
		|| parameter->material->getShaderProgram() == nullptr)
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

	auto program = parameter->material->getShaderProgram();

	int nOffset = 0;
	for (const auto& item : parameter->material->getShaderProgram()->getShaderProperty()->getAttribs())
	{
		VertexDataType type = (VertexDataType)item.first;
		if (type == VertexDataType::POSITION)
		{
			if (nVerticeSize == 0)
			{
				return;
			}
			program->bindAttribPointer(vao, item.second,
				vertices.getUnitSize(), VertexAttribPointerType::FLOAT, nOffset);

			nOffset += nVerticeSize;
		}
		else if (type == VertexDataType::COLOR)
		{
			if (nColorSize == 0)
			{
				continue;
			}
			program->bindAttribPointer(vao, item.second,
				colors.getUnitSize(), VertexAttribPointerType::FLOAT, nOffset);
			nOffset += nColorSize;
		}
		else if (type == VertexDataType::UV)
		{
			if (nUVSize == 0)
			{
				continue;
			}
			program->bindAttribPointer(vao, item.second,
				texcoords.getUnitSize(), VertexAttribPointerType::FLOAT, nOffset);
			nOffset += nUVSize;
		}
		else if (type == VertexDataType::NORMAL)
		{
			if (nNormalSize == 0)
			{
				continue;
			}
			program->bindAttribPointer(vao, item.second,
				normals.getUnitSize(), VertexAttribPointerType::FLOAT, nOffset);
			nOffset += nNormalSize;
		}
		else if (type == VertexDataType::TANGENT)
		{
			if (nTangentSize == 0)
			{
				continue;
			}
			program->bindAttribPointer(vao, item.second,
				tangents.getUnitSize(), VertexAttribPointerType::FLOAT, nOffset);
			nOffset += nTangentSize;
		}
		else if (type == VertexDataType::BITANGENT)
		{
			if (nBitangentSize == 0)
			{
				continue;
			}
			program->bindAttribPointer(vao, item.second,
				bitangents.getUnitSize(), VertexAttribPointerType::FLOAT, nOffset);
			nOffset += nBitangentSize;
		}
		else if (type == VertexDataType::MODEL_MATRIX)
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
	if (parameter == nullptr || parameter->mesh == nullptr
		|| parameter->material == nullptr
		|| parameter->material->getShaderProgram() == nullptr
		|| parameter->material->getMaterialSetting() == nullptr)
	{
		return;
	}

	auto program = parameter->material->getShaderProgram();

	auto vao = parameter->mesh->getVertexArrayObject();
	for (const auto& item : parameter->material->getShaderProgram()->getShaderProperty()->getAttribs())
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
	if (parameter == nullptr
		|| parameter->node == nullptr
		|| parameter->material == nullptr
		|| parameter->material->getMaterialSetting() == nullptr
		|| parameter->material->getShaderProgram() == nullptr)
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
	auto program = parameter->material->getShaderProgram();
	math::Vector3 viewPos = pCamera->getWorldMatrix().getPosition();
	for (const auto& item : parameter->material->getShaderProgram()->getShaderProperty()->getEnvUniforms())
	{
		auto pUniform = program->getUniform(item.second);
		if (!pUniform)
		{
			continue;
		}
		EnvUniformType type = (EnvUniformType)item.first;
		if (type == EnvUniformType::VIEW_POSITION)
		{
			pUniform->setValue3(1, viewPos.getValue());
		}
		else if (type == EnvUniformType::LIGHT_COUNT)
		{
			pUniform->setValue((int)G_ENVIRONMENT->getAllLights().size());
		}
		else if (type == EnvUniformType::GAMMA)
		{
			pUniform->setValue(G_ENVIRONMENT->getGamma());
		}
		else if (type == EnvUniformType::POINT_SIZE)
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
	if (parameter == nullptr
		|| parameter->node == nullptr
		|| parameter->material == nullptr
		|| parameter->material->getMaterialSetting() == nullptr
		|| parameter->material->getShaderProgram() == nullptr)
	{
		return;
	}

	auto program = parameter->material->getShaderProgram();

	auto pCamera = getCamera(parameter->node);
	if (pCamera == nullptr)
	{
		return;
	}

	math::Matrix4x4 projMat = pCamera->getProjectMatrix();
	math::Matrix4x4 viewMat = pCamera->getViewMatrix();
	math::Matrix4x4 modelMat = getWorldMatrix(parameter->node);

	math::Matrix3x3 normalMat = modelMat.getInverse().getTranspose();

	for (const auto& item : parameter->material->getShaderProgram()->getShaderProperty()->getMatrixUniforms())
	{
		auto pUniform = program->getUniform(item.second);
		if (!pUniform)
		{
			continue;
		}
		MatrixUniformType type = (MatrixUniformType)item.first;
		if (type == MatrixUniformType::PROJECT_MATRIX)
		{
			pUniform->setMatrix4x4(projMat);
		}
		else if (type == MatrixUniformType::VIEW_MATRIX)
		{
			pUniform->setMatrix4x4(viewMat);
		}
		else if (type == MatrixUniformType::MODEL_MATRIX)
		{
			pUniform->setMatrix4x4(modelMat);
		}
		else if (type == MatrixUniformType::NORMAL_MATRIX)
		{
			pUniform->setMatrix3x3(normalMat);
		}

		GLDebug::showError();
	}
}

void render::DrawCore::updateMaterialUniformValue(const DrawParameter* parameter)
{
	if (parameter == nullptr
		|| parameter->node == nullptr
		|| parameter->textureCache == nullptr
		|| parameter->material == nullptr
		|| parameter->material->getMaterialSetting() == nullptr
		|| parameter->material->getShaderProgram() == nullptr)
	{
		return;
	}

	const auto pDetail = parameter->material->getMaterialDetail();
	if (pDetail == nullptr)
	{
		return;
	}
	auto program = parameter->material->getShaderProgram();
	auto textureCache = parameter->textureCache;

	GLDebug::showError();
	for (const auto& item : parameter->material->getShaderProgram()->getShaderProperty()->getMaterialUniforms())
	{
		auto pUniform = program->getUniform(item.second);
		if (!pUniform)
		{
			continue;
		}
		MaterialUniformType type = (MaterialUniformType)item.first;
		if (type == MaterialUniformType::MATERIAL_EMISSION)
		{
			pUniform->setValue4(1, pDetail->getEmission());
		}
		else if (type == MaterialUniformType::MATERIAL_COLOR_AMBIENT)
		{
			pUniform->setValue4(1, pDetail->getAmbient());
		}
		else if (type == MaterialUniformType::MATERIAL_COLOR_DIFFUSE)
		{
			pUniform->setValue4(1, pDetail->getDiffuse());
		}
		else if (type == MaterialUniformType::MATERIAL_COLOR_SPECULAR)
		{
			pUniform->setValue4(1, pDetail->getSpecular());
		}
		else if (type == MaterialUniformType::MATERIAL_TEXTURE)
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
		else if (type == MaterialUniformType::MATERIAL_TEXTURE_DIFFUSE)
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
		else if (type == MaterialUniformType::MATERIAL_TEXTURE_SPECULAR)
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
		else if (type == MaterialUniformType::MATERIAL_TEXTURE_ALPHA)
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
		else if (type == MaterialUniformType::MATERIAL_TEXTURE_BUMP)
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
		else if (type == MaterialUniformType::MATERIAL_TEXTURE_NORMAL)
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
		else if (type == MaterialUniformType::MATERIAL_TEXTURE_SHADOW)
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
		else if (type == MaterialUniformType::MATERIAL_SHININESS)
		{
			pUniform->setValue(pDetail->getSpecularShiness());
		}
		else if (type == MaterialUniformType::MATERIAL_STRENGTH)
		{
			pUniform->setValue(pDetail->getSpecularStrength());
		}
	}
}

void render::DrawCore::updateTexturesUnifromValue(const DrawParameter* parameter)
{
	if (parameter == nullptr
		|| parameter->textureCache == nullptr
		|| parameter->material == nullptr
		|| parameter->material->getMaterialSetting() == nullptr
		|| parameter->material->getShaderProgram() == nullptr)
	{
		return;
	}

	const auto pDetail = parameter->material->getMaterialDetail();
	if (pDetail == nullptr)
	{
		return;
	}
	auto program = parameter->material->getShaderProgram();
	auto textureCache = parameter->textureCache;

	for (const auto& item : parameter->material->getShaderProgram()->getShaderProperty()->getTextureUniforms())
	{
		auto pUniform = program->getUniform(item.second);
		TextureUniformType textureID = (TextureUniformType)item.first;
		if (!pUniform)
		{
			if (textureID == TextureUniformType::TEXTURE0)
			{
				return;
			}
			else
			{
				continue;
			}
		}
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
	if (parameter == nullptr
		|| parameter->textureCache == nullptr
		|| parameter->material == nullptr
		|| parameter->material->getMaterialSetting() == nullptr
		|| parameter->material->getShaderProgram() == nullptr)
	{
		return;
	}

	const auto pDetail = parameter->material->getMaterialDetail();
	if (pDetail == nullptr)
	{
		return;
	}
	auto program = parameter->material->getShaderProgram();
	auto textureCache = parameter->textureCache;
	for (const auto& item : parameter->material->getShaderProgram()->getShaderProperty()->getMaterialUniforms())
	{
		auto pUniform = program->getUniform(item.second);
		if (!pUniform)
		{
			continue;
		}
		MaterialUniformType type = (MaterialUniformType)item.first;
		if (type == MaterialUniformType::MATERIAL_TEXTURE)
		{
			auto pTexture = textureCache->getTexture(pDetail->getAmbientTextureMap());
			if (pTexture)
			{
				pTexture->unbindTexture();
				GLState::disable((EnableMode)pTexture->getTextureTarget());
			}

			GLDebug::showError();
		}
		else if (type == MaterialUniformType::MATERIAL_TEXTURE_DIFFUSE)
		{
			auto pTexture = textureCache->getTexture(pDetail->getDiffuseTextureMap());
			if (pTexture)
			{
				pTexture->unbindTexture();
				GLState::disable((EnableMode)pTexture->getTextureTarget());
			}

			GLDebug::showError();
		}
		else if (type == MaterialUniformType::MATERIAL_TEXTURE_SPECULAR)
		{
			auto pTexture = textureCache->getTexture(pDetail->getSpecularTextureMap());
			if (pTexture)
			{
				pTexture->unbindTexture();
				GLState::disable((EnableMode)pTexture->getTextureTarget());
			}
			GLDebug::showError();
		}
		else if (type == MaterialUniformType::MATERIAL_TEXTURE_ALPHA)
		{
			auto pTexture = textureCache->getTexture(pDetail->getAlphaTextureMap());
			if (pTexture)
			{
				pTexture->unbindTexture();
				GLState::disable((EnableMode)pTexture->getTextureTarget());
			}
			GLDebug::showError();
		}
		else if (type == MaterialUniformType::MATERIAL_TEXTURE_BUMP)
		{
			auto pTexture = textureCache->getTexture(pDetail->getBumpTextureMap());
			if (pTexture)
			{
				pTexture->unbindTexture();
				GLState::disable((EnableMode)pTexture->getTextureTarget());
			}
			GLDebug::showError();
		}
		else if (type == MaterialUniformType::MATERIAL_TEXTURE_NORMAL)
		{
			auto pTexture = textureCache->getTexture(pDetail->getNormalTextureMap());
			if (pTexture)
			{
				pTexture->unbindTexture();
				GLState::disable((EnableMode)pTexture->getTextureTarget());
			}
			GLDebug::showError();
		}
		else if (type == MaterialUniformType::MATERIAL_TEXTURE_SHADOW)
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
	if (parameter == nullptr
		|| parameter->textureCache == nullptr
		|| parameter->material == nullptr
		|| parameter->material->getMaterialSetting() == nullptr
		|| parameter->material->getShaderProgram() == nullptr)
	{
		return;
	}

	const auto pDetail = parameter->material->getMaterialDetail();
	if (pDetail == nullptr)
	{
		return;
	}
	auto program = parameter->material->getShaderProgram();
	auto textureCache = parameter->textureCache;
	for (const auto& item : parameter->material->getShaderProgram()->getShaderProperty()->getTextureUniforms())
	{
		auto pUniform = program->getUniform(item.second);
		if (!pUniform)
		{
			continue;
		}
		TextureUniformType type = (TextureUniformType)item.first;
		if (type == TextureUniformType::TEXTURE0)
		{
			auto pTexture = textureCache->getTexture(pDetail->getAmbientTextureMap());
			if (pTexture)
			{
				pTexture->unbindTexture();
				GLState::disable((EnableMode)pTexture->getTextureTarget());
			}

			GLDebug::showError();
		}
		else if (type == TextureUniformType::TEXTURE1)
		{
			auto pTexture = textureCache->getTexture(pDetail->getDiffuseTextureMap());
			if (pTexture)
			{
				pTexture->unbindTexture();
				GLState::disable((EnableMode)pTexture->getTextureTarget());
			}

			GLDebug::showError();
		}
		else if (type == TextureUniformType::TEXTURE2)
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
	if (parameter == nullptr
		|| parameter->node == nullptr
		|| parameter->material == nullptr
		|| parameter->material->getMaterialSetting() == nullptr
		|| parameter->material->getShaderProgram() == nullptr)
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
	for (const auto& item : lights)
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
	auto program = parameter->material->getShaderProgram();
	for (const auto& item : parameter->material->getShaderProgram()->getShaderProperty()->getSingleLightUniforms())
	{
		auto pUniform = program->getUniform(item.second);
		if (!pUniform)
		{
			continue;
		}
		SingleLightUniformType type = (SingleLightUniformType)item.first;
		if (type == SingleLightUniformType::LIGHT_ENABLED)
		{
			pUniform->setValue(1);
		}
		else if (type == SingleLightUniformType::LIGHT_LOCAL)
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
		else if (type == SingleLightUniformType::LIGHT_SPOT)
		{
			pUniform->setValue(pLight->is<SpotLight>() ? 1 : 0);
		}
		else if (type == SingleLightUniformType::LIGHT_POSITION)
		{
			pUniform->setValue3(1, lightPos.getValue());
		}
		else if (type == SingleLightUniformType::LIGHT_DIRECTION)
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
		else if (type == SingleLightUniformType::LIGHT_HALF_VECTOR)
		{
			pUniform->setValue3(1, halfVector.getValue());
		}
		else if (type == SingleLightUniformType::LIGHT_COLOR)
		{
			pUniform->setValue4(1, pLight->getColor());
		}
		else if (type == SingleLightUniformType::LIGHT_AMBIENT)
		{
			pUniform->setValue4(1, pLight->getAmbient());
		}
		else if (type == SingleLightUniformType::LIGHT_SPOT_EXPONENT)
		{
			auto pSpotLight = pLight->as<SpotLight>();
			if (pSpotLight)
			{
				pUniform->setValue(pSpotLight->getExponent());
			}
		}
		else if (type == SingleLightUniformType::LIGHT_SPOT_COST_CUTOFF)
		{
			auto pSpotLight = pLight->as<SpotLight>();
			if (pSpotLight)
			{
				pUniform->setValue(pSpotLight->getCutOff());
			}
		}
		else if (type == SingleLightUniformType::LIGHT_CONSTANT_ATTENUATION)
		{
			auto pPointLight = pLight->as<PointLight>();
			if (pPointLight)
			{
				pUniform->setValue(pPointLight->getConstantAttenuation());
			}
		}
		else if (type == SingleLightUniformType::LIGHT_LINEAR_ATTENUATION)
		{
			auto pPointLight = pLight->as<PointLight>();
			if (pPointLight)
			{
				pUniform->setValue(pPointLight->getLinearAttenuation());
			}
		}
		else if (type == SingleLightUniformType::LIGHT_QUADRATIC_ATTENUATION)
		{
			auto pPointLight = pLight->as<PointLight>();
			if (pPointLight)
			{
				pUniform->setValue(pPointLight->getQuadraticAttenuation());
			}
		}
		else if (type == SingleLightUniformType::LIGHT_SPACE_MATRIX)
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
	if (parameter == nullptr
		|| parameter->node == nullptr
		|| parameter->material == nullptr
		|| parameter->material->getMaterialSetting() == nullptr
		|| parameter->material->getShaderProgram() == nullptr)
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
	auto program = parameter->material->getShaderProgram();
	math::Vector3 viewPos = pCamera->getWorldMatrix().getPosition();
	for (const auto& light : mapLights)
	{
		auto pLight = light.second;
		int index = light.first;


		math::Vector3 lightPos = pLight->getWorldMatrix().getPosition();
		math::Vector3 nodePos = getWorldMatrix(parameter->node).getPosition();
		math::Vector3 viewDirection = viewPos - nodePos;
		math::Vector3 lightDirection = lightPos - nodePos;
		math::Vector3 halfVector = lightDirection + viewDirection;

		for (const auto& item : parameter->material->getShaderProgram()->getShaderProperty()->getMultiLightsUniforms())
		{
			std::string text = getCString(item.second.c_str(), index);
			auto pUniform = program->getUniform(text);
			MultiLightsUniformType type = (MultiLightsUniformType)item.first;
			if (!pUniform)
			{
				continue;
			}
			else if (type == MultiLightsUniformType::MULTI_LIGHT_ENABLED)
			{
				pUniform->setValue(1);
			}
			else if (type == MultiLightsUniformType::MULTI_LIGHT_LOCAL)
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
			else if (type == MultiLightsUniformType::MULTI_LIGHT_SPOT)
			{
				pUniform->setValue(pLight->is<SpotLight>() ? 1 : 0);
			}
			else if (type == MultiLightsUniformType::MULTI_LIGHT_POSITION)
			{
				pUniform->setValue3(1, lightPos.getValue());
			}
			else if (type == MultiLightsUniformType::MULTI_LIGHT_DIRECTION)
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
			else if (type == MultiLightsUniformType::MULTI_LIGHT_HALF_VECTOR)
			{
				pUniform->setValue3(1, halfVector.getValue());
			}
			else if (type == MultiLightsUniformType::MULTI_LIGHT_COLOR)
			{
				pUniform->setValue4(1, pLight->getColor());
			}
			else if (type == MultiLightsUniformType::MULTI_LIGHT_AMBIENT)
			{
				pUniform->setValue4(1, pLight->getAmbient());
			}
			else if (type == MultiLightsUniformType::MULTI_LIGHT_SPOT_EXPONENT)
			{
				auto pSpotLight = pLight->as<SpotLight>();
				if (pSpotLight)
				{
					pUniform->setValue(pSpotLight->getExponent());
				}
			}
			else if (type == MultiLightsUniformType::MULTI_LIGHT_SPOT_COST_CUTOFF)
			{
				auto pSpotLight = pLight->as<SpotLight>();
				if (pSpotLight)
				{
					pUniform->setValue(pSpotLight->getCutOff());
				}
			}
			else if (type == MultiLightsUniformType::MULTI_LIGHT_CONSTANT_ATTENUATION)
			{
				auto pPointLight = pLight->as<PointLight>();
				if (pPointLight)
				{
					pUniform->setValue(pPointLight->getConstantAttenuation());
				}
			}
			else if (type == MultiLightsUniformType::MULTI_LIGHT_LINEAR_ATTENUATION)
			{
				auto pPointLight = pLight->as<PointLight>();
				if (pPointLight)
				{
					pUniform->setValue(pPointLight->getLinearAttenuation());
				}
			}
			else if (type == MultiLightsUniformType::MULTI_LIGHT_QUADRATIC_ATTENUATION)
			{
				auto pPointLight = pLight->as<PointLight>();
				if (pPointLight)
				{
					pUniform->setValue(pPointLight->getQuadraticAttenuation());
				}
			}
			else if (type == MultiLightsUniformType::MULTI_LIGHT_SPACE_MATRIX)
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
	if (parameter == nullptr
		|| parameter->material == nullptr
		|| parameter->material->getMaterialSetting() == nullptr
		|| parameter->material->getShaderProgram() == nullptr)
	{
		return;
	}

	const auto pDetail = parameter->material->getMaterialDetail();
	if (pDetail == nullptr)
	{
		return;
	}
	auto program = parameter->material->getShaderProgram();
	for (const auto& item : parameter->material->getMaterialSetting()->getSelfDefinedUniforms())
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

void render::DrawCore::drawWithBufferObject(const DrawParameter* parameter)
{
	if (parameter == nullptr || parameter->mesh == nullptr) return;

	auto detail = parameter->mesh->getMeshDetail();
	if (detail == nullptr)
	{
		return;
	}
	uint32_t nVerticeSize = detail->getVertices().getSize();

	if (nVerticeSize == 0)
	{
		return;
	}

	uint32_t nIndiceLength = detail->getIndices().getLength();
	if (nIndiceLength == 0)
	{
		return;
	}

	auto drawMode = parameter->mesh->getDrawMode();

	GLDebug::showError();
	parameter->mesh->getIndiceBuffer()->bindBuffer();
	if (parameter->mesh->getModelMatrices().getLength() > 0)
	{
		int primaryCount = 1;
		if (parameter->mesh->isBatchDraw())
		{
			primaryCount = parameter->mesh->getModelMatrices().getVerticeCount();
		}
		GLBufferObjects::drawElementsInstanced(drawMode, nIndiceLength, IndexDataType::UNSIGNED_INT, nullptr, primaryCount);
		if (_debugDrawMode != DrawMode::NONE)
		{
			GLBufferObjects::drawElementsInstanced(_debugDrawMode, nIndiceLength, IndexDataType::UNSIGNED_INT, nullptr, primaryCount);
		}

	}
	else
	{
		GLBufferObjects::drawElements(drawMode, nIndiceLength, IndexDataType::UNSIGNED_INT, nullptr);
		if (_debugDrawMode != DrawMode::NONE)
		{
			GLBufferObjects::drawElements(_debugDrawMode, nIndiceLength, IndexDataType::UNSIGNED_INT, nullptr);
		}
	}

	GLDebug::showError();
}

void render::DrawCore::drawWithClientArray(const DrawParameter* parameter)
{
	if (parameter == nullptr || parameter->mesh == nullptr) return;

	auto detail = parameter->mesh->getMeshDetail();
	if (detail == nullptr)
	{
		return;
	}
	const sys::MeshMemoryData& vertices = detail->getVertices();
	if (vertices.getLength() == 0)
	{
		//PRINT("Mesh Vertice is NULL\n");
		return;
	}

	const sys::MeshMemoryData& indices = detail->getIndices();
	if (indices.getLength() == 0)
	{
		return;
	}

	const sys::MeshMemoryData& colors = detail->getColors();
	const sys::MeshMemoryData& texcoords = detail->getUVs();
	const sys::MeshMemoryData& normals = detail->getNormals();
	const sys::MeshMemoryData& tangents = detail->getTangents();
	const sys::MeshMemoryData& bitangents = detail->getBitangents();

	if (vertices.getLength() > 0)
	{
		GLClientArrays::enableClientState(ClientArrayType::VERTEX_ARRAY);
		GLClientArrays::setVertexPointer(vertices.getUnitSize(), DataType::FLOAT, 0, vertices.getValue());
		GLDebug::showError();
	}
	if (colors.getLength() > 0)
	{
		GLClientArrays::enableClientState(ClientArrayType::COLOR_ARRAY);
		GLClientArrays::setColorPointer(colors.getUnitSize(), DataType::FLOAT, 0, colors.getValue());
		GLDebug::showError();
	}

	if (texcoords.getLength() > 0)
	{
		GLClientArrays::enableClientState(ClientArrayType::TEXTURE_COORD_ARRAY);
		GLClientArrays::setTexCoordPointer(texcoords.getUnitSize(), DataType::FLOAT, 0, texcoords.getValue());
		GLDebug::showError();
	}

	if (normals.getLength() > 0)
	{
		GLClientArrays::enableClientState(ClientArrayType::NORMAL_ARRAY);
		GLClientArrays::setNormalPointer(DataType::FLOAT, 0, normals.getValue());
		GLDebug::showError();
	}
	/*
	if (tangents.getLength() > 0)
	{
		GLClientArrays::enableClientState(ClientArrayType::TANGENT_ARRAY);
		GLClientArrays::setTangentPointer(DataType::FLOAT, 0, bitangents.getValue());
		GLDebug::showError();
	}

	if (bitangents.getLength() > 0)
	{
		GLClientArrays::enableClientState(ClientArrayType::BITANGENT_ARRAY);
		GLClientArrays::setBitangentPointer(DataType::FLOAT, 0, bitangents.getValue());
		GLDebug::showError();
	}
	*/
	{
		GLClientArrays::drawElements(parameter->mesh->getDrawMode(), indices.getLength(), IndexDataType::UNSIGNED_INT, indices.getValue());
		GLDebug::showError();
	}

	GLClientArrays::disableClientState(ClientArrayType::VERTEX_ARRAY);
	GLClientArrays::disableClientState(ClientArrayType::NORMAL_ARRAY);
	GLClientArrays::disableClientState(ClientArrayType::TEXTURE_COORD_ARRAY);
	GLClientArrays::disableClientState(ClientArrayType::COLOR_ARRAY);
	/*
	GLClientArrays::disableClientState(ClientArrayType::BITANGENT_ARRAY);
	GLClientArrays::disableClientState(ClientArrayType::TANGENT_ARRAY);
	*/
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
	_vertexCount = 0;
}

void render::DrawCore::increaseDrawCall()
{
	_drawCallCount++;
}

void render::DrawCore::increaseUnDrawCall()
{
	_undrawCallCount++;
}

void render::DrawCore::addVertexCount(int count)
{
	_vertexCount += count;
}

void render::DrawCore::endRecordDrawCall()
{
	_oneDrawCallCount = _drawCallCount;
	_oneUnDrawCallCount = _undrawCallCount;
	_oneVertexCount = _vertexCount;
}

int render::DrawCore::getDrawCallCount()
{
	return _oneDrawCallCount;
}

int render::DrawCore::getUnDrawCallCount()
{
	return _oneUnDrawCallCount;
}

int render::DrawCore::getVertexCount()
{
	return _oneVertexCount;
}

void render::DrawCore::addDrawParameter(DrawParameter* parameter)
{
	if (parameter == nullptr)
	{
		return;
	}
	if (parameter->material->getShaderProgram() == nullptr)
	{
		return;
	}
	if (getDrawType() == DrawType::Default)
	{
		return;
	}
	if (parameter->data != nullptr)
	{
		auto bdp = (BatchDrawParameter*)parameter->data;
		bdp->redraw = true;
		_redrawParameters.insert(bdp);
		return;
	}
	if (getDrawType() == DrawType::Batch)
	{
		this->addBatchDrawParameter(parameter);
	}
	else if (getDrawType() == DrawType::Pack)
	{
		this->addPackDrawParameter(parameter);
	}
}

void render::DrawCore::removeDrawParameter(DrawParameter* parameter)
{
	if (parameter == nullptr)
	{
		return;
	}

	if (parameter == nullptr)
	{
		return;
	}
	if (parameter->data == nullptr)
	{
		return;
	}

	BatchDrawParameter* bdp = ((BatchDrawParameter*)parameter->data);
	bdp->remove(parameter);
	bdp->redraw = true;

	if (bdp->root == nullptr)
	{
		auto it0 = std::find(_batchDrawParameters.begin(), _batchDrawParameters.end(), bdp);
		if (it0 != _batchDrawParameters.end())
		{
			_batchDrawParameters.erase(it0);
		}
		auto it1 = std::find(_packDrawParameters.begin(), _packDrawParameters.end(), bdp);
		if (it1 != _packDrawParameters.end())
		{
			_packDrawParameters.erase(it1);
		}

		SAFE_DELETE(bdp);
		_redrawParameters.erase(bdp);
	}
	else
	{
		_redrawParameters.insert(bdp);
	}
}

void render::DrawCore::removeAllDrawParameters()
{
	for (auto& item : _batchDrawParameters)
	{
		SAFE_DELETE(item);
	}
	for (auto& item : _packDrawParameters)
	{
		SAFE_DELETE(item);
	}
	_batchDrawParameters.clear();
	_packDrawParameters.clear();
}

float render::DrawCore::getDrawZOrder(Node* node)
{
	if (node == nullptr) return 0;
	if (node->getParent() == nullptr) return 0;

	int nTotalCount = 0;
	auto temp = node;
	while (temp && temp->getParent())
	{
		int index = temp->getParent()->indexOfChild(temp);
		nTotalCount += index + 1;
		for (int i = 0; i < index; i++)
		{
			nTotalCount += getChildrenCount(temp->getParent()->getChildAt(i));
		}
		temp = temp->getParent();
	}
	return nTotalCount;
}

int render::DrawCore::getChildrenCount(Node* node)
{
	if (node == nullptr) return 0;
	int nTotalCount = 0;
	int nChildrenCount = node->getChildrenCount();
	for (int i = 0; i < nChildrenCount; i++)
	{
		nTotalCount += getChildrenCount(node->getChildAt(i));
	}
	nTotalCount += nChildrenCount;
	return nTotalCount;
}

void render::DrawCore::addBatchDrawParameter(DrawParameter* parameter)
{
	if (parameter == nullptr)
	{
		return;
	}

	bool bFind = false;
	for (auto& item : _batchDrawParameters)
	{
		if (isSameObject(item->root, parameter))
		{
			item->add(parameter);
			bFind = true;
			break;
		}
	}

	if (!bFind)
	{
		_batchDrawParameters.push_back(new BatchDrawParameter(parameter));
	}

	_redrawParameters.insert((BatchDrawParameter*)parameter->data);
}

void render::DrawCore::addPackDrawParameter(DrawParameter* parameter)
{
	if (parameter == nullptr) return;
	bool bFind = false;
	for (auto& item : _packDrawParameters)
	{
		if (isSameMaterial(item->root, parameter))
		{
			item->add(parameter);
			bFind = true;
			break;
		}
	}
	if (!bFind)
	{
		_packDrawParameters.push_back(new BatchDrawParameter(parameter));
	}

	_redrawParameters.insert((BatchDrawParameter*)parameter->data);
}

void render::DrawCore::processDraw()
{
	if (getDrawType() == DrawType::Default)
	{
		return;
	}
	if (_redrawParameters.size() == 0) 
		return;

	if (getDrawType() == DrawType::Batch)
	{
		this->processBatchDraw();
	}
	else if (getDrawType() == DrawType::Pack)
	{
		this->processPackDraw();
	}
}

void render::DrawCore::processBatchDraw()
{
#ifdef UPDATE_NODE_COUNT
	int nMaxCount = UPDATE_NODE_COUNT;
	std::vector<BatchDrawParameter*> curDrawCall;
	for (auto& item : _redrawParameters)
	{
		curDrawCall.push_back(item);
		nMaxCount--;
		if (nMaxCount == 0)
		{
			break;
		}
	}
#endif //  UPDATE_NODE_COUNT

	int unitSize = sizeof(float);
	size_t matrixSize = 16 * unitSize;
#ifdef  UPDATE_NODE_COUNT
	for (const auto& item : curDrawCall)
	{
#else
	for (const auto& item : _redrawParameters)
	{
#endif
		_redrawParameters.erase(item);

		if (item->redraw == false) continue;
		item->redraw = false;
		auto root = item->root;

		int count = 0;
		
		for (int i = 0; i < item->children.size(); i++)
		{
			auto node = item->children[i]->node;
			if (node->isRecursiveVisible())
			{
				count++;
			}
		}

		float* ptr = (float*)root->mesh->createModelMatrices(count, 16);
		for (int i = 0; i < count; i++)
		{
			auto node = item->children[i]->node;
			memcpy(ptr + i * 16, node->getWorldMatrix().getValue(), matrixSize);
			node->setSkipDraw(true);
		}
		root->mesh->forceUpdateMeshData();
		root->mesh->setBatchDraw(true);
		root->node->setSkipDraw(false);
	}
}

void render::DrawCore::processPackDraw()
{
#ifdef UPDATE_NODE_COUNT
	// 只更新部分
	int nMaxCount = UPDATE_NODE_COUNT;
	std::vector<BatchDrawParameter*> curDrawCall;
	for (auto& item : _redrawParameters)
	{
		curDrawCall.push_back(item);
		nMaxCount--;
		if (nMaxCount == 0)
		{
			break;
		}
	}

	for (const auto& item : curDrawCall)
	{
		_redrawParameters.erase(item);
#else
	for (auto& item : _redrawParameters)
	{
#endif //  UPDATE_NODE_COUNT

		if (item->redraw == false) continue;
		item->redraw = false;

		int count = item->children.size();
		auto root = item->root;
		if (item->tempMeshDtail)
		{
			root->mesh->setMeshDetail(item->tempMeshDtail);
			root->mesh->forceUpdateMeshData();
			SAFE_RELEASE(item->tempMeshDtail);
			item->tempMeshDtail = nullptr;
		}
		auto pMeshDetail = CREATE_OBJECT(sys::MeshDetail);
		for (int i = 0; i < count; i++)
		{
			auto node = item->children[i]->node;
			node->setSkipDraw(true);
		}
		if (item->packMeshes(pMeshDetail))
		{
			item->tempMeshDtail = root->mesh->getMeshDetail();
			SAFE_RETAIN(item->tempMeshDtail);
			root->mesh->setMeshDetail(pMeshDetail);
			root->mesh->forceUpdateMeshData();
			root->mesh->setBatchDraw(false);

			root->node->setSkipDraw(false);
		}
	}
}

void render::DrawCore::unbatch()
{
	int matrixSize = 16 * sizeof(float);
	for (const auto& item : _batchDrawParameters)
	{
		int count = item->children.size();
		auto root = item->root;

		root->mesh->createModelMatrices(0, 0);
		root->mesh->forceUpdateMeshData();
		root->mesh->setBatchDraw(false);

		if (count == 1) continue;

		for (int i = 0; i < count; i++)
		{
			auto node = item->children[i]->node;
			node->setSkipDraw(false);
		}
	}

	for (const auto& item : _packDrawParameters)
	{
		int count = item->children.size();
		auto root = item->root;

		if (item->tempMeshDtail)
		{
			root->mesh->setMeshDetail(item->tempMeshDtail);
			SAFE_RELEASE(item->tempMeshDtail);
			item->tempMeshDtail = nullptr;
		}
		root->mesh->forceUpdateMeshData();
		root->mesh->setBatchDraw(false);

		if (count == 1) continue;
		for (int i = 0; i < count; i++)
		{
			auto node = item->children[i]->node;
			node->setSkipDraw(false);
		}
	}
}

bool render::DrawCore::isSameObject(DrawParameter* a, DrawParameter* b)
{
	if (a == nullptr || b == nullptr) return false;
	if (a->node->getFirstParentClippingNode() != b->node->getFirstParentClippingNode()) return false;
	if (a->tessilation != b->tessilation) return false;
	if (!a->material->equals(*b->material)) return false;
	if (!a->mesh->equals(*b->mesh)) return false;
	if (!isSameTexture(a, b)) return false;
	return true;
}

bool render::DrawCore::isSameMaterial(DrawParameter* a, DrawParameter* b)
{
	if (a == nullptr || b == nullptr) return false;
	if (a->node->getFirstParentClippingNode() != b->node->getFirstParentClippingNode()) return false;
	if (a->tessilation != b->tessilation) return false;
	if (!a->material->equals(*b->material)) return false;
	if (!a->mesh->sameLayout(*b->mesh)) return false;
	if (!isSameTexture(a, b)) return false;
	return true;
}

bool render::DrawCore::isSameTexture(DrawParameter* a, DrawParameter* b)
{
	if (a == nullptr || b == nullptr) return false;

	auto texCacheA = a->textureCache;
	auto texCacheB = b->textureCache;

	auto materialDetailA = a->material->getMaterialDetail();
	auto materialDetailB = b->material->getMaterialDetail();

	if (texCacheA->getTexture(materialDetailA->getTexture()) != texCacheB->getTexture(materialDetailB->getTexture()))
	{
		return false;
	}

	return true;
}

/////////////////////////////////////////////////////////////////////////////////
render::DrawCore::BatchDrawParameter::BatchDrawParameter(DrawParameter* parameter)
{
	root = parameter;
	this->add(parameter);
}
bool render::DrawCore::BatchDrawParameter::contains(DrawParameter* parameter)
{
	if (parameter == nullptr) return false;
	if (parameter == root) return true;
	for (auto item : children)
	{
		if (item == parameter)
		{
			return true;
		}
	}
	return false;
}

void render::DrawCore::BatchDrawParameter::remove(DrawParameter* parameter)
{
	if (parameter == nullptr) return;
	if (parameter == root)
	{
		children.erase(children.begin());
		root = children.size() > 0 ? children[0] : nullptr;
		redraw = true;
	}
	else
	{
		auto it = std::find(children.begin(), children.end(), parameter);
		if (it != children.end())
		{
			children.erase(it);
			redraw = true;
		}
	}
	parameter->data = nullptr;
}

void render::DrawCore::BatchDrawParameter::add(DrawParameter* parameter)
{
	if (parameter == nullptr) return;
	children.push_back(parameter);
	parameter->data = this;
	redraw = true;
}

bool concat_ptr_memory_vertices(
	sys::MeshDetail* dest,
	const std::vector<sys::MeshDetail*>& srcs,
	const std::vector<math::Matrix4x4>& mats)
{
	uint32_t verticeCount = 0;
	for (size_t i = 0; i < srcs.size(); i++)
	{
		verticeCount += srcs[i]->getVertices().getVerticeCount();
	}
	if (verticeCount == 0) return false;
	uint32_t unitSize = srcs[0]->getVertices().getUnitSize();
	float* ptr = (float*)dest->createVertices(verticeCount, unitSize);
	uint32_t offset = 0; 
	for (size_t i = 0; i < srcs.size(); i++)
	{
		float* vptr = (float*)srcs[i]->getVertices().getPtr();
		uint32_t vcount = srcs[i]->getVertices().getVerticeCount();
		for (size_t j = 0; j < vcount; j++)
		{
			math::Vector3 pos(vptr + j * unitSize);
			pos = mats[i] * pos;
			memcpy(ptr + offset + j * unitSize, pos.getValue(), pos.getSize()); 
		}
		offset += srcs[i]->getVertices().getLength();
	}

	return true;
}

bool concat_ptr_memory_indices(
	sys::MeshDetail* dest,
	const std::vector<sys::MeshDetail*>& srcs)
{
	uint32_t verticeCount = 0;
	uint32_t data[6] = { 0,1,2,0,2,3 };	
	for (size_t i = 0; i < srcs.size(); i++)
	{
		verticeCount += srcs[i]->getIndices().getVerticeCount();
	}
	if (verticeCount == 0) return false;
	uint32_t unitSize = srcs[0]->getIndices().getUnitSize();
	uint32_t* ptr = (uint32_t*)dest->createIndices(verticeCount, unitSize);
	uint32_t offset = 0; 
	uint32_t voffset = 0;
	for (size_t i = 0; i < srcs.size(); i++)
	{
		uint32_t* vptr = (uint32_t*)srcs[i]->getIndices().getPtr();
		uint32_t icount = srcs[i]->getIndices().getVerticeCount();
		uint32_t vcount = srcs[i]->getVertices().getVerticeCount();
		if (icount > 6)
		{
			int a = 1;
		}
		for (size_t j = 0; j < icount; j++)
		{
			ptr[offset + j] = vptr[j] + voffset;
		}
		offset += srcs[i]->getIndices().getLength();
		voffset += vcount;
	}
	return true;
}

bool concat_ptr_memory_colors(
	sys::MeshDetail* dest,
	const std::vector<sys::MeshDetail*>& srcs)
{
	uint32_t verticeCount = 0;
	for (size_t i = 0; i < srcs.size(); i++)
	{
		verticeCount += srcs[i]->getColors().getVerticeCount();
	}
	if (verticeCount == 0) return false;
	uint32_t unitSize = srcs[0]->getColors().getUnitSize();
	float* ptr = (float*)dest->createColors(verticeCount, unitSize);
	uint32_t offset = 0; 
	for (size_t i = 0; i < srcs.size(); i++)
	{
		memcpy(ptr + offset, srcs[i]->getColors().getPtr(), srcs[i]->getColors().getSize());
		offset += srcs[i]->getColors().getLength();
	}

	return true;
}

bool concat_ptr_memory_uvs(
	sys::MeshDetail* dest,
	const std::vector<sys::MeshDetail*>& srcs)
{
	uint32_t verticeCount = 0;
	for (size_t i = 0; i < srcs.size(); i++)
	{
		verticeCount += srcs[i]->getUVs().getVerticeCount();
	}
	if (verticeCount == 0) return false;
	uint32_t unitSize = srcs[0]->getUVs().getUnitSize();
	float* ptr = (float*)dest->createUVs(verticeCount, unitSize);
	uint32_t offset = 0;
	for (size_t i = 0; i < srcs.size(); i++)
	{
		memcpy(ptr + offset, srcs[i]->getUVs().getPtr(), srcs[i]->getUVs().getSize());
		offset += srcs[i]->getUVs().getLength();
	}

	return true;
}


bool render::DrawCore::BatchDrawParameter::packMeshes(sys::MeshDetail* meshDetail)
{
	if (meshDetail == nullptr || children.size() == 0) return false;

	std::vector<sys::MeshDetail*> vecMeshDetails;
	std::vector<math::Matrix4x4> vecMatrices;
	
	for (const auto & item : children)
	{
		if (item->node->isRecursiveVisible())
		{
			vecMeshDetails.push_back(item->mesh->getMeshDetail());
			auto mat = item->node->getWorldMatrix();
			mat.setValue(3, 2, mat.getValue(3, 2) + item->localZOrder);
			vecMatrices.push_back(mat);
		}
	}

	if (vecMeshDetails.size() == 0 || vecMatrices.size() == 0) return false;

	if (!concat_ptr_memory_vertices(meshDetail, vecMeshDetails, vecMatrices)) return false;
	if (!concat_ptr_memory_colors(meshDetail, vecMeshDetails)) return false;
	if (!concat_ptr_memory_uvs(meshDetail, vecMeshDetails)) return false;
	if (!concat_ptr_memory_indices(meshDetail, vecMeshDetails)) return false;

	//CONCAT_PTR_MEMORY_DATAS(meshDetail, vecMeshDetails, createNormals, getNormals);
	//CONCAT_PTR_MEMORY_DATAS(meshDetail, vecMeshDetails, createTangents, getTangents);
	//CONCAT_PTR_MEMORY_DATAS(meshDetail, vecMeshDetails, createBitangents, getBitangents);

	return true;
}
