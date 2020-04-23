#pragma once

#include "macros.h"
#include "mathlib.h"

namespace render
{
	/**
	*	光栅
	*/
	class GLRasterization
	{
	public:
		static void drawBitMap(float width, float heith, float xorig, float yorig, float xmove, float ymove, const uint8_t* value);
	public:
		static void clearIndex(int mask);
	public:
		static void setClipPlane(ClipPlaneName name, const double* value);
		static void getClipPlane(ClipPlaneName name, double* equation);
	public:
		// 复制数据到缓存区
		static void copyPixels(float x, float y, float width, float height, PixelCopyType copyType);
		static void drawPixels(float width, float heith, PixelFormat format, PixelType type, const void* value);
	public:
		static void getFeedBackBuffer(int size, FeedBackMode mode, float* buffer);
	public:
		static void getMap(MapTarget target, GetMapTarget parameter, float* value);
		static void getPixelMap(PixelMap map, float* value);
		static void getPolygonStipple(uint8_t* mask);
	public:// name stack
		static void initNames();
		static void loadName(int name);
		static void pushName(int name);
		static void popName();
	public:
		static void setLineStipple(int factor, uint16_t pattern);
	public:
		static void setPassThrough(float value);
	public:
		static void setRasterPos(float x, float y, float z = 0);
		static void setRect(float x1, float y1, float x2, float y2);
		static void setRect(const math::Vector2& src, const math::Vector2& dest);
		static void setRect(const math::Vector2& src, const math::Size& size);
	public:
		static void setPixelZoom(float x, float y);
		/**
		*	A pointer to a 32x32 stipple pattern that will be unpacked from memory in the same way that glDrawPixels unpacks pixels.
		*/
		static void setPolygonStripple(const uint8_t *mask);
	public:
		/**
		*	设置渲染样式
		*/
		static void setRenderMode(RenderingMode mode);
		/**
		*	设置成渲染， 默认
		*/
		static void setRenderMode();
		static void setSelectMode();
		static void getSelectBuffer(int size, uint32_t* buffer);
		static void setFeedbackMode();
	public:
		static void setWindowPos(float x, float y, float z = 0);
	};
}