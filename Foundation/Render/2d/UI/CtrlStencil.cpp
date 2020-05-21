#include "CtrlStencil.h"
#include "Common/Fragment/import.h"
#include "Graphic/import.h"
#include "Common/View/import.h"

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

void render::CtrlStencil::setStencilMode(StencilMode mode)
{
	_stencilMode = mode;
}

void render::CtrlStencil::beforeDrawNode()
{
	CtrlWidget::beforeDrawNode();
}

void render::CtrlStencil::afterDrawNode()
{	
	GLState::enable(EnableMode::STENCIL_TEST);
	GLState::setStencilMask(0x1);
	GLState::setStencilFunc(StencilFunction::ALWAYS, 0x1, 0x1);
	GLState::setStencilOp(StencilOpResult::KEEP, StencilOpResult::KEEP, StencilOpResult::REPLACE);
	GLState::setColorMask(false, false, false, false);
	GLState::setDepthMask(false);

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

	Pixel::dumpStencil();

	if (_stencilMode == StencilMode::INCLUDE)
	{
		GLState::setStencilFunc(StencilFunction::EQUAL, 0x1, 0x1);
	}
	else
	{
		GLState::setStencilFunc(StencilFunction::NOTEQUAL, 0x1, 0x1);
	}
	
	GLState::setStencilOp(StencilOpResult::REPLACE, StencilOpResult::REPLACE, StencilOpResult::KEEP);
	GLState::setColorMask(true, true, true, true);
	GLState::setDepthMask(true);

	this->drawAllChildren();


	GLState::disable(EnableMode::STENCIL_TEST);
	GLState::setStencilMask(0x0);

	if (_bClip)
	{
		GLState::disable(EnableMode::SCISSOR_TEST);
	}

	GLState::disable(EnableMode::STENCIL_TEST);
}

