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
	*	���ƽڵ�
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
		*	ƬԪ����
		*/
		FragmentOperator* getFragOperator() const;
		/**
		*	����
		*/
		Material* getMaterial() const;
		/**
		*	����
		*/
		Mesh* getMesh() const;
		/**
		*	��Ⱦ����
		*/
		DrawParameter* getDrawParameter();
		/**
		*	��ȡ������
		*/
		DrawTextureCache* getDrawTextureCache() const;
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
		*	����Bump����
		*/
		void setBumpTexture(const std::string& fullpath);
		/**
		*	����normal����
		*/
		void setNormalTexture(const std::string& fullpath);
		/**
		*	����shadow����
		*/
		void setShadowTexture(const Texture* texture);
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
		*	��ȡ��ɫ��
		*/
		ShaderProgram* getShaderProgram() const;
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
		*	���»�������
		*/
		virtual void updateMeshData();
		/**
		*	��ʼ����Ⱦ����
		*/
		void initDrawParameter();
		/**
		*	��ʼ����Ⱦ����
		*/
		void initZOrderDrawParameter();
	protected:
		/**
		*	��ɫ�ı�
		*/
		virtual void onColorChange();
		/**
		*	��ǰ�ڵ����ɫ�ı�
		*/
		void onDrawNodeColorChange();
		/**
		*	��ϸı�
		*/
		virtual void onBlendChange();
	protected:
		// ����
		Material* _material = nullptr;
		// ����
		Mesh* _mesh = nullptr;
		// ƬԪ����
		FragmentOperator* _fragOperator = nullptr;
		// ������
		DrawTextureCache* _textureCache = nullptr;
		// ���Ʋ���
		DrawParameter _drawParameter;
	};
}