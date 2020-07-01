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


	float num0 = 2;
	float num1 = 3;

	render::VertexArrayObject* vao = CREATE_OBJECT(render::VertexArrayObject);
	vao->bindVertexArray();
	render::GLDebug::showError();
	render::ArrayBuffer* buffer = CREATE_OBJECT(render::ArrayBuffer);
	buffer->bindBuffer();
	buffer->setBufferData(2 * UNIT_SIZE, nullptr, BufferDataUsage::STATIC_DRAW);
	buffer->setBufferSubData(0, UNIT_SIZE, &num0);
	buffer->setBufferSubData(UNIT_SIZE, UNIT_SIZE, &num1);
	render::GLDebug::showError();

	auto data = vao->getVertexAttrib<render::VertexAttribPointer>(0);
	data->setVertexAttribPointer(1, VertexAttribPointerType::FLOAT, 0);
	render::GLDebug::showError();

	data = vao->getVertexAttrib<render::VertexAttribPointer>(1);
	data->setVertexAttribPointer(1, VertexAttribPointerType::FLOAT, UNIT_SIZE);
	render::GLDebug::showError();

	vao->setBuffer(buffer);
	vao->unbindVertexArray();
	render::GLDebug::showError();

	xfbObj->setInputFunc([vao](render::ShaderProgram* program) {
		vao->bindVertexArray();
		render::GLDebug::showError();

		auto a = program->getAttrib("in_num0");
		if (a)
		{
			auto data = vao->getVertexAttrib<render::VertexAttribPointer>(a->getAttribID());
			if (data)
			{
				data->enableVertexArrayAttrib();
				render::GLDebug::showError();
			}
		}

		auto b = program->getAttrib("in_num1");
		if (b)
		{
			auto data = vao->getVertexAttrib<render::VertexAttribPointer>(b->getAttribID());
			if (data)
			{
				data->enableVertexArrayAttrib();
				render::GLDebug::showError();
			}
		}
	});

	xfbObj->setOutputFunc([vao](render::TransformFeedbackBuffer* buffer) {
		render::GLDebug::showError();
		vao->unbindVertexArray();
		render::GLDebug::showError();
		buffer->bindBuffer();
		render::GLDebug::showError();
		auto pData = (float*)buffer->getMapBufferRange(0, sizeof(float), MapBufferRangeAccess::MAP_READ_BIT);
		render::GLDebug::showError();
		if (pData)
		{
			PRINT("out put data %f", *pData);
		}
		buffer->unmapBuffer();
		buffer->bindBuffer();
		render::GLDebug::showError();
	});

	render::GLDebug::showError();

	this->addChild(xfbObj);
}

