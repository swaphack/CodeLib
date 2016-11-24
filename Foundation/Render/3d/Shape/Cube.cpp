#include "Cube.h"

using namespace render;

Cube::Cube()
{
	_normal[EMF_FRONT] = sys::Vector(0.0f, 0.0f, 1.0f);
	_normal[EMF_BACK] = sys::Vector(0.0f, 0.0f, -1.0f);
	_normal[EMF_TOP] = sys::Vector(0.0f, 1.0f, 0.0f);
	_normal[EMF_BOTTOM] = sys::Vector(0.0f, -1.0f, 0.0f);
	_normal[EMF_LEFT] = sys::Vector(0.0f, 1.0f, 0.0f);
	_normal[EMF_RIGHT] = sys::Vector(0.0f, -1.0f, 0.0f);

	for (int i = 0; i < 6; i++)
	{
		_faceFrames[i] = nullptr;
		_normal[i] = sys::Vector(0.0f, 0.0f, 1.0f);
	}
}

Cube::~Cube()
{
	for (int i = 0; i < 6; i++)
	{
		SAFE_RELEASE(_faceFrames[i]);
	}
}

void Cube::draw()
{
	CtrlModel::draw();

	glEnable(GL_DEPTH_TEST);
	for (int i = 0; i < 6; i++)
	{
		TextureRect* texRect = getTextureRect(static_cast<ModelFace>(i));
		if (texRect)
		{
			int textID = 0;
			if (_faceFrames[i] && _faceFrames[i]->getTexture())
			{
				textID = _faceFrames[i]->getTexture()->getTextureID();
			}

			G_DRAWCOMMANDER->addCommand(DCTexture::create(textID, texRect, getColor(), _opacity, _blend, _normal[i]));
		}
	}
	//glDepthMask(GL_FALSE);
	glDisable(GL_DEPTH_TEST);

	Material::applyDefault();
}


void Cube::setFaceFrame(CubeFace face, TexFrame* frame)
{
	if (frame == nullptr)
	{
		return;
	}

	SAFE_RELEASE(_faceFrames[face]);
	SAFE_RETAIN(frame);

	_faceFrames[face] = frame;

	setDirty(true);
}

void Cube::setTexFrame(TexFrame* frame)
{
	if (frame == nullptr)
	{
		return;
	}
	CtrlModel::setTexFrame(frame);
	for (int i = 0; i < 6; i++)
	{
		this->setFaceFrame(static_cast<CubeFace>(i), frame);
	}
}

void Cube::initSelf()
{
	CtrlModel::initSelf();

	for (int i = 0; i < 6; i++)
	{
		TexFrame* frame = _faceFrames[i];
		if (frame && frame->getTexture())
		{
			sys::Size size = sys::Size(frame->getTexture()->getWidth(), frame->getTexture()->getHeight());
			TextureTool::setTexture2DCoords(getTextureRect(static_cast<ModelFace>(i)), size, frame->getRect());
		}
	}

	TextureTool::setTexture3DVertexts(&_texCube, _position, _volume, _anchor);
}

TextureRect* Cube::getTextureRect(ModelFace face)
{
	switch (face)
	{
	case ECF_FRONT:
		return &_texCube.front;
		break;
	case ECF_BACK:
		return &_texCube.back;
		break;
	case ECF_LEFT:
		return &_texCube.left;
		break;
	case ECF_RIGHT:
		return &_texCube.right;
		break;
	case ECF_TOP:
		return &_texCube.top;
		break;
	case ECF_BOTTOM:
		return &_texCube.bottom;
		break;
	default:
		break;
	}

	return nullptr;
}
