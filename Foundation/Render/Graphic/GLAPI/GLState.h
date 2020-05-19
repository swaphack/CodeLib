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
		static bool isEnabled(EnableMode capability);
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
		static void getInteger(GetTarget pname, int* value);	
		static void getInteger(uint32_t pname, int* value);
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

		static void setBlendFuncSeparate(BlendingFactorSrc srcRGB, BlendingFactorDest destRGB, BlendingFactorSrc srcAlpha, BlendingFactorDest destAlpha);
		static void setBlendFuncSeparate(uint32_t buf, BlendingFactorSrc srcRGB, BlendingFactorDest destRGB, BlendingFactorSrc srcAlpha, BlendingFactorDest destAlpha);

		static void setClampColor(bool clamp);

		static void setClipControl(ClipControlOrigin origin, ClipControlDepth depth);
	public:
		static void setColorMask(bool red, bool green, bool blue, bool alpha);
		static void setColorMask(uint32_t buffer, bool red, bool green, bool blue, bool alpha);
		/**
		*	剔除面 看不见
		*	glEnable(GL_CULL_FACE)， glDisable
		*/
		static void setCullFace(FaceType mode);
		/**
		*	深度测试
		*/
		static void setDepthFunc(DepthFunction func);
		/**
		*	深度是否可写
		*/
		static void setDepthMask(bool flag);
		static void setDepthRange(float zNear, float zFar);
		static void setDepthRangeArray(uint32_t first, int count, const double* v);
		static void setDepthRangeIndexed(uint32_t index, float zNear, float zFar);
		/**
		*	开启功能
		*/
		static void enable(EnableMode capability);
		/**
		*	关闭功能
		*/
		static void disable(EnableMode capability);
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
		static void setLogicOp(LogicOpCode op);

		static void setPixelStore(PixelStore name, float value);
		static void setPointParameter(PointParameter pname, const float* value);
		
		/**
		*	多边形样式
		*/
		static void setPolygonMode(FaceType mode, PolygonMode type);

		static void setSampleCoverage(float value, bool invert);

		static void setSampleMask(uint32_t maskNumber, uint32_t mask);
		/**
		*	裁剪测试
		*/
		static void setScissor(int x, int y, int width, int height);
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
		*	比较函数 func
		*	参考值	ref
		*	掩码 mask
		*	ref与模板缓存中已有的值进行比较， 但在此之前需要与mask进行“与”操作，丢弃结果为0的平面
		*	如果包含s个平面，那么mask中较低的s个数据分别与模板缓存中的值，以及参考值进行“与”操作，再执行比较
		*	
		*	默认值，func = GL_ALWAYS, ref =0, mask = 1
		*/
		static void setStencilFunc(StencilFunction func, int ref, uint32_t mask);
		static void setStencilFuncSeparate(FaceType type, StencilFunction func, int ref, uint32_t mask);
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
		*	默认值GL_KEEP
		*/
		static void setStencilOp(StencilOpResult stencilFail, StencilOpResult depthFail, StencilOpResult depthPass);
		static void setStencilOpSeparate(FaceType type, StencilOpResult stencilFail, StencilOpResult depthFail, StencilOpResult depthPass);
	public:
		static void setViewport(float x, float y, float width, float height);
		static void setViewportArray(uint32_t first, int count, const float* v);
		static void setViewportIndexed(uint32_t index, float x, float y, float width, float height);
	};
}