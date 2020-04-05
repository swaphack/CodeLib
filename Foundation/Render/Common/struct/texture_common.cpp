#include "texture_common.h"

using namespace render;

TextureVertex::TextureVertex()
{
	normal = math::Vector3(0, 0, 1);
}
//////////////////////////////////////////////////////////////////////////
BlendParam& BlendParam::operator=(const BlendParam& blend)
{
	src = blend.src;
	dest = blend.dest;

	return *this;
}

BlendParam::BlendParam(BlendingFactorSrc src, BlendingFactorDest dest) :src(src), dest(dest)
{

}

BlendParam::BlendParam()
{

}
//////////////////////////////////////////////////////////////////////////
TextureRectVertex::TextureRectVertex()
{
	memset(colors, 1, 16 * sizeof(float));

	uvs[0] = 0; uvs[1] = 0;
	uvs[2] = 1; uvs[3] = 0;
	uvs[4] = 1; uvs[5] = 1;
	uvs[6] = 0; uvs[7] = 1;

	indices[0] = 0; indices[1] = 1; indices[2] = 2;
	indices[3] = 0; indices[4] = 2; indices[5] = 3;
}

void TextureRectVertex::setLeftDownPoint(const math::Vector3& point)
{
	int index = 0;
	memcpy(vertices + index, point.getValue(), point.getSize() * sizeof(float));
}

void TextureRectVertex::setRightDownPoint(const math::Vector3& point)
{
	int index = 3;
	memcpy(vertices + index, point.getValue(), point.getSize() * sizeof(float));
}

void TextureRectVertex::setRightUpPoint(const math::Vector3& point)
{
	int index = 6;
	memcpy(vertices + index, point.getValue(), point.getSize() * sizeof(float));
}

void TextureRectVertex::setLeftUpPoint(const math::Vector3& point)
{
	int index = 9;
	memcpy(vertices + index, point.getValue(), point.getSize() * sizeof(float));
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
	memcpy(uvs + index, point.getValue(), point.getSize() * sizeof(float));
}

void TextureRectVertex::setRightDownUV(const math::Vector2& point)
{
	int index = 2;
	memcpy(uvs + index, point.getValue(), point.getSize() * sizeof(float));
}

void TextureRectVertex::setRightUpUV(const math::Vector2& point)
{
	int index = 4;
	memcpy(uvs + index, point.getValue(), point.getSize() * sizeof(float));
}

void TextureRectVertex::setLeftUpUV(const math::Vector2& point)
{
	int index = 6;
	memcpy(uvs + index, point.getValue(), point.getSize() * sizeof(float));
}

void TextureRectVertex::flipX()
{
	float x0 = uvs[0];
	float x1 = uvs[2];
	float x2 = uvs[4];
	float x3 = uvs[6];

	uvs[0] = x1;
	uvs[2] = x0;

	uvs[4] = x3;
	uvs[6] = x3;
}

void TextureRectVertex::flipY()
{
	float y0 = uvs[1];
	float y1 = uvs[3];
	float y2 = uvs[5];
	float y3 = uvs[7];

	uvs[1] = y1;
	uvs[3] = y0;
			 
	uvs[5] = y3;
	uvs[7] = y3;
}

//////////////////////////////////////////////////////////////////////////

TextureCubeVertex::TextureCubeVertex()
{
	memset(colors, 1, 32 * sizeof(float));

	uvs[0] = 0; uvs[1] = 0;
	uvs[2] = 1; uvs[3] = 0;
	uvs[4] = 1; uvs[5] = 1;
	uvs[6] = 0; uvs[7] = 1;

	uvs[8] = 1; uvs[9] = 0;
	uvs[10] = 0; uvs[11] = 0;
	uvs[12] = 0; uvs[13] = 1;
	uvs[14] = 1; uvs[15] = 1;

	indices[0] = 0; indices[1] = 1; indices[2] = 3;
	indices[3] = 0; indices[4] = 2; indices[5] = 3;

	indices[6] = 0; indices[7] = 1; indices[8] = 3;
	indices[9] = 0; indices[10] = 2; indices[11] = 3;

	indices[12] = 0; indices[13] = 1; indices[14] = 3;
	indices[15] = 0; indices[16] = 2; indices[17] = 3;

	indices[18] = 0; indices[19] = 1; indices[20] = 3;
	indices[21] = 0; indices[22] = 2; indices[23] = 3;

	indices[24] = 0; indices[25] = 1; indices[26] = 3;
	indices[27] = 0; indices[28] = 2; indices[29] = 3;

	indices[30] = 0; indices[31] = 1; indices[32] = 3;
	indices[33] = 0; indices[34] = 2; indices[35] = 3;

	normals[0] = 0; normals[1] = 0; normals[2] = 1;
	normals[3] = 0; normals[4] = 0; normals[5] = 1;
	normals[6] = 0; normals[7] = 0; normals[8] = 1;
	normals[9] = 0; normals[10] = 0; normals[11] = 1;
	normals[12] = 0; normals[13] = 0; normals[14] = 1;
	normals[15] = 0; normals[16] = 0; normals[17] = 1;
	normals[18] = 0; normals[19] = 0; normals[20] = 1;
	normals[21] = 0; normals[22] = 0; normals[23] = 1;
}

