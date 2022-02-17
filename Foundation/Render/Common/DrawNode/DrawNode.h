#pragma once

#include "Common/Node/Node.h"
#include "Common/Shader/ShaderProgramDelegate.h"
#include "DrawProtocol.h"
#include "TessilationProtocol.h"
#include "macros.h"

namespace render
{
	class Material;
	class Mesh;
	class FragmentOperator;
	class ShaderProgram;
	class Texture;
	class DrawTextureCache;
	class Camera;
	struct DrawParameter;

	/**
	*	绘制节点
	*/
	class DrawNode :
		public Node,
		public ColorProtocol,
		public BlendProtocol,
		public TessilationProtocol
	{
	public:
		DrawNode();
		virtual ~DrawNode();
	public:
		virtual bool init();
		virtual void draw();
	public:
		/**
		*	片元处理
		*/
		FragmentOperator* getFragOperator() const;
		/**
		*	材质
		*/
		Material* getMaterial() const;
		/**
		*	网格
		*/
		Mesh* getMesh() const;
		/**
		*	渲染参数
		*/
		DrawParameter* getDrawParameter();
		/**
		*	获取纹理缓存
		*/
		DrawTextureCache* getDrawTextureCache() const;
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
		*	设置normal纹理
		*/
		void setNormalTexture(const std::string& fullpath);
		/**
		*	设置shadow纹理
		*/
		void setShadowTexture(const Texture* texture);
		/**
		*	获取纹理
		*/
		const Texture* getTexture() const;
		/**
		*	获取纹理
		*/
		const Texture* getTexture(const std::string& name) const;
	public:
		/**
		*	设置着色器
		*/
		void setShaderProgram(ShaderProgram* program);
		/**
		*	获取着色器
		*/
		ShaderProgram* getShaderProgram() const;
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
		*	更新缓存数据
		*/
		virtual void updateMeshData();
		/**
		*	初始化渲染参数
		*/
		void initDrawParameter();
		/**
		*	初始化渲染参数
		*/
		void initZOrderDrawParameter();
	protected:
		/**
		*	颜色改变
		*/
		virtual void onColorChange();
		/**
		*	当前节点的颜色改变
		*/
		void onDrawNodeColorChange();
		/**
		*	混合改变
		*/
		virtual void onBlendChange();
	protected:
		// 材质
		Material* _material = nullptr;
		// 网格
		Mesh* _mesh = nullptr;
		// 片元处理
		FragmentOperator* _fragOperator = nullptr;
		// 纹理缓存
		DrawTextureCache* _textureCache = nullptr;
		// 绘制参数
		DrawParameter _drawParameter;
	};
}