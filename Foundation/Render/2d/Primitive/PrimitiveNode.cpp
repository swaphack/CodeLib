#include "PrimitiveNode.h"
#include "Graphic/import.h"
#include "Common/Tool/Tool.h"
#include "Common/Mesh/import.h"
#include "Common/Material/import.h"
#include "physicslib.h"
using namespace render;


PrimitiveNode::PrimitiveNode()
{
}

PrimitiveNode::~PrimitiveNode()
{
}

bool render::PrimitiveNode::init()
{
	if (!DrawNode2D::init())
	{
		return false;
	}

	addNotifyListener(NodeNotifyType::GEOMETRY, [this]() {
		this->onPrimitiveChange();
	});

	return true;
}

void render::PrimitiveNode::onPrimitiveChange()
{
	int nVertexCount = _vertexes.size();
	auto pVertice = (float*)getMesh()->getMeshDetail()->createVertices(nVertexCount, sizeof(float), 3);
	auto pColor = (float*)getMesh()->getMeshDetail()->createColors(nVertexCount, sizeof(float), 4);
	auto indice = (uint32_t*)getMesh()->getMeshDetail()->createIndices(nVertexCount, sizeof(uint32_t), 1);

	for (int i = 0; i < nVertexCount; i++)
	{
		memcpy(pVertice + i * 3, _vertexes[i].point.getValue(), 3 * sizeof(float));
		memcpy(pColor + i * 4, &_vertexes[i].color, 4 * sizeof(float));
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
	this->appendPoint(point, phy::Color4F(1.0f, 1.0f, 1.0f, 1.0f));
}

void PrimitiveNode::removeAllPoints()
{
	_vertexes.clear();
	notify(NodeNotifyType::GEOMETRY);
}

void render::PrimitiveNode::appendPoint(const math::Vector3& point, const phy::Color4F& color)
{
	this->appendPoint(PrimitiveVertex(point, color));
}

void render::PrimitiveNode::appendPoint(const PrimitiveVertex& vertex)
{
	_vertexes.push_back(vertex);
	notify(NodeNotifyType::GEOMETRY);
}

void render::PrimitiveNode::appendPoints(const std::vector<math::Vector3>& points, const phy::Color4F& color)
{
	for (size_t i = 0; i < points.size(); i++)
	{
		this->appendPoint(points[i], color);
	}
}

void render::PrimitiveNode::setPointSize(float size)
{
	_pointSize = size;
}

float render::PrimitiveNode::getPointSize() const
{
	return _pointSize;
}
