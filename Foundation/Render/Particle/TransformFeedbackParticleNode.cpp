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

	_updateBufferObject = CREATE_OBJECT(VertexArrayBufferObject);
	SAFE_RETAIN(_updateBufferObject);

	_renderBufferObject = CREATE_OBJECT(VertexArrayBufferObject);
	SAFE_RETAIN(_renderBufferObject);
}

render::TransformFeedbackParticleNode::~TransformFeedbackParticleNode()
{

	SAFE_RELEASE(_shaderProgram);

	SAFE_RELEASE(_updateObject);
	SAFE_RELEASE(_updateBufferObject);
	SAFE_RELEASE(_renderBufferObject);
}

bool render::TransformFeedbackParticleNode::init()
{
	if (!PariticleNode::init())
	{
		return false;
	}

	const char* varying[] = {"out_Position"};

	
	_updateObject->loadVertexProgram("Shader/particle/simple_particle_update.vs");
	_updateObject->setWatchVaryings(1, varying);

	_updateObject->setInputFunc([this](ShaderProgram* program) {
		GLDebug::showError();

		_updateBufferObject->bindVertexArray();
		_updateBufferObject->bindBuffer();
		GLDebug::showError();
		auto in_position = program->getAttrib("in_position");
		if (in_position) _updateBufferObject->enableVertexArrayAttrib(in_position->getAttribID());
		GLDebug::showError();
		auto in_speedAcceleration = program->getAttrib("in_speedAcceleration");
		if (in_speedAcceleration) _updateBufferObject->enableVertexArrayAttrib(in_speedAcceleration->getAttribID());
		GLDebug::showError();
		auto in_angleAcceleration = program->getAttrib("in_angleAcceleration");
		if (in_angleAcceleration) _updateBufferObject->enableVertexArrayAttrib(in_angleAcceleration->getAttribID());
		//_updateBufferObject->unbindVertexArray();
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
		_updateBufferObject->unbindVertexArray();

		uint32_t posSize = 3 * UNIT_SIZE * _particleCount;

		GLDebug::showError();
		buffer->bindBuffer();
		float* data = (float*)buffer->getMapBufferRange(0, posSize, MapBufferRangeAccess::MAP_READ_BIT);
		float* var = (float*)malloc(posSize);
		memcpy(var, data, posSize);
		buffer->unmapBuffer();
		buffer->unbindBuffer();
		GLDebug::showError();
		_renderBufferObject->bindBuffer();
		_renderBufferObject->setSubBuffer(0, posSize, var);
		_renderBufferObject->unbindBuffer();

		_updateBufferObject->bindBuffer();
		_updateBufferObject->setSubBuffer(0, posSize, var);
		_updateBufferObject->unbindBuffer();
		free(var);
		GLDebug::showError();
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
	_renderBufferObject->bindVertexArray();
	_renderBufferObject->bindBuffer();

	GLDebug::showError();
	auto v_position = _shaderProgram->getAttrib("v_position");
	if (v_position) _renderBufferObject->enableVertexArrayAttrib(v_position->getAttribID());

	GLDebug::showError();
	auto pointScale = _shaderProgram->getUniform("pointScale");
	if (pointScale) pointScale->setValue(10.0f);

	GLDebug::showError();
	GLState::setPointSize(10);
	//GLBufferObjects::drawArrays(DrawMode::TRIANGLES, 0, _particleCount / 3);
	GLBufferObjects::drawArrays(DrawMode::POINTS, 0, _particleCount);
	GLState::setPointSize(1);
	GLDebug::showError();

	_renderBufferObject->unbindVertexArray();
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

	_updateObject->setWatchPrimitiveMode(TransformFeedbackPrimitiveMode::POINTS, _particleCount);
	_updateObject->setBufferSize(posSize);
	_updateObject->setTargetBufferRange(0, 0, posSize);

	_renderBufferObject->bindVertexArray();
	_renderBufferObject->bindBuffer();
	_renderBufferObject->resizeBuffer(posSize);
	_renderBufferObject->setVertexBuffer(0, 3, VertexAttribPointerType::FLOAT, 0, 0);
	_renderBufferObject->unbindVertexArray();

	GLDebug::showError();

	_updateBufferObject->bindVertexArray();
	_updateBufferObject->bindBuffer();
	_updateBufferObject->resizeBuffer(len);
	for (int i = 0; i < _particleCount; i++)
	{
		math::Vector3 pos(sys::Random::getNumber(getWidth() / 2, getWidth()) , sys::Random::getNumber(getHeight() / 2, getHeight()), sys::Random::getNumber(getDepth() / 2, getDepth()));
		math::Vector3 speed(sys::Random::getNumber0_1(), sys::Random::getNumber0_1(), sys::Random::getNumber0_1());
		math::Vector3 angle(sys::Random::getNumber0_1(), sys::Random::getNumber0_1(), sys::Random::getNumber0_1());

		_updateBufferObject->setSubBuffer(3 * i, 3 * UNIT_SIZE, pos.getValue());
		_updateBufferObject->setSubBuffer(posSize + 3 * i, 3 * UNIT_SIZE, speed.getValue());
		_updateBufferObject->setSubBuffer(posSize + speedSize + 3 * i, 3 * UNIT_SIZE, angle.getValue());
	}

	_updateBufferObject->setVertexBuffer(0, 3, VertexAttribPointerType::FLOAT, 0, 0);
	_updateBufferObject->setVertexBuffer(1, 3, VertexAttribPointerType::FLOAT, 0, posSize);
	_updateBufferObject->setVertexBuffer(2, 3, VertexAttribPointerType::FLOAT, 0, posSize + speedSize);

	_updateBufferObject->unbindVertexArray();
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

