#include "CtrlStencil.h"
#include "Common/Fragment/import.h"
#include "Graphic/import.h"
#include "Common/View/import.h"
#include "Common/DrawNode/FragmentOperator.h"

ui::CtrlStencil::CtrlStencil()
{

}

ui::CtrlStencil::~CtrlStencil()
{
	SAFE_RELEASE(_stencilNode);
}

bool ui::CtrlStencil::init()
{
	if (!CtrlWidget::init())
	{
		return false;
	}

	return true;
}

void ui::CtrlStencil::setFunc(StencilFunction func, int ref, uint32_t mask)
{
	render::FragmentStencilTest* pStencilTest = this->getFragOperator()->getHandle<render::FragmentStencilTest>();
	if (pStencilTest)
	{
		pStencilTest->setFunc(func, ref, mask);
	}
}

void ui::CtrlStencil::setOperator(StencilOpResult stencilFail, StencilOpResult depthFail, StencilOpResult depthPass)
{
	render::FragmentStencilTest* pStencilTest = this->getFragOperator()->getHandle<render::FragmentStencilTest>();
	if (pStencilTest)
	{
		pStencilTest->setOperator(stencilFail, depthFail, depthPass);
	}
}

void ui::CtrlStencil::setStencilNode(Node* node)
{
	SAFE_RELEASE(_stencilNode);
	SAFE_RETAIN(node);
	_stencilNode = node;
}

void ui::CtrlStencil::setStencilMode(StencilMode mode)
{
	_stencilMode = mode;
}

void ui::CtrlStencil::beforeDrawNode()
{
	CtrlWidget::beforeDrawNode();
}

void ui::CtrlStencil::afterDrawNode()
{	
	render::GLState::enable(EnableMode::STENCIL_TEST);
	render::GLState::setStencilMask(0x1);
	render::GLState::setStencilFunc(StencilFunction::ALWAYS, 0x1, 0x1);
	render::GLState::setStencilOp(StencilOpResult::KEEP, StencilOpResult::KEEP, StencilOpResult::REPLACE);
	render::GLState::setColorMask(false, false, false, false);
	render::GLState::setDepthMask(false);

	if (_stencilNode)
	{
		bool hasParent = _stencilNode->getParent() != nullptr;
		if (!hasParent)
		{
			this->addChild(_stencilNode);
			_stencilNode->updateNode();
		}

		_stencilNode->drawNode();
		if (!hasParent)
		{
			this->removeChild(_stencilNode);
		}
	}

	if (_stencilMode == StencilMode::INCLUDE)
	{
		render::GLState::setStencilFunc(StencilFunction::EQUAL, 0x1, 0x1);
	}
	else
	{
		render::GLState::setStencilFunc(StencilFunction::NOTEQUAL, 0x1, 0x1);
	}
	
	render::GLState::setStencilOp(StencilOpResult::REPLACE, StencilOpResult::REPLACE, StencilOpResult::KEEP);
	render::GLState::setColorMask(true, true, true, true);
	render::GLState::setDepthMask(true);

	this->drawAllChildren();

	render::GLState::disable(EnableMode::STENCIL_TEST);
	render::GLState::setStencilMask(0x0);

	if (isClippingEnabled())
	{
		render::GLState::disable(EnableMode::SCISSOR_TEST);
	}

	render::GLState::disable(EnableMode::STENCIL_TEST);

	this->drawRect();
}

