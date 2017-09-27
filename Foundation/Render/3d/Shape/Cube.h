#pragma once

#include "../Common/import.h"

namespace render
{
	//---------------------枚举---------------------
	// 六个面
	enum ModelFace
	{
		EMF_FRONT,		// 前面
		EMF_BACK,		// 背面
		EMF_LEFT,		// 左面
		EMF_RIGHT,		// 右面
		EMF_TOP,		// 上面
		EMF_BOTTOM,		// 下面
	};

	// 3d模型基础，空间立方体
	class Cube : public Model
	{
	public:
		Cube();
		virtual ~Cube();
	public:
		virtual bool init();

		virtual void draw();

		// 设置单面的纹理帧
		void setFaceFrame(ModelFace face, TexFrame* frame);
		// 设置所有面的纹理帧
		virtual void setTexFrame(TexFrame* frame);
	protected:
		virtual void initSelf();
		// 获取面的纹理
		TextureRect* getTextureRect(ModelFace face);

		void onFaceFrameChange();
	private:
		// 六个面的纹理
		TexFrame* _faceFrames[6];
		// 法线
		sys::Vector3 _normal[6];
		// 纹理坐标
		TextureCube _texCube;
	};
}