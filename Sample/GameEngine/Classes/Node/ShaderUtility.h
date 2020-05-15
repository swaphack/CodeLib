#pragma once

#include "render.h"

class ShaderUtility
{
public:
	static void updateNodeShader(render::DrawNode* node, bool autoRotate = true);
protected:
	static void loadShader(render::Material* mat, const std::string& vpath, const std::string& fpath);
	static void initShaderAttrib(render::Material* mat);
	static void initProgramAttrib(render::ShaderProgram* program);
	static void runRotateAction(render::Node* node);

};