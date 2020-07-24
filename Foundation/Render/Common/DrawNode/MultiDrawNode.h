#pragma once

#include "Common/Node/Node.h"
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


	/**
	*	���ƽڵ�
	*/
	class MultiDrawNode : public Node
	{

	public:
		MultiDrawNode();
		virtual ~MultiDrawNode();
	public:
		virtual bool init();
		virtual void draw();
	public:
		/**
		*	����
		*/
		Materials* getMaterials();
		/**
		*	����
		*/
		Meshes* getMeshes();
		/**
		*	ƬԪ����
		*/
		FragmentOperator* getFragOperator();
	public:
		/**
		*	����
		*/
		Material* getMaterial(const std::string& name = DRAW_MATERIAL_INDEX);
		/**
		*	����
		*/
		Mesh* getMesh(const std::string& name = DRAW_MESH_INDEX);
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
	public:
		/**
		*	������ɫ��
		*/
		void setShaderProgram(ShaderProgram* program);
		/**
		*	������ɫ����������
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
		// ����
		Materials* _materiales = nullptr;
		// ����
		Meshes* _meshes = nullptr;
		// ƬԪ����
		FragmentOperator* _fragOperator = nullptr;
		// ��������
		DrawTextureCache* _textureCache = nullptr;
	};
}