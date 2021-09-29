#include "XFeedback.h"
#include "Common/Shader/ShaderProgram.h"
#include "Common/Shader/ShaderManager.h"
#include "Common/Buffer/TransformFeedbackBuffer.h"
#include "XFBBufferObject.h"
#include "Graphic/import.h"
#include "Common/VAO/VertexArrayObject.h"
#include "Common/Buffer/ArrayBuffer.h"

render::XFeedback::XFeedback()
{
	this->initXFB();
}

render::XFeedback::~XFeedback()
{
	this->releaseXFB();
}

void render::XFeedback::loadVertexProgram(const std::string& vertexFilepath, const std::string& watchVarying)
{
	SAFE_RELEASE(_shaderProgram);
	_shaderProgram = G_SHANDER->createVertexProgram(vertexFilepath, false);
	if (_shaderProgram == nullptr) return;
	SAFE_RETAIN(_shaderProgram);

	_discardFragment = true;

	const char* varyings[] = { watchVarying.c_str() };
	GLTransformFeedback::setTransformFeedbackVaryings(
		_shaderProgram->getProgramID(), 
		1, varyings, 
		TransformFeedbackBufferMode::INTERLEAVED_ATTRIBS);

	_shaderProgram->link();
	GLDebug::showError();

	_shaderProgram->validate();
}

void render::XFeedback::loadVertexProgram(const std::string& vertexFilepath, int count, const char** varyings)
{
	SAFE_RELEASE(_shaderProgram);
	_shaderProgram = G_SHANDER->createVertexProgram(vertexFilepath, false);
	if (_shaderProgram == nullptr) return;
	SAFE_RETAIN(_shaderProgram);

	_discardFragment = true;
	GLTransformFeedback::setTransformFeedbackVaryings(
		_shaderProgram->getProgramID(),
		count, varyings,
		TransformFeedbackBufferMode::INTERLEAVED_ATTRIBS);

	_shaderProgram->link();
	GLDebug::showError();

	_shaderProgram->validate();
}

render::ShaderProgram* render::XFeedback::getShaderProgram() const
{
	return _shaderProgram;
}

render::TransformFeedbackBuffer* render::XFeedback::getFeedbackBuffer() const
{
	return _XFBBuffer;
}

void render::XFeedback::loadVertexFragmentProgram(const std::string& vertexFilepath, const std::string& fragmentFilepath)
{
	SAFE_RELEASE(_shaderProgram);
	_shaderProgram = G_SHANDER->createVertexFragmentProgram(vertexFilepath, fragmentFilepath, false);
	SAFE_RETAIN(_shaderProgram);

	_discardFragment = false;
}

void render::XFeedback::setInputFunc(const XFBProgramFunc& func)
{
	_inputFunc = func;
}

void render::XFeedback::setOutputFunc(const XFBBufferFunc& func)
{
	_outputFunc = func;
}
void render::XFeedback::setBufferSize(uint32_t size)
{
	if (_XFBBuffer == nullptr)
	{
		return;
	}

	_bufferSize = size;

	_XFBBuffer->bindBuffer();
	_XFBBuffer->setBufferData(_bufferSize, nullptr, BufferDataUsage::STATIC_READ);
	_XFBBuffer->unbindBuffer();
}

void render::XFeedback::setTargetBufferRange(int index, uint32_t offset, uint32_t size)
{
	if (_XFBObject == nullptr)
	{
		return;
	}

	ASSERT(_bufferSize >= offset + size);

	_XFBObject->bindTransformFeedback();
	_XFBObject->setBufferRange(index, offset, size);
	_XFBObject->unbindTransformFeedback();
	GLDebug::showError();
}

void render::XFeedback::setWatchPrimitiveMode(TransformFeedbackPrimitiveMode mode, uint32_t count)
{
	_primitiveMode = mode;
	_watchCount = count;
}

void render::XFeedback::run()
{
	if (_shaderProgram == nullptr)
	{
		return;
	}
	GLDebug::showError();
	_shaderProgram->use();
	GLDebug::showError();
	if (_inputFunc)
	{
		_inputFunc(_shaderProgram);
	}

	GLDebug::showError();

	_XFBBuffer->bindBuffer();	
	
	GLDebug::showError();

	if (_discardFragment)
	{
		GLState::enable(EnableMode::RASTERIZER_DISCARD);
	}

	_XFBBuffer->bindBufferBase(0);
	// 
	// Ö´ÐÐshader
	_XFBObject->bindTransformFeedback();
	GLDebug::showError();
	GLTransformFeedback::beginTransformFeedback(_primitiveMode);
	GLDebug::showError();
	//GLTransformFeedback::drawTransformFeedback(DrawTransformFeedbackMode::POINTS, _XFBObject->getTransformFeedbackID());
	GLBufferObjects::drawArrays((DrawMode)_primitiveMode, 0, _watchCount);
	GLDebug::showError();
	GLTransformFeedback::endTransformFeedback();

	if (_discardFragment)
	{
		GLState::disable(EnableMode::RASTERIZER_DISCARD);
	}

	GLRender::finish();
	//
	GLDebug::showError();
	_shaderProgram->unuse();
	GLDebug::showError();
	_XFBBuffer->unbindBuffer();
	_XFBObject->unbindTransformFeedback();
	if (_outputFunc)
	{
		_outputFunc(_XFBBuffer);
	}
	GLDebug::showError();
}

void render::XFeedback::initXFB()
{
	_XFBBuffer = CREATE_OBJECT(TransformFeedbackBuffer);
	SAFE_RETAIN(_XFBBuffer);

	_XFBObject = CREATE_OBJECT(XFBBufferObject);
	SAFE_RETAIN(_XFBObject);

	_XFBObject->setBuffer(_XFBBuffer);

	_XFBObject->bindTransformFeedback();
	_XFBBuffer->bindBufferBase(0);
	_XFBObject->unbindTransformFeedback();
}

void render::XFeedback::releaseXFB()
{
	SAFE_RELEASE(_XFBBuffer);
	SAFE_RELEASE(_XFBObject);

	SAFE_RELEASE(_shaderProgram);
}

