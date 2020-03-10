#pragma once

#include "DCSpace.h"

namespace render
{
	/**
	*	ø’º‰ Ù–‘
	*/
	class DCCamera : public DCSpace
	{
	public:
		CameraDimensions Dimensions;
		CameraParams Params;
	public:
		DCCamera();
		virtual ~DCCamera();
	public:
		virtual void draw();
	public:
		static DCCamera* create(const CameraParams& params, CameraDimensions d, const math::Vector3& position, const math::Vector3& scale, const math::Vector3& rotation, bool relative);
	};

	class DCCameraMatrix : public DCSpaceMatrix
	{
	public:
		CameraDimensions Dimensions;
		CameraParams Params;
	public:
		DCCameraMatrix();
		virtual ~DCCameraMatrix();
	public:
		virtual void draw();
	public:
		static DCCameraMatrix* create(const CameraParams& params, CameraDimensions d, const math::Matrix& matrix, bool relative);
	};
}