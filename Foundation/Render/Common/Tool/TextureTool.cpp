#include "TextureTool.h"
#include "UITool.h"

using namespace render;

void TextureTool::setTexture2DCounterCoords(TextureRect* texRect, const sys::Size& size, const sys::Rect& rect)
{
	// left down
	texRect->leftUp.coords.x = rect.x / size.width;
	texRect->leftUp.coords.y = rect.y / size.height;

	// right down
	texRect->rightUp.coords.x = (rect.x + rect.width) / size.width;
	texRect->rightUp.coords.y = rect.y / size.height;

	// right up
	texRect->rightDown.coords.x = (rect.x + rect.width) / size.width;
	texRect->rightDown.coords.y = (rect.y + rect.height) / size.height;

	// left up
	texRect->leftDown.coords.x = rect.x / size.width;
	texRect->leftDown.coords.y = (rect.y + rect.height) / size.height;
}


void TextureTool::setTexture2DCoords(TextureRect* texRect, const sys::Size& size, const sys::Rect& rect)
{
	// left down
	texRect->leftDown.coords.x = rect.x / size.width;
	texRect->leftDown.coords.y = rect.y / size.height;

	// right down
	texRect->rightDown.coords.x = (rect.x + rect.width) / size.width;
	texRect->rightDown.coords.y = rect.y / size.height;

	// right up
	texRect->rightUp.coords.x = (rect.x + rect.width) / size.width;
	texRect->rightUp.coords.y = (rect.y + rect.height) / size.height;

	// left up
	texRect->leftUp.coords.x = rect.x / size.width;
	texRect->leftUp.coords.y = (rect.y + rect.height) / size.height;
}

void TextureTool::setTexture2DVertexts(TextureRect* texRect, const sys::Vector& position, const sys::Volume& volume, const sys::Vector& anchor)
{
	float x = 0;
	float y = 0;

	// left down
	x = position.x - volume.width * anchor.x;
	y = position.y - volume.height * anchor.y;
	texRect->leftDown.point = UITool::convertToOGLPoisition(x, y, position.z);

	// right down
	x = position.x + volume.width * (1 - anchor.x);
	y = position.y - volume.height * anchor.y;
	texRect->rightDown.point = UITool::convertToOGLPoisition(x, y, position.z);

	// right up
	x = position.x + volume.width * (1 - anchor.x);
	y = position.y + volume.height * (1 - anchor.y);
	texRect->rightUp.point = UITool::convertToOGLPoisition(x, y, position.z);

	// left up
	x = position.x - volume.width * anchor.x;
	y = position.y + volume.height * (1 - anchor.y);
	texRect->leftUp.point = UITool::convertToOGLPoisition(x, y, position.z);
}

/*
void TextureTool::setTexture3DCoords(TextureCube* texcube, const sys::Size& size, const sys::Rect& rect)
{
	TextureTool::setTexture2DCoords(&texcube->front, size, rect);
	TextureTool::setTexture2DCoords(&texcube->back, size, rect);
	TextureTool::setTexture2DCoords(&texcube->left, size, rect);
	TextureTool::setTexture2DCoords(&texcube->right, size, rect);
	TextureTool::setTexture2DCoords(&texcube->top, size, rect);
	TextureTool::setTexture2DCoords(&texcube->bottom, size, rect);
}
*/

void TextureTool::setTexture3DVertexts(TextureCube* texcube, const sys::Vector& position, const sys::Volume& volume, const sys::Vector& anchor)
{
	float x;
	float y;
	float z;
	sys::Vector point;

	//------ front ------

	// left down
	x = position.x - volume.width * anchor.x;
	y = position.y - volume.height * anchor.y;
	z = position.z - volume.deep * anchor.z;

	point = UITool::convertToOGLPoisition(x, y, z);
	texcube->front.leftDown.point = point;
	texcube->left.rightDown.point = point;
	texcube->bottom.leftUp.point = point;

	// right down
	x = position.x + volume.width * (1 - anchor.x);
	y = position.y - volume.height * anchor.y;
	z = position.z - volume.deep * anchor.z;

	point = UITool::convertToOGLPoisition(x, y, z);
	texcube->front.rightDown.point = point;
	texcube->right.leftDown.point = point;
	texcube->bottom.rightUp.point = point;

	// right up
	x = position.x + volume.width * (1 - anchor.x);
	y = position.y + volume.height * (1 - anchor.y);
	z = position.z - volume.deep * anchor.z;

	point = UITool::convertToOGLPoisition(x, y, z);
	texcube->front.rightUp.point = point;
	texcube->right.leftUp.point = point;
	texcube->top.rightDown.point = point;

	// left up
	x = position.x - volume.width * anchor.x;
	y = position.y + volume.height * (1 - anchor.y);
	z = position.z - volume.deep * anchor.z;

	point = UITool::convertToOGLPoisition(x, y, z);
	texcube->front.leftUp.point = point;
	texcube->left.rightUp.point = point;
	texcube->top.leftDown.point = point;

	//------ back ------

	// left down
	x = position.x - volume.width * anchor.x;
	y = position.y - volume.height * anchor.y;
	z = position.z + volume.deep * (1 - anchor.z);

	point = UITool::convertToOGLPoisition(x, y, z);
	texcube->back.rightDown.point = point;
	texcube->left.leftDown.point = point;
	texcube->bottom.leftDown.point = point;

	// right down
	x = position.x + volume.width * (1 - anchor.x);
	y = position.y - volume.height * anchor.y;
	z = position.z + volume.deep * (1 - anchor.z);

	point = UITool::convertToOGLPoisition(x, y, z);
	texcube->back.leftDown.point = point;
	texcube->right.rightDown.point = point;
	texcube->bottom.rightDown.point = point;

	// right up
	x = position.x + volume.width * (1 - anchor.x);
	y = position.y + volume.height * (1 - anchor.y);
	z = position.z + volume.deep * (1 - anchor.z);

	point = UITool::convertToOGLPoisition(x, y, z);
	texcube->back.leftUp.point = point;
	texcube->top.rightUp.point = point;
	texcube->right.rightUp.point = point;

	// left up
	x = position.x - volume.width * anchor.x;
	y = position.y + volume.height * (1 - anchor.y);
	z = position.z + volume.deep * (1 - anchor.z);

	point = UITool::convertToOGLPoisition(x, y, z);
	texcube->back.rightUp.point = point;
	texcube->left.leftUp.point = point;
	texcube->top.leftUp.point = point;
}


