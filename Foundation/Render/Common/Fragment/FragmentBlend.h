#pragma once

#include "FragmentHandle.h"
#include "Graphic/GLAPI/macros.h"

namespace render
{
	class FragmentBlendBase : public FragmentHandle
	{
	public:
		FragmentBlendBase();
		virtual ~FragmentBlendBase();
	public:
		void setBlendColor(const sys::Color4F& color);
	public:
		virtual void begin();
		virtual void update();
		virtual void end();
	protected:
		sys::Color4F _blendColor;
	};
	/**
	*	»ìºÏ
	*/
	class FragmentBlend : public FragmentBlendBase
	{
	public:
		FragmentBlend();
		virtual ~FragmentBlend();
	public:
		void setBlendFactor(BlendingFactorSrc src, BlendingFactorDest dst);
		void setBlendEquation(BlendEquationMode mode);
	public:
		virtual void update();
	protected:
		BlendingFactorSrc _src = BlendingFactorSrc::SRC_ALPHA;
		BlendingFactorDest _dest = BlendingFactorDest::ONE_MINUS_SRC_ALPHA;
		BlendEquationMode _mode = BlendEquationMode::FUNC_ADD;
	};

	//////////////////////////////////////////////////////////////////////////
	class FragmentBlendSeparate : public FragmentBlendBase
	{
	public:
		FragmentBlendSeparate();
		virtual ~FragmentBlendSeparate();
	public:
		void setBlendFactor(BlendingFactorSrc srcRGB, BlendingFactorDest dstRGB,
			BlendingFactorSrc srcAlpha, BlendingFactorDest dstAlpha);
		void setBlendEquation(BlendEquationMode rgbMode, BlendEquationMode alphaMode);
	public:
		virtual void update();
	protected:
		BlendingFactorSrc _srcRGB = BlendingFactorSrc::SRC_COLOR;
		BlendingFactorDest _destRGB = BlendingFactorDest::ONE_MINUS_SRC_COLOR;
		BlendingFactorSrc _srcAlpha = BlendingFactorSrc::SRC_ALPHA;
		BlendingFactorDest _destAlpha = BlendingFactorDest::ONE_MINUS_SRC_ALPHA;
		BlendEquationMode _rgbMode = BlendEquationMode::FUNC_ADD;
		BlendEquationMode _alphaMode = BlendEquationMode::FUNC_ADD;
	};

	//////////////////////////////////////////////////////////////////////////
	class FragmentBlendBuffer : public FragmentBlend
	{
	public:
		FragmentBlendBuffer();
		virtual ~FragmentBlendBuffer();
	public:
		void setBufferID(uint32_t buffer);
	public:
		virtual void update();
	protected:
		uint32_t _bufferID = 0;
	};

	//////////////////////////////////////////////////////////////////////////
	class FragmentBlendSeparateBuffer : public FragmentBlendSeparate
	{
	public:
		FragmentBlendSeparateBuffer();
		virtual ~FragmentBlendSeparateBuffer();
	public:
		void setBufferID(uint32_t buffer);
	public:
		virtual void update();
	protected:
		uint32_t _bufferID = 0;
	};
}