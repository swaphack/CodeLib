#include "SphereModel.h"
#include "Graphic/import.h"
#include "mathlib.h"

using namespace render;

#define SPHERE_HORIZONTAL_COUNT 50
#define SPHERE_VERTICAL_COUNT 50
#define SPHERE_FACE_COUNT 3

render::SphereModel::SphereModel()
{

}

render::SphereModel::~SphereModel()
{
}

bool render::SphereModel::init()
{
	if (!Model::init())
	{
		return false;
	}

	_notify->addListen(NodeNotifyType::MODEL, [this]() {
		_loadModel = true;
		this->updateBufferData();
	});


	return true;
}

math::Vector3 render::SphereModel::getPoint(const math::Vector2& uv)
{
	return getPoint(uv.getX(), uv.getY());
}

math::Vector3 render::SphereModel::getPoint(float u, float v)
{
	float x = sin(PI * v) * cos(2 * PI * u);
	float y = sin(PI * v) * sin(2 * PI * u);
	float z = cos(PI * v);
	if (abs(x) < 0.0001f) x = 0;
	if (abs(y) < 0.0001f) y = 0;
	if (abs(z) < 0.0001f) z = 0;

	return math::Vector3(x, y, z);
}

void render::SphereModel::updateSphere()
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
	pIndices.push_back(pIndices.size()); \
}

	//绘制上端三角形组
	{
		int nCount = 3 * SPHERE_HORIZONTAL_COUNT;
		auto pMesh = _meshes->getMesh(0);
		auto pVertices = std::vector<float>();
		pVertices.reserve(3 * nCount);
		auto pUVs = std::vector<float>();
		pUVs.reserve(2 * nCount);
		auto pColors = std::vector<float>();
		pColors.reserve(4 * nCount);
		auto pIndices = std::vector<uint32_t>();
		pIndices.reserve(nCount);

		for (int i = 0; i < SPHERE_HORIZONTAL_COUNT; i++)
		{
			math::Vector2 ua = math::Vector2(0, 0);
			math::Vector2 ub = math::Vector2(u, vstep);
			math::Vector2 uc = math::Vector2(u + ustep, vstep);

			math::Vector3 va = getPoint(ua);
			math::Vector3 vb = getPoint(ub);
			math::Vector3 vc = getPoint(uc);

			READ_VERTEX(va, ua);
			READ_VERTEX(vb, ub);
			READ_VERTEX(vc, uc);

			u += ustep;
		}

		pMesh->getMeshDetail()->setVertices(nCount, &pVertices[0]);
		pMesh->getMeshDetail()->setUVs(nCount, &pUVs[0]);
		pMesh->getMeshDetail()->setColors(nCount, &pColors[0]);
		pMesh->getMeshDetail()->setIndices(nCount, &pIndices[0]);
	}

	//绘制中间四边形组
	u = 0, v = vstep;
	{
		int nCount = 4 * (SPHERE_VERTICAL_COUNT - 2) * SPHERE_HORIZONTAL_COUNT;
		auto pMesh = _meshes->getMesh(1);
		auto pVertices = std::vector<float>();
		pVertices.reserve(3 * nCount);
		auto pUVs = std::vector<float>();
		pUVs.reserve(2 * nCount);
		auto pColors = std::vector<float>();
		pColors.reserve(4 * nCount);
		auto pIndices = std::vector<uint32_t>();
		pIndices.reserve(nCount);

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

				u += ustep;
			}
			v += vstep;
		}

		pMesh->getMeshDetail()->setVertices(nCount, &pVertices[0]);
		pMesh->getMeshDetail()->setUVs(nCount, &pUVs[0]);
		pMesh->getMeshDetail()->setColors(nCount, &pColors[0]);
		pMesh->getMeshDetail()->setIndices(nCount, &pIndices[0]);
	}
	
	//绘制下端三角形组
	u = 0;
	{
		int nCount = 3 * SPHERE_HORIZONTAL_COUNT;
		auto pMesh = _meshes->getMesh(2);
		auto pVertices = std::vector<float>();
		pVertices.reserve(3 * nCount);
		auto pUVs = std::vector<float>();
		pUVs.reserve(2 * nCount);
		auto pColors = std::vector<float>();
		pColors.reserve(4 * nCount);
		auto pIndices = std::vector<uint32_t>();
		pIndices.reserve(nCount);

		//绘制下端三角形组
		for (int i = 0; i < SPHERE_HORIZONTAL_COUNT; i++)
		{
			math::Vector2 ua = math::Vector2(0, 0);
			math::Vector2 ub = math::Vector2(u, 1 - vstep);
			math::Vector2 uc = math::Vector2(u + ustep, 1 - vstep);

			math::Vector3 va = getPoint(ua);
			math::Vector3 vb = getPoint(ub);
			math::Vector3 vc = getPoint(uc);

			READ_VERTEX(va, ua);
			READ_VERTEX(vb, ub);
			READ_VERTEX(vc, uc);

			//u += ustep;
		}
		pMesh->getMeshDetail()->setVertices(nCount, &pVertices[0]);
		pMesh->getMeshDetail()->setUVs(nCount, &pUVs[0]);
		pMesh->getMeshDetail()->setColors(nCount, &pColors[0]);
		pMesh->getMeshDetail()->setIndices(nCount, &pIndices[0]);
	}
}

