#include "DCCamera.h"

using namespace render;

DCCamera::DCCamera()
{

}

DCCamera::~DCCamera()
{

}

void DCCamera::draw()
{
	glMatrixMode(GL_PROJECTION);
	DCSpace::draw();

	if (Dimensions == ED_2D)
	{
		glOrtho(Params.xLeft,
			Params.xRight,
			Params.yBottom,
			Params.yTop,
			Params.zNear,
			Params.zFar);
	}
	else if (Dimensions == ED_3D)
	{
		glFrustum(Params.xLeft,
			Params.xRight,
			Params.yBottom,
			Params.yTop,
			Params.zNear,
			Params.zFar);
	}

	SHOW_OPENGL_ERROR_MESSAGE();
}

DCCamera* DCCamera::create(const CameraParams& params, CameraDimensions d, const math::Vector3& position, const math::Vector3& scale, const math::Vector3& rotation, bool relative)
{
	DCCamera* pSpace = sys::Instance<DCCamera>::getInstance();
	pSpace->Position = position;
	pSpace->Scale = scale;
	pSpace->Rotation = rotation;
	pSpace->Relative = relative;
	pSpace->Params = params;
	pSpace->Dimensions = d;
	return pSpace;
}


DCCameraMatrix::DCCameraMatrix()
{

}

DCCameraMatrix::~DCCameraMatrix()
{

}

void DCCameraMatrix::draw()
{
	glMatrixMode(GL_PROJECTION);
	DCSpaceMatrix::draw();

	SHOW_OPENGL_ERROR_MESSAGE();

	if (Dimensions == ED_2D)
	{
		glOrtho(Params.xLeft,
			Params.xRight,
			Params.yBottom,
			Params.yTop,
			Params.zNear,
			Params.zFar);
	}
	else if (Dimensions == ED_3D)
	{
		glFrustum(Params.xLeft,
			Params.xRight,
			Params.yBottom,
			Params.yTop,
			Params.zNear,
			Params.zFar);
	}

	SHOW_OPENGL_ERROR_MESSAGE();
}

DCCameraMatrix* DCCameraMatrix::create(const CameraParams& params, CameraDimensions d, const math::Matrix& matrix, bool relative)
{
	DCCameraMatrix* pSpace = sys::Instance<DCCameraMatrix>::getInstance();
	pSpace->Relative = relative;
	pSpace->Matrix = matrix.transpose();
	pSpace->Params = params;
	pSpace->Dimensions = d;
	return pSpace;
}
