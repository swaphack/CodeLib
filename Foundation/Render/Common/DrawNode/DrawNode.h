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
	*	���ƽڵ�
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
		*	ƬԪ����
		*/
		FragmentOperator* getFragOperator();
		/**
		*	����
		*/
		Material* getMaterial();
		/**
		*	����
		*/
		Mesh* getMesh();
	public:
		/**
		*	��������
		*/
		void setTexture(const std::string& fullpath);
		/**
		*	��������
		*/
		void setTexture(const Texture* texture);
		/**
		*	����Ambient����
		*/
		void setAmbientTexture(const std::string& fullpath);
		/**
		*	����Diffuse����
		*/
		void setDiffuseTexture(const std::string& fullpath);
		/**
		*	����Diffuse����
		*/
		void setSpecularTexture(const std::string& fullpath);
		/**
		*	����Alpha����
		*/
		void setAlphaTexture(const std::string& fullpath);
		/**
		*	����Alpha����
		*/
		void setBumpTexture(const std::string& fullpath);
		/**
		*	��ȡ����
		*/
		const Texture* getTexture() const;
		/**
		*	��ȡ����
		*/
		const Texture* getTexture(const std::string& name) const;
	public:
		/**
		*	������ɫ��
		*/
		void setShaderProgram(ShaderProgram* program);
		/**
		*	������ɫ��������
		*/
		void setShaderProgramFunc(const ShaderProgramFunc& func);
	protected:
		/**
		*	����ǰ����
		*/
		virtual void beforeDraw();
		/**
		*	����
		*/
		virtual void onDraw();
		/**
		*	���ƺ���
		*/
		virtual void afterDraw();
	protected:
		/**
		*	��ʼ���������
		*/
		virtual void initBufferObject();
		/**
		*	����mesh����
		*/
		virtual void updateBufferData();
	protected:
		virtual void onColorChange();
	protected:
		// ����
		Material* _material = nullptr;
		// ����
		Mesh* _mesh = nullptr;
		// ƬԪ����
		FragmentOperator* _fragOperator = nullptr;
		// ������
		DrawTextureCache* _textureCache = nullptr;
	};
}