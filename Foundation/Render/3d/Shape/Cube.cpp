#include "Cube.h"
#include "Graphic/import.h"
using namespace render;

Cube::Cube()
{
	_normal[EMF_FRONT] = math::Vector3(0.0f, 0.0f, 1.0f);
	_normal[EMF_BACK] = math::Vector3(0.0f, 0.0f, -1.0f);
	_normal[EMF_TOP] = math::Vector3(0.0f, 1.0f, 0.0f);
	_normal[EMF_BOTTOM] = math::Vector3(0.0f, -1.0f, 0.0f);
	_normal[EMF_LEFT] = math::Vector3(0.0f, 1.0f, 0.0f);
	_normal[EMF_RIGHT] = math::Vector3(0.0f, -1.0f, 0.0f);

	for (int i = 0; i < 6; i++)
	{
		_faceFrames[i] = nullptr;
		_normal[i] = math::Vector3(0.0f, 0.0f, 1.0f);
	}
}

Cube::~Cube()
{
	for (int i = 0; i < 6; i++)
	{
		SAFE_RELEASE(_faceFrames[i]);
	}
}

bool Cube::init()
{
	Model::init();

	_notify->addListen(ENP_SPACE, [this](){
		onCubeChange();
	});

	_notify->addListen(ENP_MODEL_FRAME, [this](){
		onCubeChange();
	});

	return true;
}

void Cube::draw()
{
	Model::draw();

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


void Cube::setFaceFrame(ModelFace face, TexFrame* frame)
{
	if (frame == nullptr)
	{
		return;
	}

	SAFE_RELEASE(_faceFrames[face]);
	SAFE_RETAIN(frame);

	_faceFrames[face] = frame;

	_notify->addMark(ENP_MODEL_FRAME);
}

void Cube::setTexFrame(TexFrame* frame)
{
	if (frame == nullptr)
	{
		return;
	}
	Model::setTexFrame(frame);
	for (int i = 0; i < 6; i++)
	{
		this->setFaceFrame(static_cast<ModelFace>(i), frame);
	}
}

void Cube::initSelf()
{
	Model::initSelf();
}

TextureRect* Cube::getTextureRect(ModelFace face)
{
	switch (face)
	{
	case EMF_FRONT:
		return &_texCube.front;
		break;
	case EMF_BACK:
		return &_texCube.back;
		break;
	case EMF_LEFT:
		return &_texCube.left;
		break;
	case EMF_RIGHT:
		return &_texCube.right;
		break;
	case EMF_TOP:
		return &_texCube.top;
		break;
	case EMF_BOTTOM:
		return &_texCube.bottom;
		break;
	default:
		break;
	}

	return nullptr;
}

void Cube::onCubeChange()
{
	for (int i = 0; i < 6; i++)
	{
		TexFrame* frame = _faceFrames[i];
		if (frame && frame->getTexture())
		{
			math::Size size = math::Size((float)frame->getTexture()->getWidth(), (float)frame->getTexture()->getHeight());
			TextureTool::setTexture2DCoords(getTextureRect(static_cast<ModelFace>(i)), size, frame->getRect());
		}
	}

	TextureTool::setTexture3DVertexts(&_texCube, _position, _volume, _anchor);
}