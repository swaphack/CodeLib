#pragma once

#include "3d/Common/Model.h"
#include "Common/struct/import.h"

namespace render
{
	class TextureCubeMap;
	/**
	*	��պ�
	*/
	class SkyBox : public Model
	{
	public:
		SkyBox();
		virtual ~SkyBox();
	public:
		virtual bool init();
	public:
		void setFaceImage(CubeFace face, const std::string& fullpath);
		void setAllFacesImage(const std::string& fullpath);
	protected:
		void onImageChanged();
		void onSpaceChanged();
	private:
		std::string _imagePaths[6];
		// ����
		CubeVertex _cubePosition;
		// ����
		TextureCubeMap* _texCubeMap = nullptr;
	};
}