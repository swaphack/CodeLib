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
	SHOW_OPENGL_ERROR_MESSAGE();
	glEnable(GL_DEPTH_TEST);
	SHOW_OPENGL_ERROR_MESSAGE();
	glEnable(GL_BLEND);
	SHOW_OPENGL_ERROR_MESSAGE();
	glBlendFunc(Blend.src, Blend.dest);
	SHOW_OPENGL_ERROR_MESSAGE();
	glColor4f(Color.red, Color.green, Color.blue, Color.alpha);

	SHOW_OPENGL_ERROR_MESSAGE();

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, TextureID);
	{
		//glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glTexCoordPointer(3, GL_FLOAT, 0, TexCoords);
		SHOW_OPENGL_ERROR_MESSAGE();

		//glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, Vertexes);
		SHOW_OPENGL_ERROR_MESSAGE();

		//glEnableClientState(GL_NORMAL_ARRAY);
		glNormalPointer(3, GL_FLOAT, Normals);
		SHOW_OPENGL_ERROR_MESSAGE();

		// glEnableClientState(GL_COLOR_ARRAY);
		glColorPointer(3, GL_FLOAT, 0, Colors);
		SHOW_OPENGL_ERROR_MESSAGE();

		glDrawElements(GL_TRIANGLES, IndexCount, GL_UNSIGNED_SHORT, Indices);

		//SHOW_OPENGL_ERROR_MESSAGE();
	}
	glDisable(GL_TEXTURE_2D);

	glDisable(GL_BLEND);

	glDisable(GL_DEPTH_TEST);
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

	///*
	pTextureBatch->TexCoords = coords;
	pTextureBatch->Vertexes = positions;
	pTextureBatch->Normals = normals;
	pTextureBatch->Colors = colors;
	pTextureBatch->Indices = indices;

	PRINT("size of indices %d \n", sizeof(*indices));
	PRINT("size of Indices %d \n", sizeof(*pTextureBatch->Indices));
	//*/

	/*
	SAFE_FREE(pTextureBatch->Vertexes);
	SAFE_FREE(pTextureBatch->Normals);
	SAFE_FREE(pTextureBatch->Colors);
	SAFE_FREE(pTextureBatch->TexCoords);
	SAFE_FREE(pTextureBatch->Indices);

	pTextureBatch->Vertexes = (float*)malloc(vertexCount* sizeof(float));
	pTextureBatch->Normals = (float*)malloc(vertexCount* sizeof(float));
	pTextureBatch->Colors = (float*)malloc(vertexCount* sizeof(float));
	pTextureBatch->TexCoords = (float*)malloc(vertexCount* sizeof(float));
	pTextureBatch->Indices = (ushort*)malloc(indexCount* sizeof(ushort));

	memset(pTextureBatch->Vertexes, 0, vertexCount* sizeof(float));
	memset(pTextureBatch->Normals, 0, vertexCount* sizeof(float));
	memset(pTextureBatch->Colors, 0, vertexCount* sizeof(float));
	memset(pTextureBatch->TexCoords, 0, vertexCount* sizeof(float));
	memset(pTextureBatch->Indices, 0, indexCount* sizeof(ushort));

	// 顶点
	memcpy(pTextureBatch->Vertexes, positions, vertexCount* sizeof(float));
	// 法线
	memcpy(pTextureBatch->Normals, normals, vertexCount* sizeof(float));
	// 法线
	memcpy(pTextureBatch->Colors, colors, vertexCount* sizeof(float));
	// 纹理坐标
	memcpy(pTextureBatch->TexCoords, coords, vertexCount* sizeof(float));
	// 顶点顺序
	memcpy(pTextureBatch->Indices, indices, indexCount* sizeof(ushort));
	*/

	return pTextureBatch;
}
