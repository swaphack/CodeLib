#pragma once

#include "render.h"

class Utility
{
public:
	static void loadDefaultShader(render::DrawNode* node);
	static void loadDefaultShader(render::MultiDrawNode* node);

	static void loadShaderVF(render::DrawNode* node, const std::string& vpath, const std::string& fpath);
	static void loadShaderVTF(render::DrawNode* node, const std::string& vpath, const std::string& tepath, const std::string& fpath);
	static void loadShaderVTF(render::DrawNode* node, const std::string& vpath, const std::string& tcpath, const std::string& tepath, const std::string& fpath);
	static void loadShaderVGF(render::DrawNode* node, const std::string& vpath, const std::string& gpath, const std::string& fpath);
	static void loadShaderVTGF(render::DrawNode* node, const std::string& vpath, const std::string& tepath, const std::string& gpath, const std::string& fpath);
	static void loadShaderVTGF(render::DrawNode* node, const std::string& vpath, const std::string& tcpath, const std::string& tepath, const std::string& gpath, const std::string& fpath);

	static void loadShaderVF(render::MultiDrawNode* node, const std::string& vpath, const std::string& fpath);

	static void runRotateAction(render::Node* node);
protected:
	static void initShaderAttrib(render::DrawNode* node);
	static void initShaderAttrib(render::MultiDrawNode* node);

	static void initShaderAttrib();

	static void loadShaderVF(render::Material* mat, const std::string& vpath, const std::string& fpath);
	static void loadShaderVTF(render::Material* mat, const std::string& vpath, const std::string& tepath, const std::string& fpath);
	static void loadShaderVTF(render::Material* mat, const std::string& vpath, const std::string& tcpath, const std::string& tepath, const std::string& fpath);
	static void loadShaderVGF(render::Material* mat, const std::string& vpath, const std::string& gpath, const std::string& fpath);
	static void loadShaderVTGF(render::Material* mat, const std::string& vpath, const std::string& tepath, const std::string& gpath, const std::string& fpath);
	static void loadShaderVTGF(render::Material* mat, const std::string& vpath, const std::string& tcpath, const std::string& tepath, const std::string& gpath, const std::string& fpath);
	

	static void loadShaderVF(render::Materials* mats, const std::string& vpath, const std::string& fpath);
public:
	static std::string texture3dVertexPath;
	static std::string texture3dFragmentPath;
	static bool bInitShaderAttrib;
};