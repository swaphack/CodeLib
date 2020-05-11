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
};