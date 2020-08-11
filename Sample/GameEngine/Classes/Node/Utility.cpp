#include "Utility.h"

using namespace render;

std::string Utility::texture3dVertexPath = "Shader/texture/texture.vs";
std::string Utility::texture3dFragmentPath = "Shader/texture/texture.fs";

bool Utility::bInitShaderAttrib = false;

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

	initShaderAttrib();

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

	initShaderAttrib();
}

void Utility::loadShader(render::MultiDrawNode* node, const std::string& vpath, const std::string& fpath)
{
	loadShader(node->getMaterials(), vpath, fpath);
}

void Utility::initShaderAttrib(render::DrawNode* node)
{
	initShaderAttrib();
}

void Utility::initShaderAttrib()
{
	if (bInitShaderAttrib)
	{
		return;
	}

	bInitShaderAttrib = true;

	G_UNIFORMSHADERAPPLY->addUniform(UniformType::PROJECT_MATRIX, "matrix.project");
	G_UNIFORMSHADERAPPLY->addUniform(UniformType::VIEW_MATRIX, "matrix.view");
	G_UNIFORMSHADERAPPLY->addUniform(UniformType::MODEL_MATRIX, "matrix.model");
	G_UNIFORMSHADERAPPLY->addUniform(UniformType::NORMAL_MATRIX, "matrix.normal");
	G_UNIFORMSHADERAPPLY->addUniform(UniformType::MVP_MATRIX, "matrix.mvp");
	G_UNIFORMSHADERAPPLY->addUniform(UniformType::MV_MATRIX, "matrix.mv");
	

	G_UNIFORMSHADERAPPLY->addUniform(UniformType::LIGHT_ENABLED, "light.isEnabled");
	G_UNIFORMSHADERAPPLY->addUniform(UniformType::LIGHT_LOCAL, "light.isLocal");
	G_UNIFORMSHADERAPPLY->addUniform(UniformType::LIGHT_SPOT, "light.isSpot");
	G_UNIFORMSHADERAPPLY->addUniform(UniformType::LIGHT_POSITION, "light.position");
	G_UNIFORMSHADERAPPLY->addUniform(UniformType::LIGHT_DIRECTION, "light.direction");
	G_UNIFORMSHADERAPPLY->addUniform(UniformType::LIGHT_HALF_VECTOR, "light.halfVector");
	G_UNIFORMSHADERAPPLY->addUniform(UniformType::LIGHT_SPACE_MATRIX, "light.spaceMatrix");
	G_UNIFORMSHADERAPPLY->addUniform(UniformType::LIGHT_COLOR, "light.color");
	G_UNIFORMSHADERAPPLY->addUniform(UniformType::LIGHT_AMBIENT, "light.ambient");
	G_UNIFORMSHADERAPPLY->addUniform(UniformType::LIGHT_SPOT_EXPONENT, "light.spotExponent");
	G_UNIFORMSHADERAPPLY->addUniform(UniformType::LIGHT_SPOT_COST_CUTOFF, "light.spotCostCutoff");
	G_UNIFORMSHADERAPPLY->addUniform(UniformType::LIGHT_CONSTANT_ATTENUATION, "light.constantAttenuation");
	G_UNIFORMSHADERAPPLY->addUniform(UniformType::LIGHT_LINEAR_ATTENUATION, "light.linearAttenuation");
	G_UNIFORMSHADERAPPLY->addUniform(UniformType::LIGHT_QUADRATIC_ATTENUATION, "light.quadraticAttenuation");


	G_UNIFORMSHADERAPPLY->addUniform(UniformType::MULTI_LIGHT_ENABLED, "lights[%d].isEnabled");
	G_UNIFORMSHADERAPPLY->addUniform(UniformType::MULTI_LIGHT_LOCAL, "lights[%d].isLocal");
	G_UNIFORMSHADERAPPLY->addUniform(UniformType::MULTI_LIGHT_SPOT, "lights[%d].isSpot");
	G_UNIFORMSHADERAPPLY->addUniform(UniformType::MULTI_LIGHT_POSITION, "lights[%d].position");
	G_UNIFORMSHADERAPPLY->addUniform(UniformType::MULTI_LIGHT_DIRECTION, "lights[%d].direction");
	G_UNIFORMSHADERAPPLY->addUniform(UniformType::MULTI_LIGHT_HALF_VECTOR, "lights[%d].halfVector");
	G_UNIFORMSHADERAPPLY->addUniform(UniformType::MULTI_LIGHT_SPACE_MATRIX, "lights[%d].spaceMatrix");
	G_UNIFORMSHADERAPPLY->addUniform(UniformType::MULTI_LIGHT_COLOR, "lights[%d].color");
	G_UNIFORMSHADERAPPLY->addUniform(UniformType::MULTI_LIGHT_AMBIENT, "lights[%d].ambient");
	G_UNIFORMSHADERAPPLY->addUniform(UniformType::MULTI_LIGHT_SPOT_EXPONENT, "lights[%d].spotExponent");
	G_UNIFORMSHADERAPPLY->addUniform(UniformType::MULTI_LIGHT_SPOT_COST_CUTOFF, "lights[%d].spotCostCutoff");
	G_UNIFORMSHADERAPPLY->addUniform(UniformType::MULTI_LIGHT_CONSTANT_ATTENUATION, "lights[%d].constantAttenuation");
	G_UNIFORMSHADERAPPLY->addUniform(UniformType::MULTI_LIGHT_LINEAR_ATTENUATION, "lights[%d].linearAttenuation");
	G_UNIFORMSHADERAPPLY->addUniform(UniformType::MULTI_LIGHT_QUADRATIC_ATTENUATION, "lights[%d].quadraticAttenuation");

	G_UNIFORMSHADERAPPLY->addUniform(UniformType::MATERIAL_EMISSION, "material.emission");
	G_UNIFORMSHADERAPPLY->addUniform(UniformType::MATERIAL_COLOR_AMBIENT, "material.ambient");
	G_UNIFORMSHADERAPPLY->addUniform(UniformType::MATERIAL_COLOR_DIFFUSE, "material.diffuse");
	G_UNIFORMSHADERAPPLY->addUniform(UniformType::MATERIAL_COLOR_SPECULAR, "material.specular");
	G_UNIFORMSHADERAPPLY->addUniform(UniformType::MATERIAL_TEXTURE, "material.tex");
	G_UNIFORMSHADERAPPLY->addUniform(UniformType::MATERIAL_TEXTURE_NORMAL, "material.texNormal");
	G_UNIFORMSHADERAPPLY->addUniform(UniformType::MATERIAL_TEXTURE_ALPHA, "material.texAlpha");
	G_UNIFORMSHADERAPPLY->addUniform(UniformType::MATERIAL_TEXTURE_BUMP, "material.texBump");
	G_UNIFORMSHADERAPPLY->addUniform(UniformType::MATERIAL_TEXTURE_DIFFUSE, "material.texDiffuse");
	G_UNIFORMSHADERAPPLY->addUniform(UniformType::MATERIAL_TEXTURE_SPECULAR, "material.texSpecular");
	G_UNIFORMSHADERAPPLY->addUniform(UniformType::MATERIAL_SHININESS, "material.shininess");
	G_UNIFORMSHADERAPPLY->addUniform(UniformType::MATERIAL_STRENGTH, "material.strength");
	
	G_UNIFORMSHADERAPPLY->addVertexData(VertexDataType::POSITION, "v_position");
	G_UNIFORMSHADERAPPLY->addVertexData(VertexDataType::COLOR, "v_color");
	G_UNIFORMSHADERAPPLY->addVertexData(VertexDataType::UV, "v_texcoord");
	G_UNIFORMSHADERAPPLY->addVertexData(VertexDataType::NORMAL, "v_normal");
	G_UNIFORMSHADERAPPLY->addVertexData(VertexDataType::TANGENT, "v_tangent");
	G_UNIFORMSHADERAPPLY->addVertexData(VertexDataType::BITANGENT, "v_bitangent");
	
	
	G_UNIFORMSHADERAPPLY->addUniform(UniformType::VIEW_POSITION, "env.viewPos");
	G_UNIFORMSHADERAPPLY->addUniform(UniformType::GAMMA, "env.gamma");
	G_UNIFORMSHADERAPPLY->addUniform(UniformType::MULTI_LIGHT_COUNT, "env.lightCount");

	G_UNIFORMSHADERAPPLY->addUniform(UniformType::TEXTURE0, "tex.texture0");
	G_UNIFORMSHADERAPPLY->addUniform(UniformType::TEXTURE1, "tex.texture1");
	G_UNIFORMSHADERAPPLY->addUniform(UniformType::TEXTURE2, "tex.texture2");

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
	initShaderAttrib();
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
