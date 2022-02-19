#pragma once

#include <set>
#include <vector>

#include "mathlib.h"

namespace alg
{
	namespace mesh
	{
		class PointSet;
		class MeshTriangle;
		/**
		*	1、空圆特性：Delaunay三角网是唯一的（任意四点不能共圆），在Delaunay三角形网中任一三角形的外接圆范围内不会有其它点存在。
		*	2、最大化最小角特性：在散点集可能形成的三角剖分中，Delaunay三角剖分所形成的三角形的最小角最大。
		*	从这个意义上讲，Delaunay三角网是“最接近于规则化的“的三角网。
		*	具体的说是指在两个相邻的三角形构成凸四边形的对角线，在相互交换后，六个内角的最小角不再增大
		*/
		class Delaunay
		{
		public:
			Delaunay();
			virtual ~Delaunay();
		public:
			/**
			*	使用点集生成三角形
			*	1、构造一个超级三角形，包含所有散点，放入三角形链表。
			*	2、将点集中的散点依次插入，在三角形链表中找出外接圆包含插入点的三角形（称为该点的影响三角形），
			*	删除影响三角形的公共边，将插入点同影响三角形的全部顶点连接起来，
			*	完成一个点在Delaunay三角形链表中的插入。
			*	3、根据优化准则对局部新形成的三角形优化。将形成的三角形放入Delaunay三角形链表。
			*	4、循环执行上述第2步，直到所有散点插入完毕。
			*/
			std::vector<math::TrianglePoints> createWithBowyerWatson(const std::vector<math::Vector3>& srcPoints);
			/**
			*	在指定区域内，使用点集生成三角形
			*	1、构造矩形区域的两个三角形，包含所有散点，放入三角形链表。
			*	2、将点集中的散点依次插入，在三角形链表中找出外接圆包含插入点的三角形（称为该点的影响三角形），
			*	删除影响三角形的公共边，将插入点同影响三角形的全部顶点连接起来，
			*	完成一个点在Delaunay三角形链表中的插入。
			*	3、根据优化准则对局部新形成的三角形优化。将形成的三角形放入Delaunay三角形链表。
			*	4、循环执行上述第2步，直到所有散点插入完毕。
			*/
			std::vector<math::TrianglePoints> createWithBowyerWatson(const math::RectPoints& rect, const std::vector<math::Vector3>& srcPoints);
		public:
			/**
			*	点集
			*/
			const PointSet* getPointSet() const;
			/**
			*	点集
			*/
			PointSet* getPointSet();
		protected:
			/**
			*	创建超级三角形
			*/
			MeshTriangle* initSuperTriangle();
			/**
			*	创建区域三角形
			*/
			std::vector<MeshTriangle*> initRectTriangle(const math::RectPoints& rect);
			/**
			*	生成三角形
			*/
			void generateTriangle(const std::vector<math::Vector3>& points, std::set<MeshTriangle*>& meshTriangles);
			/**
			*	移除三角形
			*/
			void removeTriangle(std::set<MeshTriangle*>& meshTriangles,
				std::vector<MeshTriangle*>& badTriangles,
				int index);
		private:
			/**
			*	点集
			*/
			PointSet* _pointSet = nullptr;
		};
	}
}
