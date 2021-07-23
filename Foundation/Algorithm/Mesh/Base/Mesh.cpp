#include "Mesh.h"
#include "macros.h"
#include <map>
#include <set>

alg::Mesh::Mesh()
{
}

alg::Mesh::~Mesh()
{
}

bool alg::Mesh::initWithTriangles(const std::vector<math::Triangle>& data)
{
	std::vector<math::Vector3> vertices;
	std::vector<int> indices;

	if (!convertToVertices(data, vertices, indices))
	{
		return false;
	}

	return initWithVertices(vertices, indices);
}

bool alg::Mesh::initWithVertices(const std::vector<math::Vector3>& vertices, const std::vector<int>& indices)
{
	_vertices = vertices;
	_indices = indices;

	return true;
}

const std::vector<math::Vector3>& alg::Mesh::getVertices() const
{
	return _vertices;
}

const std::vector<int>& alg::Mesh::getIndices() const
{
	return _indices;
}

bool alg::Mesh::toTriangles(std::vector<math::Triangle>& data)
{
	if (_vertices.size() < TRIANGLE_INDEX_COUNT || _indices.size() < TRIANGLE_INDEX_COUNT)
	{
		return false;
	}

	int verticeCount = _vertices.size();
	int indiceCount = _indices.size();

	int triangleCount = indiceCount / TRIANGLE_INDEX_COUNT;

	if (triangleCount == 0)
	{
		return false;
	}

	for (size_t i = 0; i < triangleCount; i+= TRIANGLE_INDEX_COUNT)
	{
		math::Triangle triangle;
		for (size_t j = 0; j < triangle.getLength();  j++)
		{
			int index = _indices[i * TRIANGLE_INDEX_COUNT + j];
			if (index >= verticeCount) return false;
			triangle.setValue(j, _vertices[index]);
		}

		data.push_back(triangle);
	}

	return data.size() > 0;
}

bool alg::Mesh::convertToVertices(const std::vector<math::Triangle>& data, std::vector<math::Vector3>& vertices, std::vector<int>& indices)
{
	if (data.size() == 0)
	{
		return false;
	}
	std::map<math::Vector3, int, math::CompareVector3> tempIndices;

	for (size_t i = 0; i < data.size(); i++)
	{
		for (size_t j = 0; j < data[i].getLength(); j++)
		{
			const auto& point = data[i].getValue(j);
			int index = tempIndices.size();
			auto it = tempIndices.find(point);
			if (it == tempIndices.end())
			{
				tempIndices[point] = index;
				vertices.push_back(point);
				indices.push_back(index);
			}
			else
			{
				indices.push_back(it->second);
			}
		}
	}

	return true;
}
