#pragma once

#include "macros.h"
#include "mathlib.h"

namespace render
{
	/**
	*	图元数据处理
	*/
	class GLPrimitive
	{
	public:
		static void setClipPlane(ClipPlaneName name, const double* value);
		static void setDepthRange(float zNear, float zFar);
	public: 
		static void loadFrustum(float left, float right, float bottom, float top, float zNear, float zFar);
		static void loadOrtho(float left, float right, float bottom, float top, float zNear, float zFar);
		static void setViewport(float x, float y, float width, float height);
	public:
		static void setPointSize(float size);
		static void setLineWidth(float width);
		static void setLineStipple(int factor, uint16_t pattern);
		/**
		*	A pointer to a 32x32 stipple pattern that will be unpacked from memory in the same way that glDrawPixels unpacks pixels.
		*/
		static void setPolygonStripple(const uint8_t *mask);
		static void setPolygonOffset(float factor, float units);
	public:
		static void setPixelStore(PixelStore name, float value);
		static void setPixelTransfer(PixelTransfer name, float value);
		static void setPixelMap(PixelMap name, int size, const float* value);
	public:
		static void setRasterPos(float x, float y, float z = 0);
		static void setRect(float x1, float y1, float x2, float y2);
		static void setRect(const math::Vector2& src, const math::Vector2& dest);
		static void setRect(const math::Vector2& src, const math::Size& size);
	public:
		static void setPixelZoom(float x, float y);
		static void drawPixels(float width, float heith, PixelFormat format, PixelType type, const void* value);
	public:
		static void drawBitMap(float width, float heith, float xorig, float yorig, float xmove, float ymove, const uint8_t* value);
	public:
		/**
		*	前方绕行方式
		*/
		static void setFrontFace(FrontFaceDirection mode);
		/**
		*	剔除面 看不见
		*	glEnable(GL_CULL_FACE)， glDisable
		*/
		static void setCullFace(CullFaceMode mode);
	};
}