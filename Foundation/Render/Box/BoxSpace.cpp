#include "BoxSpace.h"
#include "BoxDrawProtocol.h"
#include "BoxDraw.h"
#include "algorithm.h"
#include "Common/Scene/Scene.h"
#include "Common/Scene/Camera.h"
#include "Common/Tool/Tool.h"

// 盒子空间
alg::QuadTree<math::Rect, int, render::BoxDrawProtocol*> _quadTree;

render::BoxSpace::BoxSpace()
{
	_quadTree.setLeafItemCount(8);
	_quadTree.setCondtionIncludeFunc([this](const math::Rect& a, const int& b) {
		auto it = _boxes.find(b);
		if (it != _boxes.end())
		{
			auto box = static_cast<render::Box2DDrawProtocol*>(it->second);
			if (box)
			{
				return a.isOverlap(box->getBoxRect());
			}
		}
		return false;
	});
	_quadTree.setCondtionDivideFunc([this](const math::Rect& a, std::vector<math::Rect>& b) {
		if (a.getSize() == math::Size()) return false;
		float w = a.getHalfWidth();
		float h = a.getHalfHeight();
		if (w <= 0 || h <= 0
			|| w < _minRectWidth || h < _minRectHeight)
		{
			return false;
		}
		b.push_back(math::Rect(a.getMinX(), a.getMinY(), w, h));
		b.push_back(math::Rect(a.getMiddleX(), a.getMinY(), w, h));
		b.push_back(math::Rect(a.getMinX(), a.getMiddleY(), w, h));
		b.push_back(math::Rect(a.getMiddleX(), a.getMiddleY(), w, h));
		return b.size() > 0;
	});
}

render::BoxSpace::~BoxSpace()
{
	this->removeAllBoxes();
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
	_quadTree.initRoot(math::Rect(-0.5f * size, size));
}

render::BoxDraw* render::BoxSpace::getBoxDraw()
{
	return _boxDraw;
}

void render::BoxSpace::setMinRectSize(int width, int height)
{
	_minRectWidth = width;
	_minRectHeight = height;
}

int render::BoxSpace::getBoxIncreaseID()
{
	return _increaseBoxID++;
}

void render::BoxSpace::addBox(BoxDrawProtocol* box)
{
	if (box == nullptr) return;

	box->setBoxID(getBoxIncreaseID());
	_boxes[box->getBoxID()] = box;
	this->registerBoxEvent(box);
}

void render::BoxSpace::updateBox(BoxDrawProtocol* box)
{
	if (box == nullptr) return;

	if (_boxDraw)
	{
		_boxDraw->refreshBoxes();
	}

	int id = box->getBoxID();
	_quadTree.remove(id);
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

	if (box->getBoxDrawType() == render::BoxDrawType::TWO)
	{
		auto pBox = static_cast<Box2DDrawProtocol*>(box);
		if (pBox)
		{
			const auto& rect = pBox->getBoxRect();
			if (rect.getSize() == math::Size())
			{// 排除无大小矩形
				return;
			}
			_boxes[id] = box;
			_quadTree.add(id, box);
		}
	}
	
}

void render::BoxSpace::removeBox(BoxDrawProtocol* box)
{
	if (box == nullptr) return;

	this->unregisterBoxEvent(box);

	int id = box->getBoxID();
	_quadTree.remove(id);
	_boxes.erase(id);
}

void render::BoxSpace::removeAllBoxes()
{
	for (const auto& item : _boxes)
	{
		this->unregisterBoxEvent(item.second);
	}

	_boxes.clear();

	_quadTree.clear();
}

const std::map<int, render::BoxDrawProtocol*>& render::BoxSpace::getAllBoxes() const
{
	return _boxes;
}

bool render::BoxSpace::containsTouchPoint(const math::Vector2& touchPoint, std::vector<render::BoxDrawProtocol*>& boxes)
{
	if (_boxDraw == nullptr) return false;
	auto pCamera = _boxDraw->getCamera();
	if (pCamera == nullptr) return false;

	math::Vector3 worldPoint = pCamera->convertScreenToLocalPoint(touchPoint);
	std::vector<BoxDrawProtocol*> temps;
	if (getBoxesOfSharedPoint(worldPoint, temps))
	{
		for (const auto& item : temps)
		{
			if (item->containsTouchPoint(touchPoint))
			{
				boxes.push_back(item);
			}
		}
	}

	return boxes.size() > 0;
}

bool render::BoxSpace::getBoxesOfSharedPoint(const math::Vector3& worldPoint, std::vector<render::BoxDrawProtocol*>& boxes)
{
	int key = _increaseBoxID + 1;
	render::Box2DDrawProtocol* pro = nullptr;
	{
		math::Rect rect(worldPoint.getX(), worldPoint.getY(), 0, 0);
		render::Box2DDrawProtocol* pro = new render::Box2DDrawProtocol();
		pro->setBoxRect(rect);
		_quadTree.add(key, pro);
		_boxes[key] = pro;
	}

	
	std::map<int, render::BoxDrawProtocol*> target;
	bool result = _quadTree.findNode(key, target);

	{
		delete pro;
		_quadTree.remove(key);
		_boxes.erase(key);
	}
	
	if (!result)
	{
		return false;
	}
	for (const auto& item : target)
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

	return boxes.size() > 0;
}

void render::BoxSpace::registerBoxEvent(BoxDrawProtocol* box)
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

void render::BoxSpace::unregisterBoxEvent(BoxDrawProtocol* box)
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
