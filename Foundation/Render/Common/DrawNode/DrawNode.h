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
	*	���ƽڵ�
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
		void setTexture(const Texture* texture);
		/**
		*	��������
		*/
		void setTexture(const std::string& fullpath);
		/**
		*	�������
		*/
		void addMaterialTexture(const std::string& matName, const std::string& fullpath);
		/**
		*	�������
		*/
		void addMaterialTexture(const std::string& matName, const Texture* texture);
		/**
		*	��������
		*/
		void setTextureName(const std::string& textureName);
		/**
		*	����Ambient����
		*/
		void setAmbientTextureName(const std::string& textureName);
		/**
		*	����Diffuse����
		*/
		void setDiffuseTextureName(const std::string& textureName);
		/**
		*	����Diffuse����
		*/
		void setSpecularTextureName(const std::string& textureName);
		/**
		*	����Alpha����
		*/
		void setAlphaTextureName(const std::string& textureName);
		/**
		*	����Alpha����
		*/
		void setBumpTextureName(const std::string& textureName);
	public:
		/**
		*	��ȡ��ɫ��
		*/
		ShaderProgram* getMaterialShaderProgram(const std::string& matName);
		/**
		*	������ɫ��
		*/
		void setShaderProgram(ShaderProgram* program);
	public:
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
		virtual void initBufferObject();
		virtual void updateBufferData();
	protected:
		// ����
		Materials* _materiales = nullptr;
		// ����
		Meshes* _meshes = nullptr;
		// ƬԪ����
		FragmentOperator* _fragOperator = nullptr;
	};
}