#include "CtrlWidget.h"
#include "Common/Tool/import.h"
#include "Resource/Detail/ModelDetail.h"
#include "Resource/Detail/MaterialDetail.h"
#include "Resource/Detail/MeshDetail.h"
#include "Graphic/import.h"
#include "Common/Shader/import.h"
#include "Common/Buffer/import.h"
#include "Common/View/import.h"
#include "Common/Material/import.h"

using namespace render;

render::CtrlWidget::CtrlWidget()
{
}

render::CtrlWidget::~CtrlWidget()
{
}

bool render::CtrlWidget::init()
{
	if (!ColorNode::init())
	{
		return false;
	}
	// 添加属性改变监听
	_notify->addListen(ENP_SPACE, [&](){
		Tool::calRect(math::Vector3(), _volume, _anchor, _rectVertex);
	});

	return true; 
}

const render::RectVertex& render::CtrlWidget::getRectVertex()
{
	return _rectVertex;
}

bool render::CtrlWidget::containTouchPoint(float x, float y)
{
	return _rectVertex.containPoint(x, y);
}

