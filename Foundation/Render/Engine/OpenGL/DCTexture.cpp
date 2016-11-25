#include "macros.h"
using namespace render;

DCTexture::DCTexture()
{

}

DCTexture::~DCTexture()
{

}

void DCTexture::draw()
{
	glEnable(GL_BLEND);
	glBlendFunc(Blend.src, Blend.dest);

	glColor4f(Color.red, Color.green, Color.blue, Color.alpha);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, TextureID);
	glBegin(GL_QUADS);
	{
		glNormal3f(Normal.x, Normal.y, Normal.z);
		for (int i = 0; i < 4; i++)
		{
			glTexCoord3f(Coord[i].x, Coord[i].y, Coord[i].z);
			glVertex3f(Position[i].x, Position[i].y, Position[i].z);
		}
	}
	glEnd();

	glDisable(GL_TEXTURE_2D);

	glDisable(GL_BLEND);
}

DCTexture* DCTexture::create(int textureID, const TextureRect* texRect, const sys::Color4B& color, uchar opacity, const BlendParam& blend, const sys::Vector& normal /*= sys::Vector::Zero*/)
{
	if (textureID <= 0 || texRect == nullptr)
	{
		return nullptr;
	}
	DCTexture* pTexture = sys::Instance<DCTexture>::getInstance();
	pTexture->TextureID = textureID;
	pTexture->Normal = normal;
	pTexture->Blend = blend;

	pTexture->Position[0] = texRect->leftDown.point;
	pTexture->Coord[0] = texRect->leftDown.coords;

	pTexture->Position[1] = texRect->rightDown.point;
	pTexture->Coord[1] = texRect->rightDown.coords;

	pTexture->Position[2] = texRect->rightUp.point;
	pTexture->Coord[2] = texRect->rightUp.coords;

	pTexture->Position[3] = texRect->leftUp.point;
	pTexture->Coord[3] = texRect->leftUp.coords;

	convertColor4BTo4F(color, pTexture->Color);
	pTexture->Color.red *= opacity / sys::COLOR_FLOAT_VALUE;
	pTexture->Color.green *= opacity / sys::COLOR_FLOAT_VALUE;
	pTexture->Color.blue *= opacity / sys::COLOR_FLOAT_VALUE;
	pTexture->Color.alpha *= opacity / sys::COLOR_FLOAT_VALUE;

	return pTexture;
}
