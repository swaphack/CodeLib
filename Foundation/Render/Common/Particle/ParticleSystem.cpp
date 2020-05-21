#include "ParticleSystem.h"
#include "Common/Transform/import.h"
#include "Common/Shader/import.h"
#include "Common/Buffer/import.h"
#include "Common/BufferObject/import.h"
#include "Graphic/import.h"
#include "Common/Tool/Tool.h"
#include "Common/Texture/import.h"

render::FeedbackProgram::FeedbackProgram()
{
	program = CREATE_OBJECT(ShaderProgram);
	feedback = CREATE_OBJECT(TransformFeedbackObject);
	vao = CREATE_OBJECT(VertexArrayObject);
	buffer = CREATE_OBJECT(TransformFeedbackBuffer);

	feedback->setShaderProgram(program);
	vao->setBuffer(buffer);

	SAFE_RETAIN(program);
	SAFE_RETAIN(feedback);
	SAFE_RETAIN(vao);
	SAFE_RETAIN(buffer);
}

render::FeedbackProgram::~FeedbackProgram()
{
	SAFE_RELEASE(program);
	SAFE_RELEASE(feedback);
	SAFE_RELEASE(buffer);
	SAFE_RELEASE(vao);
}

void render::FeedbackProgram::initShaderProgram(const std::string& vpath, const std::string& fpath)
{
	program->loadVertexAndFragmentShader(vpath, fpath);
}

void render::FeedbackProgram::doFunc(ParticleSystem* node)
{
	if (program && func)
	{
		func(node, program);
	}
}

//////////////////////////////////////////////////////////////////////////
render::ParticleSystem::ParticleSystem()
{
	_renderTBO = CREATE_OBJECT(TextureBufferObject);
	SAFE_RETAIN(_renderTBO);

	_renderTB = CREATE_OBJECT(TextureBuffer);
	SAFE_RETAIN(_renderTB);

	_renderVAO = CREATE_OBJECT(VertexArrayObject);
	SAFE_RETAIN(_renderVAO);

	_renderVAO->setBuffer(_renderTB);
	_renderTBO->setBuffer(_renderTB);
	_renderTBO->setTexture(CREATE_OBJECT(Texture2D));
}

render::ParticleSystem::~ParticleSystem()
{
	SAFE_RELEASE(_renderTBO);
	SAFE_RELEASE(_renderTB);
}

bool render::ParticleSystem::init()
{
	if (!Node::init())
	{
		return false;
	}

	_notify->addListen(NodeNotifyType::PARTICLE, [&]() {
		this->onParticleChange();
	});

	return true;
}

void render::ParticleSystem::draw()
{
	_renderProgram.program->use();
	_renderProgram.doFunc(this);

	_renderVAO->bindVertexArray();
	GLBufferObjects::bindBufferBase(BufferTarget::TRANSFORM_FEEDBACK_BUFFER, 0, _renderTB->getBufferID());

	_renderProgram.feedback->beginWatch(TransformFeedbackPrimitiveMode::TRIANGLES);
	// render;
	_renderProgram.feedback->endWatch();

	_updateProgram.program->use();
	_renderProgram.doFunc(this);

	if ((_frameCount & 1) != 0)
	{
		_renderProgram.vao->bindVertexArray();
		_updateProgram.buffer->setBufferBase(0);
	}
	else
	{
		_updateProgram.vao->bindVertexArray();
		_renderProgram.buffer->setBufferBase(0);
	}

	_renderProgram.feedback->beginWatch(TransformFeedbackPrimitiveMode::TRIANGLES);
	GLBufferObjects::drawArrays(DrawMode::POINTS, 0, _particleCount);
	_renderProgram.feedback->endWatch();

	GLState::disable(EnableMode::TEXTURE_2D);
	GLVertexArrays::bindVertexArray(0);
	GLShader::useProgram(0);
	GLDebug::showError();

	_frameCount++;
}

render::FeedbackProgram* render::ParticleSystem::getUpdateFeedback() const
{
	return (render::FeedbackProgram*)&_updateProgram;
}

