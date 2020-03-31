#pragma once

#include <cstdint>
#include "macros.h"
namespace render
{
	/**
	*	状态
	*/
	class GLState
	{
	public:
		/**
		*	开启功能
		*/
		static void enable(EnableModel capability);
		/**
		*	关闭功能
		*/
		static void disable(EnableModel capability);
		/**
		*	查询功能状态
		*/
		static bool isEnabled(EnableModel capability);
	public:
		/**
		*	获取bool类型的状态值
		*/
		static void getBoolean(GetTarget pname, uint8_t* value);
		/**
		*	获取double类型的状态值
		*/
		static void getDouble(GetTarget pname, double* value);
		/**
		*	获取float类型的状态值
		*/
		static void getFloat(GetTarget pname, float* value);
		/**
		*	获取int类型的状态值
		*/
		static void getInt(GetTarget pname, int* value);
	public:
		static void finish();
		static void flush();
	public:
		static void pushAttrib(AttribMask value);
		static void popAttrib();
		static void pushClientAttrib(ClientAttribMask value);
		static void popClientAttrib();
	public:
		static void getClipPlane(ClipPlaneName name, double* equation);
		static void getPixelMap(PixelMap map, float* value);
		static void getTexImage(TextureTarget target, int level, TextureParameter internalFormat, PixelType pixelType, void* data);
		static void getLight(LightName name, LightParameter mode, float* value);
		static void getPolygonStipple(uint8_t* mask);
		static void getTexLevelParameter(TextureTarget target, int level, GetTextureParameter parameter, float* value);
		static void getMap(MapTarget target, GetMapTarget parameter, float* value);
		static void getTexEnv(TextureEnvTarget target, TextureEnvParameter parameter, float* value);
		static void getTexParameter(TextureTarget target, GetTextureParameter parameter, int* value);
		static void getTexParameter(TextureTarget target, GetTextureParameter parameter, float* value);
		static void getMaterial(GetMaterialFace face, MaterialParameter parameter, float* value);
		static void getTexGen(TextureCoordName coord, TextureGenParameter parameter, float* value);
		static void getPointer(GetPointerTarget target, void** value);
	public:
		static void enableClientState(ClientArrayType type);
		static void disableClientState(ClientArrayType type);
	public:
	};
}