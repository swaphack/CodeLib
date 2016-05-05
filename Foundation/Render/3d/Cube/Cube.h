#pragma once

#include "../../Common/common.h"

namespace render
{
	// �������������
	enum CubeFace
	{
		ECF_FRONT = 0,
		ECF_BACK = 1,
		ECF_LEFT = 2,
		ECF_RIGHT = 3,
		ECF_TOP = 4,
		ECF_BOTTOM,
	};

	// 3dģ�ͻ������ռ�������
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
		// �����������
		TexFrame* _faceTexFrames[6];
	};
}