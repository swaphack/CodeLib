#include "Utility.h"

using namespace render;

std::string Utility::texture3dVertexPath = "Shader/texture/texture.vs";

std::string Utility::texture3dFragmentPath = "Shader/texture/texture.fs";


bool Utility::bInitShaderAttrib = false;

void Utility::loadShaderVF(render::Materials* mats, const std::string& vpath, const std::string& fpath)
{
	if (mats == nullptr)
	{
		return;
	}
	ShaderProgram* pProgram = G_SHANDER->createVertexFragmentProgram(vpath, fpath);
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

void Utility::loadShaderVF(render::DrawNode* node, const std::string& vpath, const std::string& fpath)
{
	loadShaderVF(node->getMaterial(), vpath, fpath);
}

void Utility::loadShaderVTF(render::DrawNode* node, const std::string& vpath, const std::string& tepath, const std::string& fpath)
{
	loadShaderVTF(node->getMaterial(), vpath, tepath, fpath);
}

void Utility::loadShaderVTF(render::DrawNode* node, const std::string& vpath, const std::string& tcpath, const std::string& tepath, const std::string& fpath)
{
	loadShaderVTF(node->getMaterial(), vpath, tcpath, tepath, fpath);
}

void Utility::loadShaderVF(render::Material* mat, const std::string& vpath, const std::string& fpath)
{
	if (mat == nullptr)
	{
		return;
	}
	ShaderProgram* pProgram = G_SHANDER->createVertexFragmentProgram(vpath, fpath);
	if (pProgram == nullptr)
	{
		return;
	}
	mat->setShaderProgram(pProgram);

	initShaderAttrib();
}

void Utility::loadShaderVTF(render::Material* mat, const std::string& vpath, const std::string& tepath, const std::string& fpath)
{
	if (mat == nullptr)
	{
		return;
	}
	ShaderProgram* pProgram = G_SHANDER->createVertexTessFragmentProgram(vpath, tepath, fpath);
	if (pProgram == nullptr)
	{
		return;
	}
	mat->setShaderProgram(pProgram);

	initShaderAttrib();
}

void Utility::loadShaderVTF(render::Material* mat, const std::string& vpath, const std::string& tcpath, const std::string& tepath, const std::string& fpath)
{
	if (mat == nullptr)
	{
		return;
	}
	ShaderProgram* pProgram = G_SHANDER->createVertexTessFragmentProgram(vpath, tcpath, tepath, fpath);
	if (pProgram == nullptr)
	{
		return;
	}
	mat->setShaderProgram(pProgram);

	initShaderAttrib();
}

void Utility::loadShaderVF(render::MultiDrawNode* node, const std::string& vpath, const std::string& fpath)
{
	loadShaderVF(node->getMaterials(), vpath, fpath);
}

void Utility::loadShaderVGF(render::DrawNode* node, const std::string& vpath, const std::string& gpath, const std::string& fpath)
{
	loadShaderVGF(node->getMaterial(), vpath, gpath, fpath);
}

void Utility::loadShaderVTGF(render::DrawNode* node, const std::string& vpath, const std::string& tepath, const std::string& gpath, const std::string& fpath)
{
	loadShaderVTGF(node->getMaterial(), vpath, tepath, gpath, fpath);
}

void Utility::loadShaderVTGF(render::DrawNode* node, const std::string& vpath, const std::string& tcpath, const std::string& tepath, const std::string& gpath, const std::string& fpath)
{
	loadShaderVTGF(node->getMaterial(), vpath, tcpath, tepath, gpath, fpath);
}

void Utility::loadShaderVGF(render::Material* mat, const std::string& vpath, const std::string& gpath, const std::string& fpath)
{
	if (mat == nullptr)
	{
		return;
	}
	ShaderProgram* pProgram = G_SHANDER->createVertexGeometryFragmentProgram(vpath, gpath, fpath);
	if (pProgram == nullptr)
	{
		return;
	}
	mat->setShaderProgram(pProgram);

	initShaderAttrib();
}

void Utility::loadShaderVTGF(render::Material* mat, const std::string& vpath, const std::string& tepath, const std::string& gpath, const std::string& fpath)
{
	if (mat == nullptr)
	{
		return;
	}
	ShaderProgram* pProgram = G_SHANDER->createVertexTessGeometryFragmentProgram(vpath, tepath, gpath, fpath);
	if (pProgram == nullptr)
	{
		return;
	}
	mat->setShaderProgram(pProgram);

	initShaderAttrib();
}

void Utility::loadShaderVTGF(render::Material* mat, const std::string& vpath, const std::string& tcpath, const std::string& tepath, const std::string& gpath, const std::string& fpath)
{
	if (mat == nullptr)
	{
		return;
	}
	ShaderProgram* pProgram = G_SHANDER->createVertexTessGeometryFragmentProgram(vpath, tcpath, tepath, gpath, fpath);
	if (pProgram == nullptr)
	{
		return;
	}
	mat->setShaderProgram(pProgram);

	initShaderAttrib();
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

	G_UNIFORMSHADERAPPLY->addUniform(MatrixUniformType::PROJECT_MATRIX, "matrix.project");
	G_UNIFORMSHADERAPPLY->addUniform(MatrixUniformType::VIEW_MATRIX, "matrix.view");
	G_UNIFORMSHADERAPPLY->addUniform(MatrixUniformType::MODEL_MATRIX, "matrix.model");
	G_UNIFORMSHADERAPPLY->addUniform(MatrixUniformType::NORMAL_MATRIX, "matrix.normal");
	

	G_UNIFORMSHADERAPPLY->addUniform(SingleLightUniformType::LIGHT_ENABLED, "light.isEnabled");
	G_UNIFORMSHADERAPPLY->addUniform(SingleLightUniformType::LIGHT_LOCAL, "light.isLocal");
	G_UNIFORMSHADERAPPLY->addUniform(SingleLightUniformType::LIGHT_SPOT, "light.isSpot");
	G_UNIFORMSHADERAPPLY->addUniform(SingleLightUniformType::LIGHT_POSITION, "light.position");
	G_UNIFORMSHADERAPPLY->addUniform(SingleLightUniformType::LIGHT_DIRECTION, "light.direction");
	G_UNIFORMSHADERAPPLY->addUniform(SingleLightUniformType::LIGHT_HALF_VECTOR, "light.halfVector");
	G_UNIFORMSHADERAPPLY->addUniform(SingleLightUniformType::LIGHT_SPACE_MATRIX, "light.spaceMatrix");
	G_UNIFORMSHADERAPPLY->addUniform(SingleLightUniformType::LIGHT_COLOR, "light.color");
	G_UNIFORMSHADERAPPLY->addUniform(SingleLightUniformType::LIGHT_AMBIENT, "light.ambient");
	G_UNIFORMSHADERAPPLY->addUniform(SingleLightUniformType::LIGHT_SPOT_EXPONENT, "light.spotExponent");
	G_UNIFORMSHADERAPPLY->addUniform(SingleLightUniformType::LIGHT_SPOT_COST_CUTOFF, "light.spotCostCutoff");
	G_UNIFORMSHADERAPPLY->addUniform(SingleLightUniformType::LIGHT_CONSTANT_ATTENUATION, "light.constantAttenuation");
	G_UNIFORMSHADERAPPLY->addUniform(SingleLightUniformType::LIGHT_LINEAR_ATTENUATION, "light.linearAttenuation");
	G_UNIFORMSHADERAPPLY->addUniform(SingleLightUniformType::LIGHT_QUADRATIC_ATTENUATION, "light.quadraticAttenuation");


	G_UNIFORMSHADERAPPLY->addUniform(MultiLightsUniformType::MULTI_LIGHT_ENABLED, "lights[%d].isEnabled");
	G_UNIFORMSHADERAPPLY->addUniform(MultiLightsUniformType::MULTI_LIGHT_LOCAL, "lights[%d].isLocal");
	G_UNIFORMSHADERAPPLY->addUniform(MultiLightsUniformType::MULTI_LIGHT_SPOT, "lights[%d].isSpot");
	G_UNIFORMSHADERAPPLY->addUniform(MultiLightsUniformType::MULTI_LIGHT_POSITION, "lights[%d].position");
	G_UNIFORMSHADERAPPLY->addUniform(MultiLightsUniformType::MULTI_LIGHT_DIRECTION, "lights[%d].direction");
	G_UNIFORMSHADERAPPLY->addUniform(MultiLightsUniformType::MULTI_LIGHT_HALF_VECTOR, "lights[%d].halfVector");
	G_UNIFORMSHADERAPPLY->addUniform(MultiLightsUniformType::MULTI_LIGHT_SPACE_MATRIX, "lights[%d].spaceMatrix");
	G_UNIFORMSHADERAPPLY->addUniform(MultiLightsUniformType::MULTI_LIGHT_COLOR, "lights[%d].color");
	G_UNIFORMSHADERAPPLY->addUniform(MultiLightsUniformType::MULTI_LIGHT_AMBIENT, "lights[%d].ambient");
	G_UNIFORMSHADERAPPLY->addUniform(MultiLightsUniformType::MULTI_LIGHT_SPOT_EXPONENT, "lights[%d].spotExponent");
	G_UNIFORMSHADERAPPLY->addUniform(MultiLightsUniformType::MULTI_LIGHT_SPOT_COST_CUTOFF, "lights[%d].spotCostCutoff");
	G_UNIFORMSHADERAPPLY->addUniform(MultiLightsUniformType::MULTI_LIGHT_CONSTANT_ATTENUATION, "lights[%d].constantAttenuation");
	G_UNIFORMSHADERAPPLY->addUniform(MultiLightsUniformType::MULTI_LIGHT_LINEAR_ATTENUATION, "lights[%d].linearAttenuation");
	G_UNIFORMSHADERAPPLY->addUniform(MultiLightsUniformType::MULTI_LIGHT_QUADRATIC_ATTENUATION, "lights[%d].quadraticAttenuation");

	G_UNIFORMSHADERAPPLY->addUniform(MaterialUniformType::MATERIAL_EMISSION, "material.emission");
	G_UNIFORMSHADERAPPLY->addUniform(MaterialUniformType::MATERIAL_COLOR_AMBIENT, "material.ambient");
	G_UNIFORMSHADERAPPLY->addUniform(MaterialUniformType::MATERIAL_COLOR_DIFFUSE, "material.diffuse");
	G_UNIFORMSHADERAPPLY->addUniform(MaterialUniformType::MATERIAL_COLOR_SPECULAR, "material.specular");
	G_UNIFORMSHADERAPPLY->addUniform(MaterialUniformType::MATERIAL_TEXTURE, "material.tex");
	G_UNIFORMSHADERAPPLY->addUniform(MaterialUniformType::MATERIAL_TEXTURE_NORMAL, "material.texNormal");
	G_UNIFORMSHADERAPPLY->addUniform(MaterialUniformType::MATERIAL_TEXTURE_ALPHA, "material.texAlpha");
	G_UNIFORMSHADERAPPLY->addUniform(MaterialUniformType::MATERIAL_TEXTURE_BUMP, "material.texBump");
	G_UNIFORMSHADERAPPLY->addUniform(MaterialUniformType::MATERIAL_TEXTURE_DIFFUSE, "material.texDiffuse");
	G_UNIFORMSHADERAPPLY->addUniform(MaterialUniformType::MATERIAL_TEXTURE_SPECULAR, "material.texSpecular");
	G_UNIFORMSHADERAPPLY->addUniform(MaterialUniformType::MATERIAL_TEXTURE_SHADOW, "material.texShadow");
	G_UNIFORMSHADERAPPLY->addUniform(MaterialUniformType::MATERIAL_SHININESS, "material.shininess");
	G_UNIFORMSHADERAPPLY->addUniform(MaterialUniformType::MATERIAL_STRENGTH, "material.strength");
	
	G_UNIFORMSHADERAPPLY->addVertexData(VertexDataType::POSITION, "v_position");
	G_UNIFORMSHADERAPPLY->addVertexData(VertexDataType::COLOR, "v_color");
	G_UNIFORMSHADERAPPLY->addVertexData(VertexDataType::UV, "v_texcoord");
	G_UNIFORMSHADERAPPLY->addVertexData(VertexDataType::NORMAL, "v_normal");
	G_UNIFORMSHADERAPPLY->addVertexData(VertexDataType::TANGENT, "v_tangent");
	G_UNIFORMSHADERAPPLY->addVertexData(VertexDataType::BITANGENT, "v_bitangent");
	
	
	G_UNIFORMSHADERAPPLY->addUniform(EnvUniformType::VIEW_POSITION, "env.viewPos");
	G_UNIFORMSHADERAPPLY->addUniform(EnvUniformType::GAMMA, "env.gamma");
	G_UNIFORMSHADERAPPLY->addUniform(EnvUniformType::LIGHT_COUNT, "env.lightCount");
	G_UNIFORMSHADERAPPLY->addUniform(EnvUniformType::POINT_SIZE, "env.pointSize");

	G_UNIFORMSHADERAPPLY->addUniform(TextureUniformType::TEXTURE0, "tex.texture0"); 
	G_UNIFORMSHADERAPPLY->addUniform(TextureUniformType::TEXTURE1, "tex.texture1");
	G_UNIFORMSHADERAPPLY->addUniform(TextureUniformType::TEXTURE2, "tex.texture2");
	G_UNIFORMSHADERAPPLY->addUniform(TextureUniformType::TEXTURE3, "tex.texture3");
	G_UNIFORMSHADERAPPLY->addUniform(TextureUniformType::TEXTURE4, "tex.texture4");
	G_UNIFORMSHADERAPPLY->addUniform(TextureUniformType::TEXTURE5, "tex.texture5");
	G_UNIFORMSHADERAPPLY->addUniform(TextureUniformType::TEXTURE6, "tex.texture6");
	G_UNIFORMSHADERAPPLY->addUniform(TextureUniformType::TEXTURE7, "tex.texture7");

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

void Utility::loadDefaultShader(render::DrawNode* node)
{
	loadShaderVF(node->getMaterial(), texture3dVertexPath, texture3dFragmentPath);
}

void Utility::loadDefaultShader(render::MultiDrawNode* node)
{
	loadShaderVF(node->getMaterials(), texture3dVertexPath, texture3dFragmentPath);
}
