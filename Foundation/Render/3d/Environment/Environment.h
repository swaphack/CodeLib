#pragma once

#include "system.h"
#include <map>
#include "Graphic/GLAPI/macros.h"
namespace render
{
	class ShaderProgram;
	class Light;

	// 阴影着色器
	struct ShadowShader
	{
		// 记录阴影着色器
		ShaderProgram* castShaderProgram = nullptr;
		// 绘制着色器
		ShaderProgram* renderShaderProgram = nullptr;

		ShadowShader() 
		{}

		~ShadowShader()
		{
			SAFE_RELEASE(castShaderProgram);
			SAFE_RELEASE(renderShaderProgram);
		}
	};

	class Environment : public sys::Object
	{
	public:
		Environment();
		virtual ~Environment();
	public:
		/**
		*	添加光源
		*/ 
		void addLight(Light* light);
		/**
		*	移除光源
		*/ 
		void removeLight(Light* light);
		/**
		*	获取光源
		*/ 
		Light* getLight(int index) const;
		/**
		*	获取所有光源
		*/
		const std::map<int, Light*>& getAllLights() const;
		/**
		*	是否有光源
		*/
		bool hasLight() const;
	public:
		/**
		*	gamma 值
		*/
		void setGamma(float value);
		/**
		*	gamma 值
		*/
		float getGamma() const;
	public:
		/**
		*	添加产生阴影节点
		*/
		void addCastShadowNode(Node* node);
		/**
		*	移除产生阴影节点
		*/
		void removeCastShadowNode(Node* node);
		/**
		*	添加接收阴影节点
		*/
		void addRecieveShadowNode(Node* node);
		/**
		*	移除接收阴影节点
		*/
		void removeRecieveShadowNode(Node* node);
	public:
		/**
		*	投影阴影着色器
		*/
		void setCastShaderProgram(ShaderProgram* program);
		/**
		*	接受阴影着色器
		*/
		void setReceiveLightShaderProgram(ShaderProgram* program);
		/**
		*	绘制着色器
		*/
		void setRenderShaderProgram(ShaderProgram* program);
	private:
		// 光源
		std::map<int, Light*> _lights;
		// gamma 值
		float _gamma = 2.2f;
		// 产生阴影节点
		std::set<Node*> _castShadowNodes;
		// 接收阴影节点
		std::set<Node*> _recieveShadowNodes;
		// 阴影着色器
		ShadowShader _shadowShader;
	};

#define G_ENVIRONMENT sys::Instance<render::Environment>::getInstance()
}
