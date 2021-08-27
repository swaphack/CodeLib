#include "MeshPolygonEdge.h"
#include "MeshVertex.h"
#include "MeshEdge.h"
#include "MeshPolygon.h"

alg::MeshPolygonEdge::MeshPolygonEdge(MeshEdge* edge)
{
    _edge = edge;
}

alg::MeshPolygonEdge::~MeshPolygonEdge()
{
}

alg::MeshEdge* alg::MeshPolygonEdge::getEdge() const
{ 
	return _edge;
}

alg::MeshVertex* alg::MeshPolygonEdge::addSharedPointEdge(MeshPolygonEdge* polygonEdge)
{
    if (polygonEdge == nullptr || _edge == polygonEdge->_edge) return nullptr;
    auto point = _edge->getSharedPoint(polygonEdge->_edge);
    if (point == nullptr) return nullptr;

    this->_addSharedPointEdge(point, polygonEdge);
    polygonEdge->_addSharedPointEdge(point, this);

    return point;
}

std::vector<alg::MeshPolygonEdge*>* alg::MeshPolygonEdge::getPolygonEdges(MeshVertex* point)
{
    std::vector<MeshPolygonEdge*> values;
    auto it = _sharedPointEdges.find(point);
    if (it == _sharedPointEdges.end()) return nullptr;
    return &it->second;
}

/**
*   添加共顶点边
*/


/**
*   关联
*/


/// <summary>
/// 获取构成凸包的边
/// </summary>
/// <param name="endPoint"></param>
/// <returns></returns>

alg::MeshPolygonEdge* alg::MeshPolygonEdge::getConvexPolygonEdge(MeshVertex* endPoint)
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
                auto line = math::Line2d(startPoint->getPosition(), endPoint->getPosition());
                // 剔除另一端不满足的点
                if (line.getPointPositionType(math::Vector2(e0->getPosition())) == math::PointAndLinePosition2DType::EXLUDE_RIGHT)
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

void alg::MeshPolygonEdge::linkTo(MeshPolygon* polygon)
{
    if (polygon == nullptr)
    {
        return;
    }
    _sharedEdgePolygons.insert(polygon);
}

void alg::MeshPolygonEdge::_addSharedPointEdge(MeshVertex* point, MeshPolygonEdge* polygonEdge)
{
    if (point == nullptr || polygonEdge == nullptr) return;
    _sharedPointEdges[point].push_back(polygonEdge);
}

/**
*   创建多边形边
*/

std::map<alg::MeshEdge*, alg::MeshPolygonEdge*> alg::MeshPolygonEdge::createPolygonEdges(const std::set<MeshEdge*>& edges)
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

math::Polygon alg::MeshPolygonEdge::getConvexPolygon(MeshPolygonEdge* polygonEdge)
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
