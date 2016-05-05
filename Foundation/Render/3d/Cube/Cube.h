#pragma once

#include "../../Common/common.h"

namespace render
{
	// 立方体的六个面
	enum CubeFace
	{
		ECF_FRONT = 0,
		ECF_BACK = 1,
		ECF_LEFT = 2,
		ECF_RIGHT = 3,
		ECF_TOP = 4,
		ECF_BOTTOM,
	};

	// 3d模型基础，空间立方体
	class Cube : public CtrlModel
	{
	public:
		Cube();
		virtual ~Cube();
	public:
		virtual void draw();
	protected:
		virtual void initSelf();
	private:
		TextureCube _cube;
		// 六个面的纹理
		TexFrame* _faceTexFrames[6];
	};
}