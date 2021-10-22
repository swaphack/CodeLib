#pragma once

#include "system.h"
#include "mathlib.h"
#include "Common/Shader/ShaderProgramDelegate.h"

namespace sys
{
	class MeshDetail;
	class ModelDetail;
	class MaterialDetail;
}

namespace render
{
	class ShaderProgram;
	class VertexArrayObject;
	class Texture;
	class Node;
	class Material;

	/**
	*	����
	*/
	class Materials : public sys::Object
	{
	
	public:
		Materials();
		virtual ~Materials();
	public:
		/**
		*	�ڵ�
		*/
		void setNode(Node* node);
		/**
		*	�ڵ�
		*/
		Node* getNode();
	public:
		/**
		*	ģ������
		*/
		void setModelDetail(const sys::ModelDetail* modelDetail);
	public:
		/**
		*	����ģ�Ͳ���
		*/
		void addMaterial(const std::string& name, sys::MaterialDetail* material);
		/**
		*	�Ƴ�ģ�Ͳ���
		*/
		void removeMaterial(const std::string& name);
		/**
		*	�Ƴ�����ģ�Ͳ���
		*/
		void removeAllMaterials();
		/**
		*	��ȡģ�Ͳ���
		*/
		Material* getMaterial(const std::string& name);
		/**
		*	��ȡģ�Ͳ���
		*/
		const std::map<std::string, Material*>& getMaterials() const;
		/**
		*	ͳ��ģ�Ͳ�������
		*/
		int getMaterialCount() const;
	public:
		/**
		*	��������
		*/
		void setMaterialTexture(const std::string& matName, const std::string& textureName);
		/**
		*	������ɫ��
		*/
		void setMaterialShaderProgram(const std::string& matName, ShaderProgram* program);
		/**
		*	������ɫ��������
		*/
		void setMaterialShaderProgramFunc(const std::string& matName, const ShaderProgramFunc& func);

	private:
		// ģ�Ͳ���
		std::map<std::string, Material*> _materials;
		// �ڵ�
		Node* _node = nullptr;
	};
}