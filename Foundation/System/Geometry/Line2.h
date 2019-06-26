#pragma once

#include "macros.h"

namespace sys
{
	struct AABB;
	// �߶�
	struct Line2
	{
		// ���
		Vector2 src;
		// �յ�
		Vector2 dest;
		/**
		*	���캯��
		*/
		Line2();
		/**
		*	���캯��
		*/
		Line2(const Vector2& src, const Vector2& dest);
		/**
		*	����
		*/
		float getLength();
		/**
		*	��������
		*/
		Vector2 getVector();
		/**
		*	��������
		*/
		Vector2 getVector() const;
		/**
		*	��ȡ��Χ��
		*/
		AABB getBounds();
		/**
		*	��ȡ��Χ��
		*/
		AABB getBounds() const;
		/**
		*	�Ƿ������
		*/
		bool contains(const Vector2& point32);
		/**
		*	�Ƿ�����߶�
		*/
		bool contains(const Line2& line);
		/**
		*	�߶��Ƿ��ཻ
		*/
		bool int32ersects(const Line2& line);
		/**
		*	���߶ε������
		*/
		Vector2 closestPoint32(const Vector2& point32);
	public:
		/**
		*	�㵽ֱ�ߵľ���
		*	(x-x1)/(x2-x1)=(y-y1)/(y2-y1)
		*	ֱ�߷��� a * x + b * y + c = 0
		*	�������������ϵ
		*/
		static float distance(const Line2& line, const Vector2& point32);
	};
}