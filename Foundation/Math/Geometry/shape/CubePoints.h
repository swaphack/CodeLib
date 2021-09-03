#pragma once

#include "Algebra/import.h"
#include "Geometry/base/Points.h"
#include "Geometry/3d/Cuboids.h"
#include "RectPoints.h"

namespace math
{
	/**
	*	立方体顶点
	*	每个面以左下角作为基础点
	* 
	*		  |         |
	*	left  | /		| right   
	*		  |/________|
	*			bottom
	*/
	struct CubePoints : public Points<Vector3, 8>
	{
	public:
		CubePoints();
		CubePoints(const Vector3& frontLeftBottom, const Vector3& frontRightBottom, const Vector3& frontRightTop, const Vector3& frontLeftTop,
			const Vector3& backLeftBottom, const Vector3& backRightBottom, const Vector3& backRightTop, const Vector3& backLeftTop);
		CubePoints(const Vector3& frontLeftBottom, const Vector3& backRightTop);
		CubePoints(const RectPoints& front, const RectPoints& back);
		CubePoints(const Vector3* points);
		CubePoints(const std::vector<Vector3>& points);
		virtual ~CubePoints();
	public:
		CREATE_INDEX_VALUE(FrontLeftBottom, 0, Vector3);
		CREATE_INDEX_VALUE(FrontRightBottom, 1, Vector3);
		CREATE_INDEX_VALUE(FrontRightTop, 2, Vector3);
		CREATE_INDEX_VALUE(FrontLeftTop, 3, Vector3);
		CREATE_INDEX_VALUE(BackLeftBottom, 4, Vector3);
		CREATE_INDEX_VALUE(BackRightBottom, 5, Vector3);
		CREATE_INDEX_VALUE(BackRightTop, 6, Vector3);
		CREATE_INDEX_VALUE(BackLeftTop, 7, Vector3);
	public:
		void setPoints(const Vector3& frontLeftBottom, const Vector3& frontRightBottom, const Vector3& frontRightTop, const Vector3& frontLeftTop,
			const Vector3& backLeftBottom, const Vector3& backRightBottom, const Vector3& backRightTop, const Vector3& backLeftTop);
		void setPoints(const Vector3& frontLeftBottom, const Vector3& backRightTop);
		void setPoints(const RectPoints& front, const RectPoints& back);
		void setPoints(const std::vector<Vector3>& points);
	public:
		operator Cuboids() const;
	};
}
