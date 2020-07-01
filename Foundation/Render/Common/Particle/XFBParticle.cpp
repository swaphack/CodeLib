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

render::XFBParticle::XFBParticle()
{
	program = CREATE_OBJECT(VertexFragmentShaderProgram);
	xfbo = CREATE_OBJECT(TransformFeedback);
	xfbb = CREATE_OBJECT(TransformFeedbackBuffer);

	vao = CREATE_OBJECT(VertexArrayObject);
	vbo = CREATE_OBJECT(ArrayBuffer);

	SAFE_RETAIN(program);

	SAFE_RETAIN(xfbo);
	SAFE_RETAIN(xfbb);

	SAFE_RETAIN(vao);
	SAFE_RETAIN(vbo);
}

render::XFBParticle::~XFBParticle()
{
	SAFE_RELEASE(program);
	SAFE_RELEASE(xfbo);
	SAFE_RELEASE(vbo);
	SAFE_RELEASE(vao);
}

void render::XFBParticle::initXFBObject(int count)
{
	if (program)
	{
		program->use();
	}
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
	if (program && func)
	{
		func(node, program);
	}
}

//////////////////////////////////////////////////////////////////////////
void render::XFBUpdateParticle::initXFB(int count)
{
	xfbb->bindBuffer();
	xfbb->setBufferData(count * ParticleData::totalSize(), BufferDataUsage::DYNAMIC_COPY);

	auto buffer = (float*)xfbb->getMapBufferRange(0, count * ParticleData::totalSize(), GL_MAP_WRITE_BIT | GL_MAP_INVALIDATE_BUFFER_BIT);
	for (int i = 0; i < count; i++)
	{
		math::Vector3 pos = math::Vector3(sys::Random::getNumber0_1(), sys::Random::getNumber0_1(), sys::Random::getNumber0_1());
		pos = pos + math::Vector3(-0.5f, 40, 0.0f);
		memcpy(buffer + i * 6, pos.getValue(), 3 * sizeof(float));

		pos = math::Vector3(pos.getX(), pos.getY() * 0.3f, pos.getZ() * 0.3f);
		memcpy(buffer + i * 6 + 3, pos.getValue(), 3 * sizeof(float));
	}
	xfbb->unmapBuffer();
}

void render::XFBUpdateParticle::initVAO(int count)
{
	vao->bindVertexArray();
	vbo->bindBuffer(xfbb->getBufferID());

	auto p0 = vao->getVertexAttrib<VertexAttribPointer>(0);
	p0->setVertexAttribPointer(3, VertexAttribPointerType::FLOAT, ParticleData::totalSize(), 0);
	p0->enableVertexAttribArray();

	auto p1 = vao->getVertexAttrib<VertexAttribPointer>(1);
	p1->setVertexAttribPointer(3, VertexAttribPointerType::FLOAT, ParticleData::totalSize(), ParticleData::offsetVel());
	p1->enableVertexAttribArray();
}

//////////////////////////////////////////////////////////////////////////
void render::XFBRenderParticle::initXFB(int count)
{
	xfbb->bindBuffer();
	xfbb->setBufferData(count * ParticleData::totalSize(), BufferDataUsage::DYNAMIC_COPY);
}

void render::XFBRenderParticle::initVAO(int count)
{
	vao->bindVertexArray();
	vbo->bindBuffer(xfbb->getBufferID());

	auto p0 = vao->getVertexAttrib<VertexAttribPointer>(0);
	p0->setVertexAttribPointer(3, VertexAttribPointerType::FLOAT, ParticleData::totalSize(), 0);
	p0->enableVertexAttribArray();

	auto p1 = vao->getVertexAttrib<VertexAttribPointer>(1);
	p1->setVertexAttribPointer(3, VertexAttribPointerType::FLOAT, ParticleData::totalSize(), ParticleData::offsetVel());
	p1->enableVertexAttribArray();
}
