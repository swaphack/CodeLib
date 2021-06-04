#pragma once

#include <vector>
#include <map>
#include <set>

#include "mathlib.h"

#include "TriangleMesh.h"

namespace alg
{
	/*  ���������㷨
	*	@href: http://hhoppe.com/
	*
	*/
	class ProgressiveMeshAlgorithm
	{
	public:
		ProgressiveMeshAlgorithm();
		~ProgressiveMeshAlgorithm();
	public:
		/**
		*	����
		*/
		bool reduceMesh(const std::vector<math::Triangle>& inData, std::vector<math::Triangle>& outData);
		/**
		*	���� δ���
		*/
		bool reduceMesh(const TriangleMesh& inData, TriangleMesh& outData);
	protected:
		/**
		*	���
		*/
		void cleanUp();
	private:
		/**
		*	�����ε������������������ι��ߵ����
		*/
		//std::map<int, TriangleEdge> _triangleEdgeInfos;

		/**
		*	ÿ�����������������
		*/
		std::map<math::Vector3, std::set<int>> _triangleVertexInfos;
	};
}