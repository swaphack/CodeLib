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
	*	材质
	*/
	class Materials : public sys::Object
	{
	
	public:
		Materials();
		virtual ~Materials();
	public:
		/**
		*	节点
		*/
		void setNode(Node* node);
		/**
		*	节点
		*/
		Node* getNode();
	public:
		/**
		*	模型数据
		*/
		void setModelDetail(const sys::ModelDetail* modelDetail);
	public:
		/**
		*	设置模型材质
		*/
		void addMaterial(const std::string& name, sys::MaterialDetail* material);
		/**
		*	移除模型材质
		*/
		void removeMaterial(const std::string& name);
		/**
		*	移除所有模型材质
		*/
		void removeAllMaterials();
		/**
		*	获取模型材质
		*/
		Material* getMaterial(const std::string& name);
		/**
		*	获取模型材质
		*/
		const std::map<std::string, Material*>& getMaterials() const;
		/**
		*	统计模型材质数量
		*/
		int getMaterialCount() const;
	public:
		/**
		*	设置纹理
		*/
		void setMaterialTexture(const std::string& matName, const std::string& textureName);
		/**
		*	设置着色器
		*/
		void setMaterialShaderProgram(const std::string& matName, ShaderProgram* program);
		/**
		*	设置着色器处理函数
		*/
		void setMaterialShaderProgramFunc(const std::string& matName, const ShaderProgramFunc& func);

	private:
		// 模型材质
		std::map<std::string, Material*> _materials;
		// 节点
		Node* _node = nullptr;
	};
}