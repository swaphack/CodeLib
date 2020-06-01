#pragma once

#include "3d/Common/Model.h"
#include "Common/struct/import.h"

namespace render
{
	class TextureCubeMap;

	/**
	*	����������
	*/
	class CubeMap : public Model
	{
	public:
		CubeMap();
		virtual ~CubeMap();
	public:
		virtual bool init();
	public:
		void setFaceImage(CubeFace face, const std::string& filepath);
	protected:
		void onImageChanged();
		virtual void onCubeChanged();
	protected:
		// ����
		CubeVertex _cubePosition;
		// ����
		TextureCubeMap* _texCubeMap = nullptr;

		std::string _imagePaths[6];
	};
}