#include "PrimitiveNode.h"
#include "Graphic/import.h"
#include "Common/Tool/Tool.h"
#include "Common/Mesh/import.h"
#include "Common/Material/import.h"
using namespace render;


PrimitiveNode::PrimitiveNode()
{
}

PrimitiveNode::~PrimitiveNode()
{
}

bool render::PrimitiveNode::init()
{
	if (!DrawNode::init())
	{
		return false;
	}

	_notify->addListen(NodeNotifyType::GEOMETRY, [this]() {
		this->onPrimitiveChange();
	});

	return true;
}

void render::PrimitiveNode::onPrimitiveChange()
{
	int nVertexCount = _points.size();
	auto vertice = (float*)getMesh()->getMeshDetail()->createVertices(nVertexCount, sizeof(float), 3);
	auto indice = (uint32_t*)getMesh()->getMeshDetail()->createIndices(nVertexCount, sizeof(uint32_t), 1);

	for (int i = 0; i < nVertexCount; i++)
	{
		memcpy(vertice + i * 3, _points[i].getValue(), 3 * sizeof(float));
		memcpy(indice + i, &i, sizeof(uint32_t));
	}

	this->updateMeshData();
}

void PrimitiveNode::setDrawMode(DrawMode mode)
{
	getMesh()->setDrawMode(mode);
}

DrawMode PrimitiveNode::getDrawMode()
{
	return getMesh()->getDrawMode();
}

void PrimitiveNode::appendPoint(const math::Vector3& point)
{
	_points.push_back(point);

	notify(NodeNotifyType::GEOMETRY);
}

void PrimitiveNode::appendPoint(const math::Vector2& point)
{
	math::Vector3 temp = point;
	this->appendPoint(temp);
}

void PrimitiveNode::removePoint(const math::Vector3& point)
{
	std::vector<math::Vector3>::iterator it = _points.begin();
	while (it != _points.end())
	{
		if ((*it) == point)
		{
			_points.erase(it);
			notify(NodeNotifyType::GEOMETRY);
			return;
		}
		it++;
	}
}

void PrimitiveNode::removePoint(const math::Vector2& point)
{
	math::Vector3 temp = point;
	this->removePoint(temp);
}

void PrimitiveNode::removeAllPoints()
{
	_points.clear();
	notify(NodeNotifyType::GEOMETRY);
}

void PrimitiveNode::setPoints(const std::vector<math::Vector3>& points)
{
	_points.clear();

	_points = points;

	notify(NodeNotifyType::GEOMETRY);
}

void render::PrimitiveNode::setPointSize(float size)
{
	_pointSize = size;
}

float render::PrimitiveNode::getPointSize() const
{
	return _pointSize;
}
