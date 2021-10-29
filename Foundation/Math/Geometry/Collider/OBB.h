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
	class OBB : public BoundingBox
	{
	public:
		/**
		*	����
		*/
		OBB(const Vector3& center, const Vector3& volume, const Vector3& rotation);
		/**
		*	����
		*/
		OBB(const Vector3& center, const Vector3& volume);
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
		virtual bool contains(const Vector2& point) const;
		/**
		*	�Ƿ������
		*/
		virtual bool contains(const Vector3& point) const;
	public:
		/**
		*	�Ƿ�����߶�
		*/
		bool contains(const LineSegment2d& line) const;
		/**
		*	�Ƿ�����߶�
		*/
		bool contains(const LineSegment3d& line) const;
		/**
		*	�Ƿ����߶��ཻ
		*/
		bool intersects(const LineSegment2d& line) const;
		/**
		*	�Ƿ����߶��ཻ
		*/
		bool intersects(const LineSegment3d& line) const;
		/**
		*	����=
		*/
		OBB& operator=(const OBB& obb);
	public:
		/**
		*	�Ƿ��������ཻ
		*/
		virtual bool hitRay(const Ray& ray) const;
	protected:
		// ���
		Vector3 _volume;
		// ��ת�Ƕ�
		Vector3 _rotation;
	};
}