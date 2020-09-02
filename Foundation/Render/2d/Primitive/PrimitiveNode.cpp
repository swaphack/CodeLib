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
	int nVertexCount = _vertexes.size();
	auto pVertice = (float*)getMesh()->getMeshDetail()->createVertices(nVertexCount, sizeof(float), 3);
	auto pColor = (uint8_t*)getMesh()->getMeshDetail()->createColors(nVertexCount, sizeof(uint8_t), 4);
	auto indice = (uint32_t*)getMesh()->getMeshDetail()->createIndices(nVertexCount, sizeof(uint32_t), 1);

	for (int i = 0; i < nVertexCount; i++)
	{
		memcpy(pVertice + i * 3, _vertexes[i].point.getValue(), 3 * sizeof(float));
		memcpy(pColor + i * 4, &_vertexes[i].color, 4 * sizeof(uint8_t));
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
	this->appendPoint(point, sys::Color4B(255, 255, 255, 255));
}

void PrimitiveNode::removeAllPoints()
{
	_vertexes.clear();
	notify(NodeNotifyType::GEOMETRY);
}

void render::PrimitiveNode::appendPoint(const math::Vector3& point, const sys::Color4B& color)
{
	this->appendPoint(PrimitiveVertex(point, color));
}

void render::PrimitiveNode::appendPoint(const PrimitiveVertex& vertex)
{
	_vertexes.push_back(vertex);
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
