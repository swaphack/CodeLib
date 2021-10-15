#include "VertexTool.h"
#include "Tool.h"

using namespace render;

void VertexTool::setTexture2DCoords(RectVertex* texRect, const math::Rect& rect, bool rotate)
{
	if (texRect == nullptr) return;

	math::RectPoints rectPoints(rect);
	float uvs[8] = { 0 };
	if (rotate)
	{
		uvs[0] = rectPoints.getRightBottom().getX(); uvs[1] = rectPoints.getRightBottom().getY();
		uvs[2] = rectPoints.getRightTop().getX(); uvs[3] = rectPoints.getRightTop().getY();
		uvs[4] = rectPoints.getLeftTop().getX(); uvs[5] = rectPoints.getLeftTop().getY();
		uvs[6] = rectPoints.getLeftBottom().getX(); uvs[7] = rectPoints.getLeftBottom().getY();
	}
	else
	{
		uvs[0] = rectPoints.getLeftBottom().getX(); uvs[1] = rectPoints.getLeftBottom().getY();
		uvs[2] = rectPoints.getRightBottom().getX(); uvs[3] = rectPoints.getRightBottom().getY();
		uvs[4] = rectPoints.getRightTop().getX(); uvs[5] = rectPoints.getRightTop().getY();
		uvs[6] = rectPoints.getLeftTop().getX(); uvs[7] = rectPoints.getLeftTop().getY();
	}
	memcpy(texRect->uvs, uvs, sizeof(uvs));
}

void VertexTool::setTexture2DVertices(RectVertex* texRect, const math::Vector3& position, const math::Volume& volume, const math::Vector3& anchor)
{
	if (texRect == nullptr) return;

	float x0 = position.getX() - volume.getWidth() * anchor.getX();
	float x1 = position.getX() + volume.getWidth() * (1 - anchor.getX());
	float y0 = position.getY() - volume.getHeight() * anchor.getY();
	float y1 = position.getY() + volume.getHeight() * (1 - anchor.getY());

	// left down
	texRect->setLeftBottomPosition(math::Vector3(x0, y0, position.getZ()));

	// right down
	texRect->setRightBottomPosition(math::Vector3(x1, y0, position.getZ()));

	// right up
	texRect->setRightTopPosition(math::Vector3(x1, y1, position.getZ()));

	// left up
	texRect->setLeftTopPosition(math::Vector3(x0, y1, position.getZ()));
}

void VertexTool::setTexture3DVertices(CubeVertex* texcube, const math::Vector3& position, const math::Volume& volume, const math::Vector3& anchor)
{
	if (texcube == nullptr) return;

	float x0 = position.getX() - volume.getWidth() * anchor.getX();
	float y0 = position.getY() - volume.getHeight() * anchor.getY();
	float z0 = position.getZ() - volume.getDepth() * anchor.getZ();

	float x1 = position.getX() + volume.getWidth() * (1 - anchor.getX());
	float y1 = position.getY() + volume.getHeight() * (1 - anchor.getY());
	float z1 = position.getZ() + volume.getDepth() * (1 - anchor.getZ());

	//------ front ------

	// left down
	texcube->setFrontLeftBottomPosition(math::Vector3(x0, y0, z0));

	// right down
	texcube->setFrontRightBottomPosition(math::Vector3(x1, y0, z0));

	// right up
	texcube->setFrontRightTopPosition(math::Vector3(x1, y1, z0));

	// left up
	texcube->setFrontLeftTopPosition(math::Vector3(x0, y1, z0));

	//------ back ------

	// left down
	texcube->setBackLeftBottomPosition(math::Vector3(x1, y0, z1));

	// right down
	texcube->setBackRightBottomPosition(math::Vector3(x0, y0, z1));

	// right up
	texcube->setBackRightTopPosition(math::Vector3(x0, y1, z1));

	// left up
	texcube->setBackLeftTopPosition(math::Vector3(x1, y1, z1));
}

void render::VertexTool::setTexture2DFlip(float(*uvs)[8], bool bFlipX, bool bFlipY)
{
	if (uvs == nullptr) return;

	if (bFlipX)
	{
		for (int i = 0; i < 2; i++)
		{
			int idx0 = 4 * i;
			int idx1 = 4 * i + 2;
			(*uvs)[idx0] = (*uvs)[idx0] + (*uvs)[idx1];
			(*uvs)[idx1] = (*uvs)[idx0] - (*uvs)[idx1];
			(*uvs)[idx0] = (*uvs)[idx0] - (*uvs)[idx1];
		}
	}

	if (bFlipY)
	{
		for (int i = 0; i < 2; i++)
		{
			int idx0 = 2 * i + 1;
			int idx1 = 8 - (2 * i + 1);

			(*uvs)[idx0] = (*uvs)[idx0] + (*uvs)[idx1];
			(*uvs)[idx1] = (*uvs)[idx0] - (*uvs)[idx1];
			(*uvs)[idx0] = (*uvs)[idx0] - (*uvs)[idx1];
		}
	}
}

