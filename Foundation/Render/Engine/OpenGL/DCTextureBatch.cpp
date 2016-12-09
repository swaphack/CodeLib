#include "macros.h"

using namespace render;

DCTextureBatch::DCTextureBatch()
:Vertexes(nullptr)
, Normals(nullptr)
, Colors(nullptr)
, TexCoords(nullptr)
, Indices(nullptr)
{

}

DCTextureBatch::~DCTextureBatch()
{
}

void DCTextureBatch::draw()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(Blend.src, Blend.dest);
	glColor4f(Color.red, Color.green, Color.blue, Color.alpha);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, TextureID);
	{
		//glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glTexCoordPointer(TexCoords->size, GL_FLOAT, 0, TexCoords->value);

		//glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(Vertexes->size, GL_FLOAT, 0, Vertexes->value);

		//glEnableClientState(GL_NORMAL_ARRAY);
		glNormalPointer(GL_FLOAT, 0, Normals->value);

		//glEnableClientState(GL_COLOR_ARRAY);
		glColorPointer(Colors->size, GL_FLOAT, 0, Colors->value);

		// for debug
		//glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		//glDisableClientState(GL_VERTEX_ARRAY);
		//glDisableClientState(GL_NORMAL_ARRAY);
		//glDisableClientState(GL_COLOR_ARRAY);

		glDrawElements(GL_TRIANGLES, Indices->count, GL_UNSIGNED_SHORT, Indices->value);

		//SHOW_OPENGL_ERROR_MESSAGE();
	}
	glDisable(GL_TEXTURE_2D);

	glDisable(GL_BLEND);

	glDisable(GL_DEPTH_TEST);
}

DCTextureBatch* DCTextureBatch::create(int textureID,
	const sys::Color4B& color, uchar opacity, const BlendParam& blend,
	const T_Vertex* vertexes, const T_Vertex* normals, const T_Vertex* colors, const T_Vertex* coords,
	const T_Indice* indices)
{
	DCTextureBatch* pTextureBatch = sys::Instance<DCTextureBatch>::getInstance();

	pTextureBatch->TextureID = textureID;
	pTextureBatch->Blend = blend;

	convertColor4BTo4F(color, pTextureBatch->Color);
	pTextureBatch->Color.red *= opacity / sys::COLOR_FLOAT_VALUE;
	pTextureBatch->Color.green *= opacity / sys::COLOR_FLOAT_VALUE;
	pTextureBatch->Color.blue *= opacity / sys::COLOR_FLOAT_VALUE;
	pTextureBatch->Color.alpha *= opacity / sys::COLOR_FLOAT_VALUE;

	pTextureBatch->Vertexes = (T_Vertex*)vertexes;
	pTextureBatch->Normals = (T_Vertex*)normals;
	pTextureBatch->Colors = (T_Vertex*)colors;
	pTextureBatch->TexCoords = (T_Vertex*)coords;
	pTextureBatch->Indices = (T_Indice*)indices;

	return pTextureBatch;
}
