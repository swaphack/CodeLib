#include "SkyBox.h"
#include "Common/Texture/TextureCache.h"
render::SkyBox::SkyBox()
{

}

render::SkyBox::~SkyBox()
{

}

bool render::SkyBox::init()
{
	if (!Model::init())
	{
		return false;
	}

	_notify->addListen(NodeNotifyType::TEXTURE, [this]() {
		this->onImageChanged();
	});

	return true;
}

void render::SkyBox::loadImages(CubeFace face, const std::string& fullpath)
{
	_imagePaths[(int)face] = fullpath;

	this->notify(NodeNotifyType::TEXTURE);
}

void render::SkyBox::onImageChanged()
{
	//G_TEXTURE_CACHE->createTextureCubeMap();
}

