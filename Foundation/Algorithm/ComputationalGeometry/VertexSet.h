#pragma once

#include "macros.h"
#include <vector>

namespace acg
{
	/**
	*	����
	*/
	class VertexSet
	{
	public:
		VertexSet();
		~VertexSet();
	public:
		// ��������
		int count();
		// ���һ������
		void add(const sys::Vector2& point);
		// �Ƴ�һ������
		void remove(const sys::Vector2& point);
		// �Ƴ�һ������
		void remove(int index);
		// ������ж���
		void clear();
		// ת��Ϊ����
		sys::Vector2* toArray();
		// ��һ������
		sys::Vector2* head();
		// ���һ������
		sys::Vector2* tail();
		// β��׷��һ�����㼯��
		void append(const VertexSet& second);
		// ��������
		sys::Vector2& operator[](int index);
	private:
		std::vector<sys::Vector2> m_vecPoint;
	};
}