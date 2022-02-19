#include "Sort/Sort.h"
#include "Mesh/import.h"

#include <vector>

using namespace alg;
using namespace alg::mesh;

void testMesh()
{
	float width = 100;
	float height = 100;
	int count = 50;

	math::RectPoints rect(
		math::Vector3(),
		math::Vector3(width, 0),
		math::Vector3(width, height),
		math::Vector3(0, height));

	std::vector<math::Vector3> points;
	for (int i = 0; i < count; i++)
	{
		math::Vector3 point(sys::Random::getNumber(0.0f, width), sys::Random::getNumber(0.0f, height));
		points.push_back(point);
	}

	Delaunay delaunay;
	Voronoi voronoi;
	auto triangles = delaunay.createWithBowyerWatson(rect, points);

	std::vector<math::Polygon> polygons;
	std::vector<math::LineSegment2d> lineSegments;
	if (voronoi.createWithRect(rect, &delaunay, polygons, lineSegments))
	{
	}
}

int main(int argc, char** argv)
{
	int ary[] = { 1, 12, 8, 20, 5, 3, 6, 55 };

	Sort<int>::MergeSort(ary, 8, [](const int& a, const int& b)->int {
		return a > b ? 1 : a == b ? 0 : -1;
	});

	return 0;
}