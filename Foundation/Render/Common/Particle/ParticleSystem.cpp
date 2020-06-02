#include "ParticleSystem.h"
#include "Common/Buffer/import.h"
#include "Common/VAO/import.h"
#include "Common/Texture/import.h"
#include "Common/Shader/import.h"
#include "Graphic/import.h"
#include "Common/XFB/TransformFeedback.h"

render::ParticleSystem::ParticleSystem()
{
	_updateXFBObject = CREATE_OBJECT(ParticleUpdateXFbObject);
	SAFE_RETAIN(_updateXFBObject);

	_renderXFBObject = CREATE_OBJECT(ParticleRenderXFbObject);
	SAFE_RETAIN(_renderXFBObject);

	_geometryVBO = CREATE_OBJECT(TextureBuffer);
	SAFE_RETAIN(_geometryVBO);

	_geometryTex = CREATE_OBJECT(Texture);
	SAFE_RETAIN(_geometryTex);

	_renderVAO = CREATE_OBJECT(VertexArrayObject);
	SAFE_RETAIN(_renderVAO);
}

render::ParticleSystem::~ParticleSystem()
{
	SAFE_RELEASE(_updateXFBObject);
	SAFE_RELEASE(_renderXFBObject);

	SAFE_RELEASE(_geometryVBO);
	SAFE_RELEASE(_geometryTex);
	SAFE_RELEASE(_renderVAO);
}

bool render::ParticleSystem::init()
{
	if (!Node::init())
	{
		return false;
	}

	_notify->addListen(NodeNotifyType::PARTICLE, [this]() {
		this->initParticleSystem();
	});

	return true;
}

void render::ParticleSystem::draw()
{
	this->renderParticles();

	_frameCount++;
}

render::ParticleUpdateXFbObject* render::ParticleSystem::getUpdateXFBObject() const
{
	return _updateXFBObject;
}

render::ParticleRenderXFbObject* render::ParticleSystem::getRenderXFBObject() const
{
	return _renderXFBObject;
}

void render::ParticleSystem::setParticleCount(int count)
{
	_particleCount = count;

	this->notify(NodeNotifyType::PARTICLE);
}

int render::ParticleSystem::getParticleCount() const
{
	return _particleCount;
}

void render::ParticleSystem::initParticleSystem()
{
	GLDebug::showError();
	_updateXFBObject->initXFBObject(_particleCount);
	GLDebug::showError();
	_renderXFBObject->initXFBObject(_particleCount);
	GLDebug::showError();
	_geometryVBO->setTexture(_geometryTex);
	_geometryVBO->bindBuffer();
	_geometryVBO->setBufferData(1024 * 1024 * sizeof(float), BufferDataUsage::DYNAMIC_COPY);
	_geometryVBO->bindTexture();
	_geometryVBO->setTexBuffer(TexSizedInternalFormat::RGBA32F);
	GLDebug::showError();
	_renderVAO->setBuffer(_geometryVBO);
	_renderVAO->bindVertexArray();
	_renderVAO->bindBuffer();
	GLDebug::showError();
	auto p0 = _renderVAO->getVertexAttrib<VertexAttribPointer>(0);
	if (p0)
	{
		p0->setVertexAttribPointer(4, VertexAttribPointerType::FLOAT, 0);
		p0->enableVertexAttribArray();
	}
	GLDebug::showError();
}

void render::ParticleSystem::renderParticles()
{
	if (_particleCount == 0)
	{
		return;
	}
	GLDebug::showError();
	_renderXFBObject->program->use();
	_renderXFBObject->doFunc(this);
	_renderXFBObject->vao->bindVertexArray();
	_geometryVBO->bindBufferBase(BufferTarget::TRANSFORM_FEEDBACK_BUFFER, 0);
	GLDebug::showError();
	_renderXFBObject->xfbo->bindTransformFeedback();
	GLDebug::showError();
	_renderXFBObject->xfbo->beginWatch(TransformFeedbackPrimitiveMode::TRIANGLES);
	GLDebug::showError();
	this->drawAllChildren();
	GLDebug::showError();
	_renderXFBObject->xfbo->endWatch();
	_renderXFBObject->xfbo->unbindTransformFeedback();
	GLDebug::showError();

	_updateXFBObject->program->use();
	_updateXFBObject->doFunc(this);
	GLDebug::showError();
	if ((_frameCount & 1) != 0)
	{
		_renderXFBObject->vao->bindVertexArray();
		_updateXFBObject->vbo->bindBufferBase(BufferTarget::TRANSFORM_FEEDBACK_BUFFER, 0);
	}
	else
	{
		_updateXFBObject->vao->bindVertexArray();
		_renderXFBObject->vbo->bindBufferBase(BufferTarget::TRANSFORM_FEEDBACK_BUFFER, 0);
	}
	GLDebug::showError();
	_updateXFBObject->xfbo->bindTransformFeedback();
	_updateXFBObject->xfbo->beginWatch(TransformFeedbackPrimitiveMode::POINTS);
	GLBufferObjects::drawArrays(DrawMode::POINTS, 0, min(_particleCount, (_frameCount >> 3)));
	_updateXFBObject->xfbo->endWatch();
	_updateXFBObject->xfbo->bindTransformFeedback();
	GLDebug::showError();
	_updateXFBObject->vao->unbindVertexArray();
	GLDebug::showError();
}
