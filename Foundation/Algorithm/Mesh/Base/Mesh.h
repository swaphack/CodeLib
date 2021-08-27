#pragma once
#include "mathlib.h"
#include <vector>
#include <map>

namespace alg
{
	/**
	*	网格
	*/
	struct Mesh
	{
	public:
		Mesh();
		virtual ~Mesh();
	public:
		/**
		*	由三角形坐标初始化
		*/
		bool initWithTriangles(const std::vector<math::TrianglePoints>& data);
		/**
		*	由顶点坐标初始化
		*/
		bool initWithVertices(const std::vector<math::Vector3>& vertices, const std::vector<int>& indices);
		/**
		*	顶点坐标
		*/
		const std::vector<math::Vector3>& getVertices() const;
		/**
		*	顶点索引
		*/
		const std::vector<int>& getIndices() const;
		/**
		*	转化成三角形数据
		*/
		bool toTriangles(std::vector<math::TrianglePoints>& data);
	protected:
		/**
		*	三角形转化为顶点 
		*/
		bool convertToVertices(const std::vector<math::TrianglePoints>& data, std::vector<math::Vector3>& vertices, std::vector<int>& indices);
	private:
		/**
		*	顶点坐标
		*/
		std::vector<math::Vector3> _vertices;
		/**
		*	顶点索引
		*/
		std::vector<int> _indices;
	};
}
