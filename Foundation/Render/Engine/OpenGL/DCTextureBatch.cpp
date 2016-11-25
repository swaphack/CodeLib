#include "macros.h"

using namespace render;

DCTextureBatch::DCTextureBatch()
:TexCoords(nullptr)
, Vertexes(nullptr)
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
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(Blend.src, Blend.dest);

	glColor4f(Color.red, Color.green, Color.blue, Color.alpha);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, TextureID);
	{
		//glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glTexCoordPointer(3, GL_FLOAT, 0, TexCoords);

		//glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, Vertexes);

		//glEnableClientState(GL_NORMAL_ARRAY);
		glNormalPointer(3, GL_FLOAT, Normals);

		// glEnableClientState(GL_COLOR_ARRAY);
		glColorPointer(3, GL_FLOAT, 0, Colors);

		glDrawElements(GL_TRIANGLES, IndexCount, GL_UNSIGNED_INT, Indices);
	}
	glDisable(GL_TEXTURE_2D);

	glDisable(GL_BLEND);

	glDisable(GL_DEPTH_TEST);
}

DCTextureBatch* DCTextureBatch::create(int textureID,
	const sys::Color4B& color, uchar opacity, const BlendParam& blend,
	int vertexCount, float* normals, float* positions, float* colors, float* coords,
	int indexCount, int* indices)
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
	pTextureBatch->Vertexes = positions;
	pTextureBatch->Normals = normals;
	pTextureBatch->Colors = colors;
	pTextureBatch->Indices = indices;

	/*
	SAFE_FREE(pTextureBatch->Vertexs);
	SAFE_FREE(pTextureBatch->Normals);
	SAFE_FREE(pTextureBatch->Colors);
	SAFE_FREE(pTextureBatch->TexCoords);
	SAFE_FREE(pTextureBatch->Indices);

	pTextureBatch->Vertexs = (float*)malloc(3*vertexCount* sizeof(float));
	pTextureBatch->Normals = (float*)malloc(3*vertexCount* sizeof(float));
	pTextureBatch->Colors = (float*)malloc(3*vertexCount* sizeof(float));
	pTextureBatch->TexCoords = (float*)malloc(3*vertexCount* sizeof(float));
	pTextureBatch->Indices = (int*)malloc(indexCount* sizeof(int));

	// 顶点
	memcpy(pTextureBatch->Vertexs, positions, vertexCount* sizeof(float));
	// 法线
	memcpy(pTextureBatch->Normals, normals, vertexCount* sizeof(float));
	// 法线
	memcpy(pTextureBatch->Colors, colors, vertexCount* sizeof(float));
	// 纹理坐标
	memcpy(pTextureBatch->TexCoords, coords, vertexCount* sizeof(float));
	// 顶点顺序
	memcpy(pTextureBatch->Indices, indices, indexCount* sizeof(int));
	*/

	return pTextureBatch;
}
