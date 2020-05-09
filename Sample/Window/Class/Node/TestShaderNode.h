#pragma once

#include "TestFuncNode.h"

namespace render
{
	class Material;
}

class TestShaderNode : public TestFuncNode
{
public:
	TestShaderNode();
	virtual ~TestShaderNode();
protected:
	virtual void testFunc();
private:
	void testShaderUniformBlock();
	void testSubroutineUniform();
	void testImageShader();
	void testModelShader();
	
	void test3dsModelShader();
	void testObjModelShader();
	void testFbxModelShader();
private:
	void loadShader(render::Material* mat, const std::string& vpath, const std::string& fpath);
	void initShaderAttrib(render::Material* mat);
	void runRotateAction(render::Node* node);
private:
};