#pragma once

#include <map>
#include <string>

namespace render
{
	class ShaderProgram;
	// 着色器属性
	class ShaderProperty
	{
	public:
		ShaderProperty();
		~ShaderProperty();
	public:
		void initShaderProgram(ShaderProgram* program);

		void removeAllUniforms();
	public:
		inline const std::map<uint8_t, std::string>& getEnvUniforms() const { return _mapEnvUniforms; }
		inline const std::map<uint8_t, std::string>& getMatrixUniforms() const { return _mapMatrixUniforms; }
		inline const std::map<uint8_t, std::string>& getTextureUniforms() const { return _mapTextureUniforms; }
		inline const std::map<uint8_t, std::string>& getMaterialUniforms() const { return _mapMaterialUniforms; }
		inline const std::map<uint8_t, std::string>& getSingleLightUniforms() const { return _mapSingleLightUniforms; }
		inline const std::map<uint8_t, std::string>& getMultiLightsUniforms() const { return _mapMultiLightsUniforms; }
		inline const std::map<uint8_t, std::string>& getAttribs() const { return _mapAttribs; }
	private:
		ShaderProgram* _shaderProgram = nullptr;
		// 默认参数
		std::map<uint8_t, std::string> _mapEnvUniforms;
		std::map<uint8_t, std::string> _mapMatrixUniforms;
		std::map<uint8_t, std::string> _mapTextureUniforms;
		std::map<uint8_t, std::string> _mapMaterialUniforms;
		std::map<uint8_t, std::string> _mapSingleLightUniforms;
		std::map<uint8_t, std::string> _mapMultiLightsUniforms;
		std::map<uint8_t, std::string> _mapAttribs;
	};
}