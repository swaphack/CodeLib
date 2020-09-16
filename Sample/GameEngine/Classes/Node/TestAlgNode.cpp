#include "TestAlgNode.h"
#include "system.h"
#include "algorithm.h"

TestAlgNode::TestAlgNode()
{

}

TestAlgNode::~TestAlgNode()
{

}

void TestAlgNode::initNodes()
{
	this->testMeshMapFindPath();
}

void TestAlgNode::testRayMapFindPath()
{
	alg::RayMap* pMap = CREATE_OBJECT(alg::RayMap);
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

	alg::AStar* pPathFinder = CREATE_OBJECT(alg::AStar);
	bool ret = pPathFinder->findWay(pMap, 0, 5, path);

	int a = 0;
}

void TestAlgNode::testMeshMapFindPath()
{
	alg::MeshMap* pMap = CREATE_OBJECT(alg::MeshMap);
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

	alg::AStar* pPathFinder = CREATE_OBJECT(alg::AStar);
	bool ret = pPathFinder->findWay(pMap, 0, 5, path);

	int a = 0;
}

