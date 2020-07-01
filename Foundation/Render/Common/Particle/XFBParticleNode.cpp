#include "XFBParticleNode.h"
#include "Common/Buffer/import.h"
#include "Common/VAO/import.h"
#include "Common/TBO/import.h"
#include "Common/Texture/import.h"
#include "Common/Shader/import.h"
#include "Graphic/import.h"
#include "Common/XFB/TransformFeedback.h"
#include "Common/XFB/XFBObject.h"

render::XFBParticleNode::XFBParticleNode()
{
	_updateXFBObject = CREATE_OBJECT(XFBUpdateParticle);
	SAFE_RETAIN(_updateXFBObject);

	_renderXFBObject = CREATE_OBJECT(XFBRenderParticle);
	SAFE_RETAIN(_renderXFBObject);

	_geometryTBO = CREATE_OBJECT(TextureBufferObject);
	SAFE_RETAIN(_geometryTBO);

	_renderVAO = CREATE_OBJECT(VertexArrayObject);
	SAFE_RETAIN(_renderVAO);
}

render::XFBParticleNode::~XFBParticleNode()
{
	SAFE_RELEASE(_updateXFBObject);
	SAFE_RELEASE(_renderXFBObject);

	SAFE_RELEASE(_geometryTBO);
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
	_updateXFBObject->xfb->setWatchPrimitiveMode(TransformFeedbackPrimitiveMode::POINTS, _particleCount);
	_updateXFBObject->doFunc(this);
	GLDebug::showError();
	_renderXFBObject->initXFBObject(_particleCount);
	_renderXFBObject->xfb->setWatchPrimitiveMode(TransformFeedbackPrimitiveMode::TRIANGLES, _particleCount);
	_renderXFBObject->doFunc(this);
	GLDebug::showError();

	auto pTxtBuffer = _geometryTBO->getTextureBuffer();
	if (pTxtBuffer)
	{
		pTxtBuffer->setBufferData(1024 * 1024 * sizeof(float), BufferDataUsage::DYNAMIC_COPY);
	}
	_geometryTBO->bindTextureBuffer();
	_geometryTBO->setTexBufferFromat(TexSizedInternalFormat::RGBA32F);
	GLDebug::showError();
	_renderVAO->setBuffer(pTxtBuffer);
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
	_renderXFBObject->xfb->run();

	GLDebug::showError();
	if ((_frameCount & 1) != 0)
	{
		_renderXFBObject->vao->bindVertexArray();
	}
	else
	{
		_updateXFBObject->vao->bindVertexArray();
	}

	GLDebug::showError();
	_updateXFBObject->xfb->run();
	GLDebug::showError();
}
