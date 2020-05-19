#pragma once

#include "render.h"

class Utility
{
public:
	static void updateNodeShader(render::DrawNode* node, bool autoRotate = true);

	static void loadShader(render::Material* mat, const std::string& vpath, const std::string& fpath);
	static void initShaderAttrib(render::Material* mat);
	static void initProgramAttrib(render::ShaderProgram* program);
	static void runRotateAction(render::Node* node);
public:
	static std::string texture3dVertexPath;
	static std::string texture3dFragmentPath;
};