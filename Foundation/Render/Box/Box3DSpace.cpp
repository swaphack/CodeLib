#include "Box3DSpace.h"
#include "algorithm.h"
#include "BoxProtocol.h"
#include "Common/Node/Node.h"
#include "Common/Scene/Camera.h"

// ºÐ×Ó¿Õ¼ä
alg::space::OcTree<math::Cuboids, int, render::Box3DProtocol*> _quadTree;

render::Box3DSpace::Box3DSpace()
{
	_quadTree.setLeafItemCount(8);
	_quadTree.setCondtionIncludeFunc([this](const math::Cuboids& a, const int& b)
		{
			auto it = _boxes.find(b);
			if (it != _boxes.end())
			{
				return a.isOverlap(it->second->getBoxCuboids());
			}
			return false;
		});
	_quadTree.setCondtionDivideFunc([this](const math::Cuboids& a, std::vector<math::Cuboids>& b)
		{
			if (a.getVolume() == math::Volume()) return false;
			float w = a.getHalfWidth();
			float h = a.getHalfHeight();
			float d = a.getHalfDepth();
			if (w <= 0 || h <= 0 || d <= 0
				|| w < _minRectWidth || h < _minRectHeight || d < _minRectDepth)
			{
				return false;
			}
			b.push_back(math::Cuboids(a.getMinX(), a.getMinY(), a.getMinZ(), w, h, d));
			b.push_back(math::Cuboids(a.getMiddleX(), a.getMinY(), a.getMinZ(), w, h, d));
			b.push_back(math::Cuboids(a.getMinX(), a.getMiddleY(), a.getMinZ(), w, h, d));
			b.push_back(math::Cuboids(a.getMiddleX(), a.getMiddleY(), a.getMinZ(), w, h, d));
			b.push_back(math::Cuboids(a.getMinX(), a.getMinY(), a.getMiddleZ(), w, h, d));
			b.push_back(math::Cuboids(a.getMiddleX(), a.getMinY(), a.getMiddleZ(), w, h, d));
			b.push_back(math::Cuboids(a.getMinX(), a.getMiddleY(), a.getMiddleZ(), w, h, d));
			b.push_back(math::Cuboids(a.getMiddleX(), a.getMiddleY(), a.getMiddleZ(), w, h, d));
			return b.size() > 0;
		});
}

render::Box3DSpace::~Box3DSpace()
{
	this->removeAllBoxes();
}

void render::Box3DSpace::init(const math::Vector2& pos, const math::Size& size)
{
}

void render::Box3DSpace::setMinBoxSize(int width, int height, int depth)
{
	_minRectWidth = width;
	_minRectHeight = height;
	_minRectDepth = depth;
}

void render::Box3DSpace::addBox(Box3DProtocol* box)
{
	if (box == nullptr) return;

	const auto& cuboids = box->getBoxCuboids();
	if (cuboids.getVolume() == math::Volume())
	{
		return;
	}

	int id = box->getBoxID();
	_boxes[id] = box;
	_quadTree.add(id, box);
}

void render::Box3DSpace::removeBox(Box3DProtocol* box)
{
	if (box == nullptr) return;
	this->removeBox(box->getBoxID());
}

void render::Box3DSpace::removeBox(int boxID)
{
	_boxes.erase(boxID);
	_quadTree.remove(boxID);
}

bool render::Box3DSpace::containBox(int boxID)
{
	std::map<int, render::Box3DProtocol*> target;
	return _quadTree.findNode(boxID, target);
}

void render::Box3DSpace::removeAllBoxes()
{
	_boxes.clear();
	_quadTree.clear();
}

bool render::Box3DSpace::containsTouchPoint(Box3DProtocol* boxProtocol, const math::Vector2& touchPoint)
{
	if (boxProtocol == nullptr) return false;

	if (boxProtocol->getBoxNode() == nullptr || boxProtocol->getBoxNode()->getCamera() == nullptr)
		return false;
	auto pCamera = boxProtocol->getBoxNode()->getCamera();
	math::Ray cameraRay = pCamera->convertScreenPointToWorldRay(touchPoint);

	const auto& trianglePoints = boxProtocol->getBoxPoints();
	if (trianglePoints.size() <= 0) return false;

	math::Vector3 point;
	for (auto item : trianglePoints)
	{
		if (math::Physics::raycast(cameraRay, item, point))
		{
			return true;
		}
	}
	return false;
}

bool render::Box3DSpace::getBoxesOfIncludedPoint(int nID, const math::Vector3& worldPoint, std::map<int, render::Box3DProtocol*>& boxes)
{
	int key = nID;
	render::Box3DProtocol* pro = nullptr;
	{
		math::Cuboids rect(worldPoint.getX(), worldPoint.getY(), worldPoint.getZ(), 0, 0, 0);
		pro = new render::Box3DProtocol();
		pro->setBoxCuboids(rect);
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
