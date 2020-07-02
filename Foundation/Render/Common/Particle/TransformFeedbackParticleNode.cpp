#include "TransformFeedbackParticleNode.h"
#include "Common/Shader/import.h"
#include "Common/Buffer/TransformFeedbackBuffer.h"
#include "Common/XFB/TransformFeedbackBufferObject.h"
#include "Common/VAO/VertexArrayBufferObject.h"
#include "Graphic/import.h"

#define UNIT_SIZE sizeof(float)

render::TransformFeedbackParticleNode::TransformFeedbackParticleNode()
{
	_updateObject = CREATE_OBJECT(TransformFeedbackBufferObject);
	SAFE_RETAIN(_updateObject);

	_renderObject = CREATE_OBJECT(VertexArrayBufferObject);
	SAFE_RETAIN(_renderObject);
}

render::TransformFeedbackParticleNode::~TransformFeedbackParticleNode()
{

	SAFE_RELEASE(_shaderProgram);

	SAFE_RELEASE(_updateObject);
	SAFE_RELEASE(_renderObject);
}

bool render::TransformFeedbackParticleNode::init()
{
	if (!PariticleNode::init())
	{
		return false;
	}

	const char* varying[] = {"out_Position"};

	uint32_t size = _particleCount * 3 * UNIT_SIZE;
	_updateObject->loadVertexProgram("Shader/particle/simple_particle.vs");
	_updateObject->setWatchVaryings(1, varying);
	_updateObject->setWatchPrimitiveMode(TransformFeedbackPrimitiveMode::POINTS, _particleCount);
	_updateObject->setBufferSize(size);
	_updateObject->setTargetBufferRange(0, 0, size);

	_updateObject->setInputFunc([this](ShaderProgram* program) {
		uint32_t posSize = 3 * UNIT_SIZE * _particleCount;
		uint32_t speedSize = 3 * UNIT_SIZE * _particleCount;
		uint32_t angleSize = 3 * UNIT_SIZE * _particleCount;

		uint32_t len = posSize + speedSize + angleSize;

		auto buffer = _updateObject->getFeedbackBuffer();
		buffer->bindBuffer();
		float* data = (float*)buffer->getMapBufferRange(0, len, MapBufferRangeAccess::MAP_READ_BIT);

		_renderObject->bindVertexArray();
		_renderObject->resize(len);
		_renderObject->writeVertexAttrib(VertexAttribPointerType::FLOAT, data, posSize);
		_renderObject->writeVertexAttrib(VertexAttribPointerType::FLOAT, (void*)(data + posSize), speedSize);
		_renderObject->writeVertexAttrib(VertexAttribPointerType::FLOAT, (void*)(data + posSize + speedSize), angleSize);

		auto in_position = program->getAttrib("in_position");
		if (in_position) _renderObject->enableVertexArrayAttrib(in_position->getAttribID());

		auto in_speedAcceleration = program->getAttrib("in_speedAcceleration");
		if (in_speedAcceleration) _renderObject->enableVertexArrayAttrib(in_speedAcceleration->getAttribID());

		auto in_angleAcceleration = program->getAttrib("in_angleAcceleration");
		if (in_angleAcceleration) _renderObject->enableVertexArrayAttrib(in_angleAcceleration->getAttribID());

		auto lifeTime = program->getUniform("lifeTime");
		if (lifeTime) lifeTime->setValue(_passedTime);

		auto deltaTime = program->getUniform("deltaTime");
		if (deltaTime) deltaTime->setValue(_deltaTime);

		auto maxTime = program->getUniform("maxTime");
		if (maxTime) deltaTime->setValue(10);

		buffer->unmapBuffer();
	});

	_updateObject->setOutputFunc([this](TransformFeedbackBuffer* buffer) {
		_renderObject->unbindVertexArray();

		uint32_t posSize = 3 * UNIT_SIZE * _particleCount;
		uint32_t speedSize = 3 * UNIT_SIZE * _particleCount;
		uint32_t angleSize = 3 * UNIT_SIZE * _particleCount;

		uint32_t len = posSize + speedSize + angleSize;

		buffer->bindBuffer();
		float* data = (float*)buffer->getMapBufferRange(0, len, MapBufferRangeAccess::MAP_READ_BIT);

		_renderObject->bindVertexArray();
		_renderObject->resize(len);
		_renderObject->writeVertexAttrib(VertexAttribPointerType::FLOAT, data, posSize);
		_renderObject->writeVertexAttrib(VertexAttribPointerType::FLOAT, data + posSize, speedSize);
		_renderObject->writeVertexAttrib(VertexAttribPointerType::FLOAT, data + posSize + speedSize, angleSize);
		buffer->unmapBuffer();
		buffer->unbindBuffer();
		_renderObject->unbindVertexArray();
	});

	return true;
}

void render::TransformFeedbackParticleNode::update(float dt)
{
	if (!_shaderProgram)
	{
		return;
	}

	_updateObject->run();

	
	_shaderProgram->use();
	_renderObject->bindVertexArray();
	auto v_position = _shaderProgram->getAttrib("v_position");
	if (v_position) _renderObject->enableVertexArrayAttrib(v_position->getAttribID());

	auto pointScale = _shaderProgram->getUniform("pointScale");
	if (pointScale) pointScale->setValue(1);

	GLBufferObjects::drawArrays(DrawMode::POINTS, 0, _particleCount);

	_renderObject->unbindVertexArray();
	_shaderProgram->unuse();
}

void render::TransformFeedbackParticleNode::updateParticleParameter()
{
	uint32_t posSize = 3 * UNIT_SIZE * _particleCount;
	uint32_t speedSize = 3 * UNIT_SIZE * _particleCount;
	uint32_t angleSize = 3 * UNIT_SIZE * _particleCount;

	uint32_t len = posSize + speedSize + angleSize;

	auto buffer = _updateObject->getFeedbackBuffer();

	buffer->bindBuffer();
	buffer->setBufferData(len, BufferDataUsage::DYNAMIC_DRAW);
	float* data = (float*)buffer->getMapBufferRange(0, len, MapBufferRangeAccess::MAP_WRITE_BIT);

	for (int i = 0; i < _particleCount; i++)
	{
		math::Vector3 pos(sys::Random::getNumber0_1(), sys::Random::getNumber0_1(), sys::Random::getNumber0_1());
		math::Vector3 speed(sys::Random::getNumber0_1(), sys::Random::getNumber0_1(), sys::Random::getNumber0_1());
		math::Vector3 angle(sys::Random::getNumber0_1(), sys::Random::getNumber0_1(), sys::Random::getNumber0_1());

		memcpy(data + 3 * i, pos.getValue(), 3 * UNIT_SIZE);
		memcpy(data + posSize + 3 * i, speed.getValue(), 3 * UNIT_SIZE);
		memcpy(data + posSize + speedSize + 3 * i, angle.getValue(), 3 * UNIT_SIZE);
	}

	buffer->unmapBuffer();
	buffer->unbindBuffer();
}

render::TransformFeedbackBufferObject* render::TransformFeedbackParticleNode::getUpdateObject() const
{
	return _updateObject;
}

void render::TransformFeedbackParticleNode::loadShaderProgram(const std::string& vpath, const std::string& fpath)
{
	SAFE_RELEASE(_shaderProgram);

	_shaderProgram = G_SHANDER->createVertexFragmentProgram(vpath, fpath);

	SAFE_RETAIN(_shaderProgram);
}

