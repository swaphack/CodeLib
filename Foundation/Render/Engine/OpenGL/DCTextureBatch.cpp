#include "macros.h"

using namespace render;

DCTextureBatch::DCTextureBatch()
:TexCoords(nullptr)
, Vertexs(nullptr)
, Normals(nullptr)
, Colors(nullptr)
, Indices(nullptr)
{

}

DCTextureBatch::~DCTextureBatch()
{
	/**
	SAFE_FREE(pTextureBatch->TexCoords);
	SAFE_FREE(pTextureBatch->Vertexs);
	SAFE_FREE(pTextureBatch->Normals);
	SAFE_FREE(pTextureBatch->Colors);
	SAFE_FREE(pTextureBatch->Indices);
	*/
}

void DCTextureBatch::draw()
{
	glEnable(GL_BLEND);
	glBlendFunc(Blend.src, Blend.dest);

	glColor4f(Color.red, Color.green, Color.blue, Color.alpha);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, TextureID);
	{
		//glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, Vertexs);

		//glEnableClientState(GL_NORMAL_ARRAY);
		glNormalPointer(3, GL_FLOAT, Normals);

		// glEnableClientState(GL_COLOR_ARRAY);
		glColorPointer(3, GL_FLOAT, 0, Colors);

		//glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glTexCoordPointer(3, GL_FLOAT, 0, TexCoords);

		glDrawElements(GL_TRIANGLES, IndexCount, GL_UNSIGNED_SHORT, Indices);
	}
	glDisable(GL_TEXTURE_2D);

	glDisable(GL_BLEND);
}

DCTextureBatch* DCTextureBatch::create(int textureID,
	const sys::Color4B& color, uchar opacity, const BlendParam& blend,
	int vertexCount, float* normals, float* positions, float* colors, float* coords,
	int indexCount, ushort* indices)
{
	DCTextureBatch* pTextureBatch = sys::Instance<DCTextureBatch>::getInstance();

	pTextureBatch->TextureID = textureID;
	pTextureBatch->Blend = blend;

	convertColor4BTo4F(color, pTextureBatch->Color);
	pTextureBatch->Color.red *= opacity / sys::COLOR_FLOAT_VALUE;
	pTextureBatch->Color.green *= opacity / sys::COLOR_FLOAT_VALUE;
	pTextureBatch->Color.blue *= opacity / sys::COLOR_FLOAT_VALUE;
	pTextureBatch->Color.alpha *= opacity / sys::COLOR_FLOAT_VALUE;

	pTextureBatch->VertexCount = vertexCount;
	pTextureBatch->IndexCount = indexCount;

	pTextureBatch->TexCoords = coords;
	pTextureBatch->Vertexs = positions;
	pTextureBatch->Normals = normals;
	pTextureBatch->Colors = colors;
	pTextureBatch->Indices = indices;

	/*
	SAFE_FREE(pTextureBatch->TexCoords);
	SAFE_FREE(pTextureBatch->Vertexs);
	SAFE_FREE(pTextureBatch->Normals);
	SAFE_FREE(pTextureBatch->Colors);
	SAFE_FREE(pTextureBatch->Indices);

	pTextureBatch->TexCoords = (float*)malloc(vertexCount* sizeof(float));
	pTextureBatch->Vertexs = (float*)malloc(vertexCount* sizeof(float));
	pTextureBatch->Normals = (float*)malloc(vertexCount* sizeof(float));
	pTextureBatch->Colors = (float*)malloc(vertexCount* sizeof(float));
	pTextureBatch->Indices = (ushort*)malloc(indexCount* sizeof(ushort));

	// ��������
	memcpy(pTextureBatch->TexCoords, coords, vertexCount* sizeof(float));
	// ����
	memcpy(pTextureBatch->Vertexs, positions, vertexCount* sizeof(float));
	// ����
	memcpy(pTextureBatch->Normals, normals, vertexCount* sizeof(float));
	// ����
	memcpy(pTextureBatch->Colors, colors, vertexCount* sizeof(float));
	// ������
	memcpy(pTextureBatch->Indices, indices, indexCount* sizeof(ushort));
	*/

	return pTextureBatch;
}
