#include "CtrlStencil.h"
#include "Common/Fragment/import.h"
#include "Graphic/import.h"

render::CtrlStencil::CtrlStencil()
{

}

render::CtrlStencil::~CtrlStencil()
{
	SAFE_RELEASE(_stencilNode);
}

bool render::CtrlStencil::init()
{
	if (!CtrlWidget::init())
	{
		return false;
	}

	return true;
}

void render::CtrlStencil::setFunc(StencilFunction func, int ref, uint32_t mask)
{
	FragmentStencilTest* pStencilTest = this->getFragOperator()->getHandle<FragmentStencilTest>();
	if (pStencilTest)
	{
		pStencilTest->setFunc(func, ref, mask);
	}
}

void render::CtrlStencil::setOperator(StencilOpResult stencilFail, StencilOpResult depthFail, StencilOpResult depthPass)
{
	FragmentStencilTest* pStencilTest = this->getFragOperator()->getHandle<FragmentStencilTest>();
	if (pStencilTest)
	{
		pStencilTest->setOperator(stencilFail, depthFail, depthPass);
	}
}

void render::CtrlStencil::setStencilNode(Node* node)
{
	SAFE_RELEASE(_stencilNode);
	SAFE_RETAIN(node);
	_stencilNode = node;
}

void render::CtrlStencil::beforeDrawNode()
{
	CtrlWidget::beforeDrawNode();
}

void render::CtrlStencil::afterDrawNode()
{
	GLState::enable(EnableMode::STENCIL_TEST);
	GLState::setStencilOp(StencilOpResult::KEEP, StencilOpResult::DECR_WRAP, StencilOpResult::REPLACE);

	//GLState::setStencilMask(0xFF);
	GLState::setStencilFunc(StencilFunction::ALWAYS, 2, 0xff);

	GLDebug::showError();

	if (_stencilNode)
	{
		bool hasParent = _stencilNode->getParent() != nullptr;
		if (!hasParent)
		{
			_stencilNode->updateNode();
		}

		_stencilNode->drawNode();
	}

	GLState::setStencilOp(StencilOpResult::DECR_WRAP, StencilOpResult::INCR, StencilOpResult::KEEP);
	GLState::setStencilFunc(StencilFunction::EQUAL, 2, 0xff);
	//GLState::setStencilMask(0x00);

	GLDebug::showError();

	this->drawAllChildren();

	if (_bClip)
	{
		GLState::disable(EnableMode::SCISSOR_TEST);
	}

	GLState::disable(EnableMode::STENCIL_TEST);
}

