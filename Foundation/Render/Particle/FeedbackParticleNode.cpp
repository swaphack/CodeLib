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

		_updateBufferObject->bindBuffer();
		_updateBufferObject->bindVertexArray();
		GLDebug::showError();
		program->enableAttrib(_updateBufferObject, "in_position");
		GLDebug::showError();
		program->enableAttrib(_updateBufferObject, "in_speedAcceleration");
		GLDebug::showError();
		program->enableAttrib(_updateBufferObject, "in_angleAcceleration");
		//_updateBufferObject->unbindVertexArray();
		GLDebug::showError();
		program->setUniformValue("lifeTime", _passedTime);
		program->setUniformValue("deltaTime", _deltaTime);
		program->setUniformValue("maxTime", 10.0f);
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
	_renderBufferObject->setVertexAttribPointer(0, 3, VertexAttribPointerType::FLOAT, 0, 0);
	_renderBufferObject->unbindVertexArray();
	_renderBufferObject->unbindBuffer();

	GLDebug::showError();

	_updateBufferObject->bindBuffer();
	_updateBufferObject->bindVertexArray();

	_updateBufferObject->resizeBuffer(len);
	for (int i = 0; i < _particleCount; i++)
	{
		math::Vector3 pos(sys::Random::getNumber(0,100) , sys::Random::getNumber(0, 100), sys::Random::getNumber(-100, 100));
		math::Vector3 speed(sys::Random::getNumber(1.0f,20.0f), sys::Random::getNumber(1.0f,20.0f), sys::Random::getNumber(1.0f,20.0f));
		math::Vector3 angle(sys::Random::getNumber(1.0f,20.0f), sys::Random::getNumber(1.0f,20.0f), sys::Random::getNumber(1.0f,20.0f));

		_updateBufferObject->setSubBuffer(3 * i, 3 * UNIT_SIZE, pos.getValue());
		_updateBufferObject->setSubBuffer(posSize + 3 * i, 3 * UNIT_SIZE, speed.getValue());
		_updateBufferObject->setSubBuffer(posSize + speedSize + 3 * i, 3 * UNIT_SIZE, angle.getValue());
	}

	_updateBufferObject->setVertexAttribPointer(0, 3, VertexAttribPointerType::FLOAT, 0, 0);
	_updateBufferObject->setVertexAttribPointer(1, 3, VertexAttribPointerType::FLOAT, 0, posSize);
	_updateBufferObject->setVertexAttribPointer(2, 3, VertexAttribPointerType::FLOAT, 0, posSize + speedSize);

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

