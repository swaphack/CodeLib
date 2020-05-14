#include "TextureTool.h"
#include "Tool.h"

using namespace render;

void TextureTool::setTexture2DCoords(TextureRectVertex* texRect, const math::Size& size, const math::Rect& rect)
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

void TextureTool::setTexture2DVertexts(TextureRectVertex* texRect, const math::Vector3& position, const math::Volume& volume, const math::Vector3& anchor)
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

void TextureTool::setTexture3DVertexts(TextureCubeVertex* texcube, const math::Vector3& position, const math::Volume& volume, const math::Vector3& anchor)
{
	float x;
	float y;
	float z;
	math::Vector3 point;

	//------ front ------

	// left down
	x = position.getX() - volume.getWidth() * anchor.getX();
	y = position.getY() - volume.getHeight() * anchor.getY();
	z = position.getZ() - volume.getDepth() * anchor.getZ();

	texcube->setFrontLeftDownPoint(point);

	// right down
	x = position.getX() + volume.getWidth() * (1 - anchor.getX());
	y = position.getY() - volume.getHeight() * anchor.getY();
	z = position.getZ() - volume.getDepth() * anchor.getZ();

	texcube->setFrontRightDownPoint(point);

	// right up
	x = position.getX() + volume.getWidth() * (1 - anchor.getX());
	y = position.getY() + volume.getHeight() * (1 - anchor.getY());
	z = position.getZ() - volume.getDepth() * anchor.getZ();

	texcube->setFrontRightUpPoint(point);

	// left up
	x = position.getX() - volume.getWidth() * anchor.getX();
	y = position.getY() + volume.getHeight() * (1 - anchor.getY());
	z = position.getZ() - volume.getDepth() * anchor.getZ();

	texcube->setFrontLeftUpPoint(point);

	//------ back ------

	// left down
	x = position.getX() - volume.getWidth() * anchor.getX();
	y = position.getY() - volume.getHeight() * anchor.getY();
	z = position.getZ() + volume.getDepth() * (1 - anchor.getZ());

	texcube->setBackLeftDownPoint(point);

	// right down
	x = position.getX() + volume.getWidth() * (1 - anchor.getX());
	y = position.getY() - volume.getHeight() * anchor.getY();
	z = position.getZ() + volume.getDepth() * (1 - anchor.getZ());

	texcube->setBackRightDownPoint(point);

	// right up
	x = position.getX() + volume.getWidth() * (1 - anchor.getX());
	y = position.getY() + volume.getHeight() * (1 - anchor.getY());
	z = position.getZ() + volume.getDepth() * (1 - anchor.getZ());

	texcube->setBackRightUpPoint(point);

	// left up
	x = position.getX() - volume.getWidth() * anchor.getX();
	y = position.getY() + volume.getHeight() * (1 - anchor.getY());
	z = position.getZ() + volume.getDepth() * (1 - anchor.getZ());

	texcube->setBackLeftUpPoint(point);
}

void TextureTool::setTexture2DFlip(TextureRectVertex* texRect, bool bFlipX, bool bFlipY)
{
	math::Vector3 temp;

	if (bFlipX)
	{
		texRect->flipX();
	}

	if (bFlipY)
	{
		texRect->flipY();
	}
}