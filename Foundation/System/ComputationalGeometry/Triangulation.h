#pragma once

#include "macros.h"
#include <vector>

namespace sys
{
	/**
	*	�����λ�
	*	�Զ����µ�ɨ�跽ʽ
	*/
	class Triangulation
	{
	public:
		enum class VertexType
		{
			// ��ʼ
			eStart,
			// ����
			eEnd,
			// ��ͨ
			eRegular,
			// ����
			eSplit,
			// ���
			eMerge,
		};

		struct Vertex
		{
		public:
			// ����
			int index;
			// ����
			VertexType type;

		};
	public:
		Triangulation();
		~Triangulation();
	public:
		/**
		*	������
		*/
		int getIndiceCount();
		/**
		*	��������
		*/
		int* getIndices();
		/**
		*	��ȡ����ε������λ�����
		*	���ȶ�y���������
		*/
		bool indicesOfPolygon(Vector2* points, int count);
	protected:
		/**
		*	srcλ��dest֮��
		*/
		bool lower(const Vector2& src, const Vector2& dest);
		/**
		*	srcλ��dest֮��
		*/
		bool upper(const Vector2& src, const Vector2& dest);
		/**
		*	�ж϶�������
		*/
		Vertex vertexOfIndex(int index);
	private:
		// ����
		Vector2* m_pPoints;
		// ������
		int m_nCount;
		// ��������
		int* m_pIndices;
		// ������
		int m_nIndiceCount;
	};
}