#pragma once

#include <cstdint>
#include "FragmentHandle.h"
#include "Graphic/GLAPI/macros.h"
#include <map>

namespace render
{
	// ��������
	enum class FragmentSampleType
	{
		// ʹ��ƬԪ��alphaֵ�������Ĳ���������
		SAMPLE_ALPHA_TO_COVERAGE = GL_SAMPLE_ALPHA_TO_COVERAGE,
		// ��ƬԪ��alphaֵ����Ϊ����alphaֵ���������Ĳ���������
		SAMPLE_ALPHA_TO_ONE = GL_SAMPLE_ALPHA_TO_ONE,
		// ʹ��glSampleCoverage�����㣬�븲���ʼ���Ľ�����������
		SAMPLE_COVERAGE = GL_SAMPLE_COVERAGE,
		// ʹ��mask������
		SAMPLE_MASK = GL_SAMPLE_MASK,
	};
	/**
	*	ͼԪ�Ķ��ز��� MSAA
	*	��һ�ֿ���ݵļ�������ͨ����һ�������Ͻ��ж�β�����μ��㲢���ջ���(Resolve to single-sample)����ʹ���Ƶ�ͼ���Ե����ƽ��
	*	���������طָ�Ϊ��� 4�� 8��16��32
	*/
	class FragmentSample : public FragmentHandle
	{
	public:
		FragmentSample();
		virtual ~FragmentSample();
	public:
		void setSampleType(FragmentSampleType type);
		void setSampleCoverage(float value, bool invert);
		/**
			����һ��32Ϊ�Ĳ�������mask�������ǰ֡�����������32������������������ĳ��ȿ����Ƕ��32λ��С���ֶ����
			������Ҫ��index����
			Ҳ����ͨ��ƬԴ��ɫ��д��gl_SampleMask������
		*/
		void setSampleMask(uint32_t index, uint32_t mask);
		void clearSampelMask();
	public:
		virtual void begin();
		virtual void update();
		virtual void end();
	protected:
		std::map<uint32_t, uint32_t> _sampleMask;
		sys::Tuple2<float, bool> _sampleConverage;
	};
}

