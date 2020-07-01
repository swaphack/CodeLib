#include "XFBParticle.h"
#include "ParticleData.h"
#include "Common/Transform/import.h"
#include "Common/Shader/import.h"
#include "Common/Buffer/import.h"
#include "Common/VAO/import.h"
#include "Graphic/import.h"
#include "Common/Tool/Tool.h"
#include "Common/Texture/import.h"
#include "Common/XFB/TransformFeedback.h"
#include "XFBParticleNode.h"
#include "Common/XFB/XFBObject.h"

render::XFBParticle::XFBParticle()
{
	xfb = CREATE_OBJECT(XFBObject);
	vao = CREATE_OBJECT(VertexArrayBufferObject);

	SAFE_RETAIN(xfb);
	SAFE_RETAIN(vao);
}

render::XFBParticle::~XFBParticle()
{
	SAFE_RELEASE(xfb);
	SAFE_RELEASE(vao);
}

void render::XFBParticle::initXFBObject(int count)
{
	this->initXFB(count);
	this->initVAO(count);
}

void render::XFBParticle::initXFB(int count)
{
}

void render::XFBParticle::initVAO(int count)
{
	
}

void render::XFBParticle::doFunc(XFBParticleNode* node)
{
	xfb->setInputFunc([this, node](ShaderProgram* program) {
		func(node, program);
	});
}

//////////////////////////////////////////////////////////////////////////
void render::XFBUpdateParticle::initXFB(int count)
{
	auto xfbBuffer = xfb->getFeedbackBuffer();

	xfbBuffer->bindBuffer();
	xfbBuffer->setBufferData(count * ParticleData::totalSize(), BufferDataUsage::DYNAMIC_COPY);

	float* buffer = (float*)xfbBuffer->getMapBufferRange(0, count * ParticleData::totalSize(), GL_MAP_WRITE_BIT | GL_MAP_INVALIDATE_BUFFER_BIT);
	for (int i = 0; i < count; i++)
	{
		math::Vector3 pos = math::Vector3(sys::Random::getNumber0_1(), sys::Random::getNumber0_1(), sys::Random::getNumber0_1());
		pos = pos + math::Vector3(-0.5f, 40, 0.0f);
		memcpy(buffer + i * 6, pos.getValue(), 3 * sizeof(float));

		pos = math::Vector3(pos.getX(), pos.getY() * 0.3f, pos.getZ() * 0.3f);
		memcpy(buffer + i * 6 + 3, pos.getValue(), 3 * sizeof(float));
	}
	xfbBuffer->unmapBuffer();
}

void render::XFBUpdateParticle::initVAO(int count)
{
	vao->resize(count * ParticleData::totalSize());
	vao->writeVertexAttrib(VertexAttribPointerType::FLOAT, nullptr, 3, ParticleData::totalSize());
	vao->writeVertexAttrib(VertexAttribPointerType::FLOAT, nullptr, 3, ParticleData::totalSize());
}

//////////////////////////////////////////////////////////////////////////
void render::XFBRenderParticle::initXFB(int count)
{
	auto xfbBuffer = xfb->getFeedbackBuffer();

	xfbBuffer->bindBuffer();
	xfbBuffer->setBufferData(count * ParticleData::totalSize(), BufferDataUsage::DYNAMIC_COPY);
}

void render::XFBRenderParticle::initVAO(int count)
{
	vao->resize(count * ParticleData::totalSize());
	vao->writeVertexAttrib(VertexAttribPointerType::FLOAT, nullptr, 3, ParticleData::totalSize());
	vao->writeVertexAttrib(VertexAttribPointerType::FLOAT, nullptr, 3, ParticleData::totalSize());
}
