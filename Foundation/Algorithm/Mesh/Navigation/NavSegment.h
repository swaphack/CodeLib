#pragma once
#include "mathlib.h"
#include <set>

namespace alg
{
	namespace mesh
	{
		class NavPoly;

		/**
		*	导航网格中的线段
		*/
		struct NavSegment
		{
		public:
			// 起始点
			math::Vector3 src;
			// 终点
			math::Vector3 dest;
			// 正切教
			float tan = 0;
			// 边对应的多边形
			std::set<NavPoly*> polygons;
		public:
			NavSegment();
			NavSegment(const math::Vector3& src, const math::Vector3& dest);
			virtual~NavSegment();
		public:
			/**
			*	获取夹角
			*/
			float getAngle() const;
			/**
			*	对应多边形个数
			*/
			int getPolygonCount() const;
			/**
			*	添加多边形
			*/
			void addPolygon(const NavPoly* poly);
			/**
			*	是否是同一线段
			*/
			bool equals(const NavSegment& segment) const;
		};
	}
}