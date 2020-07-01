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
#define MAT_TEXTURE_AMBIENT "MAT_TEXTURE_AMBIENT"
#define MAT_TEXTURE_DIFFUSE "MAT_TEXTURE_DIFFUSE"
#define MAT_TEXTURE_SPECULAR "MAT_TEXTURE_SPECULAR"
#define MAT_TEXTURE_ALPHA "MAT_TEXTURE_ALPHA"
#define MAT_TEXTURE_BUMP "MAT_TEXTURE_BUMP"

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
		void setTexture(const std::string& name, const std::string& fullpath);
		/**
		*	��������
		*/
		void setTexture(const std::string& name, const Texture* texture);
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
		// ����
		Materials* _materiales = nullptr;
		// ����
		Meshes* _meshes = nullptr;
		// ƬԪ����
		FragmentOperator* _fragOperator = nullptr;
	};
}