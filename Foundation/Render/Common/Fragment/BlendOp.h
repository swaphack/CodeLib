#pragma once

#include "FragmentTestOp.h"
#include "Graphic/GLAPI/macros.h"

namespace render
{
	class BlendOpBase : public FragmentTestOp
	{
	public:
		BlendOpBase();
		virtual ~BlendOpBase();
	public:
		void setBlendColor(const sys::Color4F& color);
	public:
		virtual void startTest();
		virtual void test();
		virtual void endTest();
	protected:
		sys::Color4F _blendColor;
	};
	/**
	*	»ìºÏ
	*/
	class BlendOp : public BlendOpBase
	{
	public:
		BlendOp();
		virtual ~BlendOp();
	public:
		void setBlendFactor(BlendingFactorSrc src, BlendingFactorDest dst);
		void setBlendEquation(BlendEquationMode mode);
	public:
		virtual void test();
	protected:
		BlendingFactorSrc _src = BlendingFactorSrc::SRC_ALPHA;
		BlendingFactorDest _dest = BlendingFactorDest::ONE_MINUS_SRC_ALPHA;
		BlendEquationMode _mode = BlendEquationMode::FUNC_ADD;
	};

	//////////////////////////////////////////////////////////////////////////
	class BlendSeparateOp : public BlendOpBase
	{
	public:
		BlendSeparateOp();
		virtual ~BlendSeparateOp();
	public:
		void setBlendFactor(BlendingFactorSrc srcRGB, BlendingFactorDest dstRGB,
			BlendingFactorSrc srcAlpha, BlendingFactorDest dstAlpha);
		void setBlendEquation(BlendEquationMode rgbMode, BlendEquationMode alphaMode);
	public:
		virtual void test();
	protected:
		BlendingFactorSrc _srcRGB = BlendingFactorSrc::SRC_COLOR;
		BlendingFactorDest _destRGB = BlendingFactorDest::ONE_MINUS_SRC_COLOR;
		BlendingFactorSrc _srcAlpha = BlendingFactorSrc::SRC_ALPHA;
		BlendingFactorDest _destAlpha = BlendingFactorDest::ONE_MINUS_SRC_ALPHA;
		BlendEquationMode _rgbMode = BlendEquationMode::FUNC_ADD;
		BlendEquationMode _alphaMode = BlendEquationMode::FUNC_ADD;
	};

	//////////////////////////////////////////////////////////////////////////
	class BlendBufferOp : public BlendOp
	{
	public:
		BlendBufferOp();
		virtual ~BlendBufferOp();
	public:
		void setBufferID(uint32_t buffer);
	public:
		virtual void test();
	protected:
		uint32_t _bufferID = 0;
	};

	//////////////////////////////////////////////////////////////////////////
	class BlendSeparateBufferOp : public BlendSeparateOp
	{
	public:
		BlendSeparateBufferOp();
		virtual ~BlendSeparateBufferOp();
	public:
		void setBufferID(uint32_t buffer);
	public:
		virtual void test();
	protected:
		uint32_t _bufferID = 0;
	};
}