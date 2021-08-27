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
    /// ����εı�
    /// </summary>
    class MeshPolygonEdge : MeshProtocol
    {
    public:
        MeshPolygonEdge(MeshEdge* edge);
        virtual ~MeshPolygonEdge();
    public:
        MeshEdge* getEdge() const;
        /**
        *   ��ӹ������
        */
        MeshVertex* addSharedPointEdge(MeshPolygonEdge* polygonEdge);
        /**
        *   ��ȡ����ı�
        */
        std::vector<MeshPolygonEdge*>* getPolygonEdges(MeshVertex* point);
        /// <summary>
        /// ��ȡ����͹���ı�
        /// </summary>
        /// <param name="endPoint"></param>
        /// <returns></returns>
        MeshPolygonEdge* getConvexPolygonEdge(MeshVertex* endPoint);

        /**
        *   ����
        */
        void linkTo(MeshPolygon* polygon);
    private:
        /**
        *   ��ӹ������
        */
        void _addSharedPointEdge(MeshVertex* point, MeshPolygonEdge* polygonEdge);
    public:
        /**
        *   ��������α�
        */
        static std::map<MeshEdge*, MeshPolygonEdge*> createPolygonEdges(const std::set<MeshEdge*>& edges);

        /**
        *   ��ȡ͹����� ������,˳ʱ�뷽��
        */
        static math::Polygon getConvexPolygon(MeshPolygonEdge* polygonEdge);
    private:
        MeshEdge* _edge = nullptr;
        std::map<MeshVertex*, std::vector<MeshPolygonEdge*>> _sharedPointEdges;
        std::set<MeshPolygon*> _sharedEdgePolygons;
    };
}