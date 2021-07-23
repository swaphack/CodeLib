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
	*	���񶥵�
	*/
	class MeshVertex : public MeshProtocol
	{
	public:
		MeshVertex(const math::Vector3& position);
		MeshVertex(PointSet* pointSet, const math::Vector3& position);
		virtual ~MeshVertex();
	public:
		/**
		*	λ��
		*/
		void setPosition(const math::Vector3& position);
		/**
		*	λ��
		*/
		const math::Vector3& getPosition() const;
		/**
		*	��ӹ����
		*/
		void addSharedPointEdge(MeshEdge* edge);
		/**
		*	�Ƴ������
		*/
		void removeSharedPointEdge(MeshEdge* edge);
		/**
		*	�����
		*/
		const std::set<MeshEdge*>& getSharedPointEdges() const;
		/**
		*	����ı�
		*/
		std::set<MeshEdge*>& getSharedPointEdges();
	public:
		/**
		*	�Ƿ����
		*/
		bool equal(const MeshVertex& vertex) const;
		/**
		*	�Ƿ����
		*/
		bool equal(const MeshVertex* pVertex) const;
	private:
		/**
		*	�����ı�
		*/
		std::set<MeshEdge*> _sharedPointEdges;
		/**
		*	λ��
		*/
		math::Vector3 _position;
	};
}
