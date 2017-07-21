#pragma once

#include "macros.h"
#include <vector>

namespace sys
{
	/**
	*	����
	*/
	struct VertexSet
	{
	public:
		// ��������
		int count();
		// ���һ������
		void add(const Vector2& point);
		// �Ƴ�һ������
		void remove(const Vector2& point);
		// �Ƴ�һ������
		void remove(int index);
		// ������ж���
		void clear();
		// ת��Ϊ����
		Vector2* toArray();
		// ��һ������
		Vector2* head();
		// ���һ������
		Vector2* tail();
		// β��׷��һ�����㼯��
		void append(const VertexSet& second);
		// ��������
		Vector2* operator[](int index);
	private:
		std::vector<Vector2> m_vecPoint;
	};
}