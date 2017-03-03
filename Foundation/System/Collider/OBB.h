#pragma once

#include "macros.h"

namespace sys
{
	struct Line3;
	struct Line2;

	/**
	*	OBB��ײ��
	*	oriented bounding box(������α߽��)
	*	
	*/
	struct OBB 
	{
		// ���Ե�
		Vector3 center;
		// ���
		Vector3 size;
		// ��ת�Ƕ�
		Vector3 rotation;

		/**
		*	����
		*/
		OBB(const Vector3& center, const Vector3& size, const Vector3& rotation);
		/**
		*	�Ƿ������
		*/
		bool contains(const Vector2& point);
		/**
		*	�Ƿ������
		*/
		bool contains(const Vector3& point);
		/**
		*	�Ƿ�����߶�
		*/
		bool contains(const Line2& line);
		/**
		*	�Ƿ�����߶�
		*/
		bool contains(const Line3& line);
		/**
		*	�Ƿ����߶��ཻ
		*/
		bool intersects(const Line2& line);
		/**
		*	�Ƿ����߶��ཻ
		*/
		bool intersects(const Line3& line);
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

		/**
		*	x�����Сֵ
		*/
		float minX();
		/**
		*	y�����Сֵ
		*/
		float minY();
		/**
		*	z�����Сֵ
		*/
		float minZ();

		/**
		*	x������ֵ
		*/
		float maxX();
		/**
		*	y������ֵ
		*/
		float maxY();
		/**
		*	z������ֵ
		*/
		float maxZ();

		/**
		*	x�����Сֵ
		*/
		float minX() const;
		/**
		*	y�����Сֵ
		*/
		float minY() const;
		/**
		*	z�����Сֵ
		*/
		float minZ() const;

		/**
		*	x������ֵ
		*/
		float maxX() const;
		/**
		*	y������ֵ
		*/
		float maxY() const;
		/**
		*	z������ֵ
		*/
		float maxZ() const;
	};
}