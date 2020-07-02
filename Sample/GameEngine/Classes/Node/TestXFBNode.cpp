#include "TestXFBNode.h"

TestXFBNode::TestXFBNode()
{

}

TestXFBNode::~TestXFBNode()
{

}

void TestXFBNode::initNodes()
{
#define UNIT_SIZE sizeof(float)

	const char* varings[] = { "out_addValue", "out_subValue" };

	render::GLDebug::showError();
	auto xfbObj = CREATE_OBJECT(render::TransformFeedbackBufferObject);
	xfbObj->loadVertexProgram("Shader/xfb/xfb_add.vs");
	xfbObj->setWatchVaryings(2, varings);
	xfbObj->setWatchPrimitiveMode(TransformFeedbackPrimitiveMode::POINTS, 1);
	xfbObj->setBufferSize(2 * UNIT_SIZE);
	xfbObj->setTargetBufferRange(0, 0, 2 * UNIT_SIZE);

	float num0 = 2;
	float num1 = 3;

	render::VertexArrayBufferObject* vab = CREATE_OBJECT(render::VertexArrayBufferObject);
	vab->resize(2 * UNIT_SIZE);
	vab->writeVertexAttrib(VertexAttribPointerType::FLOAT, &num0);
	vab->writeVertexAttrib(VertexAttribPointerType::FLOAT, &num1);

	xfbObj->setInputFunc([vab](render::ShaderProgram* program) {
		vab->bindVertexArray();
		render::GLDebug::showError();

		auto a = program->getAttrib("in_num0");
		if (a)
		{
			vab->enableVertexArrayAttrib(a->getAttribID());
		}

		auto b = program->getAttrib("in_num1");
		if (b)
		{
			vab->enableVertexArrayAttrib(b->getAttribID());
		}
	});

	xfbObj->setOutputFunc([vab](render::TransformFeedbackBuffer* buffer) {
		render::GLDebug::showError();
		vab->unbindVertexArray();

		sys::StreamReader reader;

		buffer->flush(0, 2 * UNIT_SIZE, reader);
		float a = reader.readFloat();
		float b = reader.readFloat();
		PRINT("out put data %f, %f", a, b);

		render::GLDebug::showError();
	});

	render::GLDebug::showError();

	xfbObj->run();
}

