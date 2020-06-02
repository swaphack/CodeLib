#include "Calculator.h"
#include "Common/Shader/import.h"
#include "Common/VAO/import.h"
#include "Common/XFB/TransformFeedback.h"
#include "Common/Buffer/import.h"
#include "ShaderDocument.h"
#include "ShaderVariableType.h"
#include "ShaderParameter.h"
#include "Graphic/import.h"

render::Calculator::Calculator()
{
	_shaderProgram = CREATE_OBJECT(ShaderProgram);
	SAFE_RETAIN(_shaderProgram);

	_xfbObject = CREATE_OBJECT(TransformFeedback);
	SAFE_RETAIN(_xfbObject);

	_xfbBuffer = CREATE_OBJECT(TransformFeedbackBuffer);
	SAFE_RETAIN(_xfbBuffer);

	_xfbObject->setBuffer(_xfbBuffer);
}

render::Calculator::~Calculator()
{
	SAFE_RELEASE(_shaderProgram);
	SAFE_RELEASE(_xfbObject);
	SAFE_RELEASE(_xfbBuffer);
}

void render::Calculator::setProgramFunc(const ShaderProgramFunc& func)
{
	_shaderProgramFunc = func;
}

void render::Calculator::run()
{
	if (_shaderProgram == nullptr)
	{
		return;
	}

	this->calOutputBuffer();

	_shaderProgram->use();
	if (_shaderProgramFunc)
	{
		_shaderProgramFunc(_shaderProgram);
	}

	_xfbObject->bindTransformFeedback();
	_xfbObject->beginWatch(TransformFeedbackPrimitiveMode::TRIANGLES);
	GLBufferObjects::drawArrays(DrawMode::TRIANGLES, 0, 6);
	_xfbObject->endWatch();
	_xfbObject->unbindTransformFeedback();
	_shaderProgram->unuse();
}

void render::Calculator::getOutputData()
{
	_xfbBuffer->bindBuffer();
	char* data = (char*)_xfbBuffer->getMapBuffer(AccessType::READ_ONLY);
	if (data == nullptr)
	{
		_xfbBuffer->unbindBuffer();
		return;
	}
	uint32_t offset = 0;
	for (auto item : _document->getAllOutputParameters())
	{
		uint32_t size = _document->getTypeSize(item.second->getType());
		item.second->setValue(size, data + offset);
		offset += size;
	}
	_xfbBuffer->unbindBuffer();
}

void render::Calculator::calOutputBuffer()
{
	int count = _document->getAllOutputParameters().size();
	char** names = new char*[count];

	uint32_t size = 0;
	int i = 0;
	for (auto item : _document->getAllOutputParameters())
	{
		size += _document->getTypeSize(item.second->getType());
		names[i] = new char[item.first.size() + 1];
		strcpy(names[i], item.first.c_str());
		i++;
	}

	_xfbObject->setShaderProgram(_shaderProgram);
	_xfbObject->setFeedbackVaryings(count, names, TransformFeedbackBufferMode::INTERLEAVED_ATTRIBS);
	GLDebug::showError();

	_shaderProgram->link();
	GLDebug::showError();

	for (size_t i = 0; i < count; i++) {
		delete[] names[i];
	}
	delete[] names;

	_xfbBuffer->bindBuffer();
	_xfbBuffer->setBufferData(size, BufferDataUsage::DYNAMIC_READ);
	_xfbBuffer->unbindBuffer();

	_xfbObject->bindTransformFeedback();
	_xfbBuffer->bindBufferBase(0);
	_xfbObject->unbindTransformFeedback();
	_xfbBuffer->unbindBuffer();
}

