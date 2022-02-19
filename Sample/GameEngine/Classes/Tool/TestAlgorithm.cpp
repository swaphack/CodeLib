#include "TestAlgorithm.h"
#include "system.h"
#include "algorithm.h"
#include "../Env/Utility.h"

TestAlgorithm::TestAlgorithm()
{

}

TestAlgorithm::~TestAlgorithm()
{

}

void TestAlgorithm::initNodes()
{
	//this->testMeshMapFindPath();

	this->testDelaunay();
}

void TestAlgorithm::testRayMapFindPath()
{
	alg::map::RayMap* pMap = CREATE_OBJECT(alg::map::RayMap);
	pMap->addPoint(math::Vector3(0, 0));
	pMap->addPoint(math::Vector3(0, 10));
	pMap->addPoint(math::Vector3(1, 0));
	pMap->addPoint(math::Vector3(2, 2));
	pMap->addPoint(math::Vector3(2.5f, 1.5f));
	pMap->addPoint(math::Vector3(100, 100));

	pMap->addRayRelation<0, 2>(1, 2);
	pMap->addRayRelation<1, 1>(1);
	pMap->addRayRelation<2, 3>(0, 4, 5);
	pMap->addRayRelation<3, 2>(0, 4);
	pMap->addRayRelation<4, 3>(2, 3, 5);
	pMap->addRayRelation<5, 2>(2, 4);

	std::vector<uint32_t> path;

	alg::map::AStar* pPathFinder = CREATE_OBJECT(alg::map::AStar);
	bool ret = pPathFinder->findWay(pMap, 0, 5, path);

	int a = 0;
}

void TestAlgorithm::testMeshMapFindPath()
{
	alg::map::MeshMap* pMap = CREATE_OBJECT(alg::map::MeshMap);
	pMap->addPoint(math::Vector3(0, 0));
	pMap->addPoint(math::Vector3(0, 10));
	pMap->addPoint(math::Vector3(1, 0));
	pMap->addPoint(math::Vector3(2, 2));
	pMap->addPoint(math::Vector3(2.5f, 1.5f));
	pMap->addPoint(math::Vector3(100, 100));

	pMap->addMeshRelation<3>(0, 1, 3);
	pMap->addMeshRelation<3>(0, 2, 3);
	pMap->addMeshRelation<3>(2, 3, 4);
	pMap->addMeshRelation<3>(2, 4, 5);
	pMap->addMeshRelation<3>(2, 3, 5);
	pMap->addMeshRelation<3>(3, 4, 5);

	std::vector<uint32_t> path;

	alg::map::AStar* pPathFinder = CREATE_OBJECT(alg::map::AStar);
	bool ret = pPathFinder->findWay(pMap, 0, 5, path);

	int a = 0;
}

void TestAlgorithm::testWFCCreateMap()
{
#define SLOT_COUNT 12
#define RECT_WIDTH 4
#define RECT_HEIGHT 4
#define RELATION_VALUE 1
#define MODULE_COUNT 2

	uint32_t slotData[SLOT_COUNT] = { 0,1,2,3,4,5,6,7,8,9,10,11 };

	auto mapAssets = new alg::map::MapAssets<alg::map::RectModule, SLOT_COUNT, RELATION_VALUE>();
	{
		std::map<uint32_t, uint32_t> slots;
		slots[(uint32_t)alg::map::RectModuleDirection::LEFT] = slotData[0];
		slots[(uint32_t)alg::map::RectModuleDirection::RIGHT] = slotData[1];
		slots[(uint32_t)alg::map::RectModuleDirection::UP] = slotData[2];
		slots[(uint32_t)alg::map::RectModuleDirection::DOWN] = slotData[3];
		mapAssets->createModule(1, slots);
	}
	{
		std::map<uint32_t, uint32_t> slots;
		slots[(uint32_t)alg::map::RectModuleDirection::LEFT] = slotData[4];
		slots[(uint32_t)alg::map::RectModuleDirection::RIGHT] = slotData[5];
		slots[(uint32_t)alg::map::RectModuleDirection::UP] = slotData[6];
		slots[(uint32_t)alg::map::RectModuleDirection::DOWN] = slotData[7];
		mapAssets->createModule(2, slots);
	}
	{
		std::map<uint32_t, uint32_t> slots;
		slots[(uint32_t)alg::map::RectModuleDirection::LEFT] = slotData[8];
		slots[(uint32_t)alg::map::RectModuleDirection::RIGHT] = slotData[9];
		slots[(uint32_t)alg::map::RectModuleDirection::UP] = slotData[10];
		slots[(uint32_t)alg::map::RectModuleDirection::DOWN] = slotData[11];
		mapAssets->createModule(3, slots);
	}

	{
		//mapAssets->addMatchRule<8>(0, 1, 2, 3, 4, 5, 6, 7, 8);
		mapAssets->addMatchRule<2>(1, 4, 8);
		mapAssets->addMatchRule<2>(0, 5, 9);
		mapAssets->addMatchRule<2>(2, 7, 11);
		mapAssets->addMatchRule<2>(3, 6, 10);

		mapAssets->addMatchRule<2>(4, 1, 9);
		mapAssets->addMatchRule<2>(5, 0, 8);
		mapAssets->addMatchRule<2>(6, 3, 11);
		mapAssets->addMatchRule<2>(7, 2, 10);

		mapAssets->addMatchRule<2>(8, 1, 5);
		mapAssets->addMatchRule<2>(9, 0, 4);
		mapAssets->addMatchRule<2>(10, 3, 7);
		mapAssets->addMatchRule<2>(11, 2, 6);
	}
	auto map = new alg::map::RectMap<RECT_WIDTH, RECT_HEIGHT>();
	auto creator = new alg::map::RectMapCreator<SLOT_COUNT, RECT_WIDTH, RECT_HEIGHT>();
	auto wfc = new alg::map::WFCAlgorithm();
	creator->setSeed(9567);
	creator->setMapAssets(mapAssets);
	creator->create(map, wfc);

	if (!wfc->isFinish())
	{
		return;
	}
}

