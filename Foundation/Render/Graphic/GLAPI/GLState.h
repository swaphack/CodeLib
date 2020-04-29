#pragma once

#include <cstdint>
#include "macros.h"
#include "system.h"
namespace render
{
	/**
	*	״̬
	*/
	class GLState
	{
	public:
		
		/**
		*	��ѯ����״̬
		*/
		static bool isEnabled(EnableModel capability);
	public:
		/**
		*	��ȡbool���͵�״ֵ̬
		*/
		static void getBoolean(GetTarget pname, uint8_t* value);
		static void getBoolean(uint32_t pname, uint8_t* value);
		/**
		*	��ȡdouble���͵�״ֵ̬
		*/
		static void getDouble(GetTarget pname, double* value);
		static void getDouble(uint32_t pname, double* value);
		/**
		*	��ȡfloat���͵�״ֵ̬
		*/
		static void getFloat(GetTarget pname, float* value);
		static void getFloat(uint32_t pname, float* value);
		/**
		*	��ȡint���͵�״ֵ̬
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
		*	�޳��� ������
		*	glEnable(GL_CULL_FACE)�� glDisable
		*/
		static void setCullFace(FaceType mode);
		/**
		*	��Ȳ���
		*/
		static void testDepth(DepthFunction func);

		static void setDepthMask(bool flag);
		static void setDepthRange(float zNear, float zFar);
		static void setDepthRangeArray(uint32_t first, int count, const double* v);
		static void setDepthRangeIndexed(uint32_t index, float zNear, float zFar);
		/**
		*	��������
		*/
		static void enable(EnableModel capability);
		/**
		*	�رչ���
		*/
		static void disable(EnableModel capability);
		/**
		*	ǰ�����з�ʽ
		*/
		static void setFrontFace(FrontFaceDirection mode);
	public:
		/**
		*	��Ч��
		*/
		static void setFogHint(HintMode type);
		/**
		*	ƬԪ��ɫ��
		*/
		static void setFragmentShaderDerivativeHint(HintMode type);
		/**
		*	����mipmap
		*/
		static void setGenerateMipMapHint(HintMode type);
		/**
		*	�߶�ƽ��
		*/
		static void setLineSmoothHint(HintMode type);
		/**
		*	͸�ӽ���
		*/
		static void setPerspectiveCorrectionHint(HintMode type);
		/**
		*	��ƽ��
		*/
		static void setPointSmoothHint(HintMode type);
		/**
		*	�����ƽ��
		*/
		static void setPolygonSmoothHint(HintMode type);
		/**
		*	����ѹ��
		*/
		static void setTextureCompressionHint(HintMode type);
	public:
		static void setPointSize(float size);
		static void setLineWidth(float width);

		static void setPolygonOffset(float factor, float units);

	public:
		/**
		*	�����߼�
		*/
		static void setLogicOp(LogicOp op);

		static void setPixelStore(PixelStore name, float value);
		static void setPointParameter(PointParameter pname, const float* value);
		
		/**
		*	�������ʽ
		*/
		static void setPolygonMode(FaceType mode, PolygonMode type);

		static void setSampleCoverage(float value, bool invert);
		/**
		*	�ü�����
		*/
		static void setScissor(float x, float y, float width, float height);
		/**
		*	�ü�����
		*/
		static void setScissorArray(uint32_t first, int count, const int* v);
		/**
		*	�ü�����
		*/
		static void setScissorIndexed(uint32_t index, float x, float y, float width, float height);
	public:
		/**
		*	ģ�����
		*/
		static void setStencil(StencilFunction func, int ref, uint32_t mask);
		static void setStencilSeparate(FaceType type, StencilFunction func, int ref, uint32_t mask);
	public:
		/**
		*	0xFF == 0b11111111
		*	��ʱ��ģ��ֵ�������а�λ����������ģ��ֵ��ģ�建���д
		*	0x00 == 0b00000000 == 0
		*	��ʱ��ģ��ֵ�������а�λ����������0��ģ�建�岻��д
		*/
		static void setStencilMask(uint32_t mask);
		static void setStencilMaskSeparate(FaceType type, uint32_t mask);
	public:
		/**
		*	ģ�����
		*	stencilFail ���ɰ����ʧ��ʱ��ִ�еĲ���
		*	depthFail ���ɰ����ͨ������Ȳ���ʧ��ʱ��ִ�еĲ���
		*	pass ���ɰ����ͨ������Ȳ���ͨ��ʱ��ִ�еĲ���
		*/
		static void setStencilOp(StencilOp stencilFail, StencilOp depthFail, StencilOp pass);
		static void setStencilOpSeparate(FaceType type, StencilOp stencilFail, StencilOp depthFail, StencilOp pass);
	public:
		static void setViewport(float x, float y, float width, float height);
		static void setViewportArray(uint32_t first, int count, const float* v);
		static void setViewportIndexed(uint32_t index, float x, float y, float width, float height);
	};
}