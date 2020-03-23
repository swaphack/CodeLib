#include "DCMaterial.h"
using namespace render;

DCMaterial::DCMaterial()
{

}

DCMaterial::~DCMaterial()
{

}

void DCMaterial::draw()
{
	glMaterialfv(GL_FRONT, GL_AMBIENT, Ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, Diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, Specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, &Shiness);
	glMaterialfv(GL_FRONT, GL_EMISSION, Emission);

	SHOW_OPENGL_ERROR_MESSAGE();
}

DCMaterial* DCMaterial::create(float* ambient, float* diffuse, float* specular, float shiness, float* emission)
{
	DCMaterial* pMaterial = sys::Instance<DCMaterial>::getInstance();
	memcpy(pMaterial->Ambient, ambient, 4 * sizeof(float));
	memcpy(pMaterial->Diffuse, diffuse, 4 * sizeof(float));
	memcpy(pMaterial->Specular, specular, 4 * sizeof(float));
	memcpy(pMaterial->Emission, emission, 4 * sizeof(float));
	pMaterial->Shiness = shiness;

	return pMaterial;
}

