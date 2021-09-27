#pragma once

#include "macros.h"
#include "mathlib.h"
#include <string>
#include <map>
#include "macros.h"
namespace render
{
	/**
	*	ͳһ��ɫ��Ӧ��
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
		*	���Attrib shader in�ֶ�
		*/
		void addVertexData(VertexDataType vat, const std::string& name);
		/**
		*	���Attrib����
		*/
		std::string getVertexName(VertexDataType vat) const;
		/**
		*	�Ƴ�����Attrib
		*/
		void removeVertexDatas();
		/**
		*	����Attrib
		*/
		const std::map<VertexDataType, std::string>& getVertexDataTypes() const;
	public:
		/**
		*	���Uniform shader�ֶ�
		*/
		void addUniform(EnvUniformType vut, const std::string& name);
		std::string getUniformName(EnvUniformType vut) const;
		/**
		*	���Uniform shader�ֶ�
		*/
		void addUniform(MatrixUniformType vut, const std::string& name);
		std::string getUniformName(MatrixUniformType vut) const;
		/**
		*	���Uniform shader�ֶ�
		*/
		void addUniform(TextureUniformType vut, const std::string& name);
		std::string getUniformName(TextureUniformType vut) const;
		/**
		*	���Uniform shader�ֶ�
		*/
		void addUniform(MaterialUniformType vut, const std::string& name);
		std::string getUniformName(MaterialUniformType vut) const;
		/**
		*	���Uniform shader�ֶ�
		*/
		void addUniform(SingleLightUniformType vut, const std::string& name);
		std::string getUniformName(SingleLightUniformType vut) const;
		/**
		*	���Uniform shader�ֶ�
		*/
		void addUniform(MultiLightsUniformType vut, const std::string& name);
		std::string getUniformName(MultiLightsUniformType vut) const;
		/**
		*	�Ƴ�����Attrib
		*/
		void removeUniformDatas();
		/**
		*	����
		*/
		const std::map<EnvUniformType, std::string>& getEnvUniforms() const;
		/**
		*	����
		*/
		const std::map<MatrixUniformType, std::string>& getMatrixUniforms() const;
		/**
		*	����
		*/
		const std::map<TextureUniformType, std::string>& getTextureUniforms() const;
		/**
		*	����
		*/
		const std::map<MaterialUniformType, std::string>& getMaterialUniforms() const;
		/**
		*	����Դ
		*/
		const std::map<SingleLightUniformType, std::string>& getSingleLightUniforms() const;
		/**
		*	���Դ
		*/
		const std::map<MultiLightsUniformType, std::string>& getMultiLightsUniforms() const;
	protected:
		/**
		*	vertex
		*/
		std::map<VertexDataType, std::string> _vertexAttribIndices;
		/**
		*	����
		*/
		std::map<EnvUniformType, std::string> _mapEnvUniforms;
		/**
		*	����
		*/
		std::map<MatrixUniformType, std::string> _mapMatrixUniforms;
		/**
		*	����
		*/
		std::map<TextureUniformType, std::string> _mapTextureUniforms;
		/**
		*	����
		*/
		std::map<MaterialUniformType, std::string> _mapMaterialUniforms;
		/**
		*	����Դ
		*/
		std::map<SingleLightUniformType, std::string> _mapSingleLightUniforms;
		/**
		*	���Դ
		*/
		std::map<MultiLightsUniformType, std::string> _mapMultiLightsUniforms;
	};

#define G_MATERIALGLOBALPARAMETER sys::Instance<render::MaterialGlobalParameter>::getInstance()
}
