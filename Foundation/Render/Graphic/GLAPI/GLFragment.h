#pragma once
#include "macros.h"
namespace render
{
	/**
	*	ƬԴ
	*/
	class GLFragment
	{
	public:
		/**
		*	�ü�����
		*/
		static void testScissor(float x, float y, float width, float height);
	public:
		/**
		*	͸���Ȳ���
		*/
		static void testAlpha(AlphaFunction func, float value);
	public:
		/**
		*	ģ�����
		*/
		static void testStencil(StencilFunction func, int ref, int mask);
		/**
		*	ģ�����
		*	stencilFail ���ɰ����ʧ��ʱ��ִ�еĲ���
		*	depthFail ���ɰ����ͨ������Ȳ���ʧ��ʱ��ִ�еĲ���
		*	pass ���ɰ����ͨ������Ȳ���ͨ��ʱ��ִ�еĲ���
		*/
		static void setStencilOp(StencilOp stencilFail, StencilOp depthFail, StencilOp pass);
	public:
		/**
		*	��Ȳ���
		*/
		static void testDepth(DepthFunction func);
	public:
		/**
		*	���
		*/
		static void setBlend(BlendingFactorSrc src, BlendingFactorDest dest);
	public:
		/**
		*	�����߼�
		*/
		static void setLogicOp(LogicOp op);
	public:
		/**
		*	�ۻ�����
		*/
		static void setAccumOp(AccumOp op, float value);
	public:

	};
}