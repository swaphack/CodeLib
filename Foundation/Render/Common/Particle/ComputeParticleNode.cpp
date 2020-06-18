#include "ComputeParticleNode.h"
#include "Common/Buffer/import.h"
#include "Common/VAO/import.h"
#include "Graphic/import.h"
#include "Common/Material/import.h"
#include "Common/Shader/import.h"
#include "Common/TBO/import.h"

#define ATTRACTOR_COUNT 32

render::ComputeParticleNode::ComputeParticleNode()
{
	_renderVAO = CREATE_OBJECT(VertexArrayObject);

	_positionBuffer = CREATE_OBJECT(ArrayBuffer);
	_velocityBuffer = CREATE_OBJECT(ArrayBuffer);

	_positionTBO = CREATE_OBJECT(TextureBufferObject);
	_velocityTBO = CREATE_OBJECT(TextureBufferObject);

	_attractorBuffer = CREATE_OBJECT(UniformBuffer);

	_attractorMasses = new float[ATTRACTOR_COUNT] {0};

	SAFE_RETAIN(_renderVAO);
	SAFE_RETAIN(_positionBuffer);
	SAFE_RETAIN(_velocityBuffer);
	SAFE_RETAIN(_attractorBuffer);
}

render::ComputeParticleNode::~ComputeParticleNode()
{
	SAFE_RELEASE(_renderVAO);
	SAFE_RELEASE(_positionBuffer);
	SAFE_RELEASE(_velocityBuffer);
	SAFE_RELEASE(_attractorBuffer);

	SAFE_RELEASE(_positionTBO);
	SAFE_RELEASE(_velocityTBO);

	delete[] _attractorMasses;
}

bool render::ComputeParticleNode::init()
{
	if (!PariticleNode::init())
	{
		return false;
	}

	_notify->addListen(NodeNotifyType::SPACE, [this]() 
	{
			this->updateParticleParameter();
	});

	_positionTBO->setBuffer(_positionBuffer);
	_positionTBO->bindTexture();
	_positionTBO->setTexBuffer(TexSizedInternalFormat::RGBA32F);

	_velocityTBO->setBuffer(_velocityBuffer);
	_velocityTBO->bindTexture();
	_velocityTBO->setTexBuffer(TexSizedInternalFormat::RGBA32F);

	for (int i = 0; i < ATTRACTOR_COUNT; i++)
	{
		_attractorMasses[i] = sys::Random::getNumber0_1();
	}

	int size = 32 * 4 * sizeof(float);

	_attractorBuffer->bindBuffer();
	_attractorBuffer->setBufferData(size, BufferDataUsage::STATIC_DRAW);
	_attractorBuffer->bindBufferBase(0);

	_attractorBuffer->unbindBuffer();

	return true;
}

void render::ComputeParticleNode::loadComputeFile(const std::string& filepath, const ShaderProgramNFunc& updateFunc)
{
	SAFE_RELEASE(_computeProgram);

	_computeProgram = G_SHANDER->createComputeProgram(filepath);
	_computeUpdateFunc = updateFunc;
}

void render::ComputeParticleNode::loadVertexAndFragmentFile(const std::string& vertex, const std::string& fragment, const ShaderProgramNFunc& updateFunc)
{
	SAFE_RELEASE(_renderProgram);

	_renderProgram = G_SHANDER->createVertexFragmentProgram(vertex, fragment);
	_renderUpdateFunc = updateFunc;
}

