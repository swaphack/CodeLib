#include "UIShaderHelper.h"
#include "UI/CtrlWidget.h"
#include "render.h"

ui::UIShaderPath ui::UIShaderHelper::_texShader;
ui::UIShaderPath ui::UIShaderHelper::_colorShader;

void ui::UIShaderHelper::loadShader(ui::CtrlWidget* node)
{
	if (node == nullptr)
	{
		return;
	}
	render::ShaderProgram* pProgram = G_SHANDER->createVertexFragmentProgram(_texShader.vertex, _texShader.fragment);
	if (pProgram != nullptr)
	{
		node->setTexShaderProgram(pProgram);
	}

	pProgram = G_SHANDER->createVertexFragmentProgram(_colorShader.vertex, _colorShader.fragment);
	if (pProgram != nullptr)
	{
		node->setColorShaderProgram(pProgram);
	}
}

void ui::UIShaderHelper::loadColorShader(render::DrawNode* node)
{
	if (node == nullptr)
	{
		return;
	}
	render::ShaderProgram* pProgram = G_SHANDER->createVertexFragmentProgram(_colorShader.vertex, _colorShader.fragment);
	if (pProgram != nullptr)
	{
		node->setShaderProgram(pProgram);
	}
}

void ui::UIShaderHelper::loadTexShader(render::DrawNode* node)
{
	if (node == nullptr)
	{
		return;
	}
	render::ShaderProgram* pProgram = G_SHANDER->createVertexFragmentProgram(_texShader.vertex, _texShader.fragment);
	if (pProgram != nullptr)
	{
		node->setShaderProgram(pProgram);
	}
}



void ui::UIShaderHelper::setTexShader(const std::string& vertexShader, const std::string& fragmentShader)
{
	_texShader.vertex = vertexShader;
	_texShader.fragment = fragmentShader;
}

void ui::UIShaderHelper::setColorShader(const std::string& vertexShader, const std::string& fragmentShader)
{
	_colorShader.vertex = vertexShader;
	_colorShader.fragment = fragmentShader;
}