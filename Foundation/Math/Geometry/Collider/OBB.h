#pragma once

#include "BoundingBox.h"
#include "Geometry/2d/LineSegment2d.h"
#include "Geometry/3d/LineSegment3d.h"
#include "SphereBB.h"

namespace math
{
	/**
	*	OBB��ײ��
	*	oriented bounding box(������α߽��)
	*	
	*/
	struct OBB : public BoundingBox
	{
	public:
		/**
		*	����
		*/
		OBB(const Vector3& center, const Vector3& size, const Vector3& rotation);
		/**
		*	����
		*/
		OBB(const Vector3& center, const Vector3& size);
	public:
		/**
		*	���
		*/
		const Vector3& getVolume() const;
		/**
		*	��ת
		*/
		const Vector3& getRotation() const;
		/**
		*	���ò���
		*/
		void set(const Vector3& center, const Vector3& size, const Vector3& rotation);
		/**
		*	���ò���
		*/
		void set(const Vector3& center, const Vector3& size);
	public:
		/**
		*	�Ƿ������
		*/
		virtual bool contains(const Vector2& point);
		/**
		*	�Ƿ������
		*/
		virtual bool contains(const Vector3& point);
	public:
		/**
		*	�Ƿ�����߶�
		*/
		bool contains(const LineSegment2d& line);
		/**
		*	�Ƿ�����߶�
		*/
		bool contains(const LineSegment3d& line);
		/**
		*	�Ƿ����߶��ཻ
		*/
		bool intersects(const LineSegment2d& line);
		/**
		*	�Ƿ����߶��ཻ
		*/
		bool intersects(const LineSegment3d& line);
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
	protected:
		// ���
		Vector3 _volume;
		// ��ת�Ƕ�
		Vector3 _rotation;
	};
}