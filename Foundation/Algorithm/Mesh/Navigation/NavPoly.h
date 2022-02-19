#pragma once
#include "mathlib.h"

namespace alg
{
	namespace mesh
	{
		/**
		*	���������е��߶�
		*/
		struct NavSegment
		{
			math::Vector3 src;
			math::Vector3 dest;
		};
		/**
		*	���������еĶ���Σ�Ϊ͹�����
		*/
		class NavPoly
		{
		public:
			NavPoly();
			~NavPoly();
		public:
			/*
			*	�ж���Ŀ�������Ƿ�����,���������ȡ�����ڱ�
			*/
			bool isNeighbor(const NavPoly& poly, NavSegment& segment);
			/*
			*	����ڱ߶����
			*/
			bool addNeighbor(const NavPoly& poly);
		private:
			math::Polygon _polygon;
		};
	}
}
