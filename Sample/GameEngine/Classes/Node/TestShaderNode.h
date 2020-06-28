#pragma once

#include "TestNode.h"

namespace render
{
	class Material;
}

class TestShaderNode : public TestNode
{
public:
	TestShaderNode();
	virtual ~TestShaderNode();
protected:
	virtual void initNodes();
private:
	void testShaderUniformBlock();
	void testSubroutineUniform();
	void testImageShader();
	void testCubeModelShader();
	void testMultiMeshCubeModelShader();
	void testSphereModelShader();
	
	void test3dsModelShader();
	void testObjModelShader();
	void testFbxModelShader();

	void addLight();
	// ”–Œ Ã‚
	void testClipShader();
};