#pragma once

#include "macros.h"
#include <map>
#include <vector>

namespace acg
{
	// ��������
	enum class VertexType
	{
		// ��Ч����
		eNone,
		// ��ʼ����
		eStart,
		// ��������
		eEnd,
		// ��ͨ����
		eRegular,
		// ���Ѷ���
		eSplit,
		// ��϶���
		eMerge,
	};
	// ������Ϣ
	struct VertexInfo
	{
	public:
		// ����
		int index;
		// ����
		VertexType type;
		// ������
		sys::Vector2 point;
	public:
		VertexInfo() :index(-1), type(VertexType::eNone)
		{}
	};
	// ��
	struct Edge
	{
	public:
		// ��ʼ��
		sys::Vector2 start;
		// ��ֹ��
		sys::Vector2 end;
	public:
		Edge() {}
		Edge(sys::Vector2 start, sys::Vector2 end) :start(start), end(end){}
	public:
		float distance(const sys::Vector2& point)
		{
			float d0 = sys::Vector2::distance(point, start);
			float d1 = sys::Vector2::distance(point, end);

			return MIN(d0, d1);
		}
		// ���Ƿ��ڱߵ����
		bool onLeftSide(const sys::Vector2& point)
		{
			if (start.y < point.y || end.y > point.y)
			{
				return false;
			}

			if (start.x > point.x && end.x >= point.x)
			{
				return false;
			}

			return sys::Vector2::direction(end - start, point - start) == 1;
		}
		// ���Ƿ������˵�
		bool isVertex(const sys::Vector2& point)
		{
			return start == point || end == point;
		}
	};

	/**
	*	�����λ�
	*	�Զ����µ�ɨ�跽ʽ
	*/
	class Triangulation
	{
	public:
		Triangulation();
		~Triangulation();
	public:
		/**
		*	��ȡ����ε������λ�����
		*	���ȶ�y���������
		*/
		bool indicesOfPolygon(const sys::Vector2* points, int count);
	protected:
		/**
		*	��ȡ�ڱ�
		*/
		int getNearEdge(const sys::Vector2& point);
		/**
		*	�Ƿ����Ҷ˶���
		*/
		bool hasRightVertex(const sys::Vector2& point, const sys::Vector2* points, int count);
		/**
		*	��Ӹ�����
		*/
		void addAuxiliaryEdge(const sys::Vector2& src, const sys::Vector2& dest);
		/**
		*	�Ƴ���ʱ��
		*/
		void removeTemporaryEdge(int index);
		/**
		*	�����ʱ��
		*/
		void addTemporaryEdge(int index, const Edge& edge);
	private:
		/**
		*	srcλ��dest֮��
		*/
		bool lower(const sys::Vector2& src, const sys::Vector2& dest);
		/**
		*	srcλ��dest֮��
		*/
		bool upper(const sys::Vector2& src, const sys::Vector2& dest);
		/**
		*	�ж϶�������
		*	һ�������ˮƽɨ����l���϶��µ�ɨ������ƽ��
		*	��ʹ��Convex.sortByAxisY
		*/
		VertexInfo typeOfVertex(int index, const sys::Vector2* points, int count);
	private:
		// �����ζ�������
		int* m_pIndices[3];

		// ������
		std::vector<Edge> m_setAuxiliaryEdges;
	};
}