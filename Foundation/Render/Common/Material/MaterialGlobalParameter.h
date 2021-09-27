#pragma once

#include "macros.h"
#include "mathlib.h"
#include <string>
#include <map>
#include "macros.h"
namespace render
{
	/**
	*	统一着色器应用
	*/
	class MaterialGlobalParameter
	{
	public:
		MaterialGlobalParameter();
		virtual ~MaterialGlobalParameter();
	public:
		void init();
	public:
		/**
		*	添加Attrib shader in字段
		*/
		void addVertexData(VertexDataType vat, const std::string& name);
		/**
		*	添加Attrib索引
		*/
		std::string getVertexName(VertexDataType vat) const;
		/**
		*	移除所有Attrib
		*/
		void removeVertexDatas();
		/**
		*	所有Attrib
		*/
		const std::map<VertexDataType, std::string>& getVertexDataTypes() const;
	public:
		/**
		*	添加Uniform shader字段
		*/
		void addUniform(EnvUniformType vut, const std::string& name);
		std::string getUniformName(EnvUniformType vut) const;
		/**
		*	添加Uniform shader字段
		*/
		void addUniform(MatrixUniformType vut, const std::string& name);
		std::string getUniformName(MatrixUniformType vut) const;
		/**
		*	添加Uniform shader字段
		*/
		void addUniform(TextureUniformType vut, const std::string& name);
		std::string getUniformName(TextureUniformType vut) const;
		/**
		*	添加Uniform shader字段
		*/
		void addUniform(MaterialUniformType vut, const std::string& name);
		std::string getUniformName(MaterialUniformType vut) const;
		/**
		*	添加Uniform shader字段
		*/
		void addUniform(SingleLightUniformType vut, const std::string& name);
		std::string getUniformName(SingleLightUniformType vut) const;
		/**
		*	添加Uniform shader字段
		*/
		void addUniform(MultiLightsUniformType vut, const std::string& name);
		std::string getUniformName(MultiLightsUniformType vut) const;
		/**
		*	移除所有Attrib
		*/
		void removeUniformDatas();
		/**
		*	环境
		*/
		const std::map<EnvUniformType, std::string>& getEnvUniforms() const;
		/**
		*	矩阵
		*/
		const std::map<MatrixUniformType, std::string>& getMatrixUniforms() const;
		/**
		*	纹理
		*/
		const std::map<TextureUniformType, std::string>& getTextureUniforms() const;
		/**
		*	材质
		*/
		const std::map<MaterialUniformType, std::string>& getMaterialUniforms() const;
		/**
		*	单光源
		*/
		const std::map<SingleLightUniformType, std::string>& getSingleLightUniforms() const;
		/**
		*	多光源
		*/
		const std::map<MultiLightsUniformType, std::string>& getMultiLightsUniforms() const;
	protected:
		/**
		*	vertex
		*/
		std::map<VertexDataType, std::string> _vertexAttribIndices;
		/**
		*	环境
		*/
		std::map<EnvUniformType, std::string> _mapEnvUniforms;
		/**
		*	矩阵
		*/
		std::map<MatrixUniformType, std::string> _mapMatrixUniforms;
		/**
		*	纹理
		*/
		std::map<TextureUniformType, std::string> _mapTextureUniforms;
		/**
		*	材质
		*/
		std::map<MaterialUniformType, std::string> _mapMaterialUniforms;
		/**
		*	单光源
		*/
		std::map<SingleLightUniformType, std::string> _mapSingleLightUniforms;
		/**
		*	多光源
		*/
		std::map<MultiLightsUniformType, std::string> _mapMultiLightsUniforms;
	};

#define G_MATERIALGLOBALPARAMETER sys::Instance<render::MaterialGlobalParameter>::getInstance()
}