const float ALG_WIDTH = 1000;
const float ALG_HEIGHT = 700;

void TestAlgorithm::testDelaunay()
{
	int horizontal = 10;
	int vertical = 10;

	float perWidth = ALG_WIDTH / horizontal;
	float perHeight = ALG_HEIGHT / vertical;

	int totalCount = horizontal * vertical;
	std::vector<math::Vector3> points;
	for (size_t i = 0; i < totalCount; i++)
	{
		int row = i / vertical;
		int column = i % horizontal;

		math::Vector3 point;
		point.setX(sys::Random::getNumber(column * perWidth, (column + 1) * perWidth));
		point.setY(sys::Random::getNumber(row * perHeight, (row + 1) * perHeight));
		points.push_back(point);
	}

	math::RectPoints rectPoints;
	rectPoints.setLeftBottom(math::Vector3());
	rectPoints.setRightBottom(math::Vector3(ALG_WIDTH, 0));
	rectPoints.setRightTop(math::Vector3(ALG_WIDTH, ALG_HEIGHT));
	rectPoints.setLeftTop(math::Vector3(0, ALG_HEIGHT));

	math::Rect rect = (math::Rect)rectPoints;

	alg::mesh::Delaunay delaunay;
	alg::mesh::Voronoi voronoi;

	auto triagles = delaunay.createWithBowyerWatson(rectPoints, points);
	//drawTriangles(triagles);

	std::vector<math::Polygon> polygons;
	std::vector<math::LineSegment2d> lineSegments;
	if (voronoi.createWithRect(rect, &delaunay, polygons, lineSegments))
	{
		drawPolygons(polygons);
	}	
	drawSegments(lineSegments);
}

void TestAlgorithm::drawTriangles(const std::vector<math::TrianglePoints>& vecTrianglePoints)
{
	render::PrimitiveNode* pNode = CREATE_NODE(render::PrimitiveNode);
	pNode->setDrawMode(DrawMode::TRIANGLES);
	pNode->setPosition(10, 10);
	pNode->setPointSize(10);

	for (auto triangle : vecTrianglePoints)
	{
		for (size_t i = 0; i < 3; i++)
		{
			phy::Color4F color;
			color.setRed(sys::Random::getNumber(0.45f, 0.65f));
			color.setGreen(sys::Random::getNumber(0.45f, 0.65f));
			color.setBlue(sys::Random::getNumber(0.45f, 0.65f));
			color.setAlpha(1.0f);
			pNode->appendPoint(triangle.getValue(i), color);
		}
	}
	Utility::loadShaderVF(pNode, "Shader/geometry/draw_primitive.vs", "Shader/geometry/draw_primitive.fs");
	this->addChild(pNode);
}

void TestAlgorithm::drawPolygons(const std::vector<math::Polygon>& vecPolygons)
{
	int i = vecPolygons.size();
	for (auto polygon : vecPolygons)
	{
		drawPolygon(polygon);
		i--;
		if (i == 0) break;
	}
}

void TestAlgorithm::drawPolygon(const math::Polygon& polygon)
{
	if (polygon.getPointCount() < 3) return;

	render::PrimitiveNode* pNode = CREATE_NODE(render::PrimitiveNode);
	pNode->setPosition(10, 10);
	pNode->setDrawMode(DrawMode::POINTS);
	pNode->setDrawMode(DrawMode::POLYGON);
	pNode->setPointSize(2);

	phy::Color4F color;
	color.setRed(sys::Random::getNumber(0.75f, 1.0f));
	color.setGreen(sys::Random::getNumber(0.75f, 1.0f));
	color.setBlue(sys::Random::getNumber(0.75f, 1.0f));
	color.setAlpha(1.0f);

	for (auto point : polygon.getPoints())
	{
		pNode->appendPoint(point, color);
	}

	Utility::loadShaderVF(pNode, "Shader/geometry/draw_primitive.vs", "Shader/geometry/draw_primitive.fs");
	this->addChild(pNode);
}

void TestAlgorithm::drawSegments(const std::vector<math::LineSegment2d>& vecSegments)
{
	render::PrimitiveNode* pNode = CREATE_NODE(render::PrimitiveNode);
	pNode->setPosition(10, 10);
	pNode->setDrawMode(DrawMode::LINES);
	pNode->setPointSize(4);

	phy::Color4F color;
	color.setRed(1.0f);
	color.setGreen(1.0f);
	color.setBlue(1.0f);
	color.setAlpha(1.0f);

	for (auto segment : vecSegments)
	{
		pNode->appendPoint(segment.getSrc(), color);
		pNode->appendPoint(segment.getDest(), color);
	}

	Utility::loadShaderVF(pNode, "Shader/geometry/draw_primitive.vs", "Shader/geometry/draw_primitive.fs");
	this->addChild(pNode);
}

