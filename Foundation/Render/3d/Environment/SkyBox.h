#pragma once

#include "3d/Common/Model.h"
#include "Common/struct/import.h"

namespace render
{
	class SkyBox : public Model
	{
	public:
		SkyBox();
		virtual ~SkyBox();
	public:
		virtual bool init();
	public:
		void loadImages(CubeFace face, const std::string& fullpath);
	protected:
		void onImageChanged();
	private:
		std::string _imagePaths[6];
	};
}