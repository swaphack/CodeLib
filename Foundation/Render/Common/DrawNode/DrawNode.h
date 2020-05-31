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
		void setAllMaterialsTexture(const std::string& textureName);
		/**
		*	��������
		*/
		void setMaterialTexture(const std::string& matName, const std::string& textureName);
	public:
		/**
		*	��ȡ��ɫ��
		*/
		ShaderProgram* getMaterialShaderProgram(const std::string& matName);
		/**
		*	������ɫ��
		*/
		void setAllMaterialsShaderProgram(ShaderProgram* program);
		/**
		*	������ɫ��
		*/
		void setMaterialShaderProgram(const std::string& matName, ShaderProgram* program);
	public:
		/**
		*	������ɫ��������
		*/
		void setAllShaderProgramFunc(const ShaderProgramFunc& func);
		/**
		*	������ɫ��������
		*/
		void setMaterialShaderProgram(const std::string& matName, const ShaderProgramFunc& func);
	protected:
		/**
		*	����ǰ����
		*/
		void beforeDraw();
		/**
		*	����
		*/
		virtual void onDraw();
		/**
		*	���ƺ���
		*/
		void afterDraw();
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