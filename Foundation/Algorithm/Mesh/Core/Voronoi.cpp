#include "Voronoi.h"
#include "Mesh/Base/import.h"
#include "Delaunay.h"

alg::Voronoi::Voronoi()
{
    _pointSet = new PointSet();
}
alg::Voronoi::~Voronoi()
{
    SAFE_DELETE(_pointSet);
}

bool alg::Voronoi::createWithRect(const math::Rect& rect, Delaunay* delaunay,
    std::vector<math::Polygon>& polygons,
    std::vector<math::LineSegment2d>& lineSegments)
{
	if (delaunay == nullptr || delaunay->getPointSet() == nullptr)
	{
		return false;
	}
    _pointSet->cleanup();

	std::set<alg::MeshEdge*> voronoiEdges = generateEdgesMeshTriangle(delaunay->getPointSet()->getTriangles());
	if (voronoiEdges.size() == 0)
	{
		return false;
	}
	std::set<MeshEdge*> rectEdges;
	rectEdges.insert(_pointSet->createEdge(math::Vector3(rect.getMinX(), rect.getMinY()), math::Vector3(rect.getMaxX(), rect.getMinY())));
	rectEdges.insert(_pointSet->createEdge(math::Vector3(rect.getMaxX(), rect.getMinY()), math::Vector3(rect.getMaxX(), rect.getMaxY())));
	rectEdges.insert(_pointSet->createEdge(math::Vector3(rect.getMaxX(), rect.getMaxY()), math::Vector3(rect.getMinX(), rect.getMaxY())));
	rectEdges.insert(_pointSet->createEdge(math::Vector3(rect.getMinX(), rect.getMaxY()), math::Vector3(rect.getMinX(), rect.getMinY())));

	// 扩展边
	std::map<MeshVertex*, std::vector<MeshEdge*>> samePointEdges;
	for(auto edge : voronoiEdges)
	{
		alg::MeshVertex* pVertex = (alg::MeshVertex*)edge->getVertex(0);
		samePointEdges[pVertex].push_back(edge);

		pVertex = (alg::MeshVertex*)edge->getVertex(1);
		samePointEdges[pVertex].push_back(edge);
	}

	for(auto item : samePointEdges)
	{
		if (item.second.size() == 2)
		{
			if (rect.includes(item.first->getPosition()))
			{
				auto d0 = item.second[0]->getDirection(item.first);
				auto d1 = item.second[1]->getDirection(item.first);
				auto offset = (math::Vector3::normalize(d0) + math::Vector3::normalize(d1)) * (rect.getWidth() + rect.getHeight());
				voronoiEdges.insert(_pointSet->createEdge(item.first->getPosition(), item.first->getPosition() + offset));
			}
		}
	}

	std::set<MeshEdge*> allEdges;

	for (auto item : voronoiEdges)
	{
		allEdges.insert(item);
	}

	// 裁剪
	std::map<MeshEdge*, std::vector<math::Vector3>> allIntersectPoints;
    for(auto edge : voronoiEdges)
    {
        std::vector<math::Vector3> insetctPoints;
        std::vector<math::Vector3> otherPoints;
        for(auto item : rectEdges)
        {
            // 求交点
            math::Vector2 intersectPoint;
            auto lineSeg0 = math::LineSegment2d(item->getPosition(0), item->getPosition(1));
            auto lineSeg1 = math::LineSegment2d(edge->getPosition(0), edge->getPosition(1));
            if (lineSeg0.intersects(lineSeg1, intersectPoint))
            {
                // 与边相交的点
                insetctPoints.push_back(intersectPoint);
                allIntersectPoints[item].push_back(intersectPoint);

                auto line = math::Line2d(lineSeg0);
                // 框内的点
                if (rect.contains(edge->getPosition(0)))
                {
                    otherPoints.push_back(edge->getPosition(0));
                }
                else
                {
                    otherPoints.push_back(edge->getPosition(1));
                }
            }
        }
        if (insetctPoints.size() == 2)
        {
            _pointSet->removeEdge(edge);
            allEdges.erase(edge);
            allEdges.insert(_pointSet->createEdge(insetctPoints[0], insetctPoints[1]));
        }
        else if (insetctPoints.size() == 1 && otherPoints.size() == 1)
        {
            _pointSet->removeEdge(edge);
            allEdges.erase(edge);
            allEdges.insert(_pointSet->createEdge(insetctPoints[0], otherPoints[0]));
        }
        else
        {
            //排除大区域外的点
            if (!rect.contains(edge->getPosition(0))
                && !rect.contains(edge->getPosition(1)))
            {
                _pointSet->removeEdge(edge);
                allEdges.erase(edge);
                continue;
            }
        }
    }

    // 交点处理
    for (auto item : allIntersectPoints)
    {
        // 对点进行排序
        std::vector<math::Vector3> edgePoints;
        edgePoints.insert(edgePoints.end(), item.second.begin(), item.second.end());
        std::sort(edgePoints.begin(), edgePoints.end(), [](const math::Vector3& a, const math::Vector3& b) { return math::CompareVec3(a, b); });

        math::Vector3 firstPoint;
        math::Vector3 secondPoint;
        if (item.first->getPosition(0).getX() < item.first->getPosition(1).getX())
        {
            firstPoint = item.first->getPosition(0);
            secondPoint = item.first->getPosition(1);
        }
        else if (item.first->getPosition(0).getY() < item.first->getPosition(1).getY())
        {
            firstPoint = item.first->getPosition(0);
            secondPoint = item.first->getPosition(1);
        }
        else
        {
            firstPoint = item.first->getPosition(1);
            secondPoint = item.first->getPosition(0);
        }
        auto it = std::find(edgePoints.begin(), edgePoints.end(), firstPoint);
        if (it == edgePoints.end())
        {
            edgePoints.insert(edgePoints.begin(), firstPoint);
        }
        it = std::find(edgePoints.begin(), edgePoints.end(), secondPoint);
        if (it == edgePoints.end())
        {
            edgePoints.push_back(secondPoint);
        }
        for (int i = 0; i < edgePoints.size() - 1; i++)
        {
            allEdges.insert(_pointSet->createEdge(edgePoints[i], edgePoints[i + 1]));
        }
        allEdges.erase(item.first);
    }

    // 转成多边形的边
    std::map<MeshEdge*, MeshPolygonEdge*> polygonEdges = MeshPolygonEdge::createPolygonEdges(allEdges);
    if (polygonEdges.size() == 0)
    {
        return false;
    }

    // 转成多边形
    std::set<std::string> keys;
    for(auto item : polygonEdges)
    {
        lineSegments.push_back(math::LineSegment2d(item.first->getPosition(0), item.first->getPosition(1)));
        auto polygon = MeshPolygonEdge::getConvexPolygon(item.second);
        int count = polygon.getPointCount();
        if (count > 2)
        {
            std::vector<math::Vector3> vecPoint = polygon.getPoints();

            auto key = PointSet::getKey(vecPoint);
            auto it = keys.find(key);
            if (it == keys.end())
            {
                keys.insert(key);
                std::vector<math::Vector3> outPoints;
                if (math::GeometryUtiity::createConvexPolygon(vecPoint, outPoints))
                {// 逆时针
                    std::reverse(outPoints.begin(), outPoints.end());
                    polygons.push_back(outPoints);
                }
            }
        }
    }

	return true;
}

alg::PointSet* alg::Voronoi::getPointSet()
{
    return _pointSet;
}

std::set<alg::MeshEdge*> alg::Voronoi::generateEdgesMeshTriangle(const std::map<std::string, MeshTriangle*>& triangles)
{
	std::set<alg::MeshEdge*> edges;

	if (_pointSet == nullptr || triangles.size() == 0)
	{
		return edges;
	}

	for (auto item : triangles)
	{
		auto sharedEdgeTriangles = item.second->getSharedEdgeTriangles();
		for (auto neighbor : sharedEdgeTriangles)
		{
			auto edge = _pointSet->createEdge(
				item.second->getCircumcircle().getPosition(),
				neighbor->getCircumcircle().getPosition());

			edges.insert(edge);
		}
	}

	return edges;
}