void render::ComputeParticleNode::draw()
{
	{
		_computeProgram->use();
		GLTexture::bindImageTexture(0, _velocityBuffer->getBufferID(), 0, false, 0, AccessType::READ_WRITE, InternalImageFormat::RGBA32F);
		GLTexture::bindImageTexture(1, _positionBuffer->getBufferID(), 0, false, 0, AccessType::READ_WRITE, InternalImageFormat::RGBA32F);

		if (_computeUpdateFunc)
		{
			_computeUpdateFunc(this, _computeProgram);
		}

		_computeProgram->dispatchCompute(getParticleCount(), 1, 1);

		_computeProgram->setMemoryBarrier(MemoryBarrierBit::SHADER_IMAGE_ACCESS_BARRIER_BIT);

		_computeProgram->unuse();
	}


	{
		_renderProgram->use();
		if (_renderUpdateFunc)
		{
			_renderUpdateFunc(this, _renderProgram);
		}
		_renderVAO->bindVertexArray();

		GLState::enable(EnableMode::BLEND);
		GLState::setBlendFunc(BlendingFactorSrc::ONE, BlendingFactorDest::ONE);
		GLBufferObjects::drawArrays(DrawMode::POINTS, 0, getParticleCount());

		GLState::disable(EnableMode::BLEND);

		_renderProgram->unuse();
	}
}

void render::ComputeParticleNode::updateTime(float dt)
{
	int count = 32;
	int size = 32 * 4 * sizeof(float);

	_attractorBuffer->bindBuffer();

	float* positions = (float*)_attractorBuffer->getBufferRange(0, size, GL_MAP_WRITE_BIT | GL_MAP_INVALIDATE_BUFFER_BIT);
	for (int i = 0; i < getParticleCount(); i++)
	{
		positions[i * 4 + 0] = sinf(dt * (float)(i + 4) * 7.5f * 20.0f) * 50.0f;
		positions[i * 4 + 1] = cosf(dt * (float)(i + 7) * 3.9f * 20.0f) * 50.0f;
		positions[i * 4 + 2] = sinf(dt * (float)(i + 3) * 5.3f * 20.0f) 
			* cosf(dt * (float)(i + 5) * 9.1f) * 100.0f;
		positions[i * 4 + 3] = _attractorMasses[i];
	}
	_attractorBuffer->unmapBuffer();
	_attractorBuffer->unbindBuffer();
}

void render::ComputeParticleNode::updateParticleParameter()
{
	if (getParticleCount() <= 0)
	{
		return;
	}

	int size = getParticleCount() * 4 * sizeof(float);

	_renderVAO->bindVertexArray();
	_positionBuffer->bindBuffer();
	_positionBuffer->setBufferData(size, BufferDataUsage::DYNAMIC_COPY);

	float* position = (float*)_positionBuffer->getBufferRange(0, size, GL_MAP_WRITE_BIT | GL_MAP_INVALIDATE_BUFFER_BIT);
	for (int i = 0; i < getParticleCount(); i++)
	{
		position[i * 4 + 0] = sys::Random::getNumber(-getAnchorPointX(), 1 - getAnchorPointX()) * getWidth();
		position[i * 4 + 1] = sys::Random::getNumber(-getAnchorPointY(), 1 - getAnchorPointY()) * getHeight();
		position[i * 4 + 2] = sys::Random::getNumber(-getAnchorPointZ(), 1 - getAnchorPointZ()) * getDepth();
		position[i * 4 + 3] = 0;
	}

	auto vap = _renderVAO->getVertexAttrib<VertexAttribPointer>(0);
	if (vap)
	{
		vap->setVertexAttribPointer(4, VertexAttribPointerType::FLOAT, 0);
		vap->enableVertexAttribArray();
	}

	_positionBuffer->unmapBuffer();
	_positionBuffer->unbindBuffer();

	_renderVAO->unbindVertexArray();

	_velocityBuffer->bindBuffer();
	_velocityBuffer->setBufferData(size, BufferDataUsage::DYNAMIC_COPY);

	float* velocity = (float*)_velocityBuffer->getBufferRange(0, size, GL_MAP_WRITE_BIT | GL_MAP_INVALIDATE_BUFFER_BIT);
	for (int i = 0; i < getParticleCount(); i++)
	{
		velocity[i * 4 + 0] = sys::Random::getNumber(-1, 1);
		velocity[i * 4 + 1] = 0;
		velocity[i * 4 + 2] = 0;
		velocity[i * 4 + 3] = 0;
	}
	_velocityBuffer->unmapBuffer();
	_velocityBuffer->unbindBuffer();
}
