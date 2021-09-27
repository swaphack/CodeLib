#pragma once

#include "system.h"
#include "mathlib.h"
#include "macros.h"

namespace render
{
	class ShaderProgram;

	/**
	*	材质设定
	*/
	class MaterialSetting : public sys::Object
	{
	public:
		enum class UniformType
		{
			Integer,
			Float,
			Vec2,
			Vec3,
			Vec4,
			Mat2x2,
			Mat3x3,
			Mat4x4,
		};



#define CONSTRUCT_VALUE_TYPE(UT, T) \
UniformParameter(const std::string& name, T value) \
{\
Type = UT; \
Name = name; \
Data = (T*)malloc(sizeof(T)); \
memcpy(Data, &value, sizeof(T));\
}

#define CONSTRUCT_FLOAT_ARRAY_TYPE(UT, T) \
UniformParameter(const std::string& name, const T& value) \
{\
Type = UT; \
Name = name; \
Data = (float*)malloc(value.getSize());\
memcpy(Data, value.getValue(), value.getSize());\
}

#define AS_VALUE_TYPE(T, Func, UT, DefaultValue) \
T as##Func() \
{\
if (Data == nullptr || UT != Type ) {\
	return DefaultValue;\
}else {\
	return *((T*)Data); \
} \
}

#define AS_FLOAT_ARRAY_TYPE(T,Func, UT, DefaultValue) \
T as##Func() \
{\
if (Data == nullptr || UT != Type ) {\
	return DefaultValue;\
}else {\
	return T((float*)Data); \
} \
}

		struct UniformParameter
		{

		public:
			std::string Name;
			UniformType Type = UniformType::Integer;
			void* Data = nullptr;
		public:
			UniformParameter() {}
			UniformParameter(const std::string& name, UniformType type, void* value) 
			{
				Name = name;
				Type = type;
				Data = value;
			}

			CONSTRUCT_VALUE_TYPE(UniformType::Integer, int);
			CONSTRUCT_VALUE_TYPE(UniformType::Float, float);
			CONSTRUCT_FLOAT_ARRAY_TYPE(UniformType::Vec2, math::Vector2);
			CONSTRUCT_FLOAT_ARRAY_TYPE(UniformType::Vec3, math::Vector3);
			CONSTRUCT_FLOAT_ARRAY_TYPE(UniformType::Vec4, math::Vector4);

			CONSTRUCT_FLOAT_ARRAY_TYPE(UniformType::Mat2x2, math::Matrix2x2);
			CONSTRUCT_FLOAT_ARRAY_TYPE(UniformType::Mat3x3, math::Matrix3x3);
			CONSTRUCT_FLOAT_ARRAY_TYPE(UniformType::Mat4x4, math::Matrix4x4);

			AS_VALUE_TYPE(int, Int, UniformType::Integer, 0);
			AS_VALUE_TYPE(float, Float, UniformType::Float, 0);
			AS_FLOAT_ARRAY_TYPE(math::Vector2, Vector2, UniformType::Vec2, math::Vector2());
			AS_FLOAT_ARRAY_TYPE(math::Vector3, Vector3, UniformType::Vec3, math::Vector3());
			AS_FLOAT_ARRAY_TYPE(math::Vector4, Vector4, UniformType::Vec4, math::Vector4());
			AS_FLOAT_ARRAY_TYPE(math::Matrix2x2, Matrix2x2, UniformType::Mat2x2, math::Matrix2x2());
			AS_FLOAT_ARRAY_TYPE(math::Matrix3x3, Matrix3x3, UniformType::Mat3x3, math::Matrix3x3());
			AS_FLOAT_ARRAY_TYPE(math::Matrix4x4, Matrix4x4, UniformType::Mat4x4, math::Matrix4x4());

			~UniformParameter()
			{
				cleanup();
			}
			void cleanup()
			{
				SAFE_FREE(Data);
			}
		};
	public:
		MaterialSetting();
		virtual ~MaterialSetting();
	public:
		// 设置shaderprogram
		void setShaderProgram(ShaderProgram* shaderProgram);
		void removeAllUniforms(bool bContainSelfDefined = false);
		// 添加自定义uniform
		void addSelfDefineUniform(const std::string& name, UniformType type, void* value);
		void removeAllSelfDefineUniforms();
	public:
		inline const std::map<EnvUniformType, std::string>& getEnvUniforms() const { return _mapEnvUniforms; }
		inline const std::map<MatrixUniformType, std::string>& getMatrixUniforms() const { return _mapMatrixUniforms; }
		inline const std::map<TextureUniformType, std::string>& getTextureUniforms() const { return _mapTextureUniforms; }
		inline const std::map<MaterialUniformType, std::string>& getMaterialUniforms() const { return _mapMaterialUniforms; }
		inline const std::map<SingleLightUniformType, std::string>& getSingleLightUniforms() const { return _mapSingleLightUniforms; }
		inline const std::map<MultiLightsUniformType, std::string>& getMultiLightsUniforms() const { return _mapMultiLightsUniforms; }
		inline const std::map<std::string, UniformParameter>& getSelfDefinedUniforms() const { return _mapSelfDefinedUniforms; }

		inline const std::map<VertexDataType, std::string>& getAttribs() const { return _mapAttribs; }
	protected:
		// 初始化参数
		void initParameters(ShaderProgram* shaderProgram);
	private:
		ShaderProgram* _shaderProgram = nullptr;
		// 默认参数
		std::map<EnvUniformType, std::string> _mapEnvUniforms;
		std::map<MatrixUniformType, std::string> _mapMatrixUniforms;
		std::map<TextureUniformType, std::string> _mapTextureUniforms;
		std::map<MaterialUniformType, std::string> _mapMaterialUniforms;
		std::map<SingleLightUniformType, std::string> _mapSingleLightUniforms;
		std::map<MultiLightsUniformType, std::string> _mapMultiLightsUniforms;

		std::map<VertexDataType, std::string> _mapAttribs;

		// 自定义
		std::map<std::string, UniformParameter> _mapSelfDefinedUniforms;
	};
}