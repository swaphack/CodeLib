#include "ParticleXFbObject.h"
#include "Particle.h"
#include "Common/Transform/import.h"
#include "Common/Shader/import.h"
#include "Common/Buffer/import.h"
#include "Common/VAO/import.h"
#include "Graphic/import.h"
#include "Common/Tool/Tool.h"
#include "Common/Texture/import.h"
#include "Common/XFB/TransformFeedback.h"

render::ParticleXFbObject::ParticleXFbObject()
{
	program = CREATE_OBJECT(ShaderProgram);
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

render::ParticleXFbObject::~ParticleXFbObject()
{
	SAFE_RELEASE(program);
	SAFE_RELEASE(xfbo);
	SAFE_RELEASE(vbo);
	SAFE_RELEASE(vao);
}

void render::ParticleXFbObject::initXFBObject(int count)
{
	if (program)
	{
		program->use();
	}
	this->initXFB(count);
	this->initVAO(count);
}

void render::ParticleXFbObject::initXFB(int count)
{
}

void render::ParticleXFbObject::initVAO(int count)
{
	
}

void render::ParticleXFbObject::doFunc(ParticleSystem* node)
{
	if (program && func)
	{
		func(node, program);
	}
}

//////////////////////////////////////////////////////////////////////////
void render::ParticleUpdateXFbObject::initXFB(int count)
{
	xfbb->bindBuffer();
	xfbb->setBufferData(count * Particle::totalSize(), BufferDataUsage::DYNAMIC_COPY);

	auto buffer = (float*)xfbb->getMapBuffer(AccessType::WRITE_ONLY);
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

void render::ParticleUpdateXFbObject::initVAO(int count)
{
	vao->bindVertexArray();
	vbo->bindBuffer(xfbb->getBufferID());

	auto p0 = vao->getVertexAttrib<VertexAttribPointer>(0);
	p0->setVertexAttribPointer(3, VertexAttribPointerType::FLOAT, Particle::totalSize(), 0);
	p0->enableVertexAttribArray();

	auto p1 = vao->getVertexAttrib<VertexAttribPointer>(1);
	p1->setVertexAttribPointer(3, VertexAttribPointerType::FLOAT, Particle::totalSize(), Particle::offsetVel());
	p1->enableVertexAttribArray();
}

//////////////////////////////////////////////////////////////////////////
void render::ParticleRenderXFbObject::initXFB(int count)
{
	xfbb->bindBuffer();
	xfbb->setBufferData(count * Particle::totalSize(), BufferDataUsage::DYNAMIC_COPY);
}

void render::ParticleRenderXFbObject::initVAO(int count)
{
	vao->bindVertexArray();
	vbo->bindBuffer(xfbb->getBufferID());

	auto p0 = vao->getVertexAttrib<VertexAttribPointer>(0);
	p0->setVertexAttribPointer(3, VertexAttribPointerType::FLOAT, Particle::totalSize(), 0);
	p0->enableVertexAttribArray();

	auto p1 = vao->getVertexAttrib<VertexAttribPointer>(1);
	p1->setVertexAttribPointer(3, VertexAttribPointerType::FLOAT, Particle::totalSize(), Particle::offsetVel());
	p1->enableVertexAttribArray();
}
