#pragma once
#include "macros.h"
namespace render
{
	/**
	*	片源
	*/
	class GLFragment
	{
	public:
		/**
		*	裁剪测试
		*/
		static void testScissor(float x, float y, float width, float height);
	public:
		/**
		*	透明度测试
		*/
		static void testAlpha(AlphaFunction func, float value);
	public:
		/**
		*	模板测试
		*/
		static void testStencil(StencilFunction func, int ref, int mask);
		/**
		*	模板测试
		*	stencilFail 当蒙板测试失败时所执行的操作
		*	depthFail 当蒙板测试通过，深度测试失败时所执行的操作
		*	pass 当蒙板测试通过，深度测试通过时所执行的操作
		*/
		static void setStencilOp(StencilOp stencilFail, StencilOp depthFail, StencilOp pass);
	public:
		/**
		*	深度测试
		*/
		static void testDepth(DepthFunction func);
	public:
		/**
		*	混合
		*/
		static void setBlend(BlendingFactorSrc src, BlendingFactorDest dest);
	public:
		/**
		*	设置逻辑
		*/
		static void setLogicOp(LogicOp op);
	public:
		/**
		*	累积缓存
		*/
		static void setAccumOp(AccumOp op, float value);
	public:

	};
}