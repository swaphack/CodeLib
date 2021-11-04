#include "BoxSpace.h"
#include "BoxProtocol.h"
#include "BoxDraw.h"
#include "algorithm.h"
#include "Common/Scene/Scene.h"
#include "Common/Scene/Camera.h"
#include "Common/Tool/Tool.h"
#include "Box2DSpace.h"
#include "Box3DSpace.h"

render::BoxSpace::BoxSpace()
{
	_2dSpace = new Box2DSpace();
	_3dSpace = new Box3DSpace();
}

render::BoxSpace::~BoxSpace()
{
	this->removeAllBoxes();

	delete _2dSpace;
	delete _3dSpace;
}

void render::BoxSpace::setBoxDraw(BoxDraw* boxDraw)
{
	_boxDraw = boxDraw;
	if (boxDraw == nullptr)
	{
		this->removeAllBoxes();
		return;
	}
	math::Size size = render::Tool::getViewSize();
	_2dSpace->init(-0.5f * size, size);
	_3dSpace->init(-0.5f * size, size);
}

render::BoxDraw* render::BoxSpace::getBoxDraw()
{
	return _boxDraw;
}

void render::BoxSpace::setMinBox2DSize(int width, int height)
{
	_2dSpace->setMinBoxSize(width, height);
}

void render::BoxSpace::setMinBox3DSize(int width, int height, int depth)
{
	_3dSpace->setMinBoxSize(width, height, depth);
}

int render::BoxSpace::getBoxIncreaseID()
{
	return _increaseBoxID++;
}

void render::BoxSpace::addBox(BoxProtocol* box)
{
	if (box == nullptr) return;

	int id = getBoxIncreaseID();

	box->setBoxID(id);
	_boxes[id] = box;

	this->registerBoxEvent(box);
}

void render::BoxSpace::updateBox(BoxProtocol* box)
{
	if (box == nullptr) return;

	if (_boxDraw)
	{
		_boxDraw->refreshBoxes();
	}

	int id = box->getBoxID();
	_2dSpace->removeBox(id);
	_3dSpace->removeBox(id);
	_boxes.erase(id);

	auto pBoxNode = box->getBoxNode();
	if (pBoxNode != nullptr)
	{
		if (!pBoxNode->isVisible()
			|| !pBoxNode->isTouchEnabled())
		{
			return;
		}
	}

	_boxes[id] = box;

	auto type = box->getBoxDrawType();
	if (type == render::BoxDrawType::TWO)
	{
		auto pBox = static_cast<Box2DProtocol*>(box);
		if (pBox)
		{			
			_2dSpace->addBox(pBox);
		}
	}
	else if (type == render::BoxDrawType::THREE)
	{
		auto pBox = static_cast<Box3DProtocol*>(box);
		if (pBox)
		{
			_3dSpace->addBox(pBox);
		}
	}
}

void render::BoxSpace::removeBox(BoxProtocol* box)
{
	if (box == nullptr) return;

	this->unregisterBoxEvent(box);

	int id = box->getBoxID();
	_2dSpace->removeBox(id);
	_3dSpace->removeBox(id);
	_boxes.erase(id);
}

void render::BoxSpace::removeAllBoxes()
{
	for (const auto& item : _boxes)
	{
		this->unregisterBoxEvent(item.second);
	}

	_boxes.clear();

	_2dSpace->removeAllBoxes();
	_3dSpace->removeAllBoxes();
}

const std::map<int, render::BoxProtocol*>& render::BoxSpace::getAllBoxes() const
{
	return _boxes;
}

bool render::BoxSpace::containsTouchPoint(const math::Vector2& touchPoint, std::vector<render::BoxProtocol*>& boxes)
{
	if (_boxDraw == nullptr) return false;
	auto pCamera = _boxDraw->getCamera();
	if (pCamera == nullptr) return false;

	math::Vector3 worldPoint = pCamera->convertScreenToLocalPoint(touchPoint);
	std::vector<BoxProtocol*> temps;
	if (getBoxesOfIncludedPoint(worldPoint, temps))
	{
		for (const auto& item : temps)
		{
			if (item->getBoxNode()->containsTouchPoint(touchPoint))
			{
				boxes.push_back(item);
			}
		}
	}

	return boxes.size() > 0;
}

bool render::BoxSpace::getBoxesOfIncludedPoint(const math::Vector3& worldPoint, std::vector<render::BoxProtocol*>& boxes)
{
	int key = _increaseBoxID + 1;

	// ¶þÎ¬
	std::map<int, render::Box2DProtocol*> box2Ds;
	if (_2dSpace->getBoxesOfIncludedPoint(key, worldPoint, box2Ds))
	{
		for (const auto& item : box2Ds)
		{
			auto it = _boxes.find(item.first);
			if (it != _boxes.end())
			{
				auto pBoxNode = it->second->getBoxNode();
				if (pBoxNode == nullptr) continue;
				if (!pBoxNode->isTouchEnabled() || !pBoxNode->isVisible()) continue;
				boxes.push_back(it->second);
			}
		}
	}
	// ÈýÎ¬
	std::map<int, render::Box3DProtocol*> box3Ds;
	if (_3dSpace->getBoxesOfIncludedPoint(key, worldPoint, box3Ds))
	{
		for (const auto& item : box3Ds)
		{
			auto it = _boxes.find(item.first);
			if (it != _boxes.end())
			{
				auto pBoxNode = it->second->getBoxNode();
				if (pBoxNode == nullptr) continue;
				if (!pBoxNode->isTouchEnabled() || !pBoxNode->isVisible()) continue;
				boxes.push_back(it->second);
			}
		}
	}
	return boxes.size() > 0;
}

bool render::BoxSpace::containsTouchPoint2D(Box2DProtocol* boxProtocol, const math::Vector2& touchPoint)
{
	return _2dSpace->containsTouchPoint(boxProtocol, touchPoint);
}

bool render::BoxSpace::containsTouchPoint3D(Box3DProtocol* boxProtocol, const math::Vector2& touchPoint)
{
	return _3dSpace->containsTouchPoint(boxProtocol, touchPoint);
}

void render::BoxSpace::registerBoxEvent(BoxProtocol* box)
{
	if (box == nullptr) return;

	if (box->getBoxNode())
	{
		box->getBoxNode()->addNotifyListener(render::NodeNotifyType::Draw, this, [this, box]() {
			this->updateBox(box);
		});
	}

	if (_boxDraw)
	{
		_boxDraw->notify(render::NodeNotifyType::GEOMETRY);
	}
}

void render::BoxSpace::unregisterBoxEvent(BoxProtocol* box)
{
	if (box == nullptr) return;

	if (box->getBoxNode())
	{
		box->getBoxNode()->removeNotifyListener(render::NodeNotifyType::Draw, this);
	}

	if (_boxDraw)
	{
		_boxDraw->notify(render::NodeNotifyType::GEOMETRY);
	}
}

std::string render::BoxSpace::getRectKey(const math::Rect& rect)
{
	return getCString("%0.2f,%0.2f,%0.2f,%0.2f", rect.getMinX(), rect.getMinY(), rect.getWidth(), rect.getHeight());
}
