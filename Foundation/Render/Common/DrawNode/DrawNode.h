#pragma once

#include "Common/Node/Node.h"
#include "Common/Shader/ShaderProgramDelegate.h"

namespace render
{
	class Materials;
	class Meshes;
	class Material;
	class Mesh;
	class FragmentOperator;
	class ShaderProgram;
	class Texture;


#define DRAW_MATERIAL_INDEX "0"
#define DRAW_MESH_INDEX "0"


#define MAT_TEXTURE_NAME "MAT_TEXTURE_NAME"
#define MAT_TEXTURE_AMBIENT "MAT_TEXTURE_AMBIENT"
#define MAT_TEXTURE_DIFFUSE "MAT_TEXTURE_DIFFUSE"
#define MAT_TEXTURE_SPECULAR "MAT_TEXTURE_SPECULAR"
#define MAT_TEXTURE_ALPHA "MAT_TEXTURE_ALPHA"
#define MAT_TEXTURE_BUMP "MAT_TEXTURE_BUMP"

	/**
	*	绘制节点
	*/
	class DrawNode : public Node
	{
	public:
		DrawNode();
		virtual ~DrawNode();
	public:
		virtual bool init();
		virtual void draw();
	public:
		/** 
		*	材质
		*/
		Materials* getMaterials();
		/**
		*	网格
		*/
		Meshes* getMeshes();
		/**
		*	片元处理
		*/
		FragmentOperator* getFragOperator();
	public:
		/**
		*	材质
		*/
		Material* getMaterial(const std::string& name = DRAW_MATERIAL_INDEX);
		/**
		*	网格
		*/
		Mesh* getMesh(const std::string& name = DRAW_MESH_INDEX);
	public:
		/**
		*	设置纹理
		*/
		void setTexture(const std::string& name, const std::string& fullpath);
		/**
		*	设置纹理
		*/
		void setTexture(const std::string& name, const Texture* texture);
		/**
		*	设置纹理
		*/
		void setTexture(const std::string& fullpath);
		/**
		*	设置纹理
		*/
		void setTexture(const Texture* texture);
		/**
		*	设置Ambient纹理
		*/
		void setAmbientTexture(const std::string& fullpath);
		/**
		*	设置Diffuse纹理
		*/
		void setDiffuseTexture(const std::string& fullpath);
		/**
		*	设置Diffuse纹理
		*/
		void setSpecularTexture(const std::string& fullpath);
		/**
		*	设置Alpha纹理
		*/
		void setAlphaTexture(const std::string& fullpath);
		/**
		*	设置Alpha纹理
		*/
		void setBumpTexture(const std::string& fullpath);
	public:
		/**
		*	设置着色器
		*/
		void setShaderProgram(ShaderProgram* program);
		/**
		*	设置着色器处理函数
		*/
		void setShaderProgramFunc(const ShaderProgramFunc& func);
	protected:
		/**
		*	绘制前工作
		*/
		virtual void beforeDraw();
		/**
		*	绘制
		*/
		virtual void onDraw();
		/**
		*	绘制后工作
		*/
		virtual void afterDraw();
	protected:
		/**
		*	初始化缓存对象
		*/
		virtual void initBufferObject();
		/**
		*	更新mesh数据
		*/
		virtual void updateBufferData();
	protected:
		// 材质
		Materials* _materiales = nullptr;
		// 网格
		Meshes* _meshes = nullptr;
		// 片元处理
		FragmentOperator* _fragOperator = nullptr;
	};
}