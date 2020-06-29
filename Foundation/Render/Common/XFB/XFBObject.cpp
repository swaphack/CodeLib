#include "XFBObject.h"
#include "Common/Shader/ShaderProgram.h"
#include "Common/Shader/ShaderManager.h"
#include "Common/Buffer/TransformFeedbackBuffer.h"
#include "TransformFeedback.h"
#include "Graphic/import.h"
#include "Common/VAO/VertexArrayObject.h"
#include "Common/Buffer/ArrayBuffer.h"

render::XFBObject::XFBObject()
{
	this->initXFB();
}

render::XFBObject::~XFBObject()
{
	this->releaseXFB();
}

void render::XFBObject::loadVertexProgram(const std::string& vertexFilepath)
{
	SAFE_RELEASE(_vertexProgram);
	_vertexProgram = (ShaderProgram*)G_SHANDER->createVertexProgram(vertexFilepath);
	SAFE_RETAIN(_vertexProgram);

	_transformFeedback->setShaderProgram(_vertexProgram);
}

void render::XFBObject::setInputFunc(const XFBProgramFunc& func)
{
	_inputFunc = func;
}

void render::XFBObject::setOutputFunc(const XFBBufferFunc& func)
{
	_outputFunc = func;
}
void render::XFBObject::setBufferSize(uint32_t size)
{
	if (_transformFeedbackBuffer == nullptr)
	{
		return;
	}

	_bufferSize = size;

	_transformFeedbackBuffer->bindBuffer();
	_transformFeedbackBuffer->setBufferData(size, nullptr, BufferDataUsage::STREAM_DRAW);
	_transformFeedbackBuffer->unbindBuffer();
	GLDebug::showError();
}

void render::XFBObject::setTargetBufferRange(int index, uint32_t offset, uint32_t size)
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

void render::XFBObject::setWatchVaryings(int count, const char** varyings, TransformFeedbackBufferMode mode)
{
	if (varyings == nullptr)
	{
		return;
	}

	if (_transformFeedback == nullptr)
	{
		return;
	}

	ASSERT(_vertexProgram != nullptr);

	_transformFeedback->setFeedbackVaryings(count, varyings, mode);

	_vertexProgram->link();
	GLDebug::showError();

	_vertexProgram->validate();
}

void render::XFBObject::setWatchPrimitiveMode(TransformFeedbackPrimitiveMode mode, uint32_t count)
{
	_primitiveMode = mode;
	_watchCount = count;
}

void render::XFBObject::draw()
{
	if (_hadDraw)
	{
		return;
	}

	//_hadDraw = true;

	if (_vertexProgram == nullptr)
	{
		return;
	}
	GLDebug::showError();
	if (!_vertexProgram->isValid())
	{
		int a = 1;
	}
	_vertexProgram->use();
	GLDebug::showError();
	if (_inputFunc)
	{
		_inputFunc(_vertexProgram);
	}

	GLDebug::showError();

	GLState::enable(EnableMode::RASTERIZER_DISCARD);

	_transformFeedback->bindTransformFeedback();
	_transformFeedback->beginWatch(_primitiveMode);
	GLDebug::showError();
	GLBufferObjects::drawArrays(DrawMode::POINTS, 0, _watchCount);
	GLDebug::showError();
	_transformFeedback->endWatch();
	_transformFeedback->unbindTransformFeedback();
	GLDebug::showError();

	GLState::disable(EnableMode::RASTERIZER_DISCARD);
	_vertexProgram->unuse();
	GLDebug::showError();

	if (_outputFunc)
	{
		_outputFunc(_transformFeedbackBuffer);
	}
}

void render::XFBObject::initXFB()
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

void render::XFBObject::releaseXFB()
{
	SAFE_RELEASE(_transformFeedbackBuffer);
	SAFE_RELEASE(_transformFeedback);

	SAFE_RELEASE(_vertexProgram);
}

