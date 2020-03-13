#include "DCTextureBatch.h"

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
	glEnable(GL_BLEND);
	glBlendFunc(Blend.src, Blend.dest);
	glColor4f(Color.red, Color.green, Color.blue, Color.alpha);

	if (Normals->size > 0)
	{
		glNormalPointer(GL_FLOAT, 0, Normals->value);
		SHOW_OPENGL_ERROR_MESSAGE();
	}

	if (Vertexes->size > 0)
	{
		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(Vertexes->unit, GL_FLOAT, 0, Vertexes->value);
		SHOW_OPENGL_ERROR_MESSAGE();
	}

	if (TextureID > 0)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, TextureID);
		if (TexCoords->size > 0)
		{
			glTexCoordPointer(TexCoords->unit, GL_FLOAT, 0, TexCoords->value);
			SHOW_OPENGL_ERROR_MESSAGE();
		}
	}
	else
	{
		if (Colors->size > 0)
		{
			glColorPointer(Colors->unit, GL_FLOAT, 0, Colors->value);
			SHOW_OPENGL_ERROR_MESSAGE();
		}
	}
	if (Indices->size > 0)
	{
		glDrawElements(GL_TRIANGLES, Indices->size, GL_UNSIGNED_SHORT, Indices->value);
		/*
		glColor3f(0, 1, 1);

		glLineWidth(0.1f);
		glBegin(GL_LINE_STRIP);
		for (int i = 0; i < Indices->size; i++)
		{
			uint16_t idx = Indices->value[i];
			float x = *(Vertexes->value + idx * 3 + 0);
			float y = *(Vertexes->value + idx * 3 + 1);
			float z = *(Vertexes->value + idx * 3 + 2);
			glVertex3f(x, y, z);
		}
		glEnd();
		*/
		SHOW_OPENGL_ERROR_MESSAGE();
	}
	glDisable(GL_TEXTURE_2D);
}

DCTextureBatch* DCTextureBatch::create(int textureID,
	const sys::Color4B& color, uint8_t opacity, const BlendParam& blend,
	const T_Vertex* vertexes, const T_Vertex* normals, const T_Vertex* colors, const T_Vertex* coords,
	const T_Indice* indices)
{
	DCTextureBatch* pTextureBatch = sys::Instance<DCTextureBatch>::getInstance();

	pTextureBatch->TextureID = textureID;
	pTextureBatch->Blend = blend;

	convertColor4BTo4F(color, pTextureBatch->Color);
	pTextureBatch->Color.red *= opacity / COLOR_FLOAT_VALUE;
	pTextureBatch->Color.green *= opacity / COLOR_FLOAT_VALUE;
	pTextureBatch->Color.blue *= opacity / COLOR_FLOAT_VALUE;
	pTextureBatch->Color.alpha *= opacity / COLOR_FLOAT_VALUE;

	pTextureBatch->Vertexes = (T_Vertex*)vertexes;
	pTextureBatch->Normals = (T_Vertex*)normals;
	pTextureBatch->Colors = (T_Vertex*)colors;
	pTextureBatch->TexCoords = (T_Vertex*)coords;
	pTextureBatch->Indices = (T_Indice*)indices;

	return pTextureBatch;
}
