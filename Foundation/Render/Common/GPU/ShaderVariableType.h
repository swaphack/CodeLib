#pragma once

#include "system.h"

namespace render
{
	enum class ShaderParamterType
	{
		FLOAT,
		DOUBLE,
		INTEGER,
		UNSIGNED_INTTEGER,
		BOOL,

		FLOAT2,
		DOUBLE2,
		INTEGER2,
		UNSIGNED_INTTEGER2,
		BOOL2,

		FLOAT3,
		DOUBLE3,
		INTEGER3,
		UNSIGNED_INTTEGER3,
		BOOL3,

		FLOAT4,
		DOUBLE4,
		INTEGER4,
		UNSIGNED_INTTEGER4,
		BOOL4,

		MAT2, MAT3, MAT4,
		MAT2X2, MAT2X3, MAT2X4,
		MAT3X2, MAT3X3, MAT3X4,
		MAT4X2, MAT4X3, MAT4X4,

		DMAT2, DMAT3, DMAT4,
		DMAT2X2, DMAT2X3, DMAT2X4,
		DMAT3X2, DMAT3X3, DMAT3X4,
		DMAT4X2, DMAT4X3, DMAT4X4,
	};
	/**
	*	变量类型
	*/
	class ShaderVariableType : public sys::Object
	{
	public:
		ShaderVariableType();
		ShaderVariableType(ShaderParamterType type, uint32_t size, const std::string& mark);
		virtual ~ShaderVariableType();
	public:
		/**
		*	类型
		*/
		void setType(ShaderParamterType type);
		/**
		*	类型
		*/
		ShaderParamterType getType() const;
		/**
		*	大小
		*/
		void setSize(uint32_t size);
		/**
		*	大小
		*/
		uint32_t getSize() const;
		/**
		*	标记
		*/
		void setMark(const std::string& mark);
		/**
		*	标记
		*/
		const std::string& getMark() const;
	private:
		/**
		*	类型
		*/
		ShaderParamterType _type = ShaderParamterType::FLOAT;
		/**
		*	大小
		*/
		uint32_t _size = 0;
		/**
		*	标记
		*/
		std::string _mark;
	};
}