void TextureCubeVertex::setFrontLeftDownPoint(const math::Vector3& point)
{
	int index = 0;
	memcpy(vertices + index, point.getValue(), point.getSize() * sizeof(float));
}

void TextureCubeVertex::setFrontRightDownPoint(const math::Vector3& point)
{
	int index = 3;
	memcpy(vertices + index, point.getValue(), point.getSize() * sizeof(float));
}

void TextureCubeVertex::setFrontRightUpPoint(const math::Vector3& point)
{
	int index = 6;
	memcpy(vertices + index, point.getValue(), point.getSize() * sizeof(float));
}

void TextureCubeVertex::setFrontLeftUpPoint(const math::Vector3& point)
{
	int index = 9;
	memcpy(vertices + index, point.getValue(), point.getSize() * sizeof(float));
}

void TextureCubeVertex::setBackLeftDownPoint(const math::Vector3& point)
{
	int index = 12;
	memcpy(vertices + index, point.getValue(), point.getSize() * sizeof(float));
}

void TextureCubeVertex::setBackRightDownPoint(const math::Vector3& point)
{
	int index = 15;
	memcpy(vertices + index, point.getValue(), point.getSize() * sizeof(float));
}

void TextureCubeVertex::setBackRightUpPoint(const math::Vector3& point)
{
	int index = 18;
	memcpy(vertices + index, point.getValue(), point.getSize() * sizeof(float));
}

void TextureCubeVertex::setBackLeftUpPoint(const math::Vector3& point)
{
	int index = 21;
	memcpy(vertices + index, point.getValue(), point.getSize() * sizeof(float));
}

void render::TextureCubeVertex::setFrontLeftDownColor(const sys::Color4B& color)
{
	int index = 0;
	colors[index + 0] = color.red;
	colors[index + 1] = color.green;
	colors[index + 2] = color.blue;
	colors[index + 3] = color.alpha;
}

void render::TextureCubeVertex::setFrontRightDownColor(const sys::Color4B& color)
{
	int index = 4;
	colors[index + 0] = color.red;
	colors[index + 1] = color.green;
	colors[index + 2] = color.blue;
	colors[index + 3] = color.alpha;
}

void render::TextureCubeVertex::setFrontRightUpColor(const sys::Color4B& color)
{
	int index = 8;
	colors[index + 0] = color.red;
	colors[index + 1] = color.green;
	colors[index + 2] = color.blue;
	colors[index + 3] = color.alpha;
}

void render::TextureCubeVertex::setFrontLeftUpColor(const sys::Color4B& color)
{
	int index = 12;
	colors[index + 0] = color.red;
	colors[index + 1] = color.green;
	colors[index + 2] = color.blue;
	colors[index + 3] = color.alpha;
}

void render::TextureCubeVertex::setBackLeftDownColor(const sys::Color4B& color)
{
	int index = 16;
	colors[index + 0] = color.red;
	colors[index + 1] = color.green;
	colors[index + 2] = color.blue;
	colors[index + 3] = color.alpha;
}

void render::TextureCubeVertex::setBackRightDownColor(const sys::Color4B& color)
{
	int index = 20;
	colors[index + 0] = color.red;
	colors[index + 1] = color.green;
	colors[index + 2] = color.blue;
	colors[index + 3] = color.alpha;
}

void render::TextureCubeVertex::setBackRightUpColor(const sys::Color4B& color)
{
	int index = 24;
	colors[index + 0] = color.red;
	colors[index + 1] = color.green;
	colors[index + 2] = color.blue;
	colors[index + 3] = color.alpha;
}

void render::TextureCubeVertex::setBackLeftUpColor(const sys::Color4B& color)
{
	int index = 28;
	colors[index + 0] = color.red;
	colors[index + 1] = color.green;
	colors[index + 2] = color.blue;
	colors[index + 3] = color.alpha;
}
