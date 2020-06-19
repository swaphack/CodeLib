#include "XFBParticleNode.h"
#include "Common/Buffer/import.h"
#include "Common/VAO/import.h"
#include "Common/TBO/import.h"
#include "Common/Texture/import.h"
#include "Common/Shader/import.h"
#include "Graphic/import.h"
#include "Common/XFB/TransformFeedback.h"

render::XFBParticleNode::XFBParticleNode()
{
	_updateXFBObject = CREATE_OBJECT(XFBUpdateParticle);
	SAFE_RETAIN(_updateXFBObject);

	_renderXFBObject = CREATE_OBJECT(XFBRenderParticle);
	SAFE_RETAIN(_renderXFBObject);

	_geometryTBO = CREATE_OBJECT(TextureBufferObject);
	SAFE_RETAIN(_geometryTBO);

	_geometryBuffer = CREATE_OBJECT(TextureBuffer);
	SAFE_RETAIN(_geometryBuffer);

	_renderVAO = CREATE_OBJECT(VertexArrayObject);
	SAFE_RETAIN(_renderVAO);
}

render::XFBParticleNode::~XFBParticleNode()
{
	SAFE_RELEASE(_updateXFBObject);
	SAFE_RELEASE(_renderXFBObject);

	SAFE_RELEASE(_geometryTBO);
	SAFE_RELEASE(_geometryBuffer);
	SAFE_RELEASE(_renderVAO);
}

bool render::XFBParticleNode::init()
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

void render::XFBParticleNode::draw()
{
	this->renderParticles();

	_frameCount++;
}

void render::XFBParticleNode::update(float dt)
{

}

render::XFBUpdateParticle* render::XFBParticleNode::getUpdateXFBObject() const
{
	return _updateXFBObject;
}

render::XFBRenderParticle* render::XFBParticleNode::getRenderXFBObject() const
{
	return _renderXFBObject;
}

void render::XFBParticleNode::setParticleCount(int count)
{
	_particleCount = count;

	this->notify(NodeNotifyType::PARTICLE);
}

int render::XFBParticleNode::getParticleCount() const
{
	return _particleCount;
}

void render::XFBParticleNode::initParticleSystem()
{
	GLDebug::showError();
	_updateXFBObject->initXFBObject(_particleCount);
	GLDebug::showError();
	_renderXFBObject->initXFBObject(_particleCount);
	GLDebug::showError();
	_geometryTBO->setBuffer(_geometryBuffer);
	_geometryBuffer->setBufferData(1024 * 1024 * sizeof(float), BufferDataUsage::DYNAMIC_COPY);
	_geometryTBO->bindTexture();
	_geometryTBO->setTexBuffer(TexSizedInternalFormat::RGBA32F);
	GLDebug::showError();
	_renderVAO->setBuffer(_geometryBuffer);
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

void render::XFBParticleNode::renderParticles()
{
	if (_particleCount == 0)
	{
		return;
	}
	GLDebug::showError();
	_renderXFBObject->program->use();
	_renderXFBObject->doFunc(this);
	_renderXFBObject->vao->bindVertexArray();
	_geometryBuffer->bindBufferBase(BufferTarget::TRANSFORM_FEEDBACK_BUFFER, 0);
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
