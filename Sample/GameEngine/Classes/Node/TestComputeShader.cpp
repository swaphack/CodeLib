#include "TestComputeShader.h"

TestComputeShader::TestComputeShader()
{

}

TestComputeShader::~TestComputeShader()
{

}

void TestComputeShader::initNodes()
{
	this->testParticleNode();
}

void TestComputeShader::testSimpleComputeShader()
{
	render::ComputeProgram* program = G_SHANDER->createComputeProgram("Shader/compute/test.cs");
	render::GLDebug::showError();
}

void TestComputeShader::testParticleNode()
{
	render::ComputeParticleNode* particleNode = CREATE_NODE(render::ComputeParticleNode);
	particleNode->loadComputeFile("Shader/compute/particle.cs", [](render::Node* node, render::ShaderProgram* program) {
		auto pNode = node->as<render::ComputeParticleNode>();
		auto dt = program->getUniform("dt");
		if (dt)
		{
			dt->setValue(pNode->getPassedTime());
		}
	});

	particleNode->loadVertexAndFragmentFile(
		"Shader/particle/compute_particle.vs", 
		"Shader/particle/compute_particle.fs",
	[](render::Node* node, render::ShaderProgram* program) {
		auto pNode = node->as<render::ComputeParticleNode>();

		auto project = program->getUniform("matrix.project");
		if (project) project->setMatrix4(render::Camera::getMainCamera()->getProjectMatrix().getValue());
		auto view = program->getUniform("matrix.view");
		if (view) project->setMatrix4(render::Camera::getMainCamera()->getViewMatrix().getValue());
		auto model = program->getUniform("matrix.model");
		if (model) project->setMatrix4(node->getWorldMatrix().getValue());
		/*
		auto position = program->getAttrib("v_position");
		if (position)
		{
			render::VertexAttribPointer* pointer = pNode->getVAO()->getVertexAttrib<render::VertexAttribPointer>(position->getAttribID());
			pointer->enableVertexArrayAttrib();
			pointer->setVertexAttribPointer(4, VertexAttribPointerType::FLOAT, 0);
		}
		*/
	});

	int nGroupSize = 128;
	particleNode->setParticleCount(nGroupSize * 100);
	particleNode->setParticleGroupSize(128);
	particleNode->setVolume(512, 384);
	particleNode->setPosition(512, 384);
	particleNode->setAnchorPoint(0.5f, 0.5f);

	particleNode->start();

	this->addChild(particleNode);
}

void TestComputeShader::testCalulate()
{
}

