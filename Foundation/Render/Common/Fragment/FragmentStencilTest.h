#pragma once
#include "Graphic/GLAPI/macros.h"
#include "FragmentHandle.h"
#include <cstdint>

namespace render
{
	/**
	*	ģ��
	*	(1)��ģ����ԵĹ����У�������ʹ��һ���Ƚ������루comparison mask����ģ�建�����е�ֵ����λ�����㣬
	*	����ο�ֵ���бȽϣ��Ӷ�ʵ�ֶ�ģ�建�����е�ֵ��ĳһλ�ϵ���λ״̬���жϡ�
	*	������ģ�建�����е�ֵ����������Ϊһ������������ʹ�ã���������Ϊһ�����ؼ���ʹ�á�
	*	��OpenGL�У�����ͨ������glStencilFunc()�������趨
	*		�Ƚ�������comparison function����
	*		�ο�ֵ��reference value���Լ���
	*		�������루comparison mask����
	*	(2)���˱Ƚϲο�ֵ��ģ��ֵ֮�⣬���ǻ���Ҫʹ��һЩ����������ģ�建�����е�ֵ����Щ��������Ϊģ�������stencil operation����ģ�建�����ĸ�����ģ����ԵĽ���Լ���Ȳ��ԵĽ���������е���ϵ�������������ͼ��ʾ��ģ���������Ϊ��������������ֱ�ָ����Ӧ�ĸ��·�����
	*
	*	1. ģ�����ʧ�ܡ�
	*
	*	2. ģ�����ͨ��������Ȳ���ʧ�ܡ�
	*
	*	3. ģ�����ͨ��������Ȳ���ͨ����
	*
	*	����������е�һ������ʱ���ͻ�ִ��Ԥ���趨�ĸ��²�������OpenGL�У�����ʹ��glStencilOp()������Ϊ������������ֱ����ø��·��������磬
	*
	*	glStencilOp(GL_KEEP, // ��һ��������·���
	*
	*	GL_DECR, // �ڶ�������ĸ��·���
	*
	*	GL_INCR); // ����������ĸ��·���
	*/
	class FragmentStencilTest : public FragmentHandle
	{
	private:
		struct StencilTestData
		{
			int nStencilFun = 0;
			int nStencilRef = 0;
			int nStencilValueMask = 0;
			int nStencilFail = (int)StencilOpResult::KEEP;
			int nStencilPassDepthFail = (int)StencilOpResult::KEEP;
			int nStencilPassDepthPass = (int)StencilOpResult::KEEP;
		};
	public:
		FragmentStencilTest();
		virtual ~FragmentStencilTest();
	public:
		void setFunc(StencilFunction func, int ref, uint32_t mask);
		void setOperator(StencilOpResult stencilFail, StencilOpResult depthFail, StencilOpResult depthPass);
	public:
		virtual void update();
	protected:
		virtual void saveData();
		virtual void reloadData();
	protected:
		StencilTestData _lastStencilData;
		StencilTestData _stencilData;
	};

	//////////////////////////////////////////////////////////////////////////
	class StencilFaceOp : public FragmentStencilTest
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
