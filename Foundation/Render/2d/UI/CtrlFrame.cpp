#include "CtrlFrame.h"

#include "Common/Texture/Texture.h"
#include "Common/Texture/TexFrame.h"
#include "Common/Tool/TextureTool.h"
#include "Common/Tool/Tool.h"

#include "Graphic/import.h"

using namespace render;

CtrlFrame::CtrlFrame()
:_bFlipX(false)
, _bFlipY(false)
{
	_texFrame = new TexFrame();
}

CtrlFrame::~CtrlFrame()
{
	SAFE_DELETE(_texFrame);
}

bool CtrlFrame::init()
{
	ColorNode::init();

	_notify->addListen(ENP_SPACE, [this](){
		onTextureChange();
	});

	_notify->addListen(ENP_TEXTURE_FRAME, [this](){
		onTextureChange();
	});


	return true;
}

void CtrlFrame::drawSample()
{
	if (_texFrame->getTexture() == nullptr)
	{
		return;
	}

	int textID = _texFrame->getTexture()->getTextureID();
	if (textID == 0)
	{
		return;
	}

	GLState::enable(EnableModel::TEXTURE_2D);
	GLTexture::bindTexture2D(textID);

	GLClientArrays::enableClientState(ClientArrayType::VERTEX_ARRAY);
	GLClientArrays::setVertexPointer(3, DataType::FLOAT, 0, _texRect.vertices);

	GLClientArrays::enableClientState(ClientArrayType::TEXTURE_COORD_ARRAY);
	GLClientArrays::setTexCoordPointer(2, DataType::FLOAT, 0, _texRect.uvs);

	GLClientArrays::enableClientState(ClientArrayType::COLOR_ARRAY);
	GLClientArrays::setColorPointer(4, DataType::FLOAT, 0, _texRect.colors);

	GLVertex::drawElements(ShapeMode::TRIANGLES, 6, IndexDataType::UNSIGNED_SHORT, _texRect.indices);

	GLClientArrays::disableClientState(ClientArrayType::VERTEX_ARRAY);
	GLClientArrays::disableClientState(ClientArrayType::TEXTURE_COORD_ARRAY);
	GLClientArrays::disableClientState(ClientArrayType::COLOR_ARRAY);

	GLState::disable(EnableModel::TEXTURE_2D);
}

void CtrlFrame::setTexture(const Texture* texture)
{
	if (texture == nullptr)
	{
		return;
	}

	_texFrame->setTexture(texture);
	this->notify(ENP_TEXTURE_FRAME);
}

void CtrlFrame::setTextureWithRect(const Texture* texture)
{
	_texFrame->setTextureWithRect(texture);
	this->notify(ENP_TEXTURE_FRAME);
}

void CtrlFrame::setTexRect(const math::Rect& rect)
{
	_texFrame->setRect(rect);
	this->notify(ENP_TEXTURE_FRAME);
} 

void CtrlFrame::setTexFrame(const TexFrame* texFrame)
{
	if (texFrame == nullptr)
	{
		return;
	}

	*_texFrame = *texFrame;
	this->notify(ENP_TEXTURE_FRAME);
}

const TexFrame* CtrlFrame::getTexFrame()
{
	return _texFrame;
}

void CtrlFrame::setFlipX(bool status)
{
	_bFlipX = status;
	this->notify(ENP_TEXTURE_FRAME);
}

bool CtrlFrame::isFlipX()
{
	return _bFlipX;
}

void CtrlFrame::setFlipY(bool status)
{
	_bFlipY = status;
	this->notify(ENP_TEXTURE_FRAME);
}

bool CtrlFrame::isFlipY()
{
	return _bFlipY;
}

void CtrlFrame::onTextureChange()
{
	const Texture* texture = _texFrame->getTexture();
	if (texture == nullptr)
	{
		return;
	}

	math::Size size = math::Size(static_cast<float>(texture->getWidth()), static_cast<float>(texture->getHeight()));

	TextureTool::setTexture2DCoords(&_texRect, size, _texFrame->getRect());

	TextureTool::setTexture2DVertexts(&_texRect, math::Vector3(), _volume, _anchor);
	TextureTool::setTexture2DFlip(&_texRect, _bFlipX, _bFlipY);
}