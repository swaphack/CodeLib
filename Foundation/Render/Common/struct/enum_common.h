#pragma once

// 枚举
namespace render
{
	// 六个面
	enum class CubeFace
	{
		RIGHT,		// 右面
		LEFT,		// 左面
		
		TOP,		// 上面
		BOTTOM,		// 下面

		FRONT,		// 前面
		BACK,		// 背面
		MAX,
	};

#define CUBE_FACE_LEFT "left"
#define CUBE_FACE_RIGHT "right"
#define CUBE_FACE_FRONT "front"
#define CUBE_FACE_BACK "back"
#define CUBE_FACE_TOP "top"
#define CUBE_FACE_BOTTOM "bottom"

	static const char* CubeFaceString[] = { 
		CUBE_FACE_RIGHT, CUBE_FACE_LEFT,
		CUBE_FACE_TOP, CUBE_FACE_BOTTOM,
		CUBE_FACE_FRONT, CUBE_FACE_BACK, };
}