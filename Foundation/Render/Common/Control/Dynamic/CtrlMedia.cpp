#include "CtrlMedia.h"

using namespace render;

CtrlMedia::CtrlMedia()
:_frame(0)
, _texFrame(nullptr)
, _media(nullptr)
{

}

CtrlMedia::~CtrlMedia()
{
	this->removeAllTextures();
	SAFE_DELETE(_texFrame);
	SAFE_DELETE(_media);
}

void CtrlMedia::draw()
{
	Node::draw();
	if (_texFrame == nullptr)
	{
		return;
	}

	int textID = 0;
	if (_texFrame->getTexture())
	{
		textID = _texFrame->getTexture()->getTextureID();
	}

	GLTool::beginBlend(_blend);

	GLTool::setColor(getColor());

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textID);
	GLTool::drawRectVertex(&_texRect);
	glDisable(GL_TEXTURE_2D);

	GLTool::endBlend();
}

void CtrlMedia::setMediaPath(const char* path)
{
	_mediaDefine.filepath = path;

	SAFE_DELETE(_media);
	this->stop();

	_media = Resource::load<FFmpeg>(_mediaDefine);

	this->setVolume(_media->getWidth(), _media->getHeight(), 0);
}	

void CtrlMedia::setFrame(int frame)
{
	_frame = frame;

	setDirty(true);
}

int CtrlMedia::getFrame()
{
	return _frame;
}

void CtrlMedia::initSelf()
{
	Node::initSelf();	

	if (_texFrame == nullptr)
	{
		_texFrame = new TexFrame();
	}

	Texture2D* texture = getNextTexture();
	AUTO_RELEASE_OBJECT(texture);
	if (texture == nullptr)
	{
		return;
	}

	Texture* oldTexture = (Texture*)_texFrame->getTexture();
	if (oldTexture)
	{
		oldTexture->release();
	}

	_texFrame->setTextureWithRect(texture);

	sys::Size size = sys::Size(_texFrame->getTexture()->getWidth(), _texFrame->getTexture()->getHeight());

	TextureTool::setTexture2DCounterCoords(&_texRect, size, _texFrame->getRect());
	TextureTool::setTexture2DVertexts(&_texRect, sys::Vector::Zero, _volume, _anchor);
}

void CtrlMedia::updateSelf(float interval)
{
	_frame += interval;
	float frame = 1.0f / _media->getFrameRate();
	if (_frame > frame)
	{
		setDirty(true);
		_frame -= frame;
	}
}

Texture2D* CtrlMedia::getNextTexture()
{
	if (_media == nullptr)
	{
		return nullptr;
	}

	const Image* image = _media->getNextVideo();
	if (image == nullptr)
	{
		return nullptr;
	}

	Texture2D* texture2D = new Texture2D();
	texture2D->load(image);

	return texture2D;
}

void CtrlMedia::removeAllTextures()
{
	std::map<mf_s, Texture2D*>::iterator it = _texures.begin();

	while (it != _texures.end())
	{
		SAFE_RELEASE(it->second);
		it++;
	}

	_texures.clear();
}


