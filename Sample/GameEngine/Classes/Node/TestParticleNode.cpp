#include "TestParticleNode.h"
#include "Utility.h"
using namespace render;

TestParticleNode::TestParticleNode()
{

}

TestParticleNode::~TestParticleNode()
{

}

void TestParticleNode::testFunc()
{
	testParticle();
}

void TestParticleNode::testParticle()
{
	ParticleSystem* node = CREATE_NODE(ParticleSystem);
	node->setPosition(512, 386, 0);
	node->setScale(2, 1, 1);
	this->addChild(node);

	//////////////////////////////////////////////////////////////////////////
	auto pUpdateFeedback = node->getUpdateXFBObject();

	std::string uvfile = "Shader/particle_update_vertex.glsl";
	std::string uffile = "Shader/particle_update_fragment.glsl";

	const char* varings0[] = {
		"outPosition",
		"outVelocity",
	};

	pUpdateFeedback->program->loadVertexAndFragmentShader(uvfile, uffile);
	GLDebug::showError();

	pUpdateFeedback->xfbo->setFeedbackVaryings(2, varings0, TransformFeedbackBufferMode::INTERLEAVED_ATTRIBS);
	GLDebug::showError();

	pUpdateFeedback->program->link();
	GLDebug::showError();

	pUpdateFeedback->func = [](ParticleSystem* ps, ShaderProgram* sp) {
		const math::Matrix44& proMat = Camera::getMainCamera()->getProjectMatrix();
		const math::Matrix44& modelMat = ps->getWorldMatrix();

		ShaderUniform* pUniform = sp->getUniform("projectMatrix");
		if (pUniform) pUniform->setMatrix4(proMat);

		pUniform = sp->getUniform("modelMatrix");
		if (pUniform) pUniform->setMatrix4(modelMat);

		pUniform = sp->getUniform("triangleCount");
		if (pUniform) pUniform->setValue(ps->getParticleCount() / 3);

		pUniform = sp->getUniform("timeStep");
		if (pUniform) pUniform->setValue(0.02f);
		/*
		pUniform = sp->getUniform("geometryTBO");
		if (pUniform) 
		{
			GLTexture::activeTexture(ActiveTextureName::TEXTURE0);
			GLTexture::bindTexture2D(ps->getTextureID());
			pUniform->setValue(0);
		}
		*/
		GLDebug::showError();
	};

	GLDebug::showError();
	//////////////////////////////////////////////////////////////////////////

	auto pRenderFeedback = node->getRenderXFBObject();

	std::string rvfile = "Shader/particle_render_vertex.glsl";
	std::string rffile = "Shader/particle_render_fragment.glsl";

	const char* varings1[] = {
		"worldSpacePosition",
	};

	pRenderFeedback->program->loadVertexAndFragmentShader(rvfile, rffile);
	GLDebug::showError();

	pRenderFeedback->xfbo->setFeedbackVaryings(1, varings1, TransformFeedbackBufferMode::INTERLEAVED_ATTRIBS);
	GLDebug::showError();

	pRenderFeedback->program->link();
	GLDebug::showError();

	pRenderFeedback->func = [](ParticleSystem* ps, ShaderProgram* sp) {
		const math::Matrix44& proMat = Camera::getMainCamera()->getProjectMatrix();
		const math::Matrix44& modelMat = ps->getWorldMatrix();

		ShaderUniform* pUniform = sp->getUniform("projectMatrix");
		if (pUniform) pUniform->setMatrix4(proMat);

		pUniform = sp->getUniform("modelMatrix");
		if (pUniform) pUniform->setMatrix4(modelMat);
	};
	GLDebug::showError();

	node->setParticleCount(1000);
}

render::Node* TestParticleNode::createCubeModel()
{
	std::string filepath = "Resource/Image/NeHe.png";

	Cube* pModel = CREATE_NODE(Cube);
	pModel->setFaceImage(filepath);
	pModel->setPosition(500, 500, 0);
	pModel->setVolume(200, 200, 200);
	pModel->setAnchorPoint(0.5f, 0.5f, 0.5f);

	Utility::updateNodeShader(pModel);
	Utility::runRotateAction(pModel);

	return pModel;
}

