#pragma once

#include "TestFuncNode.h"

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
	void testColorShader();
	void testModelShader();
private:
};