#pragma once
#include "mathlib.h"
#include "NavSegment.h"

namespace alg
{
	namespace mesh
	{
		/**
		*	���������еĶ���Σ�Ϊ͹�����
		*/
		class NavPoly
		{
		public:
			NavPoly();
			~NavPoly();
		public:
			/**
			*	˳��㣬͹�����
			*/
			bool initWithPoints(const std::vector<math::Vector3>& points);
			/**
			*	����Σ�͹�����
			*/
			bool initWithPolygon(const math::Polygon& polygon);
			/**
			*	��ȡ͹�����
			*/
			const math::Polygon& getPolygon() const;
			/**
			*	��ȡ��
			*/
			const std::vector<NavSegment>& getEdges() const;
		public:
			/*
			*	�ж���Ŀ�������Ƿ�����,���������ȡ�����ڱ�,���ж�
			*/
			bool isNeighborWithSimpleCheck(const NavPoly& poly, NavSegment& segment);
			/*
			*	�ж���Ŀ�������Ƿ�����,���������ȡ�����ڱ�
			*/
			bool isNeighbor(const NavPoly& poly, NavSegment& segment);
			/*
			*	����ڱ߶����
			*/
			bool addNeighbor(const NavPoly& poly);
		private:
			// �����
			math::Polygon _polygon;
			// ��
			std::vector<NavSegment> _edges;
		};
	}
}