void render::SphereModel::onDraw()
{
	if (true)
	{
		for (int i = 0; i < SPHERE_FACE_COUNT; i++)
		{
			auto pMesh = _meshes->getMesh(i);
			if (pMesh)
			{
				const sys::MeshMemoryData& vertices = pMesh->getMeshDetail()->getVertices();
				auto ptr = (float*)vertices.getValue();
				int size = 0;
				if (i == 1)
				{
					size = vertices.getLength() / 4;
					GLVertex::beginMode(ShapeMode::LINE_LOOP);
				}
				else
				{
					size = vertices.getLength() / 3;
					GLVertex::beginMode(ShapeMode::LINE_LOOP);
				}
				
				for (int j = 0; j < size; j++)
				{
					math::Vector3 a(ptr[3 * j + 0], ptr[3 * j + 1], ptr[3 * j + 2]);
					GLVertex::setVertex(a);
				}
				GLVertex::endMode();
			}
		}
		/*
		for (int i = 0; i < SPHERE_FACE_COUNT; i++)
		{
			auto pMesh = _meshes->getMesh(i);
			if (pMesh)
			{
				const sys::MeshMemoryData& vertices = pMesh->getMeshDetail()->getVertices();
				GLClientArrays::enableClientState(ClientArrayType::VERTEX_ARRAY);
				GLClientArrays::setVertexPointer(vertices.getUnitSize(), DataType::FLOAT, 0, vertices.getValue());
				GLDebug::showError();

				const sys::MeshMemoryData& indices = pMesh->getMeshDetail()->getIndices();
				GLDebug::showError();

				DrawMode mode = DrawMode::LINE_LOOP;
				if (i == 1) mode = DrawMode::LINE_LOOP;
				GLClientArrays::drawElements(DrawMode::TRIANGLES, indices.getLength(), IndexDataType::UNSIGNED_INT, indices.getValue());
				GLDebug::showError();
				GLClientArrays::disableClientState(ClientArrayType::VERTEX_ARRAY);
			}
		}
		*/
		return;
	}
	double ustep = 1 / (double)SPHERE_HORIZONTAL_COUNT, vstep = 1 / (double)SPHERE_VERTICAL_COUNT;
	double u = 0, v = 0;
	//绘制下端三角形组
	for (int i = 0; i < SPHERE_HORIZONTAL_COUNT; i++)
	{

		math::Vector3 a = getPoint(0, 0);
		math::Vector3 b = getPoint(u, vstep);
		math::Vector3 c = getPoint(u + ustep, vstep);

		GLVertex::beginMode(ShapeMode::LINE_LOOP);
		GLVertex::setVertex(a);
		GLVertex::setVertex(b);
		GLVertex::setVertex(c);
		GLVertex::endMode();
		u += ustep;
	}
	//绘制中间四边形组
	u = 0, v = vstep;
	for (int i = 1; i < SPHERE_VERTICAL_COUNT - 1; i++)
	{
		for (int j = 0; j < SPHERE_HORIZONTAL_COUNT; j++)
		{
			math::Vector3 a = getPoint(u, v);
			math::Vector3 b = getPoint(u + ustep, v);
			math::Vector3 c = getPoint(u + ustep, v + vstep);
			math::Vector3 d = getPoint(u, v + vstep);

			GLVertex::beginMode(ShapeMode::LINE_LOOP);
			GLVertex::setVertex(a);
			GLVertex::setVertex(b);
			GLVertex::setVertex(c);
			GLVertex::setVertex(d);
			GLVertex::endMode();

			u += ustep;
		}
		v += vstep;
	}
	//绘制下端三角形组
	u = 0;
	for (int i = 0; i < SPHERE_HORIZONTAL_COUNT; i++)
	{
		math::Vector3 a = getPoint(0, 1);
		math::Vector3 b = getPoint(u, 1 - vstep);
		math::Vector3 c = getPoint(u + ustep, 1 - vstep);

		GLVertex::beginMode(ShapeMode::LINE_LOOP);
		GLVertex::setVertex(a);
		GLVertex::setVertex(b);
		GLVertex::setVertex(c);
		GLVertex::endMode();

		u += ustep;
	}
}

void render::SphereModel::initBufferObject()
{
	sys::ModelDetail* pModelDetail = CREATE_OBJECT(sys::ModelDetail);

	for (int i = 0; i < SPHERE_FACE_COUNT; i++)
	{
		auto pMat = CREATE_OBJECT(sys::MaterialDetail);
		pModelDetail->addMaterial(i, pMat);

		auto pMesh = CREATE_OBJECT(sys::MeshDetail);
		pMesh->setMaterial(i);
		pModelDetail->addMesh(i, pMesh);
	}

	this->setModelData(pModelDetail);

	this->updateSphere();
}

void SphereModel::setRadius(float radius)
{
	_radius = radius;
}

float SphereModel::getRadius()
{
	return _radius;
}
