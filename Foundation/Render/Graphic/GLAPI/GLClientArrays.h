#pragma once

#include "macros.h"

namespace render
{
	class GLClientArrays
	{
	public:
		static void enableClientState(ClientArrayType type);
		static void disableClientState(ClientArrayType type);
	public: // 坐标
		static void setVertexPointer(int size, DataType type, int stride, const void* value);
		static void setVertexPointer2(DataType type, int stride, const void* value);
		static void setVertexPointer3(DataType type, int stride, const void* value);
		static void setVertexPointer4(DataType type, int stride, const void* value);
	public: // 颜色
		static void setColorPointer(int size, DataType type, int stride, const void* value);
		static void setColorPointer3(DataType type, int stride, const void* value);
		static void setColorPointer4(DataType type, int stride, const void* value);
	public: // 法线
		static void setNormalPointer(DataType type, int stride, const void* value);
	public: // 纹理
		static void setTexCoordPointer(int size, DataType type, int stride, const void* value);
		static void setTexCoordPointer1(DataType type, int stride, const void* value);
		static void setTexCoordPointer2(DataType type, int stride, const void* value);
		static void setTexCoordPointer3(DataType type, int stride, const void* value);
		static void setTexCoordPointer4(DataType type, int stride, const void* value);
	public: // 颜色索引
		static void setIndexPointer(IndexPointerType type, int stride, const void* value);
	public: // 复合数据
		static void setInterleavedArrays(InterleavedArraysMode mode, int stride, const void* value);
	public:
		static void multiTexCoord(ActiveTextureName texture, float s, float t);
	public: // 雾
		static void setFogCoordPointer(int stride, const void* value);
	public: // 辅助颜色
		static void setSecondaryColorPointer(DataType type, int stride, const void* value);
	public:
		static void pushClientAttrib(ClientAttribMask value);
		static void popClientAttrib();

	public:
		static void setEdgeFlagPointer(int stride, const void* flag);
	public:// 用于begin end之间
		static void drawArrayElement(int index);
		static void drawArrays(ShapeMode mode, int first, int count);
	public:
		static void drawElements(ShapeMode mode, int count, IndexDataType type, const void* data);
	};
}