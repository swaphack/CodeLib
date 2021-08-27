#pragma once
#include "mathlib.h"
#include "MeshProtocol.h"

#include <vector>
#include <map>

namespace alg
{
    class MeshVertex;
    class MeshEdge;
    class MeshPolygon;

    /// <summary>
    /// 多边形的边
    /// </summary>
    class MeshPolygonEdge : MeshProtocol
    {
    public:
        MeshPolygonEdge(MeshEdge* edge);
        virtual ~MeshPolygonEdge();
    public:
        MeshEdge* getEdge() const;
        /**
        *   添加共顶点边
        */
        MeshVertex* addSharedPointEdge(MeshPolygonEdge* polygonEdge);
        /**
        *   获取共点的边
        */
        std::vector<MeshPolygonEdge*>* getPolygonEdges(MeshVertex* point);
        /// <summary>
        /// 获取构成凸包的边
        /// </summary>
        /// <param name="endPoint"></param>
        /// <returns></returns>
        MeshPolygonEdge* getConvexPolygonEdge(MeshVertex* endPoint);

        /**
        *   关联
        */
        void linkTo(MeshPolygon* polygon);
    private:
        /**
        *   添加共顶点边
        */
        void _addSharedPointEdge(MeshVertex* point, MeshPolygonEdge* polygonEdge);
    public:
        /**
        *   创建多边形边
        */
        static std::map<MeshEdge*, MeshPolygonEdge*> createPolygonEdges(const std::set<MeshEdge*>& edges);

        /**
        *   获取凸多边形 从左到右,顺时针方向
        */
        static math::Polygon getConvexPolygon(MeshPolygonEdge* polygonEdge);
    private:
        MeshEdge* _edge = nullptr;
        std::map<MeshVertex*, std::vector<MeshPolygonEdge*>> _sharedPointEdges;
        std::set<MeshPolygon*> _sharedEdgePolygons;
    };
}