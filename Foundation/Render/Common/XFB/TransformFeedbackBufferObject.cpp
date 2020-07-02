#include "TransformFeedbackBufferObject.h"
#include "Common/Shader/ShaderProgram.h"
#include "Common/Shader/ShaderManager.h"
#include "Common/Buffer/TransformFeedbackBuffer.h"
#include "TransformFeedback.h"
#include "Graphic/import.h"
#include "Common/VAO/VertexArrayObject.h"
#include "Common/Buffer/ArrayBuffer.h"

render::TransformFeedbackBufferObject::TransformFeedbackBufferObject()
{
	this->initXFB();
}

render::TransformFeedbackBufferObject::~TransformFeedbackBufferObject()
{
	this->releaseXFB();
}

void render::TransformFeedbackBufferObject::loadVertexProgram(const std::string& vertexFilepath)
{
	SAFE_RELEASE(_shaderProgram);
	_shaderProgram = (ShaderProgram*)G_SHANDER->createVertexProgram(vertexFilepath, false);
	SAFE_RETAIN(_shaderProgram);

	_transformFeedback->setShaderProgram(_shaderProgram);

	_discardFragment = true;
}

render::ShaderProgram* render::TransformFeedbackBufferObject::getShaderProgram() const
{
	return _shaderProgram;
}

render::TransformFeedbackBuffer* render::TransformFeedbackBufferObject::getFeedbackBuffer() const
{
	return _transformFeedbackBuffer;
}

void render::TransformFeedbackBufferObject::loadVertexFragmentProgram(const std::string& vertexFilepath, const std::string& fragmentFilepath)
{
	SAFE_RELEASE(_shaderProgram);
	_shaderProgram = (ShaderProgram*)G_SHANDER->createVertexFragmentProgram(vertexFilepath, false);
	SAFE_RETAIN(_shaderProgram);

	_transformFeedback->setShaderProgram(_shaderProgram);

	_discardFragment = false;
}

void render::TransformFeedbackBufferObject::setInputFunc(const XFBProgramFunc& func)
{
	_inputFunc = func;
}

void render::TransformFeedbackBufferObject::setOutputFunc(const XFBBufferFunc& func)
{
	_outputFunc = func;
}
void render::TransformFeedbackBufferObject::setBufferSize(uint32_t size)
{
	if (_transformFeedbackBuffer == nullptr)
	{
		return;
	}

	_bufferSize = size;

	_transformFeedbackBuffer->bindBuffer();
	_transformFeedbackBuffer->setBufferData(_bufferSize, nullptr, BufferDataUsage::STATIC_READ);
	_transformFeedbackBuffer->unbindBuffer();
}

void render::TransformFeedbackBufferObject::setTargetBufferRange(int index, uint32_t offset, uint32_t size)
{
	if (_transformFeedback == nullptr)
	{
		return;
	}

	ASSERT(_bufferSize >= offset + size);

	_transformFeedback->bindTransformFeedback();
	_transformFeedback->setBufferRange(index, offset, size);
	_transformFeedback->unbindTransformFeedback();
	GLDebug::showError();
}

void render::TransformFeedbackBufferObject::setWatchVaryings(int count, const char** varyings)
{
	if (varyings == nullptr)
	{
		return;
	}

	if (_transformFeedback == nullptr)
	{
		return;
	}

	ASSERT(_shaderProgram != nullptr);

	_transformFeedback->setFeedbackVaryings(count, varyings, TransformFeedbackBufferMode::INTERLEAVED_ATTRIBS);

	_shaderProgram->link();
	GLDebug::showError();

	_shaderProgram->validate();
}

void render::TransformFeedbackBufferObject::setWatchPrimitiveMode(TransformFeedbackPrimitiveMode mode, uint32_t count)
{
	_primitiveMode = mode;
	_watchCount = count;
}

void render::TransformFeedbackBufferObject::run()
{
	if (_shaderProgram == nullptr)
	{
		return;
	}
	GLDebug::showError();
	if (!_shaderProgram->isValid())
	{
		int a = 1;
	}
	_shaderProgram->use();
	GLDebug::showError();
	if (_inputFunc)
	{
		_inputFunc(_shaderProgram);
	}

	GLDebug::showError();

	_transformFeedbackBuffer->bindBuffer();	
	
	GLDebug::showError();

	if (_discardFragment)
	{
		GLState::enable(EnableMode::RASTERIZER_DISCARD);
	}

	//_transformFeedbackBuffer->bindBufferBase(0);

	_transformFeedback->bindTransformFeedback();
	_transformFeedback->beginWatch(_primitiveMode);
	GLDebug::showError();
	GLBufferObjects::drawArrays(DrawMode::POINTS, 0, _watchCount);
	GLDebug::showError();
	_transformFeedback->endWatch();

	if (_discardFragment)
	{
		GLState::disable(EnableMode::RASTERIZER_DISCARD);
	}

	GLRender::flush();
	//
	GLDebug::showError();
	_shaderProgram->unuse();
	GLDebug::showError();

	if (_outputFunc)
	{
		_outputFunc(_transformFeedbackBuffer);
	}

	_transformFeedbackBuffer->unbindBuffer();
	_transformFeedback->unbindTransformFeedback();
}

void render::TransformFeedbackBufferObject::initXFB()
{
	_transformFeedbackBuffer = CREATE_OBJECT(TransformFeedbackBuffer);
	SAFE_RETAIN(_transformFeedbackBuffer);

	_transformFeedback = CREATE_OBJECT(TransformFeedback);
	SAFE_RETAIN(_transformFeedback);

	_transformFeedback->setBuffer(_transformFeedbackBuffer);

	_transformFeedback->bindTransformFeedback();
	_transformFeedbackBuffer->bindBufferBase(0);
	_transformFeedback->unbindTransformFeedback();
}

void render::TransformFeedbackBufferObject::releaseXFB()
{
	SAFE_RELEASE(_transformFeedbackBuffer);
	SAFE_RELEASE(_transformFeedback);

	SAFE_RELEASE(_shaderProgram);
}

