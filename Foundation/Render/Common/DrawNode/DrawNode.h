#pragma once

#include "Common/Node/Node.h"
#include "Common/Shader/ShaderProgramDelegate.h"
#include "DrawProtocol.h"

namespace render
{
	class Material;
	class Mesh;
	class FragmentOperator;
	class ShaderProgram;
	class Texture;
	class DrawTextureCache;

	/**
	*	绘制节点
	*/
	class DrawNode : 
		public Node, public ColorProtocol
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
		FragmentOperator* getFragOperator();
		/**
		*	材质
		*/
		Material* getMaterial();
		/**
		*	网格
		*/
		Mesh* getMesh();
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
		*	设置Alpha纹理
		*/
		void setBumpTexture(const std::string& fullpath);
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
		virtual void onColorChange();
	protected:
		// 材质
		Material* _material = nullptr;
		// 网格
		Mesh* _mesh = nullptr;
		// 片元处理
		FragmentOperator* _fragOperator = nullptr;
		// 纹理缓存
		DrawTextureCache* _textureCache = nullptr;
	};
}