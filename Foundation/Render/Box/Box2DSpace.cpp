#include "Box2DSpace.h"
#include "algorithm.h"
#include "BoxProtocol.h"
#include "Common/Node/Node.h"
#include "Common/Scene/Camera.h"

// ºÐ×Ó¿Õ¼ä
alg::space::QuadTree<math::Rect, int, render::Box2DProtocol*> _quadTree;

render::Box2DSpace::Box2DSpace()
{
	_quadTree.setLeafItemCount(8);
	_quadTree.setCondtionIncludeFunc([this](const math::Rect& a, const int& b) 
	{
		auto it = _boxes.find(b);
		if (it != _boxes.end())
		{
			return a.isOverlap(it->second->getBoxRect());
		}
		return false;
	});
	_quadTree.setCondtionDivideFunc([this](const math::Rect& a, std::vector<math::Rect>& b) 
	{
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

render::Box2DSpace::~Box2DSpace()
{
	this->removeAllBoxes();
}

void render::Box2DSpace::init(const math::Vector2& pos, const math::Size& size)
{
	_rootRect = math::Rect(pos, size);
	_quadTree.initRoot(_rootRect);
}

void render::Box2DSpace::setMinBoxSize(int width, int height)
{
	_minRectWidth = width;
	_minRectHeight = height;
}


void render::Box2DSpace::addBox(Box2DProtocol* box)
{
	if (box == nullptr || box->getBoxNode() == nullptr) return;

	const auto& rect = box->getBoxRect();
	if (rect.getSize() == math::Size())
	{
		return;
	}

	if (!_rootRect.isOverlap(box->getBoxRect()))
	{
		return;
	}


	//bool bShow = _rootRect.isOverlap(box->getBoxRect());
	//box->getBoxNode()->setSkipDraw(!bShow);

	int id = box->getBoxID();
	_boxes[id] = box;
	_quadTree.add(id, box);
}

void render::Box2DSpace::removeBox(Box2DProtocol* box)
{
	if (box == nullptr) return;
	//box->getBoxNode()->setVisible(true);
	this->removeBox(box->getBoxID());
}

void render::Box2DSpace::removeBox(int boxID)
{
	_boxes.erase(boxID);
	_quadTree.remove(boxID);
}

bool render::Box2DSpace::containBox(int boxID)
{
	std::map<int, render::Box2DProtocol*> target;
	return _quadTree.findNode(boxID, target);
}

void render::Box2DSpace::removeAllBoxes()
{
	_boxes.clear();
	_quadTree.clear();
}

bool render::Box2DSpace::containsTouchPoint(Box2DProtocol* boxProtocol, const math::Vector2& touchPoint)
{
	if (boxProtocol == nullptr) return false;

	if (boxProtocol->getBoxNode() == nullptr || boxProtocol->getBoxNode()->getCamera() == nullptr)
		return false;
	auto pCamera = boxProtocol->getBoxNode()->getCamera();
	math::Vector3 localPointA = pCamera->convertScreenToLocalPoint(touchPoint);
	return boxProtocol->getBoxRect().contains(localPointA);
}

bool render::Box2DSpace::getBoxesOfIncludedPoint(int nID, const math::Vector3& worldPoint, std::map<int, render::Box2DProtocol*>& boxes)
{
	int key = nID;
	render::Box2DProtocol* pro = nullptr;
	{
		math::Rect rect(worldPoint.getX(), worldPoint.getY(), 0, 0);
		pro = new render::Box2DProtocol();
		pro->setBoxRect(rect);
		_quadTree.add(key, pro);
		_boxes[key] = pro;
	}

	bool result = _quadTree.findNode(key, boxes);
	{
		delete pro;
		_quadTree.remove(key);
		_boxes.erase(key);
	}

	if (!result)
	{
		return false;
	}

	return boxes.size() > 0;
}

