#include "CtrlModel.h"

using namespace render;


CtrlModel::CtrlModel()
:_material(nullptr)
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

	_material = new Material();
	AUTO_RELEASE_OBJECT(_material);
}

CtrlModel::~CtrlModel()
{
	SAFE_RELEASE(_material);

	for (int i = 0; i < 6; i++)
	{
		SAFE_RELEASE(_faceFrames[i]);
	}
}

void CtrlModel::draw()
{
	Node::draw();

	if (_material)
	{
		_material->apply();
	}
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

			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

			GLTool::setColor(getColor());

			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, textID);
			GLTool::drawRectVertexWithNormal(texRect, _normal[i]);
			glDisable(GL_TEXTURE_2D);

			glDisable(GL_BLEND);
		}
	}	
	//glDepthMask(GL_FALSE);
	glDisable(GL_DEPTH_TEST);

	Material::applyDefault();
}

void CtrlModel::setMatrial(Material* material)
{
	if (material == nullptr)
	{
		return;
	}
	SAFE_RELEASE(_material);
	SAFE_RETAIN(material);
	_material = material;
}

Material* CtrlModel::getMatrial()
{
	return _material;
}

void CtrlModel::setFaceFrame(ModelFace face, TexFrame* frame)
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

void CtrlModel::setAllFacesFrame(TexFrame* frame)
{
	for (int i = 0; i < 6; i++)
	{
		this->setFaceFrame(static_cast<ModelFace>(i), frame);
	}
}

void CtrlModel::initSelf()
{
	Node::initSelf();

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

TextureRect* CtrlModel::getTextureRect(ModelFace face)
{
	switch (face)
	{
	case render::EMF_FRONT:
		return &_texCube.front;
		break;
	case render::EMF_BACK:
		return &_texCube.back;
		break;
	case render::EMF_LEFT:
		return &_texCube.left;
		break;
	case render::EMF_RIGHT:
		return &_texCube.right;
		break;
	case render::EMF_TOP:
		return &_texCube.top;
		break;
	case render::EMF_BOTTOM:
		return &_texCube.bottom;
		break;
	default:
		break;
	}

	return nullptr;
}
