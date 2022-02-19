#pragma once
#include "mathlib.h"

namespace alg
{
	namespace mesh
	{
		/**
		*	导航网格中的线段
		*/
		struct NavSegment
		{
			math::Vector3 src;
			math::Vector3 dest;
		};
		/**
		*	导航网格中的多边形，为凸多边形
		*/
		class NavPoly
		{
		public:
			NavPoly();
			~NavPoly();
		public:
			/*
			*	判断与目标多边形是否相连,如果相连，取得相邻边
			*/
			bool isNeighbor(const NavPoly& poly, NavSegment& segment);
			/*
			*	添加邻边多边形
			*/
			bool addNeighbor(const NavPoly& poly);
		private:
			math::Polygon _polygon;
		};
	}
}
