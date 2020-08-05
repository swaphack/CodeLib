#include "Utility.h"

using namespace render;

std::string Utility::texture3dVertexPath = "Shader/texture/texture.vs";
std::string Utility::texture3dFragmentPath = "Shader/texture/texture.fs";

void Utility::loadShader(render::Materials* mats, const std::string& vpath, const std::string& fpath)
{
	if (mats == nullptr)
	{
		return;
	}
	VertexFragmentShaderProgram* pProgram = G_SHANDER->createVertexFragmentProgram(vpath, fpath);
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

void Utility::loadShader(render::DrawNode* node, const std::string& vpath, const std::string& fpath)
{
	loadShader(node->getMaterial(), vpath, fpath);
}

void Utility::loadShader(render::Material* mat, const std::string& vpath, const std::string& fpath)
{
	if (mat == nullptr)
	{
		return;
	}
	VertexFragmentShaderProgram* pProgram = G_SHANDER->createVertexFragmentProgram(vpath, fpath);
	if (pProgram == nullptr)
	{
		return;
	}
	mat->setShaderProgram(pProgram);

	initShaderAttrib(mat);
}

void Utility::loadShader(render::MultiDrawNode* node, const std::string& vpath, const std::string& fpath)
{
	loadShader(node->getMaterials(), vpath, fpath);
}

void Utility::initShaderAttrib(render::DrawNode* node)
{
	initShaderAttrib(node->getMaterial());
}

void Utility::initShaderAttrib(render::Materials* mats)
{
	if (mats == nullptr)
	{
		return;
	}

	for (auto item : mats->getMaterials())
	{
		initShaderAttrib(item.second);
		
	}
}

void Utility::initShaderAttrib(render::Material* mat)
{
	if (mat == nullptr)
	{
		return;
	}
	mat->addUniform(UniformType::PROJECT_MATRIX, "matrix.project");
	mat->addUniform(UniformType::VIEW_MATRIX, "matrix.view");
	mat->addUniform(UniformType::MODEL_MATRIX, "matrix.model");
	mat->addUniform(UniformType::NORMAL_MATRIX, "matrix.normal");
	mat->addUniform(UniformType::MVP_MATRIX, "matrix.mvp");
	mat->addUniform(UniformType::MV_MATRIX, "matrix.mv");
	

	mat->addUniform(UniformType::LIGHT_ENABLED, "light.isEnabled");
	mat->addUniform(UniformType::LIGHT_LOCAL, "light.isLocal");
	mat->addUniform(UniformType::LIGHT_SPOT, "light.isSpot");
	mat->addUniform(UniformType::LIGHT_POSITION, "light.position");
	mat->addUniform(UniformType::LIGHT_DIRECTION, "light.direction");
	mat->addUniform(UniformType::LIGHT_HALF_VECTOR, "light.halfVector");
	mat->addUniform(UniformType::LIGHT_COLOR, "light.color");
	mat->addUniform(UniformType::LIGHT_AMBIENT, "light.ambient");
	mat->addUniform(UniformType::LIGHT_SPOT_EXPONENT, "light.spotExponent");
	mat->addUniform(UniformType::LIGHT_SPOT_COST_CUTOFF, "light.spotCostCutoff");
	mat->addUniform(UniformType::LIGHT_CONSTANT_ATTENUATION, "light.constantAttenuation");
	mat->addUniform(UniformType::LIGHT_LINEAR_ATTENUATION, "light.linearAttenuation");
	mat->addUniform(UniformType::LIGHT_QUADRATIC_ATTENUATION, "light.quadraticAttenuation");

	mat->addUniform(UniformType::MULTI_LIGHT_COUNT, "lightCount");
	mat->addUniform(UniformType::MULTI_LIGHT_ENABLED, "lights[%d].isEnabled");
	mat->addUniform(UniformType::MULTI_LIGHT_LOCAL, "lights[%d].isLocal");
	mat->addUniform(UniformType::MULTI_LIGHT_SPOT, "lights[%d].isSpot");
	mat->addUniform(UniformType::MULTI_LIGHT_POSITION, "lights[%d].position");
	mat->addUniform(UniformType::MULTI_LIGHT_DIRECTION, "lights[%d].direction");
	mat->addUniform(UniformType::MULTI_LIGHT_HALF_VECTOR, "lights[%d].halfVector");
	mat->addUniform(UniformType::MULTI_LIGHT_COLOR, "lights[%d].color");
	mat->addUniform(UniformType::MULTI_LIGHT_AMBIENT, "lights[%d].ambient");
	mat->addUniform(UniformType::MULTI_LIGHT_SPOT_EXPONENT, "lights[%d].spotExponent");
	mat->addUniform(UniformType::MULTI_LIGHT_SPOT_COST_CUTOFF, "lights[%d].spotCostCutoff");
	mat->addUniform(UniformType::MULTI_LIGHT_CONSTANT_ATTENUATION, "lights[%d].constantAttenuation");
	mat->addUniform(UniformType::MULTI_LIGHT_LINEAR_ATTENUATION, "lights[%d].linearAttenuation");
	mat->addUniform(UniformType::MULTI_LIGHT_QUADRATIC_ATTENUATION, "lights[%d].quadraticAttenuation");

	mat->addUniform(UniformType::MATERIAL_EMISSION, "material.emission");
	mat->addUniform(UniformType::MATERIAL_COLOR_AMBIENT, "material.ambient");
	mat->addUniform(UniformType::MATERIAL_COLOR_DIFFUSE, "material.diffuse");
	mat->addUniform(UniformType::MATERIAL_COLOR_SPECULAR, "material.specular");
	
	mat->addUniform(UniformType::MATERIAL_TEXTURE, "material.tex");
	mat->addUniform(UniformType::MATERIAL_TEXTURE_ALPHA, "material.texAlpha");
	mat->addUniform(UniformType::MATERIAL_TEXTURE_BUMP, "material.texBump");
	mat->addUniform(UniformType::MATERIAL_TEXTURE_DIFFUSE, "material.texDiffuse");
	mat->addUniform(UniformType::MATERIAL_TEXTURE_SPECULAR, "material.texSpecular");
	
	mat->addUniform(UniformType::MATERIAL_SHININESS, "material.shininess");
	mat->addUniform(UniformType::MATERIAL_STRENGTH, "material.strength");
	
	mat->addVertexData(VertexDataType::POSITION, "v_position");
	mat->addVertexData(VertexDataType::COLOR, "v_color");
	mat->addVertexData(VertexDataType::UV, "v_texcoord");
	mat->addVertexData(VertexDataType::NORMAL, "v_normal");
	
	
	mat->addUniform(UniformType::VIEW_POSITION, "viewPos");
	
	mat->addUniform(UniformType::TEXTURE0, "tex.texture0");
	mat->addUniform(UniformType::TEXTURE1, "tex.texture1");
	mat->addUniform(UniformType::TEXTURE2, "tex.texture2");

	/*
		mat->addUniform(UniformType::TEXTURE3, "texture.texture3");
		mat->addUniform(UniformType::TEXTURE4, "texture.texture4");
		mat->addUniform(UniformType::TEXTURE5, "texture.texture5");
		mat->addUniform(UniformType::TEXTURE6, "texture.texture6");
		mat->addUniform(UniformType::TEXTURE7, "texture.texture7");
	*/
}

void Utility::initShaderAttrib(render::MultiDrawNode* node)
{
	if (node == nullptr)
	{
		return;
	}
	initShaderAttrib(node->getMaterials());
}

void Utility::bindProgramAttrib(render::ShaderProgram* program)
{
	if (program == nullptr)
	{
		return;
	}

	program->bindAttrib((uint32_t)VertexDataType::POSITION, "v_position");
	program->bindAttrib((uint32_t)VertexDataType::COLOR, "v_color");
	program->bindAttrib((uint32_t)VertexDataType::UV, "v_texcoord");

	GLDebug::showError();
}

void Utility::runRotateAction(render::Node* node)
{
	if (node == nullptr)
	{
		return;
	}
	RotateByAction* pRotateByAction = CREATE_ACTION(RotateByAction);
	pRotateByAction->setDifferentRotation(0, 360, 0);
	pRotateByAction->setDuration(5);

	RepeateForeverAction* pRepeateAction = CREATE_ACTION(RepeateForeverAction);
	pRepeateAction->setAction(pRotateByAction);

	node->getActionProxy()->runAction(pRepeateAction);
}

void Utility::updateNodeShader(render::DrawNode* node)
{
	loadShader(node->getMaterial(), texture3dVertexPath, texture3dFragmentPath);
}

void Utility::updateNodeShader(render::MultiDrawNode* node)
{
	loadShader(node->getMaterials(), texture3dVertexPath, texture3dFragmentPath);
}
