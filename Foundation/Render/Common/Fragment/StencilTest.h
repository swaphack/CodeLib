#pragma once
#include "Graphic/GLAPI/macros.h"
#include "FragmentTestOp.h"
#include <cstdint>

namespace render
{
	/**
	*	Ä£°å²âÊÔ
	*/
	class StencilOp : public FragmentTestOp
	{
	public:
		StencilOp();
		virtual ~StencilOp();
	public:
		void setFunc(StencilFunction func, int ref, uint32_t mask);
		void setOperator(StencilOpResult stencilFail, StencilOpResult depthFail, StencilOpResult depthPass);
	public:
		virtual void startTest();
		virtual void test();
		virtual void endTest();
	protected:
		StencilFunction _func;
		int _ref = 0;
		uint32_t _mask = 0;
		StencilOpResult _stencilFail = StencilOpResult::KEEP;
		StencilOpResult _depthFail = StencilOpResult::KEEP;
		StencilOpResult _depthPass = StencilOpResult::KEEP;
	};

	//////////////////////////////////////////////////////////////////////////
	class StencilFaceOp : public StencilOp
	{
	public:
		StencilFaceOp();
		virtual ~StencilFaceOp();
	public:
		void setFaceType(FaceType faceType);
	public:
		virtual void test();
	protected:
		FaceType _faceType = FaceType::FRONT;
	};
}
