#pragma once
#include "mathlib.h"
#include "NavSegment.h"

namespace alg
{
	namespace mesh
	{
		/**
		*	导航网格中的多边形，为凸多边形
		*/
		class NavPoly
		{
		public:
			NavPoly();
			~NavPoly();
		public:
			/**
			*	顺序点，凸多边形
			*/
			bool initWithPoints(const std::vector<math::Vector3>& points);
			/**
			*	多边形，凸多边形
			*/
			bool initWithPolygon(const math::Polygon& polygon);
			/**
			*	获取凸多边形
			*/
			const math::Polygon& getPolygon() const;
			/**
			*	获取边
			*/
			const std::vector<NavSegment>& getEdges() const;
		public:
			/*
			*	判断与目标多边形是否相连,如果相连，取得相邻边,简单判断
			*/
			bool isNeighborWithSimpleCheck(const NavPoly& poly, NavSegment& segment);
			/*
			*	判断与目标多边形是否相连,如果相连，取得相邻边
			*/
			bool isNeighbor(const NavPoly& poly, NavSegment& segment);
			/*
			*	添加邻边多边形
			*/
			bool addNeighbor(const NavPoly& poly);
		private:
			// 多边形
			math::Polygon _polygon;
			// 边
			std::vector<NavSegment> _edges;
		};
	}
}
