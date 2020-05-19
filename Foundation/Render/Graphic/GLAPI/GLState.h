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
		static bool isEnabled(EnableMode capability);
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
		*	�޳��� ������
		*	glEnable(GL_CULL_FACE)�� glDisable
		*/
		static void setCullFace(FaceType mode);
		/**
		*	��Ȳ���
		*/
		static void setDepthFunc(DepthFunction func);
		/**
		*	����Ƿ��д
		*/
		static void setDepthMask(bool flag);
		static void setDepthRange(float zNear, float zFar);
		static void setDepthRangeArray(uint32_t first, int count, const double* v);
		static void setDepthRangeIndexed(uint32_t index, float zNear, float zFar);
		/**
		*	��������
		*/
		static void enable(EnableMode capability);
		/**
		*	�رչ���
		*/
		static void disable(EnableMode capability);
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
		static void setLogicOp(LogicOpCode op);

		static void setPixelStore(PixelStore name, float value);
		static void setPointParameter(PointParameter pname, const float* value);
		
		/**
		*	�������ʽ
		*/
		static void setPolygonMode(FaceType mode, PolygonMode type);

		static void setSampleCoverage(float value, bool invert);

		static void setSampleMask(uint32_t maskNumber, uint32_t mask);
		/**
		*	�ü�����
		*/
		static void setScissor(int x, int y, int width, int height);
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
		*	�ȽϺ��� func
		*	�ο�ֵ	ref
		*	���� mask
		*	ref��ģ�建�������е�ֵ���бȽϣ� ���ڴ�֮ǰ��Ҫ��mask���С��롱�������������Ϊ0��ƽ��
		*	�������s��ƽ�棬��ômask�нϵ͵�s�����ݷֱ���ģ�建���е�ֵ���Լ��ο�ֵ���С��롱��������ִ�бȽ�
		*	
		*	Ĭ��ֵ��func = GL_ALWAYS, ref =0, mask = 1
		*/
		static void setStencilFunc(StencilFunction func, int ref, uint32_t mask);
		static void setStencilFuncSeparate(FaceType type, StencilFunction func, int ref, uint32_t mask);
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
		*	Ĭ��ֵGL_KEEP
		*/
		static void setStencilOp(StencilOpResult stencilFail, StencilOpResult depthFail, StencilOpResult depthPass);
		static void setStencilOpSeparate(FaceType type, StencilOpResult stencilFail, StencilOpResult depthFail, StencilOpResult depthPass);
	public:
		static void setViewport(float x, float y, float width, float height);
		static void setViewportArray(uint32_t first, int count, const float* v);
		static void setViewportIndexed(uint32_t index, float x, float y, float width, float height);
	};
}