render::FeedbackProgram* render::ParticleSystem::getRenderFeedback() const
{
	return (render::FeedbackProgram*)&_renderProgram;
}

void render::ParticleSystem::setParticleCount(int count)
{
	_particleCount = count;

	this->notify(NodeNotifyType::PARTICLE);
}

int render::ParticleSystem::getParticleCount() const
{
	return _particleCount;
}

struct buffer_t
{
	math::Vector3 position;
	math::Vector3 velocity;
};

uint32_t render::ParticleSystem::getTextureID()
{
	if (_renderTBO == nullptr || _renderTBO->getTexture() == nullptr)
	{
		return 0;
	}
	return _renderTBO->getTexture()->getTextureID();
}

void render::ParticleSystem::onParticleChange()
{
	int size = 6 * sizeof(float);
	_updateProgram.buffer->bindBuffer();
	_updateProgram.buffer->setBufferData(_particleCount * size, BufferDataUsage::DYNAMIC_COPY);

	float* buffer = (float*)_updateProgram.buffer->getMapBuffer(AccessType::WRITE_ONLY);
	for (int i = 0; i < _particleCount; i++)
	{
		math::Vector3 pos = math::Vector3(sys::Random::getNumber0_1(), sys::Random::getNumber0_1(), sys::Random::getNumber0_1());
		pos = pos + math::Vector3(-0.5f, 120.0f, 0.0f);
		memcpy(buffer + i * 3, pos.getValue(), 3 * sizeof(float));

		pos = math::Vector3(pos.getX(), pos.getY() * 0.3f, pos.getZ() * 0.3f);
		memcpy(buffer + i * 3 + 3, pos.getValue(), 3 * sizeof(float));
	}
	_updateProgram.buffer->unmapBuffer();	

	_updateProgram.vao->bindVertexArray();
	_updateProgram.vao->bindBuffer();
	{
		render::VertexAttribPointer* pointer0 = _updateProgram.vao->getVertexAttrib<render::VertexAttribPointer>(0);
		pointer0->setVertexAttribPointer(3, VertexAttribPointerType::FLOAT, size, 0);
		pointer0->enableVertexArrayAttrib();

		render::VertexAttribPointer* pointer1 = _updateProgram.vao->getVertexAttrib<render::VertexAttribPointer>(1);
		pointer1->setVertexAttribPointer(3, VertexAttribPointerType::FLOAT, size, 3 * sizeof(float));
		pointer1->enableVertexArrayAttrib();
	}

	_renderProgram.buffer->bindBuffer();
	_renderProgram.buffer->setBufferData(_particleCount * size, BufferDataUsage::DYNAMIC_COPY);

	_renderProgram.vao->bindVertexArray();
	_renderProgram.vao->bindBuffer();
	{
		render::VertexAttribPointer* pointer0 = _renderProgram.vao->getVertexAttrib<render::VertexAttribPointer>(0);
		pointer0->setVertexAttribPointer(3, VertexAttribPointerType::FLOAT, size, 0);
		pointer0->enableVertexArrayAttrib();

		render::VertexAttribPointer* pointer1 = _renderProgram.vao->getVertexAttrib<render::VertexAttribPointer>(1);
		pointer1->setVertexAttribPointer(3, VertexAttribPointerType::FLOAT, size, 3 * sizeof(float));
		pointer1->enableVertexArrayAttrib();
	}

	math::Volume volume = Tool::getGLViewSize();

	_renderTB->bindBuffer();
	_renderTB->setBufferData(volume.getWidth() * volume.getHeight() * 4 * sizeof(float), BufferDataUsage::DYNAMIC_COPY);
	_renderTBO->bindTexture();
	_renderTBO->setFormat(TexSizedInternalFormat::RGBA32F);

	_renderVAO->bindVertexArray();
	{
		render::VertexAttribPointer* pointer0 = _renderVAO->getVertexAttrib<render::VertexAttribPointer>(0);
		pointer0->setVertexAttribPointer(3, VertexAttribPointerType::FLOAT, 0);
		pointer0->enableVertexArrayAttrib();
	}

	GLDebug::showError();
}
