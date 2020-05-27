#include "SkyBox.h"
#include "Common/Texture/TextureCache.h"
#include "Common/Texture/TextureCubeMap.h"
#include "Common/Tool/VertexTool.h"
#include "Common/Mesh/Mesh.h"
#include "Graphic/import.h"

render::SkyBox::SkyBox()
{

}

render::SkyBox::~SkyBox()
{
}

bool render::SkyBox::init()
{
	if (!Cube::init())
	{
		return false;
	}

	return true;
}

void render::SkyBox::beforeDrawNode()
{
	GLState::setDepthMask(false);
	Cube::beforeDrawNode();
}

void render::SkyBox::afterDrawNode()
{
	Cube::afterDrawNode();

	GLState::setDepthMask(true);
}

