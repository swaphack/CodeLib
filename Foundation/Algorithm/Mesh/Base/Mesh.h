#pragma once
#include "mathlib.h"
#include <vector>
#include <map>

namespace alg
{
	/**
	*	����
	*/
	struct Mesh
	{
	public:
		Mesh();
		virtual ~Mesh();
	public:
		/**
		*	�������������ʼ��
		*/
		bool initWithTriangles(const std::vector<math::TrianglePoints>& data);
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
		bool toTriangles(std::vector<math::TrianglePoints>& data);
	protected:
		/**
		*	������ת��Ϊ���� 
		*/
		bool convertToVertices(const std::vector<math::TrianglePoints>& data, std::vector<math::Vector3>& vertices, std::vector<int>& indices);
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
