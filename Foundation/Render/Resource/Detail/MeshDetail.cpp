#include "MeshDetail.h"
#include "FaceDetail.h"

#include "ext-config.h"

using namespace render;

MeshDetail::MeshDetail()
{

}

MeshDetail::~MeshDetail()
{
	this->removeAllFaces();
}

void MeshDetail::setVertices(int count, float* vertexes, int unitSize)
{
	float* vertors = (float*)malloc(count * sizeof(float));
	memcpy(vertors, vertexes, count * sizeof(float));

	_vertices.init(count, vertors, unitSize);
	free(vertors);
}

void MeshDetail::setNormals(int count, float* normals, int unitSize)
{
	_normals.init(count, normals, unitSize);
}

void MeshDetail::setColors(int count, float* colors, int unitSize)
{
	float* vertors = (float*)malloc(count * sizeof(float));

	for (int i = 0; i < count; i++)
	{
		vertors[i] = colors[i] / COLOR_FLOAT_VALUE;
	}

	_colors.init(count, vertors, unitSize);

	free(vertors);
}

void MeshDetail::setUVs(int count, float* texCoords, int unitSize)
{
	_uvs.init(count, texCoords, unitSize);
}

int MeshDetail::getVerticesCount()
{
	return _vertices.size / _vertices.unit;
}

void MeshDetail::addFace(int id, FaceDetail* face)
{
	if (!face)
	{
		return;
	}

	this->removeFace(id);

	SAFE_RETAIN(face);
	_faces[id] = face;
}

void MeshDetail::removeFace(int id)
{
	auto it = _faces.find(id);
	if (it != _faces.end())
	{
		SAFE_RELEASE(it->second);
		_faces.erase(it);
	}
}

void MeshDetail::removeAllFaces()
{
	for (auto item : _faces)
	{
		SAFE_RELEASE(item.second);
	}

	_faces.clear();
}

const std::map<int, FaceDetail*>& MeshDetail::getFaces()
{
	return _faces;
}

const T_Vertex& MeshDetail::getVertices()
{
	return _vertices;
}

const T_Vertex& MeshDetail::getNormals()
{
	return _normals;
}

const T_Vertex& MeshDetail::getColors()
{
	return _colors;
}

const T_Vertex& MeshDetail::getUVs()
{
	return _uvs;
}

FaceDetail* MeshDetail::getFace(int id)
{
	auto it = _faces.find(id);
	if (it == _faces.end())
	{
		return nullptr;
	}

	return it->second;
}
