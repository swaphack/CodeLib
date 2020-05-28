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


#define DRAW_MATERIAL_INDEX 0
#define DRAW_MESH_INDEX 0


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
		Material* getMaterial(int id = 0);
		/**
		*	����
		*/
		Mesh* getMesh(int id = 0);
	public:
		/**
		*	�������
		*/
		void addMaterialTexture(const std::string& name, const std::string& fullpath);
		/**
		*	�������
		*/
		void addMaterialTexture(const std::string& name, const Texture* texture);
		/**
		*	��������
		*/
		void setAllMaterialsTexture(const std::string& name);
		/**
		*	��������
		*/
		void setMaterialTexture(int mat, const std::string& name);
	public:
		/**
		*	��ȡ��ɫ��
		*/
		ShaderProgram* getMaterialShaderProgram(int mat);
		/**
		*	������ɫ��
		*/
		void setAllMaterialsShaderProgram(ShaderProgram* program);
		/**
		*	������ɫ��
		*/
		void setMaterialShaderProgram(int mat, ShaderProgram* program);
	public:
		/**
		*	������ɫ��������
		*/
		void setAllShaderProgramFunc(const ShaderProgramFunc& func);
		/**
		*	������ɫ��������
		*/
		void setMaterialShaderProgram(int mat, const ShaderProgramFunc& func);
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