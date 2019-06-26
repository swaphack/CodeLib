#pragma once

#include "macros.h"
#include "Base/Types.h"

namespace sys
{
	struct Polygon;
	/**
	*	���弸�ε���
	*/
	struct Surface
	{
		Vector3* point32s;
		int32 count;

		Surface();
		Surface(const Surface& surface);
		Surface(Vector3* point32s, int32 count);

		~Surface();
		/**
		*	������
		*/
		Vector3 normalVector();
		/**
		*	������
		*/
		Vector3 normalVector() const;
		/**
		*	�Ƿ������
		*	���ж��Ƿ��棬���ж�ͶӰ�Ƿ����
		*/
		bool contain(const Vector3& point32);
		/**
		*	����=
		*/
		Surface& operator=(const Surface& surface);
	public:
		/**
		*	�Ƿ��Ǳ�׼�Ķ���Σ����������ڵ���3,�������ڲ����ڹ��ߵ����
		*	�ҹ���
		*/
		static bool isStandard(const Surface& surface);
		/**
		*	�Ƿ���͹�����
		*/
		static bool isConvex(const Surface& surface);
		/**
		*	����ƽ���Ƿ���
		*/
		static bool isCoplanar(const Surface& surface, const Vector3& point32);
		/**
		*	�ĵ��Ƿ���
		*/
		static bool isCoplanar(const Vector3& point320, const Vector3& point321, const Vector3& point322, 
			const Vector3& point323);
		/**
		*	ͶӰ��xoy��
		*/
		static Polygon projectOnXOY(const Surface& surface);
		/**
		*	ͶӰ��yoz��
		*/
		static Polygon projectOnYOZ(const Surface& surface);
		/**
		*	ͶӰ��xoz��
		*/
		static Polygon projectOnXOZ(const Surface& surface);
	};
}