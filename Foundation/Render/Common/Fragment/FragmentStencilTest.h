#pragma once
#include "Graphic/GLAPI/macros.h"
#include "FragmentTestOp.h"
#include <cstdint>

namespace render
{
	/**
	*	Ä£°å²âÊÔ
	*/
	class FragmentStencilOp : public FragmentTestOp
	{
	public:
		FragmentStencilOp();
		virtual ~FragmentStencilOp();
	public:
		void setFunc(StencilFunction func, int ref, uint32_t mask);
		void setOperator(StencilOpResult stencilFail, StencilOpResult depthFail, StencilOpResult depthPass);
	public:
		virtual void begin();
		virtual void update();
		virtual void end();
	protected:
		StencilFunction _func;
		int _ref = 0;
		uint32_t _mask = 0;
		StencilOpResult _stencilFail = StencilOpResult::KEEP;
		StencilOpResult _depthFail = StencilOpResult::KEEP;
		StencilOpResult _depthPass = StencilOpResult::KEEP;
	};

	//////////////////////////////////////////////////////////////////////////
	class StencilFaceOp : public FragmentStencilOp
	{
	public:
		StencilFaceOp();
		virtual ~StencilFaceOp();
	public:
		void setFaceType(FaceType faceType);
	public:
		virtual void update();
	protected:
		FaceType _faceType = FaceType::FRONT;
	};
}
