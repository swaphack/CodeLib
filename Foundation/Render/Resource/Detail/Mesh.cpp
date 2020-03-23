#include "mesh.h"
#include "Face.h"

#include "ext-config.h"

using namespace render;

Mesh::Mesh()
{

}

Mesh::~Mesh()
{
	this->removeAllFaces();
}

void Mesh::setVertices(int count, float* vertexes, int unitSize)
{
	float* vertors = (float*)malloc(count * sizeof(float));
	memcpy(vertors, vertexes, count * sizeof(float));

	_vertices.init(count, vertors, unitSize);
	free(vertors);
}

void Mesh::setNormals(int count, float* normals, int unitSize)
{
	_normals.init(count, normals, unitSize);
}

void Mesh::setColors(int count, float* colors, int unitSize)
{
	float* vertors = (float*)malloc(count * sizeof(float));

	for (int i = 0; i < count; i++)
	{
		vertors[i] = colors[i] / COLOR_FLOAT_VALUE;
	}

	_colors.init(count, vertors, unitSize);

	free(vertors);
}

void Mesh::setUVs(int count, float* texCoords, int unitSize)
{
	_uvs.init(count, texCoords, unitSize);
}

int Mesh::getVerticesCount()
{
	return _vertices.size / _vertices.unit;
}

void Mesh::addFace(int id, Face* face)
{
	if (!face)
	{
		return;
	}

	this->removeFace(id);

	SAFE_RETAIN(face);
	_faces[id] = face;
}

void Mesh::removeFace(int id)
{
	auto it = _faces.find(id);
	if (it != _faces.end())
	{
		SAFE_RELEASE(it->second);
		_faces.erase(it);
	}
}

void Mesh::removeAllFaces()
{
	for (auto item : _faces)
	{
		SAFE_RELEASE(item.second);
	}

	_faces.clear();
}

const std::map<int, Face*>& Mesh::getFaces()
{
	return _faces;
}

const T_Vertex& Mesh::getVertices()
{
	return _vertices;
}

const T_Vertex& Mesh::getNormals()
{
	return _normals;
}

const T_Vertex& Mesh::getColors()
{
	return _colors;
}

const T_Vertex& Mesh::getUVs()
{
	return _uvs;
}

Face* Mesh::getFace(int id)
{
	auto it = _faces.find(id);
	if (it == _faces.end())
	{
		return nullptr;
	}

	return it->second;
}