void render::VertexTool::setTexture2DScale9Coords(SimpleScale9Vertex* scale9Vertex, const math::Rect& rect, bool rotate, const math::Size& size, const sys::CSSMargin& margin)
{
	if (scale9Vertex == nullptr) return;

	if (size.getWidth() == 0 || size.getHeight() == 0)
		return;

	float x0 = rect.getMinX();
	float x1 = rect.getMinX();
	float x2 = rect.getMaxX();
	float x3 = rect.getMaxX();

	float y0 = rect.getMinY();
	float y1 = rect.getMinY();
	float y2 = rect.getMaxY();
	float y3 = rect.getMaxY();

	if (rotate)
	{
		x1 += margin.getLeft().getRealValue(size.getHeight()) / size.getHeight();
		x2 -= margin.getRight().getRealValue(size.getHeight()) / size.getHeight();

		y1 += margin.getBottom().getRealValue(size.getWidth()) / size.getWidth();
		y2 -= margin.getTop().getRealValue(size.getWidth()) / size.getWidth();

		scale9Vertex->setLayerUVs0(math::Vector2(x0, y3), math::Vector2(x0, y2), math::Vector2(x0, y1), math::Vector2(x0, y0));
		scale9Vertex->setLayerUVs1(math::Vector2(x1, y3), math::Vector2(x1, y2), math::Vector2(x1, y1), math::Vector2(x1, y0));
		scale9Vertex->setLayerUVs2(math::Vector2(x2, y3), math::Vector2(x2, y2), math::Vector2(x2, y1), math::Vector2(x2, y0));
		scale9Vertex->setLayerUVs3(math::Vector2(x3, y3), math::Vector2(x3, y2), math::Vector2(x3, y1), math::Vector2(x3, y0));
	}
	else
	{
		x1 += margin.getLeft().getRealValue(size.getWidth()) / size.getWidth();
		x2 -= margin.getRight().getRealValue(size.getWidth()) / size.getWidth();

		y1 += margin.getBottom().getRealValue(size.getHeight()) / size.getHeight();
		y2 -= margin.getTop().getRealValue(size.getHeight()) / size.getHeight();

		scale9Vertex->setLayerUVs0(math::Vector2(x0, y0), math::Vector2(x1, y0), math::Vector2(x2, y0), math::Vector2(x3, y0));
		scale9Vertex->setLayerUVs1(math::Vector2(x0, y1), math::Vector2(x1, y1), math::Vector2(x2, y1), math::Vector2(x3, y1));
		scale9Vertex->setLayerUVs2(math::Vector2(x0, y2), math::Vector2(x1, y2), math::Vector2(x2, y2), math::Vector2(x3, y2));
		scale9Vertex->setLayerUVs3(math::Vector2(x0, y3), math::Vector2(x1, y3), math::Vector2(x2, y3), math::Vector2(x3, y3));
	}
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

void render::VertexTool::setTexture2DScale9Flip(float(*uvs)[32], bool bFlipX, bool bFlipY)
{
	if (uvs == nullptr) return;

	if (bFlipX)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				int idx0 = i * 8 + 2 * j;
				int idx1 = i * 8 + 6 - 2 * j;
				(*uvs)[idx0] = (*uvs)[idx0] + (*uvs)[idx1];
				(*uvs)[idx1] = (*uvs)[idx0] - (*uvs)[idx1];
				(*uvs)[idx0] = (*uvs)[idx0] - (*uvs)[idx1];
			}
		}
	}

	if (bFlipY)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				int idx0 = j * 8 + 2 * i + 1;
				int idx1 = 3 * 8 + 4 * i + 2 - idx0;

				(*uvs)[idx0] = (*uvs)[idx0] + (*uvs)[idx1];
				(*uvs)[idx1] = (*uvs)[idx0] - (*uvs)[idx1];
				(*uvs)[idx0] = (*uvs)[idx0] - (*uvs)[idx1];
			}
		}
	}
}
