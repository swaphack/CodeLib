#pragma once

#include "render.h"

class Utility
{
public:
	static void updateNodeShader(render::DrawNode* node);

	static void loadShader(render::DrawNode* node, const std::string& vpath, const std::string& fpath);
	static void initShaderAttrib(render::DrawNode* node);
	static void runRotateAction(render::Node* node);
	static void bindProgramAttrib(render::ShaderProgram* program);
protected:
	static void loadShader(render::Materials* mats, const std::string& vpath, const std::string& fpath);
	static void initShaderAttrib(render::Materials* mats);
public:
	static std::string texture3dVertexPath;
	static std::string texture3dFragmentPath;
};