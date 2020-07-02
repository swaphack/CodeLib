#include "TestParticleNode.h"
#include "Utility.h"
using namespace render;

TestParticleNode::TestParticleNode()
{

}

TestParticleNode::~TestParticleNode()
{

}

void TestParticleNode::initNodes()
{
	testXFBParticle();
}

void TestParticleNode::testCollideParticle()
{
	/*
	XFBParticleNode* particleNode = CREATE_NODE(XFBParticleNode);
	particleNode->setPosition(512, 386, 0);
	particleNode->setScale(2, 1, 1);
	this->addChild(particleNode);

	//////////////////////////////////////////////////////////////////////////
	auto pUpdateFeedback = particleNode->getUpdateXFBObject();

	std::string uvfile = "Shader/particle/particle_update.vs";
	std::string uffile = "Shader/particle/particle_update.fs";

	const char* varings0[] = {
		"outPosition",
		"outVelocity",
	};

	pUpdateFeedback->xfb->loadVertexFragmentProgram(uvfile, uffile);
	pUpdateFeedback->xfb->setWatchVaryings(2, varings0);

	GLDebug::showError();

	pUpdateFeedback->func = [&](Node* ps, ShaderProgram* sp) {
		const math::Matrix44& proMat = Camera::getMainCamera()->getProjectMatrix();
		const math::Matrix44& modelMat = ps->getWorldMatrix();

		ShaderUniform* pUniform = sp->getUniform("matrix.project");
		if (pUniform) pUniform->setMatrix4(proMat);

		pUniform = sp->getUniform("matrix.model");
		if (pUniform) pUniform->setMatrix4(modelMat);

		pUniform = sp->getUniform("triangleCount");
		if (pUniform) pUniform->setValue(particleNode->getParticleCount() / 3);

		pUniform = sp->getUniform("timeStep");
		if (pUniform) pUniform->setValue(0.02f);
	
		//pUniform = sp->getUniform("geometryTBO");
		//if (pUniform)
		//{
		//	GLTexture::activeTexture(ActiveTextureName::TEXTURE0);
		//	GLTexture::bindTexture2D(ps->getTextureID());
		//	pUniform->setValue(0);
		//}
		
		GLDebug::showError();
	};

	GLDebug::showError();
	//////////////////////////////////////////////////////////////////////////

	auto pRenderFeedback = particleNode->getRenderXFBObject();

	std::string rvfile = "Shader/particle/particle_render.vs";
	std::string rffile = "Shader/particle/particle_render.fs";

	const char* varings1[] = {
		"worldSpacePosition",
	};

	pRenderFeedback->xfb->loadVertexFragmentProgram(rvfile, rffile);
	GLDebug::showError();

	pRenderFeedback->xfb->setWatchVaryings(1, varings1);

	GLDebug::showError();

	pRenderFeedback->func = [](Node* ps, ShaderProgram* sp) {
		const math::Matrix44& proMat = Camera::getMainCamera()->getProjectMatrix();
		const math::Matrix44& modelMat = ps->getWorldMatrix();

		ShaderUniform* pUniform = sp->getUniform("matrix.project");
		if (pUniform) pUniform->setMatrix4(proMat);

		pUniform = sp->getUniform("matrix.model");
		if (pUniform) pUniform->setMatrix4(modelMat);
	};
	GLDebug::showError();

	particleNode->setParticleCount(1000);
	*/
}

void TestParticleNode::testXFBParticle()
{
	render::TransformFeedbackParticleNode* node = CREATE_NODE(render::TransformFeedbackParticleNode);
	node->setPosition(512, 384);
	node->setSpeedAcceleration(10, 0, 0);
	node->setParticleCount(1000);
	node->loadShaderProgram("Shader/particle/simple_particle_render.vs", "Shader/particle/simple_particle_render.fs");

	this->addChild(node);
}

render::Node* TestParticleNode::createCubeModel()
{
	std::string filepath = "Resource/Image/NeHe.png";

	Cube* pModel = CREATE_NODE(Cube);
	pModel->setTexture(filepath);
	pModel->setPosition(500, 500, 0);
	pModel->setVolume(200, 200, 200);
	pModel->setAnchorPoint(0.5f, 0.5f, 0.5f);

	Utility::updateNodeShader(pModel);
	Utility::runRotateAction(pModel);

	return pModel;
}

