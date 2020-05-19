#include "texture_common.h"

using namespace render;

TextureVertex::TextureVertex()
{
	normal = math::Vector3(0, 0, 1);
}
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
TextureRectVertex::TextureRectVertex()
{
	uvs[0] = 0; uvs[1] = 0;
	uvs[2] = 1; uvs[3] = 0;
	uvs[4] = 1; uvs[5] = 1;
	uvs[6] = 0; uvs[7] = 1;

	indices[0] = 0; indices[1] = 1; indices[2] = 2;
	indices[3] = 0; indices[4] = 2; indices[5] = 3;

	for (int i = 0; i < 16; i++)
	{
		colors[i] = 1;
	}

	for (int i = 0; i < 12; i++)
	{
		vertices[i] = 0;
	}
}

void TextureRectVertex::setLeftDownPoint(const math::Vector3& point)
{
	int index = 0;
	memcpy(vertices + index, point.getValue(), point.getSize());
}

void TextureRectVertex::setRightDownPoint(const math::Vector3& point)
{
	int index = 3;
	memcpy(vertices + index, point.getValue(), point.getSize());
}

void TextureRectVertex::setRightUpPoint(const math::Vector3& point)
{
	int index = 6;
	memcpy(vertices + index, point.getValue(), point.getSize());
}

void TextureRectVertex::setLeftUpPoint(const math::Vector3& point)
{
	int index = 9;
	memcpy(vertices + index, point.getValue(), point.getSize());
}

void TextureRectVertex::setLeftDownColor(const sys::Color4F& color)
{
	int index = 0;
	colors[index + 0] = color.red;
	colors[index + 1] = color.green;
	colors[index + 2] = color.blue;
	colors[index + 3] = color.alpha;
}

void TextureRectVertex::setRightDownColor(const sys::Color4F& color)
{
	int index = 4;
	colors[index + 0] = color.red;
	colors[index + 1] = color.green;
	colors[index + 2] = color.blue;
	colors[index + 3] = color.alpha;
}

void TextureRectVertex::setRightUpColor(const sys::Color4F& color)
{
	int index = 8;
	colors[index + 0] = color.red;
	colors[index + 1] = color.green;
	colors[index + 2] = color.blue;
	colors[index + 3] = color.alpha;
}

void TextureRectVertex::setLeftUpColor(const sys::Color4F& color)
{
	int index = 12;
	colors[index + 0] = color.red;
	colors[index + 1] = color.green;
	colors[index + 2] = color.blue;
	colors[index + 3] = color.alpha;
}

void TextureRectVertex::setLeftDownUV(const math::Vector2& point)
{
	int index = 0;
	memcpy(uvs + index, point.getValue(), point.getSize());
}

void TextureRectVertex::setRightDownUV(const math::Vector2& point)
{
	int index = 2;
	memcpy(uvs + index, point.getValue(), point.getSize());
}

void TextureRectVertex::setRightUpUV(const math::Vector2& point)
{
	int index = 4;
	memcpy(uvs + index, point.getValue(), point.getSize());
}

void TextureRectVertex::setLeftUpUV(const math::Vector2& point)
{
	int index = 6;
	memcpy(uvs + index, point.getValue(), point.getSize());
}

//////////////////////////////////////////////////////////////////////////

TextureCubeVertex::TextureCubeVertex()
{
	// Ç°
	indices[0] = 0; indices[1] = 1; indices[2] = 2;
	indices[3] = 0; indices[4] = 2; indices[5] = 3;

	// ÓÒ±ß
	indices[6] = 1; indices[7] = 5; indices[8] = 6;
	indices[9] = 1; indices[10] = 6; indices[11] = 2;

	// ¶¥²¿
	indices[12] = 3; indices[13] = 2; indices[14] = 6;
	indices[15] = 3; indices[16] = 6; indices[17] = 7;
	//±³Ãæ
	indices[18] = 5; indices[19] = 4; indices[20] = 7;
	indices[21] = 5; indices[22] = 7; indices[23] = 6;
	// ×ó±ß
	indices[24] = 4; indices[25] = 0; indices[26] = 3;
	indices[27] = 4; indices[28] = 3; indices[29] = 7;

	// µ×²¿
	indices[30] = 0; indices[31] = 4; indices[32] = 5;
	indices[33] = 0; indices[34] = 5; indices[35] = 1;

	for (int i = 0; i < 24; i++)
	{
		vertices[i] = 0;
	}
}

void TextureCubeVertex::setFrontLeftDownPoint(const math::Vector3& point)
{
	int index = 0;
	memcpy(vertices + index, point.getValue(), point.getSize());
}

void TextureCubeVertex::setFrontRightDownPoint(const math::Vector3& point)
{
	int index = 3;
	memcpy(vertices + index, point.getValue(), point.getSize());
}

void TextureCubeVertex::setFrontRightUpPoint(const math::Vector3& point)
{
	int index = 6;
	memcpy(vertices + index, point.getValue(), point.getSize());
}

void TextureCubeVertex::setFrontLeftUpPoint(const math::Vector3& point)
{
	int index = 9;
	memcpy(vertices + index, point.getValue(), point.getSize());
}

void TextureCubeVertex::setBackLeftDownPoint(const math::Vector3& point)
{
	int index = 12;
	memcpy(vertices + index, point.getValue(), point.getSize());
}

void TextureCubeVertex::setBackRightDownPoint(const math::Vector3& point)
{
	int index = 15;
	memcpy(vertices + index, point.getValue(), point.getSize());
}

void TextureCubeVertex::setBackRightUpPoint(const math::Vector3& point)
{
	int index = 18;
	memcpy(vertices + index, point.getValue(), point.getSize());
}

void TextureCubeVertex::setBackLeftUpPoint(const math::Vector3& point)
{
	int index = 21;
	memcpy(vertices + index, point.getValue(), point.getSize());
}