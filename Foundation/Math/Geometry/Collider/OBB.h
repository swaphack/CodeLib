#pragma once

#include "Algebra/import.h"
#include "Geometry/2d/LineSegment2.h"
#include "Geometry/3d/LineSegment.h"

namespace math
{
	/**
	*	OBB��ײ��
	*	oriented bounding box(������α߽��)
	*	
	*/
	struct OBB 
	{
	public:
		// ���Ե�
		Vector3 center;
		// ���
		Vector3 size;
		// ��Χ
		Vector3 extents;
		// ��ת�Ƕ�
		Vector3 rotation;
		// ��С����
		Vector3 minPos;
		// �������
		Vector3 maxPos;
	public:
		/**
		*	����
		*/
		OBB(const Vector3& center, const Vector3& size, const Vector3& rotation);
		/**
		*	����
		*/
		OBB(const Vector3& center, const Vector3& size);
		/**
		*	�Ƿ������
		*/
		bool contains(const Vector2& point32);
		/**
		*	�Ƿ������
		*/
		bool contains(const Vector3& point32);
		/**
		*	�Ƿ�����߶�
		*/
		bool contains(const LineSegment2& line);
		/**
		*	�Ƿ�����߶�
		*/
		bool contains(const LineSegment& line);
		/**
		*	�Ƿ����߶��ཻ
		*/
		bool intersects(const LineSegment2& line);
		/**
		*	�Ƿ����߶��ཻ
		*/
		bool intersects(const LineSegment& line);
		/**
		*	�Ƿ��������
		*/
		bool contains(const OBB& bounds);
		/**
		*	�������Ƿ��ཻ
		*	�����ᶨ�ɣ�
		*	����͹��������壬����������ҵ�һ���ᣬʹ�������������ڸ����ϵ�ͶӰ�����ص���������������֮��û����ײ����������ΪSeparating Axis
		*
		*	������������������ϵ�ͶӰ�������ص������ж�Ϊ��ײ������û�з�����ײ
		*/
		bool intersects(const OBB& bounds);
		/**
		*	����=
		*/
		void operator=(const OBB& obb);
	private:
		/**
		*	����ͶӰ
		*/
		void calProjections();
	};
}