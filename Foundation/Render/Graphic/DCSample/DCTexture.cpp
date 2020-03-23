#include "DCTexture.h"
using namespace render;

DCTexture::DCTexture()
{

}

DCTexture::~DCTexture()
{

}

void DCTexture::drawDC()
{

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, TextureID);
	glBegin(GL_QUADS);
	{
		glNormal3f(Normal.getX(), Normal.getY(), Normal.getZ());
		for (int i = 0; i < 4; i++)
		{
			glTexCoord3f(Coord[i].getX(), Coord[i].getY(), Coord[i].getZ());
			glVertex3f(Position[i].getX(), Position[i].getY(), Position[i].getZ());
		}
	}
	glEnd();

	glDisable(GL_TEXTURE_2D);

	
}

DCTexture* DCTexture::create(int textureID, const TextureRect* texRect, const sys::Color4B& color, uint8_t opacity, const BlendParam& blend, const math::Vector3& normal /*= sys::Vector::Zero*/)
{
	if (textureID <= 0 || texRect == nullptr)
	{
		return nullptr;
	}

	DCTexture* pTexture = sys::Instance<DCTexture>::getInstance();
	pTexture->initColor(color, opacity, blend);

	pTexture->TextureID = textureID;
	pTexture->Normal = normal;

	pTexture->Position[0] = texRect->leftDown.point;
	pTexture->Coord[0] = texRect->leftDown.coords;

	pTexture->Position[1] = texRect->rightDown.point;
	pTexture->Coord[1] = texRect->rightDown.coords;

	pTexture->Position[2] = texRect->rightUp.point;
	pTexture->Coord[2] = texRect->rightUp.coords;

	pTexture->Position[3] = texRect->leftUp.point;
	pTexture->Coord[3] = texRect->leftUp.coords;

	return pTexture;
}
