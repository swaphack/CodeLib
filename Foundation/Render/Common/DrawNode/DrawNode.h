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
		void setTexture(const Texture* texture);
		/**
		*	设置纹理
		*/
		void setTexture(const std::string& fullpath);
		/**
		*	添加纹理
		*/
		void addMaterialTexture(const std::string& matName, const std::string& fullpath);
		/**
		*	添加纹理
		*/
		void addMaterialTexture(const std::string& matName, const Texture* texture);
		/**
		*	设置纹理
		*/
		void setTextureName(const std::string& textureName);
		/**
		*	设置Ambient纹理
		*/
		void setAmbientTextureName(const std::string& textureName);
		/**
		*	设置Diffuse纹理
		*/
		void setDiffuseTextureName(const std::string& textureName);
		/**
		*	设置Diffuse纹理
		*/
		void setSpecularTextureName(const std::string& textureName);
		/**
		*	设置Alpha纹理
		*/
		void setAlphaTextureName(const std::string& textureName);
		/**
		*	设置Alpha纹理
		*/
		void setBumpTextureName(const std::string& textureName);
	public:
		/**
		*	获取着色器
		*/
		ShaderProgram* getMaterialShaderProgram(const std::string& matName);
		/**
		*	设置着色器
		*/
		void setShaderProgram(ShaderProgram* program);
	public:
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
		virtual void initBufferObject();
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