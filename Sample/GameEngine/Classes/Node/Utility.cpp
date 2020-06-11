#include "Utility.h"

using namespace render;

std::string Utility::texture3dVertexPath = "Shader/texture3d.vs";
std::string Utility::texture3dFragmentPath = "Shader/texture3d.fs";

void Utility::loadShader(render::Materials* mats, const std::string& vpath, const std::string& fpath)
{
	if (mats == nullptr)
	{
		return;
	}
	ShaderProgram* pProgram = G_SHANDER->createShaderProgram(vpath, fpath);
	if (pProgram == nullptr)
	{
		return;
	}
	for (auto item : mats->getMaterials())
	{
		item.second->setShaderProgram(pProgram);
	}

	initShaderAttrib(mats);

}

void Utility::initShaderAttrib(render::Materials* mats)
{
	if (mats == nullptr)
	{
		return;
	}

	for (auto item : mats->getMaterials())
	{
		item.second->addUniform(UniformType::PROJECT_MATRIX, "matrix.project");
		item.second->addUniform(UniformType::VIEW_MATRIX, "matrix.view");
		item.second->addUniform(UniformType::MODEL_VIEW, "matrix.model");

		item.second->addUniform(UniformType::LIGHT_COLOR, "light.ambient");
		item.second->addUniform(UniformType::LIGHT_POSITION, "light.position");
		item.second->addUniform(UniformType::LIGHT_AMBIENT, "light.ambient");
		item.second->addUniform(UniformType::LIGHT_DIFFUSE, "light.diffuse");
		item.second->addUniform(UniformType::LIGHT_SPECULAR, "light.specular");

		item.second->addUniform(UniformType::MATERIAL_COLOR_AMBIENT, "material.ambient");
		item.second->addUniform(UniformType::MATERIAL_COLOR_DIFFUSE, "material.diffuse");
		item.second->addUniform(UniformType::MATERIAL_COLOR_SPECULAR, "material.specular");

		item.second->addUniform(UniformType::MATERIAL_TEXTURE_AMBIENT, "material.texAmbient");
		item.second->addUniform(UniformType::MATERIAL_TEXTURE_DIFFUSE, "material.texDiffuse");
		item.second->addUniform(UniformType::MATERIAL_TEXTURE_SPECULAR, "material.texSpecular");

		item.second->addUniform(UniformType::MATERIAL_SHININESS, "material.shininess");

		item.second->addVertexData(VertexDataType::POSITION, "v_position");
		item.second->addVertexData(VertexDataType::COLOR, "v_color");
		item.second->addVertexData(VertexDataType::UV, "v_texcoord");
		item.second->addVertexData(VertexDataType::NORMAL, "v_normal");


		item.second->addUniform(UniformType::VIEW_POSITION, "viewPos");

		item.second->addUniform(UniformType::TEXTURE0, "texSampler0");
		item.second->addUniform(UniformType::TEXTURE1, "texSampler1");
	}
}

void Utility::bindProgramAttrib(render::ShaderProgram* program)
{
	if (program == nullptr)
	{
		return;
	}

	program->bindAttrib((uint32_t)VertexDataType::POSITION, "vPosition");
	program->bindAttrib((uint32_t)VertexDataType::COLOR, "vColor");
	program->bindAttrib((uint32_t)VertexDataType::UV, "vUV");

	GLDebug::showError();
}

void Utility::runRotateAction(render::Node* node)
{
	if (node == nullptr)
	{
		return;
	}
	RotateByAction* pRotateByAction = CREATE_ACTION(RotateByAction);
	pRotateByAction->setRotation(180, 180, 0);
	pRotateByAction->setDuration(10);

	RepeateForeverAction* pRepeateAction = CREATE_ACTION(RepeateForeverAction);
	pRepeateAction->setAction(pRotateByAction);

	node->getActionProxy()->runAction(pRepeateAction);
}

void Utility::updateNodeShader(render::DrawNode* node)
{
	loadShader(node->getMaterials(), texture3dVertexPath, texture3dFragmentPath);
}
