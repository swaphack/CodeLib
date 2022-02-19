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
		*	1����Բ���ԣ�Delaunay��������Ψһ�ģ������ĵ㲻�ܹ�Բ������Delaunay������������һ�����ε����Բ��Χ�ڲ�������������ڡ�
		*	2�������С�����ԣ���ɢ�㼯�����γɵ������ʷ��У�Delaunay�����ʷ����γɵ������ε���С�����
		*	����������Ͻ���Delaunay�������ǡ���ӽ��ڹ��򻯵ġ�����������
		*	�����˵��ָ���������ڵ������ι���͹�ı��εĶԽ��ߣ����໥�����������ڽǵ���С�ǲ�������
		*/
		class Delaunay
		{
		public:
			Delaunay();
			virtual ~Delaunay();
		public:
			/**
			*	ʹ�õ㼯����������
			*	1������һ�����������Σ���������ɢ�㣬��������������
			*	2�����㼯�е�ɢ�����β��룬���������������ҳ����Բ���������������Σ���Ϊ�õ��Ӱ�������Σ���
			*	ɾ��Ӱ�������εĹ����ߣ��������ͬӰ�������ε�ȫ����������������
			*	���һ������Delaunay�����������еĲ��롣
			*	3�������Ż�׼��Ծֲ����γɵ��������Ż������γɵ������η���Delaunay����������
			*	4��ѭ��ִ��������2����ֱ������ɢ�������ϡ�
			*/
			std::vector<math::TrianglePoints> createWithBowyerWatson(const std::vector<math::Vector3>& srcPoints);
			/**
			*	��ָ�������ڣ�ʹ�õ㼯����������
			*	1�����������������������Σ���������ɢ�㣬��������������
			*	2�����㼯�е�ɢ�����β��룬���������������ҳ����Բ���������������Σ���Ϊ�õ��Ӱ�������Σ���
			*	ɾ��Ӱ�������εĹ����ߣ��������ͬӰ�������ε�ȫ����������������
			*	���һ������Delaunay�����������еĲ��롣
			*	3�������Ż�׼��Ծֲ����γɵ��������Ż������γɵ������η���Delaunay����������
			*	4��ѭ��ִ��������2����ֱ������ɢ�������ϡ�
			*/
			std::vector<math::TrianglePoints> createWithBowyerWatson(const math::RectPoints& rect, const std::vector<math::Vector3>& srcPoints);
		public:
			/**
			*	�㼯
			*/
			const PointSet* getPointSet() const;
			/**
			*	�㼯
			*/
			PointSet* getPointSet();
		protected:
			/**
			*	��������������
			*/
			MeshTriangle* initSuperTriangle();
			/**
			*	��������������
			*/
			std::vector<MeshTriangle*> initRectTriangle(const math::RectPoints& rect);
			/**
			*	����������
			*/
			void generateTriangle(const std::vector<math::Vector3>& points, std::set<MeshTriangle*>& meshTriangles);
			/**
			*	�Ƴ�������
			*/
			void removeTriangle(std::set<MeshTriangle*>& meshTriangles,
				std::vector<MeshTriangle*>& badTriangles,
				int index);
		private:
			/**
			*	�㼯
			*/
			PointSet* _pointSet = nullptr;
		};
	}
}
