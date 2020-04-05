#pragma once

#include "mathlib.h"
#include "macros.h"
#include "Common/struct/shape_common.h"
#include "Common/struct/texture_common.h"

namespace render
{
	/**
	*	顶点处理
	*/
	class GLVertex
	{
	public:
		static void beginMode(ShapeMode mode);
		static void endMode();
	public:
		static void setVertex(float x, float y, float z);
		static void setVertex(const math::Vector3& value);
	public:
		static void setNormal(float x, float y, float z);
		static void setNormal(const math::Vector3& value);
	public:
		static void setColor(float r, float g, float b, float a = 1);
		static void setColor(const sys::Color3F& value, float opacity = 1);
		static void setColor(const sys::Color4F& value, float opacity = 1);
		static void setColor(const sys::Color3B& value, uint8_t opacity = 255);
		static void setColor(const sys::Color4B& value, uint8_t opacity = 255);
	public:
		static void setIndex(int index);
	public:
		static void setTexCoord1D(float s);
		static void setTexCoord2D(float s, float t);
		static void setTexCoord2D(const math::Vector2& value);
		static void setTexCoord3D(float s, float t, float r);
		static void setTexCoord3D(const math::Vector2& value);
	public:
		static void setVertexPointer(int size, DataType type, int stride, const void* value);
		static void setVertexPointer2(DataType type, int stride, const void* value);
		static void setVertexPointer3(DataType type, int stride, const void* value);
		static void setVertexPointer4(DataType type, int stride, const void* value);
		
		static void setColorPointer(int size, DataType type, int stride, const void* value);
		static void setColorPointer3(DataType type, int stride, const void* value);
		static void setColorPointer4(DataType type, int stride, const void* value);
		
		static void setNormalPointer(DataType type, int stride, const void* value);

		static void setTexCoordPointer(int size, DataType type, int stride, const void* value);
		static void setTexCoordPointer1(DataType type, int stride, const void* value);
		static void setTexCoordPointer2(DataType type, int stride, const void* value);
		static void setTexCoordPointer3(DataType type, int stride, const void* value);
		static void setTexCoordPointer4(DataType type, int stride, const void* value);
		// color index
		static void setIndexPointer(IndexPointerType type, int stride, const void* value);

		static void setInterleavedArrays(InterleavedArraysMode mode, int stride, const void* value);
	public:
		// 用于begin end之间
		static void drawArrayElement(int index);
		static void drawArrays(ShapeMode mode, int first, int count);
		static void drawElements(ShapeMode mode, int count, IndexDataType type, const void* data);
	public:
		// 设置边缘编辑
		static void setEdgeFlag(bool flag);
		static void setEdgeFlagPointer(int stride, const void* flag);
	public:
		static void drawRect(const RectVertex& value);
		static void drawTextureRect(const TextureRectVertex& value);
	};
}