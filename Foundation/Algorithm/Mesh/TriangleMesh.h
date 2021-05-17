#pragma once
#include "mathlib.h"
#include <vector>
#include <map>

namespace alg
{
	/**
	*	三角形网格
	*/
	struct TriangleMesh
	{
	public:
		TriangleMesh();
		virtual ~TriangleMesh();
	public:
		/**
		*	由三角形坐标初始化
		*/
		bool initWithTriangles(const std::vector<math::Triangle>& data);
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
		bool toTriangles(std::vector<math::Triangle>& data);
	protected:
		/**
		*	转化为顶点 
		*/
		bool convertToVertices(const std::vector<math::Triangle>& data, std::vector<math::Vector3>& vertices, std::vector<int>& indices);
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
