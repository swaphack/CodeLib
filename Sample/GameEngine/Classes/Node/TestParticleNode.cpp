#include "TestParticleNode.h"

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
	auto pUpdateFeedback = node->getUpdateFeedback();

	std::string uvfile = "Resource/Shader/particle_update_vertex.glsl";
	std::string uffile = "Resource/Shader/particle_update_fragment.glsl";

	const char* varings0[] = {
		"outPosition",
		"outVelocity",
	};

	pUpdateFeedback->program->loadVertexAndFragmentShader(uvfile, uffile);
	
	pUpdateFeedback->feedback->setFeedbackVaryings(2, varings0, TransformFeedbackBufferMode::INTERLEAVED_ATTRIBS);

	pUpdateFeedback->program->link();

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

		pUniform = sp->getUniform("geometryTBO");
		if (pUniform) 
		{
			GLTexture::activeTexture(ActiveTextureName::TEXTURE0);
			GLTexture::bindTexture2D(ps->getTextureID());
			pUniform->setValue(0);
		}

		GLDebug::showError();
	};

	GLDebug::showError();
	//////////////////////////////////////////////////////////////////////////

	auto pRenderFeedback = node->getRenderFeedback();

	std::string rvfile = "Resource/Shader/particle_render_vertex.glsl";
	std::string rffile = "Resource/Shader/particle_render_fragment.glsl";

	const char* varings1[] = {
		"worldSpacePosition",
	};

	pRenderFeedback->program->loadVertexAndFragmentShader(uvfile, uffile);

	pRenderFeedback->feedback->setFeedbackVaryings(1, varings1, TransformFeedbackBufferMode::INTERLEAVED_ATTRIBS);

	pRenderFeedback->program->link();

	pRenderFeedback->func = [](ParticleSystem* ps, ShaderProgram* sp) {
		const math::Matrix44& proMat = Camera::getMainCamera()->getProjectMatrix();
		const math::Matrix44& modelMat = ps->getWorldMatrix();

		ShaderUniform* pUniform = sp->getUniform("projectMatrix");
		if (pUniform) pUniform->setMatrix4(proMat);

		pUniform = sp->getUniform("modelMatrix");
		if (pUniform) pUniform->setMatrix4(modelMat);
	};
	GLDebug::showError();
}

