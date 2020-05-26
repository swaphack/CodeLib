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


#define DRAW_MATERIAL_INDEX 0
#define DRAW_MESH_INDEX 0


#define MAT_TEXTURE_NAME "MAT_TEXTURE_NAME"

	/**
	*	绘制节点
	*/
	class DrawNode :  
		public Node
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
		Material* getMaterial(int id = 0);
		/**
		*	网格
		*/
		Mesh* getMesh(int id = 0);
	public:
		/**
		*	添加纹理
		*/
		void addMaterialTexture(const std::string& name, const std::string& fullpath);
		/**
		*	添加纹理
		*/
		void addMaterialTexture(const std::string& name, Texture* texture);
		/**
		*	设置纹理
		*/
		void setAllMaterialsTexture(const std::string& name);
		/**
		*	设置纹理
		*/
		void setMaterialTexture(int mat, const std::string& name);
	public:
		/**
		*	获取着色器
		*/
		ShaderProgram* getMaterialShaderProgram(int mat);
		/**
		*	设置着色器
		*/
		void setAllMaterialsShaderProgram(ShaderProgram* program);
		/**
		*	设置着色器
		*/
		void setMaterialShaderProgram(int mat, ShaderProgram* program);
	public:
		/**
		*	设置着色器处理函数
		*/
		void setAllShaderProgramFunc(const ShaderProgramFunc& func);
		/**
		*	设置着色器处理函数
		*/
		void setMaterialShaderProgram(int mat, const ShaderProgramFunc& func);
	protected:
		/**
		*	绘制前工作
		*/
		void beforeDraw();
		/**
		*	绘制
		*/
		virtual void onDraw();
		/**
		*	绘制后工作
		*/
		void afterDraw();
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