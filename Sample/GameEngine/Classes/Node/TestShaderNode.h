#pragma once

#include "../Env/TestNode.h"

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
	// 有问题
	void testClipShader();

	// 细分着色器
	void testTessellation();
};