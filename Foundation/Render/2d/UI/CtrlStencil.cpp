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

void render::CtrlStencil::beforeDrawNode()
{
	CtrlWidget::beforeDrawNode();
}

void render::CtrlStencil::afterDrawNode()
{
	GLState::disable(EnableMode::DEPTH_TEST);
	GLState::enable(EnableMode::STENCIL_TEST);
	GLState::setStencilFunc(StencilFunction::EQUAL, 1, 0xff);
	GLState::setStencilOp(StencilOpResult::KEEP, StencilOpResult::KEEP, StencilOpResult::KEEP);

	//////////////////////////////////////////////////////////////////////////
	//Pixel::dumpStencil();



	this->drawAllChildren();

	

	//////////////////////////////////////////////////////////////////////////

	GLState::setStencilFunc(StencilFunction::NOTEQUAL, 1, 0xff);
	GLState::setStencilOp(StencilOpResult::INVERT, StencilOpResult::INVERT, StencilOpResult::KEEP);
	//////////////////////////////////////////////////////////////////////////
	if (_stencilNode)
	{
		bool hasParent = _stencilNode->getParent() != nullptr;
		if (!hasParent)
		{
			_stencilNode->updateNode();
		}

		_stencilNode->drawNode();
	}
	//////////////////////////////////////////////////////////////////////////

	if (_bClip)
	{
		GLState::disable(EnableMode::SCISSOR_TEST);
	}

	GLState::disable(EnableMode::STENCIL_TEST);
	GLState::enable(EnableMode::DEPTH_TEST);
}

