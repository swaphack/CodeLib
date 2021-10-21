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
Size = sizeof(T);\
Data = (T*)malloc(Size); \
if (Data) memcpy(Data, &value, Size);\
}

#define CONSTRUCT_FLOAT_ARRAY_TYPE(UT, T) \
UniformParameter(const std::string& name, const T& value) \
{\
Type = UT; \
Name = name; \
Size = value.getSize();\
Data = (float*)malloc(Size);\
if (Data) memcpy(Data, value.getValue(), Size);\
}

#define AS_VALUE_TYPE(T, Func, UT, DefaultValue) \
T as##Func() const \
{\
if (Data == nullptr || UT != Type ) {\
	return DefaultValue;\
}else {\
	return *((T*)Data); \
} \
}

#define AS_FLOAT_ARRAY_TYPE(T,Func, UT, DefaultValue) \
T as##Func() const \
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
			uint32_t Size = 0;
			void* Data = nullptr;
		public:
			UniformParameter() {}
			UniformParameter(const std::string& name, UniformType type, uint32_t size, void* value)
			{
				Name = name;
				Type = type;
				Size = size;
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
			// 是否相同
			bool equals(const UniformParameter& parameter) const
			{
				if (Name != parameter.Name || Type != parameter.Type)
				{
					return false;
				}
				return memcmp(Data, parameter.Data, Size);
			}
		};
	public:
		MaterialSetting();
		virtual ~MaterialSetting();
	public:
		// 设置shaderprogram
		void setShaderProgram(ShaderProgram* shaderProgram);
		// 添加自定义uniform
		void addSelfDefineUniform(const std::string& name, UniformType type, uint32_t size, void* value);
		// 移除自定义uniform
		void removeAllSelfDefineUniforms();
		// 自定义uniform
		inline const std::map<std::string, UniformParameter>& getSelfDefinedUniforms() const { return _mapSelfDefinedUniforms; }
	public:
		// 自定义参数是否相同
		bool equalsSelfDefinedUniforms(const MaterialSetting& ms) const;
	private:
		ShaderProgram* _shaderProgram = nullptr;
		// 自定义
		std::map<std::string, UniformParameter> _mapSelfDefinedUniforms;
	};
}