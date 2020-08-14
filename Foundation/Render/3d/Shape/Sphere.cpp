#include "Sphere.h"
#include "Graphic/import.h"
#include "mathlib.h"
#include "Common/struct/vertex_common.h"
using namespace render;

#define SPHERE_HORIZONTAL_COUNT 100
#define SPHERE_VERTICAL_COUNT 100

render::Sphere::Sphere()
{

}

render::Sphere::~Sphere()
{
}

bool render::Sphere::init()
{
	if (!Model::init())
	{
		return false;
	}

	_notify->addListen(NodeNotifyType::GEOMETRY, [this]() {
		updateSphere();
	});

	return true;
}

math::Vector3 render::Sphere::getPoint(const math::Vector2& uv)
{
	return getPoint(uv.getX(), uv.getY());
}

math::Vector3 render::Sphere::getPoint(float u, float v)
{
	float x = sin(PI * v) * cos(2 * PI * u);
	float y = sin(PI * v) * sin(2 * PI * u);
	float z = cos(PI * v);

	x = x * _radius + (_anchor.getX() - 0.5f) * getWidth();
	y = y * _radius + (_anchor.getY() - 0.5f) * getHeight();
	z = z * _radius + (_anchor.getZ() - 0.5f) * getDepth();

	return math::Vector3(x, y, z);
}

void render::Sphere::updateSphere()
{
	float ustep = 1.0f / SPHERE_HORIZONTAL_COUNT, vstep = 1.0f / SPHERE_VERTICAL_COUNT;
	float u = 0, v = 0;

	float color[4] = { 1, 1, 1, 1 };
	int vsize = 3 * sizeof(float);
	int tsize = 2 * sizeof(float);
	int isize = 1 * sizeof(uint32_t);
	int csize = 4 * sizeof(float);

#define READ_VERTEX(vertex, uv) \
{ \
	pVertices.push_back(vertex.getX()); \
	pVertices.push_back(vertex.getY()); \
	pVertices.push_back(vertex.getZ()); \
	pUVs.push_back(uv.getX()); \
	pUVs.push_back(uv.getY()); \
	pColors.push_back(color[0]); \
	pColors.push_back(color[1]); \
	pColors.push_back(color[2]); \
	pColors.push_back(color[3]); \
}

#define READ_VERTEX_1(vertex, uv) \
{\
	READ_VERTEX(vertex, uv) \
	pIndices.push_back(pIndices.size()); \
}
	auto pMesh = getMesh();

	int nCount0 = 3 * SPHERE_HORIZONTAL_COUNT;
	int nCount1 = 4 * (SPHERE_VERTICAL_COUNT - 2) * SPHERE_HORIZONTAL_COUNT;
	int nCount2 = 3 * SPHERE_HORIZONTAL_COUNT;

	auto pVertices = std::vector<float>();
	pVertices.reserve(3 * (nCount0 + nCount1 + nCount2));
	auto pUVs = std::vector<float>();
	pUVs.reserve(2 * (nCount0 + nCount1 + nCount2));
	auto pColors = std::vector<float>();
	pColors.reserve(4 * (nCount0 + nCount1 + nCount2));
	auto pIndices = std::vector<uint32_t>();
	pIndices.reserve(nCount0 + 1.5f * nCount1 + nCount2);

	//�����϶���������
	{
		for (int i = 0; i < SPHERE_HORIZONTAL_COUNT; i++)
		{
			math::Vector2 ua = math::Vector2(0, 0);
			math::Vector2 ub = math::Vector2(u, vstep);
			math::Vector2 uc = math::Vector2(u + ustep, vstep);

			math::Vector3 va = getPoint(ua);
			math::Vector3 vb = getPoint(ub);
			math::Vector3 vc = getPoint(uc);

			READ_VERTEX_1(va, ua);
			READ_VERTEX_1(vb, ub);
			READ_VERTEX_1(vc, uc);

			u += ustep;
		}
	}

	//�����м��ı�����
	u = 0, v = vstep;
	{
		int index = 0;
		for (int i = 1; i < SPHERE_VERTICAL_COUNT - 1; i++)
		{
			for (int j = 0; j < SPHERE_HORIZONTAL_COUNT; j++)
			{
				math::Vector2 ua = math::Vector2(u, v);
				math::Vector2 ub = math::Vector2(u + ustep, v);
				math::Vector2 uc = math::Vector2(u + ustep, v + vstep);
				math::Vector2 ud = math::Vector2(u, v + vstep);

				math::Vector3 va = getPoint(ua);
				math::Vector3 vb = getPoint(ub);
				math::Vector3 vc = getPoint(uc);
				math::Vector3 vd = getPoint(ud);

				READ_VERTEX(va, ua);
				READ_VERTEX(vb, ub);
				READ_VERTEX(vc, uc);
				READ_VERTEX(vd, ud);

				pIndices.push_back(nCount0 + 4 * index + 0);
				pIndices.push_back(nCount0 + 4 * index + 2);
				pIndices.push_back(nCount0 + 4 * index + 1);
				pIndices.push_back(nCount0 + 4 * index + 0);
				pIndices.push_back(nCount0 + 4 * index + 3);
				pIndices.push_back(nCount0 + 4 * index + 2);

				index++;
				u += ustep;
			}
			v += vstep;
		}
	}
	
	//�����¶���������
	u = 0;
	{
		int index = 0;
		//�����¶���������
		for (int i = 0; i < SPHERE_HORIZONTAL_COUNT; i++)
		{
			math::Vector2 ua = math::Vector2(0, 1);
			math::Vector2 ub = math::Vector2(u, 1 - vstep);
			math::Vector2 uc = math::Vector2(u + ustep, 1 - vstep);

			math::Vector3 va = getPoint(ua);
			math::Vector3 vb = getPoint(ub);
			math::Vector3 vc = getPoint(uc);

			READ_VERTEX(va, ua);
			READ_VERTEX(vb, ub);
			READ_VERTEX(vc, uc);

			pIndices.push_back(nCount0 + nCount1 + 3 * index + 0);
			pIndices.push_back(nCount0 + nCount1 + 3 * index + 2);
			pIndices.push_back(nCount0 + nCount1 + 3 * index + 1);

			index++;
			u += ustep;
		}
	}

	pMesh->getMeshDetail()->setVertices(nCount0 + nCount1 + nCount2, &pVertices[0]);
	pMesh->getMeshDetail()->setUVs(nCount0 + nCount1 + nCount2, &pUVs[0]);
	pMesh->getMeshDetail()->setColors(nCount0 + nCount1 + nCount2, &pColors[0]);
	pMesh->getMeshDetail()->setIndices(pIndices.size(), &pIndices[0]);

	updateMeshData();
}

void Sphere::setRadius(float radius)
{
	_radius = radius;

	this->notify(NodeNotifyType::GEOMETRY);
}

float Sphere::getRadius()
{
	return _radius;
}
