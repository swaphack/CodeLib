#include "Utility.h"

using namespace render;

std::string textureVertexPath = "Shader/texture/texture.vs";

std::string textureFragmentPath = "Shader/texture/texture.fs";

std::string primitiveVertexPath = "Shader/geometry/draw_primitive.vs";

std::string primitiveFragmentPath = "Shader/geometry/draw_primitive.fs";

std::string materialVertexPath = "Shader/material/material_texture.vs";

std::string materialFragmentPath = "Shader/material/material_texture.fs";


void Utility::loadPrimitiveShader(render::DrawNode* node)
{
	if (node == nullptr) return;
	loadShaderVF(node, primitiveVertexPath, primitiveFragmentPath);
}

void Utility::loadPrimitiveShader(ui::CtrlWidget* node)
{
	if (node == nullptr) return;
	ShaderProgram* pProgram = G_SHANDER->createVertexFragmentProgram(primitiveVertexPath, primitiveFragmentPath);
	if (pProgram == nullptr)
	{
		return;
	}
	node->setColorShaderProgram(pProgram);
}

void Utility::loadPrimitiveShader(render::MultiDrawNode* node)
{
	if (node == nullptr) return;

	loadShaderVF(node, primitiveVertexPath, primitiveFragmentPath);
}

void Utility::loadDefaultShader(render::DrawNode* node)
{
	if (node == nullptr) return;
	loadShaderVF(node, textureVertexPath, textureFragmentPath);
}

void Utility::loadDefaultShader(ui::CtrlWidget* node)
{
	if (node == nullptr) return;
	ShaderProgram* pProgram = G_SHANDER->createVertexFragmentProgram(textureVertexPath, textureFragmentPath);
	if (pProgram == nullptr)
	{
		return;
	}
	node->setTexShaderProgram(pProgram);
}

void Utility::loadDefaultShader(render::MultiDrawNode* node)
{
	if (node == nullptr) return;
	loadShaderVF(node, textureVertexPath, textureFragmentPath);
}

void Utility::loadMaterialShader(render::DrawNode* node)
{
	if (node == nullptr) return;
	loadShaderVF(node, materialVertexPath, materialFragmentPath);
}

void Utility::loadMaterialShader(render::MultiDrawNode* node)
{
	if (node == nullptr) return;
	loadShaderVF(node, materialVertexPath, materialFragmentPath);
}

void Utility::loadShaderVF(ui::CtrlWidget* node, const std::string& vpath, const std::string& fpath)
{
	if (node == nullptr)
	{
		return;
	}
	ShaderProgram* pProgram = G_SHANDER->createVertexFragmentProgram(vpath, fpath);
	if (pProgram == nullptr)
	{
		return;
	}
	node->setTexShaderProgram(pProgram);
}

void Utility::loadShaderVF(render::MultiDrawNode* node, const std::string& vpath, const std::string& fpath)
{
	if (node == nullptr) return;

	ShaderProgram* pProgram = G_SHANDER->createVertexFragmentProgram(vpath, fpath);
	if (pProgram == nullptr)
	{
		return;
	}
	node->setShaderProgram(pProgram);
}

void Utility::loadShaderVF(render::DrawNode* node, const std::string& vpath, const std::string& fpath)
{
	if (node == nullptr)
	{
		return;
	}
	ShaderProgram* pProgram = G_SHANDER->createVertexFragmentProgram(vpath, fpath);
	if (pProgram == nullptr)
	{
		return;
	}
	node->setShaderProgram(pProgram);
}

void Utility::loadShaderVTF(render::DrawNode* node, const std::string& vpath, const std::string& tepath, const std::string& fpath)
{
	if (node == nullptr)
	{
		return;
	}
	ShaderProgram* pProgram = G_SHANDER->createVertexTessFragmentProgram(vpath, tepath, fpath);
	if (pProgram == nullptr)
	{
		return;
	}
	node->setShaderProgram(pProgram);
}

void Utility::loadShaderVTF(render::DrawNode* node, const std::string& vpath, const std::string& tcpath, const std::string& tepath, const std::string& fpath)
{
	if (node == nullptr)
	{
		return;
	}
	ShaderProgram* pProgram = G_SHANDER->createVertexTessFragmentProgram(vpath, tcpath, tepath, fpath);
	if (pProgram == nullptr)
	{
		return;
	}
	node->setShaderProgram(pProgram);
}

void Utility::loadShaderVGF(render::DrawNode* node, const std::string& vpath, const std::string& gpath, const std::string& fpath)
{
	if (node == nullptr)
	{
		return;
	}
	ShaderProgram* pProgram = G_SHANDER->createVertexGeometryFragmentProgram(vpath, gpath, fpath);
	if (pProgram == nullptr)
	{
		return;
	}
	node->setShaderProgram(pProgram);
}

void Utility::loadShaderVTGF(render::DrawNode* node, const std::string& vpath, const std::string& tepath, const std::string& gpath, const std::string& fpath)
{
	if (node == nullptr)
	{
		return;
	}
	ShaderProgram* pProgram = G_SHANDER->createVertexTessGeometryFragmentProgram(vpath, tepath, gpath, fpath);
	if (pProgram == nullptr)
	{
		return;
	}
	node->setShaderProgram(pProgram);
}

void Utility::loadShaderVTGF(render::DrawNode* node, const std::string& vpath, const std::string& tcpath, const std::string& tepath, const std::string& gpath, const std::string& fpath)
{
	if (node == nullptr)
	{
		return;
	}
	ShaderProgram* pProgram = G_SHANDER->createVertexTessGeometryFragmentProgram(vpath, tcpath, tepath, gpath, fpath);
	if (pProgram == nullptr)
	{
		return;
	}
	node->setShaderProgram(pProgram);
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