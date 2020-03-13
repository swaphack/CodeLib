#include "MultiFaceCube.h"
#include "Graphic/import.h"
using namespace render;

MultiFaceCube::MultiFaceCube()
{
	_normal[EMF_FRONT] = math::Vector3(0.0f, 0.0f, 1.0f);
	_normal[EMF_BACK] = math::Vector3(0.0f, 0.0f, -1.0f);
	_normal[EMF_TOP] = math::Vector3(0.0f, 1.0f, 0.0f);
	_normal[EMF_BOTTOM] = math::Vector3(0.0f, -1.0f, 0.0f);
	_normal[EMF_LEFT] = math::Vector3(0.0f, 1.0f, 0.0f);
	_normal[EMF_RIGHT] = math::Vector3(0.0f, -1.0f, 0.0f);

	for (int i = 0; i < CUBE_FACE_COUNT; i++)
	{
		_faceFrames[i] = nullptr;
		_normal[i] = math::Vector3(0.0f, 0.0f, 1.0f);
	}
}

MultiFaceCube::~MultiFaceCube()
{
	for (int i = 0; i < CUBE_FACE_COUNT; i++)
	{
		SAFE_RELEASE(_faceFrames[i]);
	}
}

bool MultiFaceCube::init()
{
	CubeModel::init();

	return true;
}

void MultiFaceCube::draw()
{
	for (int i = 0; i < CUBE_FACE_COUNT; i++)
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
}


void MultiFaceCube::setFaceFrame(ModelFace face, TexFrame* frame)
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

void MultiFaceCube::setAllFaceFrame(TexFrame* frame)
{
	if (frame == nullptr)
	{
		return;
	}
	for (int i = 0; i < CUBE_FACE_COUNT; i++)
	{
		this->setFaceFrame(static_cast<ModelFace>(i), frame);
	}
}

void MultiFaceCube::setAllFaceMaterial(Material* mat)
{
	if (mat == nullptr)
	{
		return;
	}

	for (int i = 0; i < CUBE_FACE_COUNT; i++)
	{
		this->addMaterial(i, mat);
	}
}

void MultiFaceCube::onCubeChange()
{
	for (int i = 0; i < CUBE_FACE_COUNT; i++)
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
