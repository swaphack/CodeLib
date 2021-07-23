#pragma once

#include "mathlib.h"
#include "system.h"
#include "MeshProtocol.h"
#include <set>

namespace alg
{
	class MeshEdge;
	class PointSet;

	/**
	*	网格顶点
	*/
	class MeshVertex : public MeshProtocol
	{
	public:
		MeshVertex(const math::Vector3& position);
		MeshVertex(PointSet* pointSet, const math::Vector3& position);
		virtual ~MeshVertex();
	public:
		/**
		*	位置
		*/
		void setPosition(const math::Vector3& position);
		/**
		*	位置
		*/
		const math::Vector3& getPosition() const;
		/**
		*	添加共点边
		*/
		void addSharedPointEdge(MeshEdge* edge);
		/**
		*	移除共点边
		*/
		void removeSharedPointEdge(MeshEdge* edge);
		/**
		*	共点边
		*/
		const std::set<MeshEdge*>& getSharedPointEdges() const;
		/**
		*	共点的边
		*/
		std::set<MeshEdge*>& getSharedPointEdges();
	public:
		/**
		*	是否相等
		*/
		bool equal(const MeshVertex& vertex) const;
		/**
		*	是否相等
		*/
		bool equal(const MeshVertex* pVertex) const;
	private:
		/**
		*	共享点的边
		*/
		std::set<MeshEdge*> _sharedPointEdges;
		/**
		*	位置
		*/
		math::Vector3 _position;
	};
}
