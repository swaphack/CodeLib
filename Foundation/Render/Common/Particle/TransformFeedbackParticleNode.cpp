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
	_updateObject->loadVertexProgram("Shader/particle/simple_particle_update.vs");
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
		GLDebug::showError();
		float* data = (float*)buffer->getMapBufferRange(0, len, MapBufferRangeAccess::MAP_READ_BIT);
		_renderObject->resizeBuffer(len);
		GLDebug::showError();
		_renderObject->setSubBuffer(0, posSize, data);
		_renderObject->setSubBuffer(posSize, speedSize, data + posSize);
		_renderObject->setSubBuffer(posSize + speedSize, angleSize, data + posSize + speedSize);
		buffer->unmapBuffer();
		buffer->unbindBuffer();

		GLDebug::showError();
		_renderObject->setVertexBuffer(0, 3, VertexAttribPointerType::FLOAT, 0, 0);
		_renderObject->setVertexBuffer(1, 3, VertexAttribPointerType::FLOAT, 0, posSize);
		_renderObject->setVertexBuffer(2, 3, VertexAttribPointerType::FLOAT, 0, posSize + speedSize);

		GLDebug::showError();

		_renderObject->bindVertexArray();
		GLDebug::showError();
		auto in_position = program->getAttrib("in_position");
		if (in_position) _renderObject->enableVertexArrayAttrib(in_position->getAttribID());
		GLDebug::showError();
		auto in_speedAcceleration = program->getAttrib("in_speedAcceleration");
		if (in_speedAcceleration) _renderObject->enableVertexArrayAttrib(in_speedAcceleration->getAttribID());
		GLDebug::showError();
		auto in_angleAcceleration = program->getAttrib("in_angleAcceleration");
		if (in_angleAcceleration) _renderObject->enableVertexArrayAttrib(in_angleAcceleration->getAttribID());
		_renderObject->unbindVertexArray();
		GLDebug::showError();
		auto lifeTime = program->getUniform("lifeTime");
		if (lifeTime) lifeTime->setValue(_passedTime);
		GLDebug::showError();
		auto deltaTime = program->getUniform("deltaTime");
		if (deltaTime) deltaTime->setValue(_deltaTime);
		GLDebug::showError();
		auto maxTime = program->getUniform("maxTime");
		if (maxTime) maxTime->setValue(10.0f);
		
		GLDebug::showError();
		GLDebug::showError();
	});

	_updateObject->setOutputFunc([this](TransformFeedbackBuffer* buffer) {
		_renderObject->unbindVertexArray();

		uint32_t posSize = 3 * UNIT_SIZE * _particleCount;
		uint32_t speedSize = 3 * UNIT_SIZE * _particleCount;
		uint32_t angleSize = 3 * UNIT_SIZE * _particleCount;

		uint32_t len = posSize + speedSize + angleSize;
		GLDebug::showError();
		buffer->bindBuffer();
		float* data = (float*)buffer->getMapBufferRange(0, len, MapBufferRangeAccess::MAP_READ_BIT);
		GLDebug::showError();
		_renderObject->resizeBuffer(len);
		_renderObject->setSubBuffer(0, posSize, data);
		_renderObject->setSubBuffer(posSize, speedSize, data + posSize);
		_renderObject->setSubBuffer(posSize + speedSize, angleSize, data + posSize + speedSize);
		GLDebug::showError();
		buffer->unmapBuffer();
		buffer->unbindBuffer();
		GLDebug::showError();
		_renderObject->setVertexBuffer(0, 3, VertexAttribPointerType::FLOAT, 0, 0);
		_renderObject->setVertexBuffer(1, 3, VertexAttribPointerType::FLOAT, 0, posSize);
		_renderObject->setVertexBuffer(2, 3, VertexAttribPointerType::FLOAT, 0, posSize + speedSize);
		GLDebug::showError();
	});

	return true;
}

void render::TransformFeedbackParticleNode::update(float dt)
{
	if (!_shaderProgram)
	{
		return;
	}

	if (_deltaTime >= 10)
	{
		_deltaTime = 0;
	}

	_updateObject->run();
	GLDebug::showError();

	GLState::enable(EnableMode::POINT_SPRITE);
	GLFixedFunction::setTexEnv(TextureEnvTarget::POINT_SPRITE, TextureEnvParameter::COORD_REPLACE, 1);
	GLState::setPointSpriteCoordOrigin(PointSpriteCoordType::LOWER_LEFT);
	
	_shaderProgram->use();
	_renderObject->bindVertexArray();

	GLDebug::showError();
	auto v_position = _shaderProgram->getAttrib("v_position");
	if (v_position) _renderObject->enableVertexArrayAttrib(v_position->getAttribID());

	GLDebug::showError();
	auto pointScale = _shaderProgram->getUniform("pointScale");
	if (pointScale) pointScale->setValue(10.0f);

	GLDebug::showError();
	GLState::setPointSize(10);
	GLBufferObjects::drawArrays(DrawMode::POINTS, 0, _particleCount);
	GLState::setPointSize(1);
	GLDebug::showError();

	_renderObject->unbindVertexArray();
	_shaderProgram->unuse();

	GLState::disable(EnableMode::POINT_SPRITE);

	GLDebug::showError();
}

void render::TransformFeedbackParticleNode::updateParticleParameter()
{
	GLDebug::showError();
	uint32_t posSize = 3 * UNIT_SIZE * _particleCount;
	uint32_t speedSize = 3 * UNIT_SIZE * _particleCount;
	uint32_t angleSize = 3 * UNIT_SIZE * _particleCount;

	uint32_t len = posSize + speedSize + angleSize;

	auto buffer = _updateObject->getFeedbackBuffer();
	
	buffer->bindBuffer();
	buffer->setBufferData(len, BufferDataUsage::STATIC_DRAW);
	for (int i = 0; i < _particleCount; i++)
	{
		math::Vector3 pos(sys::Random::getNumber0_1(), sys::Random::getNumber0_1(), sys::Random::getNumber0_1());
		math::Vector3 speed(sys::Random::getNumber0_1(), sys::Random::getNumber0_1(), sys::Random::getNumber0_1());
		math::Vector3 angle(sys::Random::getNumber0_1(), sys::Random::getNumber0_1(), sys::Random::getNumber0_1());

		buffer->setBufferSubData(3 * i, 3 * UNIT_SIZE, pos.getValue());
		buffer->setBufferSubData(posSize + 3 * i, 3 * UNIT_SIZE, pos.getValue());
		buffer->setBufferSubData(posSize + speedSize + 3 * i, 3 * UNIT_SIZE, pos.getValue());
	}

	buffer->unbindBuffer();

	GLDebug::showError();
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

