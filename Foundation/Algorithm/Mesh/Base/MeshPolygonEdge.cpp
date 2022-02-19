#include "MeshPolygonEdge.h"
#include "MeshVertex.h"
#include "MeshEdge.h"
#include "MeshPolygon.h"

alg::mesh::MeshPolygonEdge::MeshPolygonEdge(MeshEdge* edge)
{
    _edge = edge;
}

alg::mesh::MeshPolygonEdge::~MeshPolygonEdge()
{
}

alg::mesh::MeshEdge* alg::mesh::MeshPolygonEdge::getEdge() const
{ 
	return _edge;
}

alg::mesh::MeshVertex* alg::mesh::MeshPolygonEdge::addSharedPointEdge(MeshPolygonEdge* polygonEdge)
{
    if (polygonEdge == nullptr || _edge == polygonEdge->_edge) return nullptr;
    auto point = _edge->getSharedPoint(polygonEdge->_edge);
    if (point == nullptr) return nullptr;

    this->_addSharedPointEdge(point, polygonEdge);
    polygonEdge->_addSharedPointEdge(point, this);

    return point;
}

std::vector<alg::mesh::MeshPolygonEdge*>* alg::mesh::MeshPolygonEdge::getPolygonEdges(MeshVertex* point)
{
    std::vector<MeshPolygonEdge*> values;
    auto it = _sharedPointEdges.find(point);
    if (it == _sharedPointEdges.end()) return nullptr;
    return &it->second;
}

alg::mesh::MeshPolygonEdge* alg::mesh::MeshPolygonEdge::getConvexPolygonEdge(MeshVertex* endPoint)
{
    if (endPoint == nullptr) return nullptr;
    auto startPoint = _edge->getOtherPoint(endPoint);
    if (startPoint == nullptr)
    {
        return nullptr;
    }
    std::vector<MeshPolygonEdge*>* values = getPolygonEdges(endPoint);
    if (values != nullptr && values->size() > 0)
    {
        std::vector<MeshPolygonEdge*> sharedEdges;
        for (auto item : *values)
        {
            auto e0 = item->getEdge()->getOtherPoint(endPoint);
            if (e0 != nullptr)
            {
                // ÊÇ·ñË³Ê±Õë
                if (math::GeometryUtiity::isClockWise(startPoint->getPosition(), endPoint->getPosition(), e0->getPosition()))
                {
                    sharedEdges.push_back(item);
                }
            }

        }
        if (sharedEdges.size() == 0)
        {
            return nullptr;
        }
        std::sort(sharedEdges.begin(), sharedEdges.end(), [startPoint, endPoint](const MeshPolygonEdge* a, const MeshPolygonEdge* b) {
            auto e0 = a->getEdge()->getOtherPoint(endPoint);
            auto e1 = b->getEdge()->getOtherPoint(endPoint);

            auto v0 = e0->getPosition() - endPoint->getPosition();
            auto v1 = e1->getPosition() - endPoint->getPosition();
            auto v2 = startPoint->getPosition() - endPoint->getPosition();
            float a0 = math::Vector3::getRadian(v0, v2);
            float a1 = math::Vector3::getRadian(v1, v2);
            return a0 < a1;
        });

        return sharedEdges[0];
    }
    else
    {
        return nullptr;
    }
}

void alg::mesh::MeshPolygonEdge::linkTo(MeshPolygon* polygon)
{
    if (polygon == nullptr)
    {
        return;
    }
    _sharedEdgePolygons.insert(polygon);
}

void alg::mesh::MeshPolygonEdge::_addSharedPointEdge(MeshVertex* point, MeshPolygonEdge* polygonEdge)
{
    if (point == nullptr || polygonEdge == nullptr) return;
    _sharedPointEdges[point].push_back(polygonEdge);
}

std::map<alg::mesh::MeshEdge*, alg::mesh::MeshPolygonEdge*> alg::mesh::MeshPolygonEdge::createPolygonEdges(const std::set<MeshEdge*>& edges)
{
    std::map<MeshEdge*, MeshPolygonEdge*> polygonEdges;

    if (edges.size() == 0)
    {
        return polygonEdges;
    }
    std::set<MeshVertex*> sharedPoints;
    for (auto item : edges)
    {
        if (polygonEdges.find(item) == polygonEdges.end())
        {
            polygonEdges[item] = new MeshPolygonEdge(item);
        }
        auto temp = polygonEdges[item];
        for (auto item1 : polygonEdges)
        {
            item1.second->addSharedPointEdge(temp);
        }
    }

    return polygonEdges;
}

math::Polygon alg::mesh::MeshPolygonEdge::getConvexPolygon(MeshPolygonEdge* polygonEdge)
{
    MeshPolygon polygon;

    if (polygonEdge == nullptr || polygonEdge->_sharedPointEdges.size() == 0)
        return math::Polygon();

    polygon.addEdge(polygonEdge->getEdge());

    auto temp = polygonEdge;
    auto endPoint = polygonEdge->getEdge()->getVertex(0);
    do
    {
        temp = temp->getConvexPolygonEdge(endPoint);
        if (temp == nullptr)
        {
            break;
        }

        if (temp == polygonEdge)
        {
            break;
        }
        endPoint = temp->getEdge()->getOtherPoint(endPoint);
        polygon.addEdge(temp->getEdge());

    } while (true);

    std::vector<math::Vector3> points;
    for (size_t i = 0; i < polygon.getVertexCount(); i++)
    {
        auto pVertex = polygon.getVertex(i);
        if (pVertex) points.push_back(pVertex->getPosition());
    }
    return math::Polygon(points);
}
