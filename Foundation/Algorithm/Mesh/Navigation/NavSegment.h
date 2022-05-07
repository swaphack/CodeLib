#pragma once
#include "mathlib.h"
#include <set>

namespace alg
{
	namespace mesh
	{
		class NavPoly;

		/**
		*	���������е��߶�
		*/
		struct NavSegment
		{
		public:
			// ��ʼ��
			math::Vector3 src;
			// �յ�
			math::Vector3 dest;
			// ���н�
			float tan = 0;
			// �߶�Ӧ�Ķ����
			std::set<NavPoly*> polygons;
		public:
			NavSegment();
			NavSegment(const math::Vector3& src, const math::Vector3& dest);
			virtual~NavSegment();
		public:
			/**
			*	��ȡ�н�
			*/
			float getAngle() const;
			/**
			*	��Ӧ����θ���
			*/
			int getPolygonCount() const;
			/**
			*	��Ӷ����
			*/
			void addPolygon(const NavPoly* poly);
			/**
			*	�Ƿ���ͬһ�߶�
			*/
			bool equals(const NavSegment& segment) const;
		};
	}
}