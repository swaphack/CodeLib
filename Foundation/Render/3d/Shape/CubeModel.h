#pragma once

#include "3d/Common/Model.h"
#include "Common/struct/enum_common.h"
#include "Common/struct/texture_common.h"

namespace render
{
#define CUBE_FACE_COUNT 6

	class Texture2D;

	class CubeModel : public Model
	{
	public:
		CubeModel();
		virtual ~CubeModel();
	public:
		virtual bool init();
	public:
		// 添加纹理
		void addTexture(const std::string& name, Texture2D* texture);
		// 设置纹理
		void setAllFacesTexture(const std::string& name);
		// 设置纹理
		void setFaceTexture(ModelFace face, const std::string& name);
	protected:
		void initModelDetail();

		void onCubeChange();
	private:
		// 坐标
		TextureCubeVertex _cubePosition;
		// 六个面的顶点信息
		TextureRectVertex _faces[CUBE_FACE_COUNT];
	};
}