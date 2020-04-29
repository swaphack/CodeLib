#pragma once

#include <cstdint>
#include "macros.h"
#include "system.h"
namespace render
{
	/**
	*	状态
	*/
	class GLState
	{
	public:
		
		/**
		*	查询功能状态
		*/
		static bool isEnabled(EnableModel capability);
	public:
		/**
		*	获取bool类型的状态值
		*/
		static void getBoolean(GetTarget pname, uint8_t* value);
		static void getBoolean(uint32_t pname, uint8_t* value);
		/**
		*	获取double类型的状态值
		*/
		static void getDouble(GetTarget pname, double* value);
		static void getDouble(uint32_t pname, double* value);
		/**
		*	获取float类型的状态值
		*/
		static void getFloat(GetTarget pname, float* value);
		static void getFloat(uint32_t pname, float* value);
		/**
		*	获取int类型的状态值
		*/
		static void getInt(GetTarget pname, int* value);	
		static void getInt(uint32_t pname, int* value);
	public:		
		static void getTexImage(TextureTarget target, int level, TexImageInternalFormat internalFormat, TexImageDataType pixelType, void* data);
		static void getTexLevelParameter(TextureTarget target, int level, GetTextureParameter parameter, float* value);
		static void getTexParameter(TextureTarget target, GetTextureParameter parameter, int* value);
		static void getTexParameter(TextureTarget target, GetTextureParameter parameter, float* value);
		static void getPointer(GetPointerTarget target, void** value);
	public:
		static void setBlendColor(const sys::Color4F& color);
		static void setBlendEquation(BlendEquationMode mode);
		static void setBlendEquation(uint32_t buf, BlendEquationMode mode);
		static void setBlendEquationSeparate(BlendEquationMode rgb, BlendEquationMode alpha);
		static void setBlendEquationSeparate(uint32_t buf, BlendEquationMode rgb, BlendEquationMode alpha);

		static void setBlendFunc(BlendingFactorSrc src, BlendingFactorDest dest);
		static void setBlendFunc(uint32_t buf, BlendingFactorSrc src, BlendingFactorDest dest);

		static void setBlendFuncSeparate(BlendEquationMode srcRGB, BlendEquationMode destRGB, BlendEquationMode srcAlpha, BlendEquationMode destAlpha);
		static void setBlendFuncSeparate(uint32_t buf, BlendEquationMode srcRGB, BlendEquationMode destRGB, BlendEquationMode srcAlpha, BlendEquationMode destAlpha);

		static void setClampColor(bool clamp);

		static void setClipControl(ClipControlOrigin origin, ClipControlDepth depth);
	public:
		static void setColorMask(bool red, bool green, bool blue, bool alpha);
		/**
		*	剔除面 看不见
		*	glEnable(GL_CULL_FACE)， glDisable
		*/
		static void setCullFace(FaceType mode);
		/**
		*	深度测试
		*/
		static void testDepth(DepthFunction func);

		static void setDepthMask(bool flag);
		static void setDepthRange(float zNear, float zFar);
		static void setDepthRangeArray(uint32_t first, int count, const double* v);
		static void setDepthRangeIndexed(uint32_t index, float zNear, float zFar);
		/**
		*	开启功能
		*/
		static void enable(EnableModel capability);
		/**
		*	关闭功能
		*/
		static void disable(EnableModel capability);
		/**
		*	前方绕行方式
		*/
		static void setFrontFace(FrontFaceDirection mode);
	public:
		/**
		*	雾化效果
		*/
		static void setFogHint(HintMode type);
		/**
		*	片元着色器
		*/
		static void setFragmentShaderDerivativeHint(HintMode type);
		/**
		*	生成mipmap
		*/
		static void setGenerateMipMapHint(HintMode type);
		/**
		*	线段平滑
		*/
		static void setLineSmoothHint(HintMode type);
		/**
		*	透视矫正
		*/
		static void setPerspectiveCorrectionHint(HintMode type);
		/**
		*	点平滑
		*/
		static void setPointSmoothHint(HintMode type);
		/**
		*	多边形平滑
		*/
		static void setPolygonSmoothHint(HintMode type);
		/**
		*	纹理压缩
		*/
		static void setTextureCompressionHint(HintMode type);
	public:
		static void setPointSize(float size);
		static void setLineWidth(float width);

		static void setPolygonOffset(float factor, float units);

	public:
		/**
		*	设置逻辑
		*/
		static void setLogicOp(LogicOp op);

		static void setPixelStore(PixelStore name, float value);
		static void setPointParameter(PointParameter pname, const float* value);
		
		/**
		*	多边形样式
		*/
		static void setPolygonMode(FaceType mode, PolygonMode type);

		static void setSampleCoverage(float value, bool invert);
		/**
		*	裁剪测试
		*/
		static void setScissor(float x, float y, float width, float height);
		/**
		*	裁剪测试
		*/
		static void setScissorArray(uint32_t first, int count, const int* v);
		/**
		*	裁剪测试
		*/
		static void setScissorIndexed(uint32_t index, float x, float y, float width, float height);
	public:
		/**
		*	模板测试
		*/
		static void setStencil(StencilFunction func, int ref, uint32_t mask);
		static void setStencilSeparate(FaceType type, StencilFunction func, int ref, uint32_t mask);
	public:
		/**
		*	0xFF == 0b11111111
		*	此时，模板值与它进行按位与运算结果是模板值，模板缓冲可写
		*	0x00 == 0b00000000 == 0
		*	此时，模板值与它进行按位与运算结果是0，模板缓冲不可写
		*/
		static void setStencilMask(uint32_t mask);
		static void setStencilMaskSeparate(FaceType type, uint32_t mask);
	public:
		/**
		*	模板测试
		*	stencilFail 当蒙板测试失败时所执行的操作
		*	depthFail 当蒙板测试通过，深度测试失败时所执行的操作
		*	pass 当蒙板测试通过，深度测试通过时所执行的操作
		*/
		static void setStencilOp(StencilOp stencilFail, StencilOp depthFail, StencilOp pass);
		static void setStencilOpSeparate(FaceType type, StencilOp stencilFail, StencilOp depthFail, StencilOp pass);
	public:
		static void setViewport(float x, float y, float width, float height);
		static void setViewportArray(uint32_t first, int count, const float* v);
		static void setViewportIndexed(uint32_t index, float x, float y, float width, float height);
	};
}