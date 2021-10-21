#pragma once

namespace sys
{
	class MeshDetail;
}

namespace render
{
#define DRAW_MATERIAL_INDEX "0"
#define DRAW_MESH_INDEX "0"

#define MAT_TEXTURE_NAME "MAT_TEXTURE_NAME"
#define MAT_TEXTURE_AMBIENT "MAT_TEXTURE_AMBIENT"
#define MAT_TEXTURE_DIFFUSE "MAT_TEXTURE_DIFFUSE"
#define MAT_TEXTURE_SPECULAR "MAT_TEXTURE_SPECULAR"
#define MAT_TEXTURE_ALPHA "MAT_TEXTURE_ALPHA"
#define MAT_TEXTURE_BUMP "MAT_TEXTURE_BUMP"
#define MAT_TEXTURE_NORMAL "MAT_TEXTURE_NORMAL"
#define MAT_TEXTURE_SHADOW "MAT_TEXTURE_SHADOW"

	class Node;
	class DrawTextureCache;
	class Mesh;
	class ShaderProgram;
	class Material;

	/**
	*	绘制参数
	*/
	struct DrawParameter
	{
		Node* node = nullptr;
		Mesh* mesh = nullptr;
		Material* material = nullptr;
		DrawTextureCache* textureCache = nullptr;
		// 是否细分
		bool tessilation = false;
		math::Matrix4x4 matrix;

		// 额外数据
		void* data = nullptr;
	};
}