#include "VertexTool.h"
#include "Tool.h"

using namespace render;

void VertexTool::setTexture2DCoords(RectVertex* texRect, const math::Size& size, const math::Rect& rect)
{
	// left down
	texRect->setLeftDownUV(math::Vector2(rect.getX() / size.getWidth(), rect.getY() / size.getHeight()));

	// right down
	texRect->setRightDownUV(math::Vector2(rect.getMaxX() / size.getWidth(), rect.getY() / size.getHeight()));

	// right up
	texRect->setRightUpUV(math::Vector2(rect.getMaxX() / size.getWidth(), rect.getMaxY() / size.getHeight()));

	// left up
	texRect->setLeftUpUV(math::Vector2(rect.getX() / size.getWidth(), rect.getMaxY() / size.getHeight()));
}

void VertexTool::setTexture2DVertices(RectVertex* texRect, const math::Vector3& position, const math::Volume& volume, const math::Vector3& anchor)
{
	float x = 0;
	float y = 0;

	// left down
	x = position.getX() - volume.getWidth() * anchor.getX();
	y = position.getY() - volume.getHeight() * anchor.getY();
	texRect->setLeftDownPoint(math::Vector3(x, y, position.getZ()));

	// right down
	x = position.getX() + volume.getWidth() * (1 - anchor.getX());
	y = position.getY() - volume.getHeight() * anchor.getY();
	texRect->setRightDownPoint(math::Vector3(x, y, position.getZ()));

	// right up
	x = position.getX() + volume.getWidth() * (1 - anchor.getX());
	y = position.getY() + volume.getHeight() * (1 - anchor.getY());
	texRect->setRightUpPoint(math::Vector3(x, y, position.getZ()));

	// left up
	x = position.getX() - volume.getWidth() * anchor.getX();
	y = position.getY() + volume.getHeight() * (1 - anchor.getY());
	texRect->setLeftUpPoint(math::Vector3(x, y, position.getZ()));
}

void VertexTool::setTexture3DVertices(CubeVertex* texcube, const math::Vector3& position, const math::Volume& volume, const math::Vector3& anchor)
{
	float x;
	float y;
	float z;

	//------ front ------

	// left down
	x = position.getX() - volume.getWidth() * anchor.getX();

	y = position.getY() - volume.getHeight() * anchor.getY();
	z = position.getZ() + volume.getDepth() * (1 - anchor.getZ());

	texcube->setFrontLeftDownPosition(math::Vector3(x, y, z));

	// right down
	x = position.getX() + volume.getWidth() * (1 - anchor.getX());

	y = position.getY() - volume.getHeight() * anchor.getY();
	z = position.getZ() + volume.getDepth() * (1 - anchor.getZ());

	texcube->setFrontRightDownPosition(math::Vector3(x, y, z));

	// right up
	x = position.getX() + volume.getWidth() * (1 - anchor.getX());

	y = position.getY() + volume.getHeight() * (1 - anchor.getY());
	z = position.getZ() + volume.getDepth() * (1 - anchor.getZ());

	texcube->setFrontRightUpPosition(math::Vector3(x, y, z));

	// left up
	x = position.getX() - volume.getWidth() * anchor.getX();

	y = position.getY() + volume.getHeight() * (1 - anchor.getY());
	z = position.getZ() + volume.getDepth() * (1 - anchor.getZ());

	texcube->setFrontLeftUpPosition(math::Vector3(x, y, z));

	//------ back ------

	// left down
	x = position.getX() + volume.getWidth() * (1 - anchor.getX());
	y = position.getY() - volume.getHeight() * anchor.getY();
	z = position.getZ() - volume.getDepth() * anchor.getZ();

	texcube->setBackLeftDownPosition(math::Vector3(x, y, z));

	// right down
	x = position.getX() - volume.getWidth() * anchor.getX(); 
	y = position.getY() - volume.getHeight() * anchor.getY();
	z = position.getZ() - volume.getDepth() * anchor.getZ();

	texcube->setBackRightDownPosition(math::Vector3(x, y, z));

	// right up
	x = position.getX() - volume.getWidth() * anchor.getX(); 
	y = position.getY() + volume.getHeight() * (1 - anchor.getY());
	z = position.getZ() - volume.getDepth() * anchor.getZ();

	texcube->setBackRightUpPosition(math::Vector3(x, y, z));

	// left up
	x = position.getX() + volume.getWidth() * (1 - anchor.getX());
	y = position.getY() + volume.getHeight() * (1 - anchor.getY());
	z = position.getZ() - volume.getDepth() * anchor.getZ();

	texcube->setBackLeftUpPosition(math::Vector3(x, y, z));
}

void render::VertexTool::setTexture2DFlip(float* uvs, bool bFlipX, bool bFlipY)
{
	if (bFlipX)
	{
		float x0 = uvs[0];
		float x1 = uvs[2];
		float x2 = uvs[4];
		float x3 = uvs[6];

		uvs[0] = x1;
		uvs[2] = x0;

		uvs[4] = x3;
		uvs[6] = x2;
	}

	if (bFlipY)
	{
		float y0 = uvs[1];
		float y1 = uvs[3];
		float y2 = uvs[5];
		float y3 = uvs[7];

		uvs[1] = y1;
		uvs[3] = y0;

		uvs[5] = y3;
		uvs[7] = y2;
	}
}