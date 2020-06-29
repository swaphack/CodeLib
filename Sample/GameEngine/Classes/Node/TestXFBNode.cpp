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

	const char* varings[] = { "out_value" };

	render::GLDebug::showError();
	auto xfbObj = CREATE_NODE(render::XFBObject);
	xfbObj->loadVertexProgram("Shader/xfb/xfb_add.vs");
	xfbObj->setWatchVaryings(1, varings);

	xfbObj->setWatchPrimitiveMode(TransformFeedbackPrimitiveMode::POINTS, 1);

	xfbObj->setBufferSize(UNIT_SIZE);
	xfbObj->setTargetBufferRange(0, 0, UNIT_SIZE);

	xfbObj->setInputFunc([](render::ShaderProgram* program) {
		render::VertexArrayObject* vao = CREATE_OBJECT(render::VertexArrayObject);
		vao->bindVertexArray();


		float num0 = 2;
		float num1 = 3;

		auto a = program->getAttrib("in_num0");
		if (a)
		{
			auto data = vao->getVertexAttrib<render::VertexAttribPointer>(a->getAttribID());
			if (data)
			{
				data->enableVertexArrayAttrib();
				data->setVertexAttribPointer(UNIT_SIZE, VertexAttribPointerType::FLOAT, false, 0, &num0);
			}
		}

		auto b = program->getAttrib("in_num1");
		if (b)
		{
			auto data = vao->getVertexAttrib<render::VertexAttribPointer>(b->getAttribID());
			if (data)
			{
				data->enableVertexArrayAttrib();
				data->setVertexAttribPointer(UNIT_SIZE, VertexAttribPointerType::FLOAT, false, 0, &num1);
			}
		}
	});

	xfbObj->setOutputFunc([](render::TransformFeedbackBuffer* buffer) {
		buffer->bindBuffer();
		auto pData = (float*)buffer->getMapBuffer(0, sizeof(float), AccessType::READ_WRITE);
		PRINT("out put data %f", *pData);
		buffer->unmapBuffer();

		buffer->unbindBuffer();
	});
	render::GLDebug::showError();

	this->addChild(xfbObj);
}

