#pragma once

// ö��
namespace render
{
	// ������
	enum class CubeFace
	{
		RIGHT,		// ����
		LEFT,		// ����
		
		TOP,		// ����
		BOTTOM,		// ����

		FRONT,		// ǰ��
		BACK,		// ����
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