#pragma once

#include "../Common/Model.h"

namespace render
{
#define CUBE_FACE_COUNT 6

	class CubeModel : public Model
	{
	public:
		CubeModel();
		virtual ~CubeModel();
	public:
		virtual bool init();

		virtual void draw();
	public:
		// 设置纹理
		void setTexture(const std::string& name, Texture* texture);
	protected:
		void onCubeChange();
		// 获取面的纹理
		TextureRect* getTextureRect(ModelFace index);
	private:
		// 纹理
		Texture* _texture = nullptr;
		// 纹理坐标
		TextureCube _texCube;
	};
}