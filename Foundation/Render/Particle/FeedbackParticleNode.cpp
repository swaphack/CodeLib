#include "FeedbackParticleNode.h"
#include "Common/Shader/import.h"
#include "Common/Buffer/TransformFeedbackBuffer.h"
#include "Common/XFB/XFeedback.h"
#include "Common/VAO/VertexArrayBufferObject.h"
#include "Graphic/import.h"
#include "Common/Scene/Camera.h"

#define UNIT_SIZE sizeof(float)

render::FeedbackParticleNode::FeedbackParticleNode()
{
	_feedback = CREATE_OBJECT(XFeedback);
	SAFE_RETAIN(_feedback);

	_updateBufferObject = CREATE_OBJECT(VertexArrayBufferObject);
	SAFE_RETAIN(_updateBufferObject);

	_renderBufferObject = CREATE_OBJECT(VertexArrayBufferObject);
	SAFE_RETAIN(_renderBufferObject);
}

render::FeedbackParticleNode::~FeedbackParticleNode()
{

	SAFE_RELEASE(_renderProgram);

	SAFE_RELEASE(_feedback);
	SAFE_RELEASE(_updateBufferObject);
	SAFE_RELEASE(_renderBufferObject);
}

bool render::FeedbackParticleNode::init()
{
	if (!PariticleNode::init())
	{
		return false;
	}

	//const char* varying[] = {"out_Position"};
	//_feedback->loadVertexProgram("Shader/particle/simple_particle_update.vs");
	//_feedback->setWatchVaryings(1, varying);

	_feedback->setInputFunc([this](ShaderProgram* program) {
		GLDebug::showError();

		_updateBufferObject->bindVertexArray();
		_updateBufferObject->bindBuffer();
		GLDebug::showError();
		auto in_position = program->getAttrib("in_position");
		if (in_position)
		{
			_updateBufferObject->enableVertexArrayAttrib(in_position->getAttribID());
		}
		GLDebug::showError();
		auto in_speedAcceleration = program->getAttrib("in_speedAcceleration");
		if (in_speedAcceleration) 
		{
			_updateBufferObject->enableVertexArrayAttrib(in_speedAcceleration->getAttribID());
		}
		GLDebug::showError();
		auto in_angleAcceleration = program->getAttrib("in_angleAcceleration");
		if (in_angleAcceleration)
		{
			_updateBufferObject->enableVertexArrayAttrib(in_angleAcceleration->getAttribID());
		}
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

	_feedback->setOutputFunc([this](TransformFeedbackBuffer* buffer) {
		uint32_t posSize = 3 * UNIT_SIZE * _particleCount;

		GLDebug::showError();
		buffer->bindBuffer();
		float* var = (float*)malloc(posSize);
		buffer->getBufferSubData(0, posSize, var);
		buffer->unbindBuffer();

		GLDebug::showError();
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

void render::FeedbackParticleNode::update(float dt)
{
	if (!_renderProgram)
	{
		return;
	}

	if (_deltaTime >= 10)
	{
		_deltaTime = 0;
	}

	_feedback->run();
	GLDebug::showError();
}

void render::FeedbackParticleNode::draw()
{
	GLState::enable(EnableMode::POINT_SPRITE);
	GLFixedFunction::setTexEnv(TextureEnvTarget::POINT_SPRITE, TextureEnvParameter::COORD_REPLACE, 1);
	GLState::setPointSpriteCoordOrigin(PointSpriteCoordType::LOWER_LEFT);

	_renderProgram->use();
	_renderBufferObject->bindVertexArray();
	_renderBufferObject->bindBuffer();

	GLDebug::showError();
	auto v_position = _renderProgram->getAttrib("v_position");
	if (v_position) _renderBufferObject->enableVertexArrayAttrib(v_position->getAttribID());

	GLDebug::showError();
	_renderProgram->setUniformValue("pointScale", 10.0f);
	_renderProgram->setUniformValue("matrix.project", getCamera()->getProjectMatrix());
	_renderProgram->setUniformValue("matrix.view", getCamera()->getViewMatrix());
	_renderProgram->setUniformValue("matrix.model", _worldMatrix);

	GLDebug::showError();
	GLState::setPointSize(10);
	//GLBufferObjects::drawArrays(DrawMode::TRIANGLES, 0, _particleCount / 3);
	GLBufferObjects::drawArrays(DrawMode::POINTS, 0, _particleCount);
	GLState::setPointSize(1);
	GLDebug::showError();

	_renderBufferObject->unbindVertexArray();
	_renderProgram->unuse();

	GLState::disable(EnableMode::POINT_SPRITE);

	GLDebug::showError();
}

void render::FeedbackParticleNode::updateParticleParameter()
{
	GLDebug::showError();

	uint32_t posSize = 3 * UNIT_SIZE * _particleCount;
	uint32_t speedSize = 3 * UNIT_SIZE * _particleCount;
	uint32_t angleSize = 3 * UNIT_SIZE * _particleCount;

	uint32_t len = posSize + speedSize + angleSize;

	_feedback->setWatchPrimitiveMode(TransformFeedbackPrimitiveMode::POINTS, _particleCount);
	_feedback->setBufferSize(posSize);
	_feedback->setTargetBufferRange(0, 0, posSize);


	_renderBufferObject->bindBuffer();
	_renderBufferObject->resizeBuffer(posSize);
	_renderBufferObject->bindVertexArray();
	_renderBufferObject->setVertexBuffer(0, 3, VertexAttribPointerType::FLOAT, 0, 0);
	_renderBufferObject->unbindVertexArray();
	_renderBufferObject->unbindBuffer();

	GLDebug::showError();

	_updateBufferObject->bindBuffer();
	_updateBufferObject->resizeBuffer(len);
	for (int i = 0; i < _particleCount; i++)
	{
		math::Vector3 pos(sys::Random::getNumber(getWidth() / 2, getWidth()) , sys::Random::getNumber(getHeight() / 2, getHeight()), sys::Random::getNumber(getDepth() / 2, getDepth()));
		math::Vector3 speed(sys::Random::getNumber(1.0f,2.0f), sys::Random::getNumber(1.0f,2.0f), sys::Random::getNumber(1.0f,2.0f));
		math::Vector3 angle(sys::Random::getNumber(1.0f,2.0f), sys::Random::getNumber(1.0f,2.0f), sys::Random::getNumber(1.0f,2.0f));

		_updateBufferObject->setSubBuffer(3 * i, 3 * UNIT_SIZE, pos.getValue());
		_updateBufferObject->setSubBuffer(posSize + 3 * i, 3 * UNIT_SIZE, speed.getValue());
		_updateBufferObject->setSubBuffer(posSize + speedSize + 3 * i, 3 * UNIT_SIZE, angle.getValue());
	}

	_updateBufferObject->bindVertexArray();
	_updateBufferObject->setVertexBuffer(0, 3, VertexAttribPointerType::FLOAT, 0, 0);
	_updateBufferObject->setVertexBuffer(1, 3, VertexAttribPointerType::FLOAT, 0, posSize);
	_updateBufferObject->setVertexBuffer(2, 3, VertexAttribPointerType::FLOAT, 0, posSize + speedSize);

	_updateBufferObject->unbindVertexArray();
	_updateBufferObject->unbindBuffer();

	GLDebug::showError();
}

render::XFeedback* render::FeedbackParticleNode::getUpdateObject() const
{
	return _feedback;
}

void render::FeedbackParticleNode::loadRenderProgram(const std::string& vpath, const std::string& fpath)
{
	SAFE_RELEASE(_renderProgram);

	_renderProgram = G_SHANDER->createVertexFragmentProgram(vpath, fpath);

	SAFE_RETAIN(_renderProgram);
}

void render::FeedbackParticleNode::loadXFBProgram(const std::string& vpath, const std::string& watchVarying)
{
	_feedback->loadVertexProgram(vpath, watchVarying);
}

