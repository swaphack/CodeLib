#pragma once

#include "Common/Node/Node.h"
#include "DrawProtocol.h"
#include "Common/Shader/ShaderProgramDelegate.h"
#include "macros.h"

namespace render
{
	class Materials;
	class Meshes;
	class Material;
	class Mesh;
	class FragmentOperator;
	class ShaderProgram;
	class Texture;
	class DrawTextureCache;
	struct DrawParameter;

	/**
	*	多网格节点
	*/
	class MultiDrawNode : 
		public Node,
		public ColorProtocol
	{

	public:
		MultiDrawNode();
		virtual ~MultiDrawNode();
	public:
		virtual bool init();
		virtual void draw();
	public:
		/**
		*	材质
		*/
		Materials* getMaterials() const;
		/**
		*	网格
		*/
		Meshes* getMeshes() const;
		/**
		*	片元处理
		*/
		FragmentOperator* getFragOperator() const;
		/**
		*	获取纹理缓存
		*/
		DrawTextureCache* getDrawTextureCache() const;
		/**
		*	获取绘制参数
		*/
		DrawParameter* getDrawParameter(const std::string& meshName);
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
		*	设置Bump纹理
		*/
		void setBumpTexture(const std::string& fullpath);
		/**
		*	设置Normal纹理
		*/
		void setNormalTexture(const std::string& fullpath);
		/**
		*	设置Shadow纹理
		*/
		void setShadowTexture(const Texture* texture);
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
		virtual void updateMeshData();
		/**
		*	初始化渲染参数
		*/
		void initDrawParameters();
	protected:
		virtual void onColorChange();

		void onDrawNodeColorChange();
	protected:
		// 材质
		Materials* _materiales = nullptr;
		// 网格
		Meshes* _meshes = nullptr;
		// 片元处理
		FragmentOperator* _fragOperator = nullptr;
		// 纹理缓存
		DrawTextureCache* _textureCache = nullptr;
		// 绘制参数
		std::map<std::string, DrawParameter> _drawParameters;
	};
}