#pragma once

#include "../Common/import.h"

namespace render
{
	// 立方体的六个面
	enum CubeFace
	{
		ECF_FRONT = 0,	// 前面
		ECF_BACK,		// 背面
		ECF_LEFT,		// 左面
		ECF_RIGHT,		// 右面
		ECF_TOP,		// 上面
		ECF_BOTTOM,		// 下面
	};

	// 3d模型基础，空间立方体
	class Cube : public CtrlModel
	{
	public:
		Cube();
		virtual ~Cube();
	public:
		virtual bool init();

		virtual void draw();

		// 设置单面的纹理帧
		void setFaceFrame(CubeFace face, TexFrame* frame);
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