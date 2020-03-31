#pragma once

#include <cstdint>
#include "macros.h"
namespace render
{
	/**
	*	״̬
	*/
	class GLState
	{
	public:
		/**
		*	��������
		*/
		static void enable(EnableModel capability);
		/**
		*	�رչ���
		*/
		static void disable(EnableModel capability);
		/**
		*	��ѯ����״̬
		*/
		static bool isEnabled(EnableModel capability);
	public:
		/**
		*	��ȡbool���͵�״ֵ̬
		*/
		static void getBoolean(GetTarget pname, uint8_t* value);
		/**
		*	��ȡdouble���͵�״ֵ̬
		*/
		static void getDouble(GetTarget pname, double* value);
		/**
		*	��ȡfloat���͵�״ֵ̬
		*/
		static void getFloat(GetTarget pname, float* value);
		/**
		*	��ȡint���͵�״ֵ̬
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