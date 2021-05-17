#pragma once
#include "mathlib.h"
#include <vector>
#include <map>

namespace alg
{
	/**
	*	����������
	*/
	struct TriangleMesh
	{
	public:
		TriangleMesh();
		virtual ~TriangleMesh();
	public:
		/**
		*	�������������ʼ��
		*/
		bool initWithTriangles(const std::vector<math::Triangle>& data);
		/**
		*	�ɶ��������ʼ��
		*/
		bool initWithVertices(const std::vector<math::Vector3>& vertices, const std::vector<int>& indices);
		/**
		*	��������
		*/
		const std::vector<math::Vector3>& getVertices() const;
		/**
		*	��������
		*/
		const std::vector<int>& getIndices() const;
		/**
		*	ת��������������
		*/
		bool toTriangles(std::vector<math::Triangle>& data);
	protected:
		/**
		*	ת��Ϊ���� 
		*/
		bool convertToVertices(const std::vector<math::Triangle>& data, std::vector<math::Vector3>& vertices, std::vector<int>& indices);
	private:
		/**
		*	��������
		*/
		std::vector<math::Vector3> _vertices;
		/**
		*	��������
		*/
		std::vector<int> _indices;
	};
}
