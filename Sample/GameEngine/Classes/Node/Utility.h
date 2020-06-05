#pragma once

#include "render.h"

class Utility
{
public:
	static void updateNodeShader(render::DrawNode* node);

	static void loadShader(render::Materials* mats, const std::string& vpath, const std::string& fpath);
	static void initShaderAttrib(render::Materials* mats);
	static void runRotateAction(render::Node* node);


	static void bindProgramAttrib(render::ShaderProgram* program);
public:
	static std::string texture3dVertexPath;
	static std::string texture3dFragmentPath;
};