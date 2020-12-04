#include "VertexTool.h"
#include "Tool.h"

using namespace render;

void VertexTool::setTexture2DCoords(RectVertex* texRect, const math::Size& size, const math::Rect& rect)
{
	if (texRect == nullptr) return;
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
	if (texRect == nullptr) return;

	float x0 = position.getX() - volume.getWidth() * anchor.getX();
	float x1 = position.getX() + volume.getWidth() * (1 - anchor.getX());
	float y0 = position.getY() - volume.getHeight() * anchor.getY();
	float y1 = position.getY() + volume.getHeight() * (1 - anchor.getY());

	// left down
	texRect->setLeftDownPoint(math::Vector3(x0, y0, position.getZ()));

	// right down
	texRect->setRightDownPoint(math::Vector3(x1, y0, position.getZ()));

	// right up
	texRect->setRightUpPoint(math::Vector3(x1, y1, position.getZ()));

	// left up
	texRect->setLeftUpPoint(math::Vector3(x0, y1, position.getZ()));
}

void VertexTool::setTexture3DVertices(CubeVertex* texcube, const math::Vector3& position, const math::Volume& volume, const math::Vector3& anchor)
{
	if (texcube == nullptr) return;

	float x0 = position.getX() - volume.getWidth() * anchor.getX();
	float y0 = position.getY() - volume.getHeight() * anchor.getY();
	float z0 = position.getZ() + volume.getDepth() * (1 - anchor.getZ());

	float x1 = position.getX() + volume.getWidth() * (1 - anchor.getX());
	float y1 = position.getY() + volume.getHeight() * (1 - anchor.getY());
	float z1 = position.getZ() - volume.getDepth() * anchor.getZ();

	//------ front ------

	// left down
	texcube->setFrontLeftDownPosition(math::Vector3(x0, y0, z0));

	// right down
	texcube->setFrontRightDownPosition(math::Vector3(x1, y0, z0));

	// right up
	texcube->setFrontRightUpPosition(math::Vector3(x1, y1, z0));

	// left up
	texcube->setFrontLeftUpPosition(math::Vector3(x0, y1, z0));

	//------ back ------

	// left down
	texcube->setBackLeftDownPosition(math::Vector3(x1, y0, z1));

	// right down
	texcube->setBackRightDownPosition(math::Vector3(x0, y0, z1));

	// right up
	texcube->setBackRightUpPosition(math::Vector3(x0, y1, z1));

	// left up
	texcube->setBackLeftUpPosition(math::Vector3(x1, y1, z1));
}

void render::VertexTool::setTexture2DFlip(float* uvs, bool bFlipX, bool bFlipY)
{
	if (uvs == nullptr) return;

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

void render::VertexTool::setTexture2DScale9Coords(SimpleScale9Vertex* scale9Vertex, const math::Size& size, const sys::CSSMargin& margin)
{
	if (scale9Vertex == nullptr) return;

	float x0 = 0;
	float x1 = margin.getLeft().getRealValue(size.getWidth()) / size.getWidth();
	float x2 = 1 - margin.getRight().getRealValue(size.getWidth()) / size.getWidth();
	float x3 = 1;

	float y0 = 0;
	float y1 = margin.getBottom().getRealValue(size.getHeight()) / size.getHeight();
	float y2 = 1 - margin.getTop().getRealValue(size.getHeight()) / size.getHeight();
	float y3 = 1;

	scale9Vertex->setLayerUVs0(math::Vector2(x0, y0), math::Vector2(x1, y0), math::Vector2(x2, y0), math::Vector2(x3, y0));
	scale9Vertex->setLayerUVs1(math::Vector2(x0, y1), math::Vector2(x1, y1), math::Vector2(x2, y1), math::Vector2(x3, y1));
	scale9Vertex->setLayerUVs2(math::Vector2(x0, y2), math::Vector2(x1, y2), math::Vector2(x2, y2), math::Vector2(x3, y2));
	scale9Vertex->setLayerUVs3(math::Vector2(x0, y3), math::Vector2(x1, y3), math::Vector2(x2, y3), math::Vector2(x3, y3));
}

void render::VertexTool::setTexture2DScale9Vertices(SimpleScale9Vertex* scale9Vertex, const math::Vector3& position, const math::Volume& volume, const math::Vector3& anchor, const sys::CSSMargin& margin)
{
	if (scale9Vertex == nullptr) return;

	float x0 = position.getX() - volume.getWidth() * anchor.getX();
	float x1 = x0 + margin.getLeft().getRealValue(volume.getWidth());
	float x3 = position.getX() + volume.getWidth() * (1 - anchor.getX());
	float x2 = x3 - margin.getRight().getRealValue(volume.getWidth());

	float y0 = position.getY() - volume.getHeight() * anchor.getY();
	float y1 = y0 + margin.getBottom().getRealValue(volume.getHeight());
	float y3 = position.getY() + volume.getHeight() * (1 - anchor.getY());
	float y2 = y3 - margin.getTop().getRealValue(volume.getHeight());

	/*
	float z0 = position.getZ() + volume.getDepth() * (1 - anchor.getZ());
	float z1 = z0 + margin.getLeft().getRealValue(volume.getDepth());
	float z3 = position.getZ() - volume.getDepth() * anchor.getZ();
	float z2 = z3 - margin.getTop().getRealValue(volume.getDepth());
	*/

	float z0 = 0;

	scale9Vertex->setLayerPoints0(math::Vector3(x0, y0, z0), math::Vector3(x1, y0, z0), math::Vector3(x2, y0, z0), math::Vector3(x3, y0, z0));
	scale9Vertex->setLayerPoints1(math::Vector3(x0, y1, z0), math::Vector3(x1, y1, z0), math::Vector3(x2, y1, z0), math::Vector3(x3, y1, z0));
	scale9Vertex->setLayerPoints2(math::Vector3(x0, y2, z0), math::Vector3(x1, y2, z0), math::Vector3(x2, y2, z0), math::Vector3(x3, y2, z0));
	scale9Vertex->setLayerPoints3(math::Vector3(x0, y3, z0), math::Vector3(x1, y3, z0), math::Vector3(x2, y3, z0), math::Vector3(x3, y3, z0));

}
