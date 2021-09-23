#pragma once

#include "render.h"
#include "ui.h"

class Utility
{
public:// Í¼Ôª
	static void loadPrimitiveShader(render::DrawNode* node);
	static void loadPrimitiveShader(ui::CtrlWidget* node);
	static void loadPrimitiveShader(render::MultiDrawNode* node);
public: // ÎÆÀí
	static void loadDefaultShader(render::DrawNode* node);
	static void loadDefaultShader(ui::CtrlWidget* node);
	static void loadDefaultShader(render::MultiDrawNode* node);
public: // ²ÄÖÊ
	static void loadMaterialShader(render::DrawNode* node);
	static void loadMaterialShader(render::MultiDrawNode* node);
public:
	static void loadShaderVF(ui::CtrlWidget* node, const std::string& vpath, const std::string& fpath);
	static void loadShaderVF(render::MultiDrawNode* node, const std::string& vpath, const std::string& fpath);

	static void loadShaderVF(render::DrawNode* node, const std::string& vpath, const std::string& fpath);
	static void loadShaderVTF(render::DrawNode* node, const std::string& vpath, const std::string& tepath, const std::string& fpath);
	static void loadShaderVTF(render::DrawNode* node, const std::string& vpath, const std::string& tcpath, const std::string& tepath, const std::string& fpath);
	static void loadShaderVGF(render::DrawNode* node, const std::string& vpath, const std::string& gpath, const std::string& fpath);
	static void loadShaderVTGF(render::DrawNode* node, const std::string& vpath, const std::string& tepath, const std::string& gpath, const std::string& fpath);
	static void loadShaderVTGF(render::DrawNode* node, const std::string& vpath, const std::string& tcpath, const std::string& tepath, const std::string& gpath, const std::string& fpath);

	static void initShaderAttrib();
	static void runRotateAction(render::Node* node);
public:
	static bool bInitShaderAttrib;
};