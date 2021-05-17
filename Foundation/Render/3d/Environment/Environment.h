#pragma once

#include "system.h"
#include <map>
#include "Graphic/GLAPI/macros.h"
namespace render
{
	class ShaderProgram;
	class Light;

	// ��Ӱ��ɫ��
	struct ShadowShader
	{
		// ��¼��Ӱ��ɫ��
		ShaderProgram* castShaderProgram = nullptr;
		// ������ɫ��
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
		*	��ӹ�Դ
		*/ 
		void addLight(Light* light);
		/**
		*	�Ƴ���Դ
		*/ 
		void removeLight(Light* light);
		/**
		*	��ȡ��Դ
		*/ 
		Light* getLight(int index) const;
		/**
		*	��ȡ���й�Դ
		*/
		const std::map<int, Light*>& getAllLights() const;
		/**
		*	�Ƿ��й�Դ
		*/
		bool hasLight() const;
	public:
		/**
		*	gamma ֵ
		*/
		void setGamma(float value);
		/**
		*	gamma ֵ
		*/
		float getGamma() const;
	public:
		/**
		*	��Ӳ�����Ӱ�ڵ�
		*/
		void addCastShadowNode(Node* node);
		/**
		*	�Ƴ�������Ӱ�ڵ�
		*/
		void removeCastShadowNode(Node* node);
		/**
		*	��ӽ�����Ӱ�ڵ�
		*/
		void addRecieveShadowNode(Node* node);
		/**
		*	�Ƴ�������Ӱ�ڵ�
		*/
		void removeRecieveShadowNode(Node* node);
	public:
		/**
		*	ͶӰ��Ӱ��ɫ��
		*/
		void setCastShaderProgram(ShaderProgram* program);
		/**
		*	������Ӱ��ɫ��
		*/
		void setReceiveLightShaderProgram(ShaderProgram* program);
		/**
		*	������ɫ��
		*/
		void setRenderShaderProgram(ShaderProgram* program);
	private:
		// ��Դ
		std::map<int, Light*> _lights;
		// gamma ֵ
		float _gamma = 2.2f;
		// ������Ӱ�ڵ�
		std::set<Node*> _castShadowNodes;
		// ������Ӱ�ڵ�
		std::set<Node*> _recieveShadowNodes;
		// ��Ӱ��ɫ��
		ShadowShader _shadowShader;
	};

#define G_ENVIRONMENT sys::Instance<render::Environment>::getInstance()
}
